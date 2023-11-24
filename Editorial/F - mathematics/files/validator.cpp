#include "testlib.h"

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  int T = inf.readInt(1, 100000, "T");
  inf.readEoln();

  while (T--) {
    int a = inf.readInt(1, 10000, "a");
    inf.readSpace();
    int b = inf.readInt(1, 10000, "b");
    inf.readEoln();
  }

  inf.readEof();

  return 0;
}