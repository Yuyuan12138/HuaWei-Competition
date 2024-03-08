//
// Created by Yuyuan12138 on 2024/3/8.
//

#ifndef CODECRAFTSDK_ROBOT_H
#define CODECRAFTSDK_ROBOT_H
#include "Constants.h"
struct Robot{
    int x, y, goods;
    int status;
    int mbx, mby;
    Robot() {}
    Robot(int startX, int startY) {
        x = startX;
        y = startY;
    }
};
extern Robot robot[robot_num + 10];
#endif //CODECRAFTSDK_ROBOT_H
