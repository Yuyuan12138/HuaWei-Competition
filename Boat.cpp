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
                //todo 在装货点，判断是否满载

                /// 满载
                if(boat[i].num_goods >= boat[i].capacity)
                {
                    Operation boat_operate{};
                    boat_operate.objector = 1;
                    boat_operate.command = 1;
                    boat_operate.id = i;
                    operations.push_back(boat_operate);
                }else{
                    /// 不满载

                    /// 获取当前港口需要到达 虚拟点的时间
                    if(berths[boat[i].pos].transport_time <= 15000 - id)
                    {
                        /// 强制前往虚拟点
                        Operation boat_operate{};
                        boat_operate.objector = 1;
                        boat_operate.command = 1;
                        boat_operate.id = i;
                        operations.push_back(boat_operate);
                    }else{
                        /// 判断是否还有货物
                    }
                }
                /// 获取货船情况
                /// 根据轮船地点获取当前港口情况


            }else{
                /// 不在装货点
                // todo 计算最高价值的点
            }
        }

        /// todo 在泊位外等待（暂且不考虑）
        if(boat[i].status == 2)
        {
            continue;
        }
    }
}
