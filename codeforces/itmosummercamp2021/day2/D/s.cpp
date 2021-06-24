#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n;
  map<int, int> mp;
  vector<int> v1(n);
  for (auto &a: v1) {
    cin >> a;
    if (mp.find(a) != mp.end()) {
       mp[a]++;
    } else {
       mp.insert({a, 1});
    }
  }
  cin >> m;
  vector<int> v2(m);
  for (auto &a: v2) {
    cin >> a;
    int cnt = 0;
    if (mp.find(a) != mp.end()) {
       cnt = mp[a];
    }
    cout << cnt << "\n";
  }
  return 0;
}
