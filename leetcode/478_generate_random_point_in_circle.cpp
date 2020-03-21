#include <cmath>
#include <iostream>
#include <random>
#include <vector>

class CirclePointGen {
  std::random_device rd;
  std::mt19937 gen;
  double radius;
  double cx;
  double cy;
  std::uniform_real_distribution<> dist;
  
  bool isInsideCircle(double x, double y) {
    double dist = std::sqrt((x - cx) * (x - cx) + (y - cy) * (y - cy));
    return dist <= radius;
  }
    
public:
  CirclePointGen(double radius, double x_center, double y_center)
  : gen(rd()), radius(radius), cx(x_center), cy(y_center), dist(0, 2 * radius) {}
  
  std::vector<double> randPoint() {
    bool inCircle = false;
    double x, y;
    while (!inCircle) {
      x = cx - radius + dist(gen);
      y = cy - radius + dist(gen);
      inCircle = isInsideCircle(x, y);
    }
    return { x, y };
  }
};

int main() {
  CirclePointGen c(1, 0, 0);
  std::cout << "circle with radius 1, center (0, 0)\nrandom points:\n";
  std::vector<double> v = c.randPoint();
  std::cout << v[0] << ' ' << v[1] << '\n';
  v = c.randPoint();
  std::cout << v[0] << ' ' << v[1] << '\n';
  v = c.randPoint();
  std::cout << v[0] << ' ' << v[1] << '\n';
}
