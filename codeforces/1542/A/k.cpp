#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, oc = 0, ec = 0, zc = 0;
    int k;
    cin >> n;
    for(int i=0; i< (2*n); i++) {
      cin >> k;
      if (k == 0) { zc++; }
      else if (k % 2 == 0) { ec++;  } else { oc++; }
    }
    if ((zc + ec) == oc) cout << "Yes\n"; else cout <<"No\n";
  }
  return 0;
}
