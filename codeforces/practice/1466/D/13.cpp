#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
  return a.second > b.second;
}

int main() {
  int t;
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> w(n);
    vector<int> d(n, 0);
    long long ans = 0;
    for(auto &k: w) { cin >> k; ans+=k; }
    for (int i=0; i<n-1; i++) {
      int a, b;
      cin >> a >> b;
      d[a - 1]++; d[b - 1]++;
    }
    vector<pair<int, int>> gn;
    for(int k=0; k<n; k++) {
      if (d[k] > 1) gn.push_back({ k, w[k] });
    }
    sort(gn.begin(), gn.end(), compare);
    cout << ans;
    int cnt = 0, k = 0;
    while (cnt<n-1 && k<gn.size()) {
      int deg = d[gn[k].first] - 1;
      while (deg > 0) {
        ans += (w[gn[k].first]);
        cout << " " << ans;
        deg--;cnt++;
      }
      k++;
    }
    cout << "\n";      
  }
  return 0;
}
