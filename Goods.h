#ifndef CODECRAFTSDK_GOODS_H
#define CODECRAFTSDK_GOODS_H

#include <queue>

struct Good {
    int x, y;                                       // 货物坐标
    int money;                                      // 货物金额
    int expires_at;                                 // 货物消失的时间
    bool operator<(const Good& rhs) const {
        return expires_at > rhs.expires_at;
    }
};

<<<<<<< HEAD
inline std::priority_queue<Good> goods;             // 货物队列
=======
inline std::priority_queue<Good> goods;     /** 货物队列 */
>>>>>>> wrj

#endif //CODECRAFTSDK_GOODS_H
