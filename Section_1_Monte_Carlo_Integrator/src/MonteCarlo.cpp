#include <iostream>
#include <cmath>
#include <random>
#include <functional>

using std::bind;
using std::cout;
using std::function;
using std::mt19937;
using std::stoi;
using std::uniform_real_distribution;

function<bool(double, double, double)> InsideUnitSphere = [](double x, double y, double z)
{ return ((x * x + y * y + z * z) <= 1); };

double IntegrateMonteCarlo3D(int n_points, double min, double max, int seed, function<bool(double, double, double)> InsideUnitSphere)
{
  int count = 0;
  // N.B. std::pow with integer arguments can be less efficient than
  // writing the multiplication explicitly, so be careful about using it
  // inside loops for example!
  double VolCube = std::pow((max - min), 3);

  // set up random number generator here
  uniform_real_distribution<double> uniform_dist(min, max);
  mt19937 rng_mt(seed);
  auto uni_rng = bind(uniform_dist, rng_mt);

  for (int i = 0; i < n_points; i++)
  {
    // generate random points here
    double x = uni_rng();
    double y = uni_rng();
    double z = uni_rng();
    if (InsideUnitSphere(x, y, z))
      count++;
  }

  return static_cast<double>(count) / n_points * VolCube;
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    cout << "Please provide the seed as an argument to the program" << "\n";
    return 1;
  }

  int seed = stoi(argv[1]);

  int N_points = 10000;

  double UnitSphereVol = IntegrateMonteCarlo3D(N_points, -1.0, 1.0, seed, InsideUnitSphere);

  std::cout << "Volume estimate of sphere using " << N_points << " points = " << UnitSphereVol << std::endl;
}