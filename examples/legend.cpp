#include <vector>
#include "../matplotlibcpp.h"
namespace plt = matplotlibcpp;

void basic() {
  plt::figure();
  plt::plot({1, 2, 3}, {{"label", "a line"}});
  plt::plot({1, 3, 5}, {{"label", "also a line"}});
  plt::legend();
  plt::show();
}

void bbox() {
  plt::figure();
  plt::plot({1, 2, 3}, {{"label", "a line"}});
  plt::plot({1, 3, 5}, {{"label", "also a line"}});
  plt::legend(std::vector<double>{0.5, 0.7});
  plt::show();
}
/*
void keywords() {
  plt::figure();
  plt::plot({1, 2, 3}, {{"label", "a line"}});
  plt::plot({1, 3, 5}, {{"label", "also a line"}});
  plt::legend("best", {{"borderpad", "0.2"}});
  plt::show();
}
*/
int main() {
  basic();
  bbox();
  // keywords();
  return 0;
}
