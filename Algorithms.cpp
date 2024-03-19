#include "Algorithms.h"
#pragma GCC optimize(2)
using namespace std;

Point from[N][N];                           // 在最优路径中每个点的来源位置，需要在搜索的过程中维护
bool visited[N][N];
int step[N][N];
int from_move[N][N];

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
        // if(ch[dx][dy] == '*') continue;
        split_areas_dfs(dx, dy, area_idx);
    }
}

void init_robot_flag() {
    // 标记每个机器人的区域号
    for(int i = 0; i < robot_num; i++) {
        Robot& robot = robots[i];
        int area = area_id[robot.x][robot.y];
        robot_list_by_area[area].push_back(i);
        robot.area = area;
        // cerr << robot.x << ' ' << robot.y << ' ' << robot.area << endl;
    }
    
    // 标记每个机器人的区域号
    for(int i = 0; i < robot_num; i++) {
        Robot& robot = robots[i];
        robot.valid = false;
        for(int j = 0; j < berth_num; j++) {
            Berth& berth = berths[j];
            if(robot.area == berth.area) {
                robot.valid = true;
                break;
            }
        }
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
Point find_good_for_robot(int robot_id, vector<int>& nextMoves) {
    // cerr << "Finding good for robot " << robot_id << endl;
    // auto start = std::chrono::high_resolution_clock::now();
    memset(visited, 0, sizeof(visited));
    memset(step, 0x3f, sizeof(step));
    memset(from, 0, sizeof(from));
    memset(from_move, 0, sizeof(from_move));
    nextMoves.clear();
    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    // cerr << "BFS Time: " << duration << endl;

    Robot& robot = robots[robot_id];
    priority_queue<StateRobot> q;                               // BFS使用的优先队列

    // BFS过程
    q.push({robot.x, robot.y, 0});                              // 将初状态押进队列
    step[robot.x][robot.y] = 0;

    // int tm = 0;

    while(!q.empty()) {
        const auto now = q.top(); q.pop();

        const int x = now.x, y = now.y;
        // cerr << "visiting " << x << ' ' << y << ' ' << from[x][y].x << ' ' << from[x][y].y << endl;
        if(visited[x][y]) continue;
        // if(visited[x][y]) continue;
        visited[x][y] = true;
        // cerr << x << ' ' << y << ' ' << step[x][y] << ' ' << now.step << endl;
        // cerr << "step[" << x << "][" << y << "]=" << step[x][y] << " " << endl;
        if(step[x][y] < now.step) continue;
        for(int i = 0; i < 4; i++) {
            const int dx = x + to[i][0],
                      dy = y + to[i][1],
                      dstep = now.step + 1;
            // cerr << "d: " << dx << ' ' << dy << endl;
            if(!check_coord(dx, dy)) continue;
            if(visited[dx][dy]) continue;
            if(ch[dx][dy] == '#' || ch[dx][dy] == '*') continue;
            if(step[dx][dy] <= dstep) continue;                 // 步数大于当前步数，不可能是最优解
            // if(passing_time[dx][dy].count(dstep)) continue;     // 可能发生碰撞则放弃
            from[dx][dy] = {x, y};
            from_move[dx][dy] = i;
            step[dx][dy] = dstep;
            q.push({dx, dy, dstep});
            // cerr << "Pushed: " << dx << ' ' << dy << ' ' << dstep << endl;
        }
    }
//    std::cerr << "----" << std::endl;
//
//    // BFS结束，已经找到最优路径
//    cerr << "BFS finished" << endl;

    // 寻找最优货物
    int min_steps = INT_MAX;
    Point good_pos;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!is_good[i][j]) continue;
            if(!visited[i][j]) continue;    // 如果机器人无法到达则跳过
            // cerr << "found good " << i << ' ' << j << endl;
            // exit(0);
            if(step[i][j] < min_steps) {
                min_steps = step[i][j];
                good_pos = {i, j};
            }
        }
    }
    // cerr << "found best good" << endl;
    // cerr << "generating path to good" << endl;

    // 在路径中没有找到货物
    if(min_steps == INT_MAX) {
        return {-1, -1};
    }

    // 根据最优货物的坐标寻找来时路径
    Point now = good_pos;
    Point robot_pos = {robot.x, robot.y};
    while(now != robot_pos) {
        nextMoves.push_back(from_move[now.x][now.y]);
        now = from[now.x][now.y];
    }

    // cerr << "got path" << endl;

    nextMoves = vector<int>(nextMoves.crbegin(), nextMoves.crend());

    // 将未来要访问的至多十个点标记在passing_time中
    now = robot_pos;
    size_t lim = 20;
    for(int i = 0; i < min(lim, nextMoves.size()); i++) {
        passing_time[now.x][now.y].insert(i);
        now = {now.x + to[nextMoves[i]][0], now.y + to[nextMoves[i]][1]};
    }
    
    // cerr << "robot id: " << robot_id << endl;
    // cerr << "x: " << robot.x << "; y: " << robot.y << endl;
    // cerr << "good pos: " << good_pos.x << ' ' << good_pos.y << endl;
    // cerr << "path: " << endl;
    // for(auto i : nextMoves)
    //     cerr << i << ' ';
    // cerr << endl;

    return good_pos;
}

/// @brief 为每个机器人寻找距离其最近的港口，同时更新passing_time变量，记录碰撞数据
/// @param[in] robot_id 机器人编号
/// @param[out] nextMove 输出变量，机器人决定下一步向前行进的方向（0-3含义见Output.cpp，4表示不动）
/// @return 选择的港口坐标
Point find_berth_for_robot(int robot_id, vector<int> &nextMoves) {
    // cerr << "Finding berth for " << robot_id << endl;
    memset(visited, 0, sizeof(visited));
    memset(step, 0x3f, sizeof(step));
    memset(from, 0, sizeof(from));
    memset(from_move, 0, sizeof(from_move));
    nextMoves.clear();

    Robot& robot = robots[robot_id];
    priority_queue<StateRobot> q;                               // BFS使用的优先队列

    // BFS过程
    q.push({robot.x, robot.y, 0});                              // 将初状态押进队列
    step[robot.x][robot.y] = 0;

    while(!q.empty()) {
        const auto now = q.top(); q.pop();

        const int x = now.x, y = now.y;
        if(visited[x][y]) continue;
        visited[x][y] = true;
        if(step[x][y] < now.step) continue;
        for(int i = 0; i < 4; i++) {
            const int dx = x + to[i][0],
                      dy = y + to[i][1],
                      dstep = now.step + 1;
            if(!check_coord(dx, dy)) continue;
            if(visited[dx][dy]) continue;
            if(ch[dx][dy] == '#' || ch[dx][dy] == '*') continue;
            if(step[dx][dy] <= dstep) continue;                 // 步数大于当前步数，不可能是最优解
            // if(passing_time[dx][dy].count(dstep)) continue;     // 可能发生碰撞则放弃
            from[dx][dy] = {x, y};
            from_move[dx][dy] = i;
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
            if(!visited[i][j]) continue;
            if(step[i][j] < min_steps) {
                min_steps = step[i][j];
                berth_pos = {i, j};
            }
        }
    }

    // 在路径中没有找到港口
    if(min_steps == INT_MAX) {
        return {-1, -1};
    }

    // 根据最优港口的坐标寻找来时路径
    Point now = berth_pos;
    Point robot_pos = {robot.x, robot.y};
    while(now != robot_pos) {
        nextMoves.push_back(from_move[now.x][now.y]);
        now = from[now.x][now.y];
    }

    nextMoves = vector<int>(nextMoves.crbegin(), nextMoves.crend());

    now = robot_pos;
    size_t lim = 20;
    for(int i = 0; i < min(lim, nextMoves.size()); i++) {
        passing_time[now.x][now.y].insert(i);
        now = {now.x + to[nextMoves[i]][0], now.y + to[nextMoves[i]][1]};
    }

    return berth_pos;
}
