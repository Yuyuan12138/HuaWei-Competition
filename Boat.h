//
// Created by Yuyuan12138 on 2024/3/8.
//

#ifndef CODECRAFTSDK_BOAT_H
#define CODECRAFTSDK_BOAT_H

#include <vector>

inline int boat_capacity;       /// 船承载的货物容量


/**
 * @brief 船结构体
 * @param num 轮船id
 * @param pos 泊位id
 * @param status 0: 运输状态。1：装货状态。2：泊位外等待状态。
 * */
struct Boat
{
    int num;
    int pos;                    // 船当前所在港口
    int status;                 // 船的状态
} inline boat[10];

#endif //CODECRAFTSDK_BOAT_H
