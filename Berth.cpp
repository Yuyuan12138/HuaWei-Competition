//
// Created by Yuyuan12138 on 2024/3/8.
//

#include "Berth.h"

Berth::Berth(int x, int y, int transport_time, int loading_speed) {
    this -> x = x;
    this -> y = y;
    this -> transport_time = transport_time;
    this -> loading_speed = loading_speed;
}

void Berth::add_good(int value) {
    good_values.push(value);
    sum_value += value;
}

int Berth::remove_good() {
    if(good_values.empty())
        return 0;
    else {
        sum_value -= good_values.front();
        good_values.pop();
        return 1;
    }
}

//int Berth::remove_good(int value) {
////    auto it = good_values.top(value);
////    if(it == good_values.end())
////        return 0;
//    if(good_values.empty())
//    {
//        return 0;
//    }
//    good_values.pop();
//    sum_value -= value;
//    return 1;
//}

int Berth::get_value_sum() {
    return sum_value;
}

int Berth::get_good_count() {
    return good_values.size();
}