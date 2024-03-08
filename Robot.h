//
// Created by Yuyuan12138 on 2024/3/8.
//

#ifndef CODECRAFTSDK_ROBOT_H
#define CODECRAFTSDK_ROBOT_H

#include "Constants.h"

struct Robot{
    int x, y;           // 当前坐标
    bool goods;         // 是否携带货物
    int status;         // 状态：0恢复状态，1正常运行状态
    int mbx, mby;
    Robot() {}
    Robot(int startX, int startY) {
        x = startX;
        y = startY;
    }
};
inline Robot robots[robot_num + 10];

#endif //CODECRAFTSDK_ROBOT_H
