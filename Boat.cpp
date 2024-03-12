//
// Created by Yuyuan12138 on 2024/3/8.
//

#include "Boat.h"

void boatController()
{
    for(int i = 0; i < 5; i++)
    {

        if(boat[i].status == 0) continue;   /// 如果船处于运输中，则不予理会

        if(boat[i].status == 1)
        {
            /// 判断是否在装货点
            /// 如果不为 -1 则在装货点
            if(boat[i].pos != -1)
            {
                /// 在装货点
                /// 满载
                if(boat[i].num_goods >= boat[i].capacity)
                {
                    /// 去往虚拟点
                    Operation boat_operate;
                    boat_operate.objector = 1;
                    boat_operate.command = 1;
                    boat_operate.id = i;
                    berths[boat[i].pos].boat_id = -1;
                    operations.push_back(boat_operate);
                }else{
                    /// 不满载

                    /// 获取当前港口需要到达 虚拟点的时间
                    if(berths[boat[i].pos].transport_time <= 15000 - now)
                    {
                        /// 强制前往虚拟点
                        Operation boat_operate;
                        boat_operate.objector = 1;
                        boat_operate.command = 1;
                        boat_operate.id = i;
                        berths[boat[i].pos].boat_id = -1;
                        operations.push_back(boat_operate);
                    }else{
                        /// 判断是否还有货物
                        if(berths[boat[i].pos].get_good_count() <= 0)
                        {
                            /// 没有货物，去往虚拟点
                            Operation boat_operate;
                            boat_operate.objector = 1;
                            boat_operate.command = 1;
                            boat_operate.id = i;
                            berths[boat[i].pos].boat_id = -1;
                            operations.push_back(boat_operate);
                        }else{
                            /// 还有货物，呆着
                            continue;
                        }
                    }
                }
            }else{
                /// 不在装货点
                // todo 计算最高价值的点
                int max_value = 0;
                int idx = 0;
                for(int j = 0; j < berth_num;j++)
                {
                    if(berths[j].boat_id == -1)
                    {
                        /// 时间 = 去的时间 + （港口货物数量 / 装货速度）
                        int time = berths[j].get_good_count() / berths[j].loading_speed + berths[j].transport_time;
                        int value = berths[j].get_value_sum() / time;
                        if(value > max_value)
                        {
                            max_value = value;
                            idx = j;
                        }
                    }
                }
                /// 去往价值最高的索引berth
                Operation boat_operate;
                boat_operate.objector = 1;
                boat_operate.command = 0;
                boat_operate.id = i;
                boat_operate.optionArg = idx;
                operations.push_back(boat_operate);

            }
        }

        /// todo 在泊位外等待（暂且不考虑）
        if(boat[i].status == 2)
        {
            continue;
        }
    }
}
