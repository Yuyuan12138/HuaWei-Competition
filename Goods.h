#ifndef CODECRAFTSDK_GOODS_H
#define CODECRAFTSDK_GOODS_H

#include <queue>

inline constexpr int expire_time = 1000;            // 货物的停留的时间

struct Good {
    int x, y;                                       // 货物坐标
    int money;                                      // 货物金额
    int expires_at;                                 // 货物消失的时间戳
    bool operator<(const Good& rhs) const {
        return expires_at > rhs.expires_at;
    }
};

struct Goods {
    std::priority_queue<Good> q;                    // 货物队列

    /* 给定当前时间戳，删除过期的货物 */
    void remove_expired(int time);
} inline goods;

#endif //CODECRAFTSDK_GOODS_H
