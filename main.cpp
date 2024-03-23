#include "main.h"
using namespace std;
using namespace std::chrono;

/* 程序主函数 */
int main()
{
    cerr << "program begins" << endl;
    Init();
    cerr << "init ok" << endl;
    split_areas();
    cerr << "split ok" << endl;
    for(int zhen = 1; zhen <= 15000; zhen ++)
    {
        // cerr << "Reading input..." << endl;
        // cerr << "local frame: " << zhen << ' ' << endl;
        int input_now = Input();
        if(zhen == 1) {
            init_robot_flag();
            cout << "OK" << endl;
            cerr << "OK" << endl;
            fflush(stdout);
            continue;
        }
//
        // cerr << goods.size() << endl;
         cerr << "1" << endl;
//        if(input_now > zhen) {
//            continue;
//        }

        robotController();
         cerr << "2" << endl;
//        cerr << "robotController finished" << endl;

        boatController();
         cerr << "3" << endl;
//        cerr << "boatController finished" << endl;

        output();
        // cerr << "4" << endl;
//        cerr << "output ok" << endl;
    }

    return 0;
}
