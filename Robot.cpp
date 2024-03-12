//
// Created by Yuyuan12138 on 2024/3/8.
//

#include "Robot.h"

void robotController()
{
    for(int i = 0; i < robot_num; i++)
    {
        /**
         * @brief 分类机器人状态并且进行操作
         * */
         int direction = 0;
         if(robots[i].goods == 0)
         {
             /// 未携带货物，且不在货物点
             /// todo: 判断是否在货物点
             Point point{};
             /// 货物坐标
             point = find_good_for_robot(i, &direction);
             /// 塞入operation
             Operation operation{};
             operation.id = i;
             operation.objector = 0;
             operation.command = 0;
             operation.optionArg = direction;
             operations.push_back(operation);
         }

         if(robots[i].goods == 1)
         {
             /// 携带货物，且不在港口点
             /// todo: 判断是否在berth

             Point point{};
             point = find_berth_for_robot(i, &direction);
             Operation operation{};
             operation.id = i;
             operation.objector = 0;
             operation.command = 0;
             operation.optionArg = direction;
             operations.push_back(operation);
         }
    }
}