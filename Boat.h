//
// Created by Yuyuan12138 on 2024/3/8.
//

#ifndef CODECRAFTSDK_BOAT_H
#define CODECRAFTSDK_BOAT_H

#include "Constants.h"
#include <vector>
#include "Boat.h"
#include "Controller.h"
#include "Berth.h"

inline int boat_capacity[boat_num];       /// 船承载的货物容量


/**
 * @brief 船结构体
 * @param num 轮船id
 * @param capacity 船的容积
 * @param num_goods 船目前所含有的货物数量
 * @param pos 泊位id
 * @param status 0: 运输状态。1：装货状态。2：泊位外等待状态。
 * */
struct Boat
{
    int num_goods;
    int num;
    int capacity;               // 船的容积
    int pos;                    // 船当前所在港口
    int status;                 // 船的状态
} inline boat[boat_num];

void boatController();


/// 给船只找寻港口
/**
 * @brief 给船只找寻港口
 * @param 传入船只结构体
 * @return berth_id 返回泊位id
 * @note 判断的基准是，找寻价值最高的港口点，其实可以提前计算
 * */
void find_berth_for_boat(Boat boat_now, int * berth_id);

#endif //CODECRAFTSDK_BOAT_H
