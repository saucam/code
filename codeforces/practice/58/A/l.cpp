#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);
  string s;
  cin >> s;
  int k=0, j=0;
  string m = "hello";
  bool ans = false;
  while(s[k]!='\0') {
    if (s[k] == m[j]) {
      j++;
    }
    if (m[j] == '\0') {
      ans = true;
    }
    k++;
  }
  if (ans) cout <<"YES"; else cout << "NO" << "\n";
  return 0;
}
