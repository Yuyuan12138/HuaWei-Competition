#ifndef CODECRAFTSDK_FASTIO_H
#define CODECRAFTSDK_FASTIO_H

#include <iostream>

/**
 * @brief 从标准输入快速读取一个整数
 * @param[out] x 要读入的变量
*/
template<typename T> void readint(T& x) {
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
template<typename T> void writeint(T x) {
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

#endif
