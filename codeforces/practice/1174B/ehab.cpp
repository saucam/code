#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  bool hasEven = false;
  bool hasOdd = false;
  for(auto &a: v) {
    cin >> a;
    if (a&0x01) hasOdd = true; else hasEven = true;
  }
  if (hasOdd && hasEven) sort(v.begin(), v.end());
  for(auto k: v) cout << k << " ";
  cout << "\n";
  return 0;
}
