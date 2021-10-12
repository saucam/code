#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int t, n, k;
  cin >> t;
  while(t--) {
    cin >> n >> k;
    int r = 1, cnt = 0;
    while (r + cnt <= k) {
      r = r + cnt;
      cnt++;
    }
    cnt--;
    // cout << "r = " << r << "\n";
    // cout << "cnt = " << cnt << "\n";
    int diff = k - r;
    // cout << "diff = " << diff << "\n";
    cout << string(n - 2 - cnt, 'a') << 'b' << string(cnt-diff, 'a') << 'b' << string(diff, 'a') << "\n";
  }
  return 0;
}
