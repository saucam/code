#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, k;
  int w;
  cin >> k >> n >> w;
  int sum = 0;
  for(int i=1; i<=w; i++) sum += i;
  long long total = sum * k;
  long long ans = 0;
  if (total > n) ans = total - n; else ans = 0; 
  cout << ans << "\n";
  return 0;
}
