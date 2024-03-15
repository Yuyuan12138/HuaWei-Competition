//
// Created by Yuyuan12138 on 2024/3/8.
//

#include "Input.h"
using namespace std;

int Input()
{
    /// 读取帧序号和当前金钱数
    cin >> now >> money;
    
    if (cin.eof()) {
        exit(EXIT_SUCCESS);
    }

    /// 读取货物数量
    cin >> num;
    Good good;
    for(int i = 1; i <= num; i ++)
    {
        /// x, y 货物的坐标, val 金额 <= 1000
        int x, y, val;
        x++; y++;
        cin >> x >> y >> val;
        goods.add(x, y, val, now);
        goods.remove_expired(now);
    }

    for(int i = 0; i < robot_num; i ++)
    {
        /// 读取机器人状态
        cin >> robots[i].goods >> robots[i].x >> robots[i].y >> robots[i].status;
        robots[i].x++; robots[i].y++;
        robots[i].id = i;
//        cerr << robots[i].status << endl;
    }
    for(int i = 0; i < 5; i ++)
    {
        /// 读取轮船状态
        cin >> boats[i].status >> boats[i].pos;
    }

    char okk[100];
    cin >> okk;
    return now;
}
