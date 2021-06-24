#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &a: v) {
    cin >> a;
  }
  sort(v.begin(), v.end());
  for (auto a: v) {
    cout << a << " ";
  }
  cout << "\n";
  return 0;
}
