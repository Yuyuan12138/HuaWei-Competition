//
// Created by yuyuan on 2024/3/9.
//

#include "Output.h"

void output()
{
    for(auto &x: operations)
    {
        // cerr << x << endl;
        /// 机器人控制
        if(x.objector == Objector::robot)
        {
            if(x.command == Command::move)
            {
                std::cout << "move " << x.id << " " << x.optionArg << std::endl;
            }
            else if(x.command == Command::get)
            {
                std::cout << "get " << x.id << std::endl;
            }
            else if(x.command == Command::pull)
            {
                std::cout << "pull " << x.id << std::endl;
            }
        }

        /// 轮船控制
        if(x.objector == Objector::boat)
        {
            if(x.command == Command::ship)
            {
                std::cout << "ship " << x.id << " " << x.optionArg << std::endl;
            }
            else if(x.command == Command::go)
            {
                std::cout << "go " << x.id << std::endl;
            }
        }
        fflush(stdout);
    }
    operations.clear();

    std::cout << "OK" << std::endl;
    fflush(stdout);
};
