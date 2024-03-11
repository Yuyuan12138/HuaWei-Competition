//
// Created by Yuyuan12138 on 2024/3/8.
//

#ifndef CODECRAFTSDK_BERTH_H
#define CODECRAFTSDK_BERTH_H
#include "Constants.h"
#include <set>

/**
 * @brief 港口结构体
 * */
struct Berth
{
    int x;                              /*! 港口x坐标 */
    int y;                              /*! 港口y坐标 */
    int transport_time;                 /*! 港口到虚拟点的时间 */
    int loading_speed;                  /*! 每帧可以装载的物品数量 */
    int area;                           /*! 港口所属的连通块编号 */
    std::multiset<int> good_values;     /*! 每个货物的价值 */
    int sum_value = 0;                 /*! 货物价值之和 */
    Berth(){}
    Berth(int x, int y, int transport_time, int loading_speed);

    /// @brief 添加一个货物
    /// @param value 货物价值
    void add_good(int value);

    /// @brief 移除一个货物
    /// @param value 货物价值
    /// @return 成功移除的货物数量
    int remove_good(int value);

    /// @brief 查询当前货物价值之和
    /// @return 货物价值之和
    int get_value_sum();

    /// @brief 查询当前货物数量
    /// @return 货物数量
    int get_good_count();
} inline berths[berth_num + 10];
#endif //CODECRAFTSDK_BERTH_H
