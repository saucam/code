#include <bits/stdc++.h>

using namespace std;
int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  double x1, y1, x2, y2;
  cin >> x2 >> y2 >> x1 >> y1; 
  double a = y2 - y1;
  double b = x1 - x2;
  double c = -(a * x1 + b* y1);
  cout << a << " " << b << " "<< c << "\n";
  return 0;
}
