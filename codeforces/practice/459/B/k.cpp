#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int n;
  cin >> n; 
  vector<int> v(n);
  for(int &e: v) {
    cin >> e;
  }
  sort(v.begin(), v.end());
  int minCount = 0, maxCount = 0;
  if (v[0] == v[n - 1]) { cout << "0 " << (1LL * n * (n - 1)) / 2 << "\n"; }
  else {
    long long k =0;
    long long r = n - 1;
    while(v[k] == v[0]) k++;
    while(v[r] == v[n-1]) r--;
    cout << v[n - 1] - v[0] << " " << k * (n - (r + 1)) << "\n";
  }
  return 0;
}
