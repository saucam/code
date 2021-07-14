#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k; 
    vector<int> bits(32, 0);
    vector<int> a(n);
    for (auto &e: a) {
      int i=0;
      cin >> e;
      while(i < 32) {
        if (((e >> i) & 1) == 1) bits[i]++;
        i++;
      }
    }
    int i=0;
    long long ans = 0;
    while(i < 32) {
      ans = ans + (bits[i] / k);
      if (bits[i]%k != 0) ans++;
      i++;
    }
    cout << ans << "\n";
  }
  return 0;
}
