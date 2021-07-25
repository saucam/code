#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  cout << setprecision(15) << fixed;
  int n;
  cin >> n;
  vector<int> a(n, 0);
  int onec = 0;
  for(int &e: a) {
    cin >> e;
    if (e == 1) onec++;
  }
  int maxz = 0, cur = 0;
  int k = 0;
  while(a[k] == 1 && (k < n)) k++;
  if (k == n) {
    cout << n - 1 << "\n";
  } else {
    while(k < n) {
      if (a[k] == 0) cur++; else cur--;
      if (cur > maxz) maxz = cur;
      if(cur <0) cur=0;
      k++;
    }
    cout << onec + maxz << "\n";
  }
  return 0;
}
