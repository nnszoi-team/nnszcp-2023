#include "testlib.h"
#include <algorithm>

int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);

    std::string ouf_ans = ouf.readWord();
    std::string ans_ans = ans.readWord();
    
    std::transform(ouf_ans.begin(), ouf_ans.end(), ouf_ans.begin(), ::tolower);
    std::transform(ans_ans.begin(), ans_ans.end(), ans_ans.begin(), ::tolower);

    if (ouf_ans == ans_ans)
        quitf(_ok, "Accepted, the answer is correct.");
    else
        quitf(_wa, "Wrong answer, expected = %s, found = %s.", ans_ans.c_str(), ouf_ans.c_str());

    return 0;
}
