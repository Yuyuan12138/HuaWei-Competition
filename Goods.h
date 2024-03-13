#ifndef CODECRAFTSDK_GOODS_H
#define CODECRAFTSDK_GOODS_H

#include <queue>
#include "Variation.h"
#include "Map.h"
#include <iostream>

/* 货物结构体 */
struct Good {
    int x, y;                                       // 货物坐标
    int money;                                      // 货物金额
    int expires_at;                                 // 货物消失的时间戳
    Good() {}
    Good(int x, int y, int money, int now = ::now) : x(x), y(y), money(money), expires_at(now + LIFE_OF_GOOD) {}
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
     * @param money 货物价值
     * @param now 当前时间戳（默认取全局时间戳）
     * @return void
    */
   void add(int x, int y, int money, int now);

   /// @brief 返回货物数量
   /// @return 货物数量
   int size();

   /// @brief 移除位于某一点的货物
   /// @param x 货物的x坐标
   /// @param y 货物的y坐标
   /// @return 移除的货物数量
   int remove_on_map(int x, int y);
} inline goods;

inline bool is_good[N][N];          /// 每个节点是否为货物
inline bool good_money[N][N];       /// 当前位置的货物价值（只在is_good[x][y]==true是生效）

#endif //CODECRAFTSDK_GOODS_H
