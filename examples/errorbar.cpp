#include <cmath>
#include "../matplotlibcpp.h"
namespace plt = matplotlibcpp;

#ifdef WITH_EIGEN
#include <Eigen/Dense>
#endif

template <typename Vector>
void get_data(Vector& x, Vector& y, Vector& err) {
  // get number of data points
  const unsigned n = x.size();
  assert(y.size() == n && err.size() == n);

  // compute data
  for (unsigned i = 0; i < n; ++i) {
    *(x.data() + i) = 1.0 * i / n;
    *(y.data() + i) = sin(2.0 * M_PI * i / n);
    *(err.data() + i) = exp(-2.0 * i / n);
  }
}

template <typename Vector>
void plot(unsigned n) {
  Vector x(n), y(n), err(n);
  get_data(x, y, err);

  plt::figure();
  plt::errorbar(x, y, err);
  plt::show();
}

int main() {

  plot<std::vector<double>>(10);

  #ifdef WITH_EIGEN
  #include <iostream>
  std::cout << "Hello!\n";
  plot<Eigen::VectorXd>(10);
  #endif

  return 0;
}
