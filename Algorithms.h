#ifndef CODECRAFTSDK_ALGORITHMS_H
#define CODECRAFTSDK_ALGORITHMS_H

#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>

#include "Map.h"
#include "Robot.h"
#include "Goods.h"
#include "Berth.h"

/**
 * @brief 初始化结束后进行dfs，将地图划分为若干块
 * @return 无返回值，但会修改robot_list_by_area, berth_list_by_area, area_id三个变量
*/
void split_areas();

/**
 * @brief 给定机器人编号，选取距离其最近的港口编号
 * @param[in] robot_id 机器人编号
 * @return 选取的港口编号。同时记录当前机器人的路径至passing_time变量
*/
Point find_good_for_robot(int robot_id, int * nextMove);

Point find_berth_for_robot(int robot_id, int * nextMove);

#endif
