//
// Created by yuyuan on 2024/3/9.
//

#include "Output.h"

void output()
{
    for(auto &x: operations)
    {
        /// 机器人控制
        if(x.objector == 0)
        {
            if(x.command == 0)
            {
                std::cout << "move " << x.id << " " << x.optionArg << std::endl;
            }
            if(x.command == 1)
            {
                std::cout << "get " << x.id << std::endl;
            }
            if(x.command == 2)
            {
                std::cout << "pull " << x.id << std::endl;
            }
        }

        /// 轮船控制
        if(x.objector == 1)
        {
            if(x.command == 0)
            {
                std::cout << "ship " << x.id << " " << x.optionArg << std::endl;
            }
            if(x.command == 1)
            {
                std::cout << "go " << x.id << std::endl;
            }
        }
    }
    operations.clear();

    puts("OK");
    fflush(stdout);
};
