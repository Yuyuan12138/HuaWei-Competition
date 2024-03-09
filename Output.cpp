//
// Created by yuyuan on 2024/3/9.
//

#include "Output.h"

void output()
{
    for(auto &x: robotsCommand)
    {
        if(x.command == 0){
            std::cout << "move " << x.robot_id << " " << x.direction << std::endl;
        }else if(x.command == 1){
            std::cout << "get " << x.robot_id << std::endl;
        } else if(x.command == 2){
            std::cout << "pull" << x.robot_id << std::endl;
        }
    }
    // 清空控制
    robotsCommand.clear();

    for(auto &x: boatsCommand)
    {
        if(x.command == 0){
            std::cout << "ship " << x.boat_id << " " << x.to_berth << std::endl;
        }else if(x.command == 1)
        {
            std::cout << "go " << x.boat_id << std::endl;
        }
    }
    boatsCommand.clear();
    puts("OK");
    fflush(stdout);
};
