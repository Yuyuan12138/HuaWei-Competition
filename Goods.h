#ifndef CODECRAFTSDK_GOODS_H
#define CODECRAFTSDK_GOODS_H

#include <queue>
#include "Variation.h"

inline constexpr int expire_time = 1000;            // 货物的停留的时间

/* 货物结构体 */
struct Good {
    int x, y;                                       // 货物坐标
    int money;                                      // 货物金额
    int expires_at;                                 // 货物消失的时间戳
    Good() {}
    Good(int x, int y, int now) : x(x), y(y), expires_at(now + expire_time) {}
    bool operator<(const Good& rhs) const {
        return expires_at > rhs.expires_at;
    }
};


/* 货物列表结构体 */
struct Goods {
    std::priority_queue<Good> q;                    // 货物队列

    /**
     * @brief 给定当前时间戳，移除已过期的货物
     * @param time 当前时间戳（默认取全局时间戳）
     * @return 移除的货物数量
    */
    int remove_expired(int time);

    /**
     * @brief 将货物加入队列
     * @param good Good对象，要添加的货物
     * @return void
    */
    void add(Good good);

    /**
     * @brief 将货物加入队列
     * @param x 货物的x坐标
     * @param y 货物的y坐标
     * @param now 当前时间戳（默认取全局时间戳）
     * @return void
    */
   void add(int x, int y, int now);
} inline goods;

#endif //CODECRAFTSDK_GOODS_H
