#include "Algorithms.h"

int to[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
bool visited[N][N];

void split_areas_dfs(int x, int y, int area_idx) {
    visited[x][y] = true;
    area_id[x][y] = area_idx;
    for(int i = 0; i < 4; i++) {
        int dx = x + to[i][0],
            dy = y + to[i][1];
        if(visited[dx][dy]) continue;
        split_areas_dfs(dx, dy, area_idx);
    }
}

void split_areas() {
    memset(visited, 0, sizeof(visited));
    int area_idx = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!visited[i][j])
                split_areas_dfs(i, j, area_idx);
            area_idx++;
        }
    }
    for(int i = 0; i < robot_num; i++) {
        Robot& robot = robots[i];
        int area = area_id[robot.x][robot.y];
        robot_list_by_area[area].push_back(i);
    }
    for(int i = 0; i < berth_num; i++) {
        Berth& berth = berths[i];
        int area = area_id[berth.x][berth.y];
        berth_list_by_area[area].push_back(i);
    }
}