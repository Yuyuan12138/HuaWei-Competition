#include "Algorithms.h"
using namespace std;

int to[5][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {0, 0}};
int from[N][N];                     // 在最优路径中每个点的来源位置，需要在搜索的过程中维护
bool visited[N][N], step[N][N];

void split_areas_dfs(int x, int y, int area_idx) {
    visited[x][y] = true;
    area_id[x][y] = area_idx;
    for(int i = 0; i < 4; i++) {
        int dx = x + to[i][0],
            dy = y + to[i][1];
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

/// @brief 
/// @param robot_id 机器人编号
/// @return 选择到的货物编号
int find_good_for_robot(int robot_id) {
    memset(visited, 0, sizeof(visited));
    memset(step, 0, sizeof(step));

    Robot& robot = robots[robot_id];
    priority_queue<StateRobot> q;                               // BFS使用的优先队列

    // BFS过程
    q.push({robot.x, robot.y, 0});                              // 将初状态押进队列
    while(!q.empty()) {
        auto now = q.top(); q.pop();
        int x = now.x, y = now.y;
        if(step[x][y] < now.step) continue;
        for(int i = 0; i < 5; i++) {
            int dx = x + to[i][0],
                dy = y + to[i][1],
                dstep = now.step + 1;
            if(ch[dx][dy] == '#') continue;
            if(visited[dx][dy]) continue;
            if(passing_time[dx][dy].count(dstep)) continue;     // 可能发生碰撞则放弃
            if(step[dx][dy] < dstep) continue;                  // 步数大于当前步数，不可能是最优解
            step[dx][dy] = dstep;
            q.push({dx, dy, dstep});
        }
    }
    // BFS结束，已经找到最优路径

    // 下面将最优路径记录下来，存进passing_time数组内

}