#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  if (b > a) return gcd(b, a);
  return gcd(b, a%b);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n; 
    vector<int> a(n);
    vector<int> fgc(n);
    vector<int> bgc(n);

    for(auto &e: a) {
      cin >> e;
    }
    sort(a.begin(), a.end());
    fgc[0] = a[0];
    for (int i=1; i< n; i++) {
      fgc[i] = gcd(fgc[i - 1], a[i]);
    }
    bgc[n-1] = a[n-1];
    for(int i=n-2; i>=0; i--) {
      bgc[i] = gcd(a[i], bgc[i + 1]);
    }
    if (n < 2) {
      cout << 1 << "\n";
    } else {
      // int mgcd = bgc[1];
      // int numToChange = 0;
      int mgcd = fgc[n-2];
      int numToChange = n - 1;
      if (bgc[1] > mgcd) {
         mgcd = bgc[1];
         numToChange = 0;
      }

      for(int i=1; i<n-1; i++) {
        if (gcd(fgc[i-1], bgc[i+1]) > mgcd) {
          mgcd = gcd(fgc[i-1], bgc[i+1]);
          numToChange = i;
        }
      }
      long long ans = 0;
      for(int i=0; i<n; i++) {
        if (i != numToChange) {
          ans = ans + (a[i] / mgcd);
        }
      }
      cout << ans + 1 << "\n";
    }
  }
  return 0;
}
