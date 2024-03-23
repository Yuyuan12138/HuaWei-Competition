//
// Created by Yuyuan12138 on 2024/3/8.
//

#include "Init.h"


void Init()
{
    for(int i = 1; i <= n; i ++)
        scanf("%s", ch[i] + 1);
    for(int i = 0; i < berth_num; i ++)
    {
        int id;
        scanf("%d", &id);
        berths[id].id = id;
        scanf("%d%d%d%d", &berths[id].x, &berths[id].y, &berths[id].transport_time, &berths[id].loading_speed);
        berths[id].x++; berths[id].y++;
    }

    for(int i = 0; i < boat_num;i++)
    {
        scanf("%d", &boats[i].capacity);
    }

    char okk[100];
    scanf("%s", okk);
    printf("OK\n");
    fflush(stdout);
}
