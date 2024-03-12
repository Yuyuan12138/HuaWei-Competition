//
// Created by Yuyuan12138 on 2024/3/8.
//

#include "Input.h"

int Input()
{
    /// 读取帧序号和当前金钱数
    scanf("%d%d", &id, &money);

    /// 读取货物数量
    scanf("%d", &num);
    Good good;
    for(int i = 1; i <= num; i ++)
    {
        /// x, y 货物的坐标, val 金额 <= 200
//        int x, y, val;
//        scanf("%d%d%d", &x, &y, &val);
        scanf("%d%d%d", &good.x, &good.y, &good.money);
        goods.add(good);
    }

    for(int i = 0; i < robot_num; i ++)
    {
        /// 读取机器人状态
        scanf("%d%d%d%d", &robots[i].goods, &robots[i].x, &robots[i].y, &robots[i].status);
    }
    for(int i = 0; i < 5; i ++)
    {
        /// 读取轮船状态
        scanf("%d%d\n", &boat[i].status, &boat[i].pos);
        boat[i].num = i;
    }

    char okk[100];
    scanf("%s", okk);
    return id;
}
