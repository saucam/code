#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n, a;
  cin >> n; 
  map<int, int> m = { {1, 0}, {2, 0}, {3, 0}, {4, 0} };
  for(int i=0; i<n; i++) {
    cin >> a;
    m[a]++;
  }
  int ans = m[4];
  if (m[3] > m[1]) {
    ans += m[1];
    ans += m[3] - m[1];
    ans += ceil(m[2]/2.0);
  } else {
    ans += m[3];
    m[1] = m[1] - m[3];
    ans += m[2]/2;
    int r = m[2]%2;
    if (r == 1) {
       ans += 1; m[1] = m[1] -2;
       if (m[1] > 0) ans +=ceil( m[1]/4.0);
    } else {
      ans += ceil(m[1]/4.0);
    }
  }
  cout << ans;
  return 0;
}
