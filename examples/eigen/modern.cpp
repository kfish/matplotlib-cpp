#define _USE_MATH_DEFINES
#include "../../matplotlibcpp.h"
#include <Eigen/Dense>
#include <cmath>

namespace plt = matplotlibcpp;

int main() {
  // plot(y) - the x-coordinates are implicitly set to [0,1,...,n)
  // plt::plot({1,2,3,4});

  // Prepare data for parametric plot.
  int n = 5000; // number of data points
  Eigen::VectorXd x(n), y(n), z(n);
  for (int i = 0; i < n; ++i) {
    double t = 2 * M_PI * i / n;
    x(i) = 16 * sin(t) * sin(t) * sin(t);
    y(i) = 13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t);
    z(i) = 12.5 + abs(sin(x(i)));
  }

  // plot() takes an arbitrary number of (x,y,format)-triples.
  // x must be iterable (that is, anything providing begin(x) and end(x)),
  // y must either be callable (providing operator() const) or iterable.
  plt::plot(x, z, "k-", x, y, "r-");

  // show plots
  plt::show();
}
