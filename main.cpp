#include "main.h"
//using namespace std;

/* 程序主函数 */
int main()
{
    Init();
    split_areas();
    for(int zhen = 1; zhen <= 15000; zhen ++)
    {
        int input_now = Input();
        if(input_now > zhen) {
            continue;
        }

        robotController();

        boatController();
        output();
    }

    return 0;
}
