#include "testlib.h"

const double eps = 1e-5;

int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);

  int T = inf.readInt();

  while (T--) {
    double ans_1 = ans.readDouble();
    int ans_2 = ans.readInt();

    double out = ouf.readDouble();

    double delta_1 = fabs(out - ans_1);
    double delta_2 = fabs(out - ans_2);

    if (delta_1 > eps && delta_1 / ans_1 > eps && delta_2 > eps) {
      quitf(_wa, "The answer is wrong: expected %f or %f, found %f.", ans_1,
            ans_2, out);
    }
  }

  quitf(_ok, "The answer is correct.");
}
