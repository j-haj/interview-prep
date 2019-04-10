#include <cctype>
#include <iostream>
#include <random>

double estimate(std::size_t n_iter) {
  double count_in = 0;
  double count_tot = 0;
  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::uniform_real_distribution<> dist(0., 1.);
  for (std::size_t i = 0; i < n_iter; ++i) {
    const double x = dist(gen);
    const double y = dist(gen);
    const auto r_2 = x*x + y*y;
    ++count_tot;
    if (r_2 <= 1.) {
      ++count_in;
    }
  }
  return 4. * count_in / count_tot;
}

int main() {
  std::size_t N = 100000000;
  std::cout << "Estimating pi over " << N << " trials."
	    << "\nPi = " << estimate(N) << '\n';
  return 0;
}
    
