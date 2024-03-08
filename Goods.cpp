#include "Goods.h"

int Goods::remove_expired(int time = now) {
    int removed_count = 0;
    while(q.top().expires_at >= time) {
        q.pop();
        removed_count++;
    }
    return removed_count;
}

void Goods::add(Good good) {
    q.push(good);
}

void Goods::add(int x, int y, int now = now) {
    Good good(x, y, now);
    q.push(good);
}
