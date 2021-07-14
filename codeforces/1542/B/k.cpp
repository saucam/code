#include <bits/stdc++.h>

using namespace std;

/*
 * 1
 * 1.a , 1 + b
 * 1.a.a, 1.a + b, (1 + b)a , 1 + b + b
 * (1.a.a.a), (1.a.a + b), (1 + b)a.a, (1+b)a + b, a(1 + b + b), 1 + b +b + b
 * if n n.a , n + b in the set 
 * also it means for some x in the set x.a = n, or for some y, y + b = n in the set
 * n / a in the set ? or n - b in the set?
 */

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, a, b;
    cin >> n >> a >> b;
    bool ans = false;
      for(long long i = 1; i<=n; i*=a) {
        if ((n - i)%b == 0) { ans = true; break;  } if (a == 1) break;
      }
    if (ans) cout <<"Yes\n"; else cout << "No\n";
  }
  return 0;
}
