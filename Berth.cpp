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

void sort_highest_value_vector()
{
    highest_value_vector.clear();
    for(int i = 0; i < berth_num; i++ )
    {
        highest_value_vector.push_back(berths[i]);
    }
}

bool cmp_only_used_(Berth a, Berth b)
{
    int value_a = a.get_value_sum() / a.loading_speed + a.transport_time;
    int value_b = b.get_value_sum() / b.loading_speed + b.transport_time;
    return value_a < value_b;
}
//int Berth::get_single_value() {
//    if(good_values.empty())
//    {
//        return -1;
//    }
//    return good_values.top();
//}