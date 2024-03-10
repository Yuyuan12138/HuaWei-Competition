#include "main.h"
//using namespace std;

/* 程序主函数 */
int main()
{
    Init();
    for(int zhen = 1; zhen <= 15000; zhen ++)
    {
        Operation op;
        for(int i = 0; i < robot_num; i++)
        {
            op.objector = 0;
            op.command = 0;
            op.optionArg = 0;
            op.id = i % 5;
            operations.push_back(op);
        }
        output();
    }

    return 0;
}
