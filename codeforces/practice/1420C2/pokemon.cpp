#include <bits/stdc++.h>
#include <array>

using namespace std;

long long v[300000 + 2];
long long ans = 0;
int n;
inline void add(int i) {
  if (i < 1 || i > n) return;
  if ( (v[i-1] <  v[i]) && (v[i] > v[i+1])) ans += v[i];
  if ((v[i-1] > v[i]) && (v[i] < v[i+1])) ans -= v[i];
}

inline void erase(int i) {
  if (i < 1 || i > n) return;
  if ( (v[i-1] <  v[i]) && (v[i] > v[i+1])) ans -= v[i];
  if ((v[i-1] > v[i]) && (v[i] < v[i+1])) ans += v[i];
}

inline void callAddOrErase(int l, int r, int &ans, void f(int, int& )) {
      f(l-1, ans);
      f(l, ans);
      f(l+1, ans);
      if (l != r) {
        if ((r-1 != l) && (r-1 != l + 1)) f(r-1, ans);
        if (r != (l+1) ) f(r, ans);
        f(r+1, ans);   
      }
}

int main() {
  ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int q, l, r;
    cin >> n >> q;
    // vector<long long> v(n+2);
    v[0] = -1;
    for(int i = 1; i<=n; i++) cin >> v[i];
    v[n+1] = -1;
    ans = 0;
    // positive is 0, negative is 1
    // vector<array<int, 2> > dp(n, { 0, 0 } );
    for(int k=1;k<=n;k++) {
      // if local maxima add, if local minima subtract
      if ((v[k-1] > v[k]) && (v[k] < v[k + 1])) ans -= v[k];
      if ((v[k-1] < v[k]) && (v[k] > v[k + 1])) ans += v[k];
    }
    cout << ans << "\n";
    while(q--) {
      cin >> l >> r;
      erase(l-1);
      erase(l);
      erase(l+1);
      if (l != r) {
        if ((r-1 != l) && (r-1 != l + 1)) erase(r-1);
        if (r != (l+1) ) erase(r);
        erase(r+1);   
      }

      swap(v[l], v[r]);
      add(l-1);
      add(l);
      add(l+1);
      if (l != r) {
        if ((r-1 != l) && (r-1 != l + 1)) add(r-1);
        if (r != (l+1) ) add(r);
        add(r+1);   
      }

      cout << ans << "\n";
    }
  }
  return 0;
}
