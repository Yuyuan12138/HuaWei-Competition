#include "Goods.h"

int Goods::remove_expired(int time = now) {
    int removed_count = 0;
    vector<decltype(st.begin())> v;
    for(auto i = st.begin(); i != st.end(); i++) {
        if(i -> expires_at <= time) {
            v.push_back(i);
        }
    }
    for(auto i : v) {
        st.erase(i);
        removed_count++;
    }
    return removed_count;
}

int Goods::remove(int x, int y) {
    int removed_count = 0;
    if(!is_good[x][y]) {
        return 0;
    }
    else {
        is_good[x][y] = false;
        auto it = st.find(Good(x, y, -1));
        return remove(it);
    }
}


int Goods::remove(set<Good>::iterator good) {
    try {
        st.erase(good);
        return 1;
    } catch(exception) {
        cerr << "Error when erasing good." << endl;
        return 0;
    }
}

void Goods::add(Good good) {
    st.insert(good);
    is_good[good.x][good.y] = true;
    // cerr << "adding " << good.x << ' ' << good.y << endl;
    good_money[good.x][good.y] = good.money;
}

void Goods::add(int x, int y, int money, int now = now) {
    Good good(x, y, money, now + LIFE_OF_GOOD);
    add(good);
}

int Goods::size() {
    return st.size();
}
