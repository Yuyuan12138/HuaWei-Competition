//
// Created by Yuyuan12138 on 2024/3/8.
//

#include "Boat.h"

/**
 * @version 0.0.2 boat.cpp
 *  @brief 实现船的控制逻辑
 * */
void boatController()
{
    // todo 0 和 2 窗台的算法优化
    /*! 通过status判断目前船的行动状态
     * 如果是0，则是运输中，则不管
     * 如果是1，则是在装货或者虚拟点
     * 如果是2，则是在泊位外等待，不管
     * 遍历每一艘船
     * */
     for(int i = 0; i < boat_num; i++)
     {
         cerr << boats[i].pos << endl;
         fflush(stderr);
         if(boats[i].status == 0) continue;
         if(boats[i].status == 2) continue;

         /// 如果在虚拟点，则寻找价值最高的那个点

         if(boats[i].pos == -1)
         {
             for(int j = 0; j < berth_num; j++)
             {
                 cerr << "Berths: " << j << " " << berths[j].num_boatStore << endl;
                 if(berths[j].num_boatStore != 0) continue;
                //  cerr << "Berths: " << j << ' ' << berths[j].get_good_count() << endl;
                 if(berths[j].get_good_count() == 0) continue;
//                 cerr << "---------" << endl;

                 Operation operation(Objector::boat, Command::ship, i, j);
                 operations.push_back(operation);
                 berths[j].num_boatStore += 1;
             }
         }else{
             if(berths[boats[i].pos].transport_time >= 15000 - now - 45)
             {
                 Operation operation(Objector::boat, Command::go, i);
                 operations.push_back(operation);
                 continue;
             }
             if(berths[boats[i].pos].get_good_count() <= 0 && boats[i].num_goods != 0)
             {
                 Operation operation(Objector::boat, Command::go, i);
                 operations.push_back(operation);
                 continue;
             }
             int min_num = min(berths[boats[i].pos].loading_speed, berths[boats[i].pos].get_good_count());
             for(int _ = 0; _ < min_num; _++)
             {
                 berths[boats[i].pos].remove_good();
             }

         }

     }

}


/**
 * @version 0.0.1 boat.cpp
 * */
//void boatController()
//{
//    ///  每个船所装的货物数量要自更新
//    for(int i = 0; i < 5; i++)
//    {
//        if(boats[i].status == 0)
//        {
//            boats[i].num_goods = 0;
//        }   /// 如果船处于运输中，则不予理会
//
//        if(boats[i].status == 1)
//        {
//            Operation boat_operate{};
//            boat_operate.objector = 1;
//            boat_operate.command = 0;
//            boat_operate.id = i;
//            boat_operate.optionArg = i;
////            berths[boats[i].pos].num_boatStore -= 1;
//            operations.push_back(boat_operate);
////            /// 判断是否在装货点
////            /// 如果不为 -1 则在装货点
////            if(boats[i].pos != -1)
////            {
////                /// 在装货点
////                /// 满载
////                if(boats[i].num_goods >= boats[i].capacity)
////                {
////                    /// 去往虚拟点
////                    Operation boat_operate{};
////                    boat_operate.objector = 1;
////                    boat_operate.command = 1;
////                    boat_operate.id = i;
////                    berths[boats[i].pos].num_boatStore -= 1;
////                    operations.push_back(boat_operate);
////                }else{
////                    /// 不满载
////                    /// 获取当前港口需要到达 虚拟点的时间
////                    if(berths[boats[i].pos].transport_time <= 15000 - now)
////                    {
////                        /// 强制前往虚拟点
////                        Operation boat_operate{};
////                        boat_operate.objector = 1;
////                        boat_operate.command = 1;
////                        boat_operate.id = i;
////                        berths[boats[i].pos].num_boatStore -= 1;
////                        operations.push_back(boat_operate);
////                    }else{
////                        /// 判断是否还有货物
////                        if(berths[boats[i].pos].get_good_count() <= 0 && boats[i].num_goods > 0)
////                        {
////                            /// 没有货物，去往虚拟点 但船上有
////                            Operation boat_operate{};
////                            boat_operate.objector = 1;
////                            boat_operate.command = 1;
////                            boat_operate.id = i;
////                            berths[boats[i].pos].num_boatStore -= 1;
////                            boats[i].num_goods = 0;
////                            operations.push_back(boat_operate);
////                        }else{
////                            /// 减去货物，还有货物，呆着
////                            if(berths[boats[i].pos].get_good_count() > berths[boats[i].pos].loading_speed)
////                            {
////                                boats[i].num_goods += berths[boats[i].pos].loading_speed;
////                            }else{
////                                boats[i].num_goods += berths[boats[i].pos].get_good_count();
////                            }
////
////                            for(int _ = 0; _ < berths[boats[i].pos].loading_speed; _++)
////                            {
////                                berths[boats[i].pos].remove_good();
////                            }
////
////                            continue;
////                        }
////                    }
////                }
////            }else{
////
////                /// 不在装货点
////                ///  计算最高价值的点
////                int max_value = 0;
////                int idx = 0;
////                boats[i].num_goods = 0;
////
////                /// 遍历每个berth， 首先保证没有船只在该港口
////                /// 然后寻找价值最高的那个映射
////                /// 前提条件：berth 数量大于 boat数量
////                for(int j = 0; j < berth_num; j++)
////                {
////                    /**
////                     * 如果该港口没有船只，那么计算value数值，如果value > max_value 那么暂定去到这个港口
////                     * */
////                    if(berths[j].num_boatStore <= 0)
////                    {
////                        /// 时间 = 去的时间 + （港口货物数量 / 装货速度）
////                        int time = berths[j].get_good_count() / berths[j].loading_speed + berths[j].transport_time;
////                        int value = berths[j].get_value_sum() / time;
////                        if(value >= max_value)
////                        {
////                            max_value = value;
////                            idx = j;
////                        }
////
////                    }
////                }
////                berths[idx].num_boatStore += 1;
////                /// 去往价值最高的索引berth
////                Operation boat_operate{};
////                boat_operate.objector = 1;
////                boat_operate.command = 0;
////                boat_operate.id = i;
////                boat_operate.optionArg = idx;
////
////                operations.push_back(boat_operate);
////
////            }
//        }
//
//        ///  在泊位外等待（暂且不考虑）
//        if(boats[i].status == 2)
//        {
//            continue;
//        }
//
//    }
//}
