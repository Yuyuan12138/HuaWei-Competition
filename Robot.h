//
// Created by Yuyuan12138 on 2024/3/8.
//

#ifndef CODECRAFTSDK_ROBOT_H
#define CODECRAFTSDK_ROBOT_H

#include "Constants.h"
#include <vector>
#include "Algorithms.h"
#include "Output.h"
#include "Controller.h"

/**
 * @brief 机器人的结构体
 * @param x, y 表示当前坐标
 * @param goods 0, 未携带货物。1，携带货物。
 * @param status 0恢复状态，1正常运行状态
 * */
struct Robot{
    int x, y;           // 当前坐标
    int goods;          // 是否携带货物
    int status;         // 状态：0恢复状态，1正常运行状态
    int id;
    int mbx, mby;
    int area;           // 机器人所属的连通块编号
    bool valid = true;
    int good_money;
    Robot() {}
    Robot(int startX, int startY) {
        x = startX;
        y = startY;
    }
} inline robots[robot_num + 10];


void robotController();

#endif //CODECRAFTSDK_ROBOT_H


/**
 *  Why I code this program has been forgotten. If you want to optimize my code.
 *  I advice you not to do that.
 *  It works, that's ok.
 *  Only me and the God know the reason.
 *  And know only the God.
 *  xD
 * */
