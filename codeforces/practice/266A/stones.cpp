#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  int n, k=0, ans = 0;
  cin >> n;
  cin >> s;
  
  char prev = 0;
  while (s[k]!='\0') {
    if (s[k] == prev) ans++;
    prev = s[k];
    k++;
  }
  printf("%d\n", ans);
  return 0;
}
