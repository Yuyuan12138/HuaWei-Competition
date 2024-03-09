#ifndef CODECRAFTSDK_MAP_H
#define CODECRAFTSDK_MAP_H

#include "Constants.h"
#include <set>


inline constexpr int N = 210;   /** 地图大小 */

inline char ch[N][N];           /** 地图 */
inline int area_id[N][N];       /** 每个坐标所属的区域编号 */
inline std::vector<int> robot_list_by_area[MAX_AREAS];      // 每个区域的机器人列表
inline std::vector<int> berth_list_by_area[MAX_AREAS];      // 每个区域的港口列表
inline std::set<int> passing_time[N][N];                 // 每个位置被经过的时间戳

#endif
