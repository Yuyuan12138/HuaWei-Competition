//
// Created by yuyuan on 2024/3/7.
//

#include "_pojo_header.h"

struct Robot                    // 机器人
{
    int x, y, goods;
    int status;                 // 状态
    int mbx, mby;
    Robot() {}
    Robot(int startX, int startY) {
        x = startX;
        y = startY;
    }
}robot[robot_num + 10];