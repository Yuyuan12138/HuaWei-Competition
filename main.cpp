#include "main.h"
using namespace std;

/* 程序主函数 */
int main()
{
    cerr << "program begins" << endl;
    Init();
    cerr << "init ok" << endl;
    split_areas();
    cerr << "split ok" << endl;
    for(int zhen = 1; zhen <= 100; zhen ++)
    {
        int input_now = Input();
        cerr << "Read input for frame " << input_now << endl;
        if(input_now > zhen) {
            continue;
        }

        robotController();
        cerr << "robotController finished" << endl;

        boatController();
        cerr << "boatController finished" << endl;

        output();
        cerr << "output ok" << endl;
    }

    return 0;
}
