#include "../matplotlibcpp.h"
#include <vector>

namespace plt = matplotlibcpp;

int main() {
  // plot(y) - the x-coordinates are implicitly set to [0,1,...,n)
  // plt::plot({1, 2, 3, 4});
  std::vector<double> y = {1, 2, 3, 4};
  plt::plot(y);
  plt::savefig("minimal.pdf");
}
