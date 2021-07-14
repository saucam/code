#include <bits/stdc++.h>

using namespace std;

const double PI = atan2(0, -1);

struct point {
  double x, y;
  point(double x_, double y_) : x(x_) , y(y_) {}

  point operator+(point const &other) {
    return point(x + other.x, y + other.y);
  }
  point operator-(point const &other) {
    return point(x - other.x, y - other.y);
  }
  double len() {
    return sqrt(x * x + y * y);
  }
};

struct line {
  double a, b, c;
  line(double a_, double b_, double c_): a(a_), b(b_), c(c_) {}
  line(point p1, point p2) {
    a = p2.y - p1.y;
    b = p1.x - p2.x;
    c = -(a * p1.x + b* p1.y);
    // abs(num) <= 1e-9
    // -1e-9 <= num <= 1e-9
    // 0.3 - 0.2 - 0.1 != 0 
    assert(abs(a * p2.x + b * p2.y + c) <= 1e-9);
    // double tmp = sqrt(a*a + b * b);
    // a/=tmp;
    // b /=tmp;
    // c/=tmp;
    // sqrt (a * a + b* b) = 1
  }
  double dist(point p) {
    return (a * p.x + b*p.y + c) / sqrt(a * a + b * b);
    // return (a * p.x + b*p.y + c); // in case we normalized the line!! in that case sqrt is 1
  }
};

ostream& operator<<(ostream& o, point p) {
  return o << "(" << p.x << ", " << p.y << ")";
}

bool is_parallel(line l1, line l2) {
  return abs(l1.a * l2.b - l1.b*l2.a) <= 1e-9;
}

point intersection(line l1, line l2) {
  double denom = l1.a * l2.b - l1.b * l2.a;
  double nx = -l1.c * l2.b + l1.b * l2.c;
  double ny = -l1.a * l2.c + l1.c * l2.a;
  return point (nx / denom, ny / denom);
}

double cross(point p1, point p2) {
  return p1.x * p2.y - p1.y * p2.x;
}

double triangle_area(point a, point b, point c) {
  point v1 = b - a;
  point v2 = c - a;
  return abs(cross(v1, v2)/ 2);
}

double dot(point p1, point p2) {
  return p1.x * p2.x + p1.y * p2.y;
}

double angle_between_vectors(point v1, point v2) {
  return atan2(cross(v1, v2), dot(v1, v2));
}
bool is_polygon_convex(vector<point> poly) {
  double s = 0;
  for (int i=0; i< poly.size(); i++) {
    int j = (i + 1) % poly.size();
    int k = (j + 1) % poly.size();
    if (cross(poly[j] - poly[i], poly[k] - poly[j]) <= 0) {
      return false;
    }
    s += angle_between_vectors(poly[j] - poly[i], poly[k] - poly[j]);
  }
  if (abs(s - 2*PI) <= 0.1 ) {
    return true;
  }
  return false;
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int a1, b1, c1, a2, b2, c2;
  cin  >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
  line l1 (a1, b1, c1);
  line l2 (a2, b2, c2);
  point ans = intersection(l1, l2);
  printf("%.10f %.10f\n", ans.x, ans.y);
  
  return 0;
}
