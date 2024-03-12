#include "Algorithms.h"
using namespace std;

int to[5][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {0, 0}};
int next_move[N][N];                        // 每一个点决定向下移动的方向
Point from[N][N];                           // 在最优路径中每个点的来源位置，需要在搜索的过程中维护
bool visited[N][N], step[N][N];

inline bool check_coord(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > n)
        return false;
    return true;
}

void split_areas_dfs(int x, int y, int area_idx) {
    // cerr << x << ' ' << y << endl;
    visited[x][y] = true;
    area_id[x][y] = area_idx;
    for(int i = 0; i < 4; i++) {
        int dx = x + to[i][0],
            dy = y + to[i][1];
        if(!check_coord(dx, dy)) continue;
        if(visited[dx][dy]) continue;
        if(ch[dx][dy] == '#') continue;
        split_areas_dfs(dx, dy, area_idx);
    }
}

void split_areas() {
    memset(visited, 0, sizeof(visited));

    // DFS查找连通块
    int area_idx = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!visited[i][j])
                split_areas_dfs(i, j, area_idx);
            area_idx++;
        }
    }

    // 标记每个机器人的区域号
    for(int i = 0; i < robot_num; i++) {
        Robot& robot = robots[i];
        int area = area_id[robot.x][robot.y];
        robot_list_by_area[area].push_back(i);
        robot.area = area;
    }

    /// 标记每个港口的区域号
    for(int i = 0; i < berth_num; i++) {
        Berth& berth = berths[i];
        int area = area_id[berth.x][berth.y];
        berth_list_by_area[area].push_back(i);
        berth.area = area;
    }
}

/// @brief 对机器人进行BFS的状态结构
struct StateRobot {
    int x, y;
    int step;
    bool operator<(const StateRobot& rhs) const {
        return step > rhs.step;
    }
};

/// @brief 为每个机器人寻找距离其最近的货物，同时更新passing_time变量，记录碰撞数据
/// @param[in] robot_id 机器人编号
/// @param[out] nextMove 输出变量，机器人决定下一步向前行进的方向（0-3含义见Output.cpp，4表示不动）
/// @return 选择的货物坐标
Point find_good_for_robot(int robot_id, int * nextMove) {
    memset(visited, 0, sizeof(visited));
    memset(step, 0, sizeof(step));

    Robot& robot = robots[robot_id];
    priority_queue<StateRobot> q;                               // BFS使用的优先队列

    // BFS过程
    q.push({robot.x, robot.y, 0});                              // 将初状态押进队列
    while(!q.empty()) {
        auto now = q.top(); q.pop();
        int x = now.x, y = now.y;
        cerr << x << ' ' << y << endl;
        visited[x][y] = true;
        if(step[x][y] < now.step) continue;
        for(int i = 0; i < 5; i++) {
            int dx = x + to[i][0],
                dy = y + to[i][1],
                dstep = now.step + 1;
            if(!check_coord(dx, dy)) continue;
            if(ch[dx][dy] == '#') continue;
            if(visited[dx][dy]) continue;
            if(passing_time[dx][dy].count(dstep)) continue;     // 可能发生碰撞则放弃
            if(step[dx][dy] < dstep) continue;                  // 步数大于当前步数，不可能是最优解
            from[dx][dy] = {x, y};
            next_move[x][y] = i;
            step[dx][dy] = dstep;
            q.push({dx, dy, dstep});
        }
    }
    // BFS结束，已经找到最优路径

    cerr << "BFS finished" << endl;
    // 寻找最优货物
    int min_steps = INT_MAX;
    Point good_pos;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!is_good[i][j]) continue;
            if(step[i][j] < min_steps) {
                min_steps = step[i][j];
                good_pos = {i, j};
            }
        }
    }

    // 根据最优货物的坐标寻找来时路径
    Point now = good_pos;
    Point robot_pos = {robot.x, robot.y};
    while(now != robot_pos) {
        passing_time[now.x][now.y].insert(step[now.x][now.y]);
        now = from[now.x][now.y];
    }
    passing_time[now.x][now.y].insert(step[now.x][now.y]);      // 此时点到达机器人位置，将时刻0的位置信息记录下来

    *nextMove = next_move[robot.x][robot.y];

    return good_pos;
}

/// @brief 为每个机器人寻找距离其最近的港口，同时更新passing_time变量，记录碰撞数据
/// @param[in] robot_id 机器人编号
/// @param[out] nextMove 输出变量，机器人决定下一步向前行进的方向（0-3含义见Output.cpp，4表示不动）
/// @return 选择的港口坐标
Point find_berth_for_robot(int robot_id, int * nextMove) {
    memset(visited, 0, sizeof(visited));
    memset(step, 0, sizeof(step));

    Robot& robot = robots[robot_id];
    priority_queue<StateRobot> q;                               // BFS使用的优先队列

    // BFS过程
    q.push({robot.x, robot.y, 0});                              // 将初状态押进队列
    while(!q.empty()) {
        auto now = q.top(); q.pop();
        int x = now.x, y = now.y;
        visited[x][y] = true;
        if(step[x][y] < now.step) continue;
        for(int i = 0; i < 5; i++) {
            int dx = x + to[i][0],
                dy = y + to[i][1],
                dstep = now.step + 1;
            if(!check_coord(dx, dy)) continue;
            if(ch[dx][dy] == '#') continue;
            if(visited[dx][dy]) continue;
            if(passing_time[dx][dy].count(dstep)) continue;     // 可能发生碰撞则放弃
            if(step[dx][dy] < dstep) continue;                  // 步数大于当前步数，不可能是最优解
            from[dx][dy] = {x, y};
            next_move[x][y] = i;
            step[dx][dy] = dstep;
            q.push({dx, dy, dstep});
        }
    }
    // BFS结束，已经找到最优路径

    // 寻找最优港口
    int min_steps = INT_MAX;
    Point berth_pos;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(ch[i][j] != 'B') continue;       // 如果不是港口则跳过
            if(step[i][j] < min_steps) {
                min_steps = step[i][j];
                berth_pos = {i, j};
            }
        }
    }

    // 根据最优货物的坐标寻找来时路径
    Point now = berth_pos;
    Point robot_pos = {robot.x, robot.y};
    while(now != robot_pos) {
        passing_time[now.x][now.y].insert(step[now.x][now.y]);
        now = from[now.x][now.y];
    }
    passing_time[now.x][now.y].insert(step[now.x][now.y]);      // 此时点到达机器人位置，将时刻0的位置信息记录下来

    *nextMove = next_move[robot.x][robot.y];

    return berth_pos;
}
