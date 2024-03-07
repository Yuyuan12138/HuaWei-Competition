//
// Created by yuyuan on 2024/3/7.
//

#include "_pojo_header.h"

struct Berth                    // 泊位
{
    int x;
    int y;
    int transport_time;         // 到虚拟点的时间
    int loading_speed;          // 每帧可装载的物品数
    Berth(){}
    Berth(int x, int y, int transport_time, int loading_speed) {
        this -> x = x;
        this -> y = y;
        this -> transport_time = transport_time;
        this -> loading_speed = loading_speed;
    }
}berth[berth_num + 10], r;
