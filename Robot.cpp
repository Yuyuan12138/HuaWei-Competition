//
// Created by Yuyuan12138 on 2024/3/8.
//

#include "Robot.h"

void robotController()
{
    static vector<int> nextMoves;
    static int now_idx = 0;

    for(int i = 1; i <= 200; i++) {
        for(int j = 1; j <= 200; j++)
            passing_time[i][j].clear();
    }

    for(int i = 0; i < robot_num; i++)
    {
        Robot& robot = robots[i];
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
                if(now_idx >= 10 || now_idx == nextMoves.size() - 1) {
                    find_good_for_robot(i, nextMoves);
                }
                if(nextMoves.empty())
                    continue;

                Operation operation(Objector::robot, Command::move, i, nextMoves[now_idx++]);
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
                if(now_idx >= 10 || now_idx == nextMoves.size() - 1) {
                    find_berth_for_robot(i, nextMoves);
                }

                Operation operation(Objector::robot, Command::move, i, nextMoves[now_idx++]);
                operations.push_back(operation);
            }

        }
    }
}