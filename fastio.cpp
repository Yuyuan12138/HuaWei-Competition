#include "fastio.h"

template<typename T> void readint(T& x) {
    int v = 0, w = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if(ch == '-')
            w = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        v = v * 10 + ch - '0';
        ch = getchar();
    }
    x = v * w;
}

template<typename T> void writeint(T x) {
    if (x < 0) {
        putchar('-');
        write(-x);
    } else if (x < 10) {
        putchar(x + '0');
    } else {
        write(x / 10);
        putchar(x % 10 + '0');
    }
}