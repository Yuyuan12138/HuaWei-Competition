#ifndef CODECRAFTSDK_POINT_H
#define CODECRAFTSDK_POINT_H

#include <array>

/// @brief 点的坐标结构
struct Point {
    int x, y;

    Point() {};
    Point(int x, int y) : x(x), y(y) {}

    /// @brief 两个点相等的比较运算符
    /// @param rhs 等号右侧的点
    /// @return true / false
    bool operator==(const Point& rhs) const;

    /// @brief 两个点不相等的比较运算符
    /// @param rhs 等号右侧的点
    /// @return true / false
    bool operator!=(const Point& rhs) const;
};

#endif