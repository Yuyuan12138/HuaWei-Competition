//
// Created by Yuyuan12138 on 2024/3/8.
//

#include "Input.h"

/**
 * @brief 从标准输入快速读取一个整数
 * @param[out] x 要读入的变量
*/
template<typename T> void read(T& x) {
    int v = 0, w = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if(ch == '-')
            w = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        v = v * 10 + ch - '0';
        ch = getchar();
    }
    x = v * w;
}

/**
 * @brief 向标准输出快速写入一个整数
 * @param[in] x 要写入的变量
*/
template<typename T> void write(T x) {
    if (x < 0) {
        putchar('-');
        write(-x);
    } else if (x < 10) {
        putchar(x + '0');
    } else {
        write(x / 10);
        putchar(x % 10 + '0');
    }
}

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
        int sts;
        scanf("%d%d%d%d", &robots[i].goods, &robots[i].x, &robots[i].y, &sts);
    }
    for(int i = 0; i < 5; i ++)
        scanf("%d%d\n", &boat[i].status, &boat[i].pos);
    char okk[100];
    scanf("%s", okk);
    return id;
}
