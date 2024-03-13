#include "Goods.h"

int Goods::remove_expired(int time = now) {
    int removed_count = 0;
    while(!q.empty() && q.top().expires_at <= time) {
        auto& good = q.top();
        is_good[good.x][good.y] = false;
        cerr << "removing " << good.x << ' ' << good.y << endl;
        q.pop();
        removed_count++;
    }
    return removed_count;
}

int Goods::remove_on_map(int x, int y) {
    int removed_count = 0;
    if(!is_good[x][y])
        return 0;
    else {
        is_good[x][y] = false;
        return 1;
    }
}

void Goods::add(Good good) {
    q.push(good);
    is_good[good.x][good.y] = true;
    cerr << "adding " << good.x << ' ' << good.y << endl;
    good_money[good.x][good.y] = good.money;
}

void Goods::add(int x, int y, int money, int now = now) {
    Good good(x, y, money, now + LIFE_OF_GOOD);
    add(good);
}

int Goods::size() {
    return q.size();
}
