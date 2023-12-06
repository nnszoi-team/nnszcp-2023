#include "testlib.h"

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    const int max_n = 3e3, max_m = 2e5, l = 1, r = 1e9;

    int n = inf.readInt(l, max_n, "n");
    inf.readSpace();
    int m = inf.readInt(l, max_m, "m");
    
    inf.readEoln();
    for (int i = 0; i < n; ++i)
    {
        int h = inf.readInt(l, r, "h");
        inf.readSpace();   
    }

    inf.readEoln();
    for (int i = 0; i < m; ++i)
    {
        int s = inf.readInt(l, r, "s");
        inf.readSpace();
    }

    inf.readEof();

    return 0;
}
