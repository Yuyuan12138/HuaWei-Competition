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
        if(x.objector == 0)
        {
            if(x.command == 0)
            {
                std::cout << "move " << x.id << " " << x.optionArg << std::endl;
                std::cerr << "move " << x.id << " " << x.optionArg << std::endl;
            }
            else if(x.command == 1)
            {
                std::cout << "get " << x.id << std::endl;
                std::cerr << "get " << x.id << std::endl;
            }
            else if(x.command == 2)
            {
                std::cout << "pull " << x.id << std::endl;
                std::cerr << "pull " << x.id << std::endl;
            }
        }

        /// 轮船控制
        if(x.objector == 1)
        {
            if(x.command == 0)
            {
                std::cout << "ship " << x.id << " " << x.optionArg << std::endl;
                std::cerr << "ship " << x.id << " " << x.optionArg << std::endl;
            }
            else if(x.command == 1)
            {
                std::cout << "go " << x.id << std::endl;
                std::cerr << "go " << x.id << std::endl;
            }
        }
        fflush(stdout);
    }
    operations.clear();

    std::cout << "OK" << std::endl;
    fflush(stdout);
};
