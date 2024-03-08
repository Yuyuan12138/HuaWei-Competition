//
// Created by Yuyuan12138 on 2024/3/8.
//

#ifndef CODECRAFTSDK_BERTH_H
#define CODECRAFTSDK_BERTH_H
#include "Constants.h"

/**
 * @brief 港口结构体
 * */
struct Berth
{
    int x;                      /*! 港口x坐标 */
    int y;                      /*! 港口y坐标 */
    int transport_time;         /*! 港口到虚拟点的时间 */
    int loading_speed;          /*! 每帧可以装载的物品数量 */
    Berth(){}
    Berth(int x, int y, int transport_time, int loading_speed) {
        this -> x = x;
        this -> y = y;
        this -> transport_time = transport_time;
        this -> loading_speed = loading_speed;
    }
} inline berth[berth_num + 10];
#endif //CODECRAFTSDK_BERTH_H
