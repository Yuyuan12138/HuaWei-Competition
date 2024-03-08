//
// Created by Yuyuan12138 on 2024/3/8.
//

#ifndef CODECRAFTSDK_BOAT_H
#define CODECRAFTSDK_BOAT_H

inline int boat_capacity;       // 船承载的货物容量

struct Boat
{
    int num;
    int pos;                    // 船当前所在港口
    int status;                 // 船的状态
};

extern Boat boat[10];
#endif //CODECRAFTSDK_BOAT_H
