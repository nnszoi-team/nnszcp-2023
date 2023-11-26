#include "testlib.h"

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    std::string s = inf.readWord();

    for (const char &ch : s)
        if (ch < 'a' || 'z' < ch)
            quitf(_fail, "Found non-lowercase letter \'%c\' in the string.", ch);

    inf.readEoln();
    inf.readEof();

    return 0;
}
