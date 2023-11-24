#include "testlib.h"

const double eps = 1e-5;

int main(int argc, char *argv[]) {
  registerTestlibCmd(argc, argv);

  int T = inf.readInt();

  for (int i = 1; i <= T; ++i) {
    long double answer = ans.readDouble();
    long double out = ouf.readDouble();

    long double delta = fabs(out - answer);

    if (delta > eps && delta / answer > eps) {
      quitf(_wa, "Testcase #%d: the answer is wrong: expected %Lf, found %Lf.", i, answer, out);
    }
  }

  quitf(_ok, "The answer is correct.");
}
