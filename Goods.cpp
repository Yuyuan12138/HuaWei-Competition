#include "Goods.h"

void Goods::remove_expired(int time) {
    while(q.top().expires_at >= time) {
        q.pop();
    }
}