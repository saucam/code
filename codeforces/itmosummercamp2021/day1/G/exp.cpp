#include <bits/stdc++.h>

using namespace std;

int c[51];
int main() {
  int n;
  cin >> n;
  int k = 0, m = 0;
  vector<int> v(n);
  for(auto &a: v) {
     cin >> a;
     c[a]++;
  }
  for(auto a: v) {
     if ((c[a] >= m) && (a != 0)) { m = c[a]; }
  }
  if (m == 0) cout << "-1" << "\n"; else cout << m << "\n";
  return 0;
}
