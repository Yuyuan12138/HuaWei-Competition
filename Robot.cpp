//
// Created by Yuyuan12138 on 2024/3/8.
//

#include "Robot.h"

void robotController()
{
    static vector<int> nextMoves[10];
    static int now_idx[10] = {};

    // for(int i = 1; i <= 200; i++) {
    //     for(int j = 1; j <= 200; j++)
    //         passing_time[i][j].clear();
    // }

    for(int i = 0; i < robot_num; i++)
    {
        Robot& robot = robots[i];
        // cerr << robot.valid << endl;
        if(!robot.valid) continue;

        /// 处于恢复状态，则不操作
        if(robot.status == 0) continue;

        /// 分类机器人状态并且进行操作
        if(robot.goods == 0)
        {
            /// 未携带货物，且不在货物点
            ///  判断是否在货物点
            if(is_good[robot.x][robot.y])
            {
                cerr << "picking good at " << robot.x << ' ' << robot.y << endl;
                is_good[robot.x][robot.y] = false;
                robot.goods = 1;

                Operation operation(Objector::robot, Command::get, i);
                operations.push_back(operation);
            } else {
                if(now_idx[i] >= 10 || now_idx[i] > nextMoves[i].size() - 1 || nextMoves[i].empty()) {
                    find_good_for_robot(i, nextMoves[i]);
                    now_idx[i] = 0;
                    continue;
                }
                if(nextMoves[i].empty()) {
                    // cerr << "empty" << endl;
                    continue;
                }
                // cerr << now_idx << ' ' << nextMoves[i].size() << endl;
                Operation operation(Objector::robot, Command::move, i, nextMoves[i][now_idx[i]++]);
                operations.push_back(operation);
            }
        }
        else if(robot.goods == 1)
        {
            /// 携带货物，且不在港口点
            ///  判断是否在berth
            if(ch[robot.x][robot.y] == 'B')
            {
                robot.goods = 0;
                Operation operation(Objector::robot, Command::pull, i);
                operations.push_back(operation);
            } else {
                if(now_idx[i] >= 10 || now_idx[i] > nextMoves[i].size() - 1 || nextMoves[i].empty()) {
                    find_berth_for_robot(i, nextMoves[i]);
                    now_idx[i] = 0;
                    continue;
                }
                if(nextMoves[i].empty())
                    continue;

                Operation operation(Objector::robot, Command::move, i, nextMoves[i][now_idx[i]++]);
                operations.push_back(operation);
            }

        }
    }
}