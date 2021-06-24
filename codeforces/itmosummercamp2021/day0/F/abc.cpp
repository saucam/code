#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  long long ans = 0;
  int k = 0, ac = 0, ab = 0;
  while (s[k] != '\0') {
    if (s[k] == 'a') ac++;
    if (s[k] == 'b') ab += (ac) ;
    if (s[k] == 'c') ans += (ab);
    k++;
  }
  printf("%lld", ans);
  return 0;
}
