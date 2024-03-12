#include "Goods.h"

int Goods::remove_expired(int time = now) {
    int removed_count = 0;
    while(q.top().expires_at >= time) {
        auto& good = q.top();
        is_good[good.x][good.y] = false;
        q.pop();
        removed_count++;
    }
    return removed_count;
}

void Goods::add(Good good) {
    q.push(good);
    is_good[good.x][good.y] = true;
    good_money[good.x][good.y] = true;
}

void Goods::add(int x, int y, int money, int now = now) {
    Good good(x, y, money, now);
    add(good);
}

int Goods::size() {
    return q.size();
}
