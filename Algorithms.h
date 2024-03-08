#ifndef CODECRAFTSDK_ALGORITHMS_H
#define CODECRAFTSDK_ALGORITHMS_H

#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

#include "Map.h"
#include "Robot.h"
#include "Goods.h"

inline std::vector<int> robot_list_by_area[MAX_AREAS];
inline std::vector<int> berth_list_by_area[MAX_AREAS];

/**
 * @brief 程序开始时进行dfs，将地图划分为若干块
*/
void split_areas();


#endif