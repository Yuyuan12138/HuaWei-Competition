//
// Created by yuyuan on 2024/3/7.
//

#include "_pojo_header.h"

struct Boat                     // 轮船
{
    int num;
    int pos;                    // 位于的泊位编号（-1为虚拟点）
    int status;                 // 状态：0占用、1装货/运输完成、2等待
}boat[10];
