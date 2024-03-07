//
// Created by yuyuan on 2024/3/7.
//
#ifndef CODECRAFTSDK__INPUT_HEADER_H
#define CODECRAFTSDK__INPUT_HEADER_H
#include "_input_header.h"
#endif //CODECRAFTSDK__INPUT_HEADER_H


int Input()
{
    scanf("%d%d", &id, &money);
    int num;
    scanf("%d", &num);
    for(int i = 1; i <= num; i ++)
    {
        int x, y, val;
        scanf("%d%d%d", &x, &y, &val);
    }
    for(int i = 0; i < robot_num; i ++)
    {
        scanf("%d%d%d%d", &robot[i].goods, &robot[i].x, &robot[i].y, &robot[i].status);
    }
    for(int i = 0; i < 5; i ++)
        scanf("%d%d\n", &boat[i].status, &boat[i].pos);
    char okk[100];
    scanf("%s", okk);
    return id;
}
