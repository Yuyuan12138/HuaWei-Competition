#include "main.h"
//using namespace std;

/* 程序主函数 */
int main()
{
    Init();
    for(int zhen = 1; zhen <= 15000; zhen ++)
    {
        int id = Input();
//        for(int i = 0; i < robot_num; i ++)
//            printf("move %d %d\n", i, rand() % 4);
//        puts("OK");
//        fflush(stdout);
        Robots_command r{};
        r.command = 1;
        r.robot_id = 1;
        for(int i = 0; i < robot_num; i++)
        {
            robotsCommand.push_back(r);
        }
        output();
    }

    return 0;
}
