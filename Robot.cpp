//
// Created by Yuyuan12138 on 2024/3/8.
//

#include "Robot.h"

void robotController()
{
    for(int i = 1; i <= 200; i++) {
        for(int j = 1; j <= 200; j++)
            passing_time[i][j].clear();
    }

    for(int i = 0; i < robot_num; i++)
    {
        /// 处于恢复状态，则不操作
        if(robots[i].status == 0) continue;
        /**
         * @brief 分类机器人状态并且进行操作
         * */
        int direction = 0;

        /// 机器人坐标
        Point robotPoint;
        Operation operation{};
        robotPoint.x = robots[i].x, robotPoint.y = robots[i].y;

        if(robots[i].goods == 0)
        {
            /// 未携带货物，且不在货物点
            ///  判断是否在货物点
            Point point;
            point = find_good_for_robot(i, &direction);

            if(point == robotPoint)
            {
                is_good[point.x][point.y] = false;
                operation.objector = 0;
                operation.command = 1;
                operation.id = i;
                operations.push_back(operation);
                continue;
            }

            /// 货物坐标

//             cerr << "found good for robot" << endl;
            /// 塞入operation

            operation.id = i;
            operation.objector = 0;
            operation.command = 0;
            operation.optionArg = direction;
            if(direction < 0 || direction > 3)
               continue;
            operations.push_back(operation);

        }
        else if(robots[i].goods == 1)
        {
            /// 携带货物，且不在港口点
            ///  判断是否在berth

            Point point;
            point = find_berth_for_robot(i, &direction);

            if(point == robotPoint)
            {
                operation.objector = 0;
                operation.id = i;
                operation.command = 2;
                operations.push_back(operation);

                continue;
            }
            if(direction > 3)
            {
                continue;
            }

            operation.id = i;
            operation.objector = 0;
            operation.command = 0;
            operation.optionArg = direction;

            operations.push_back(operation);
        }
    }
}