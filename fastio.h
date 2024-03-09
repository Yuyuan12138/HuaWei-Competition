#ifndef CODECRAFTSDK_FASTIO_H
#define CODECRAFTSDK_FASTIO_H

#include <iostream>

/**
 * @brief 从标准输入快速读取一个整数
 * @param[out] x 要读入的变量
*/
template<typename T> void read(T& x);


/**
 * @brief 向标准输出快速写入一个整数
 * @param[in] x 要写入的变量
*/
template<typename T> void write(T x);

#endif