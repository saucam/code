#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x = 0;
  cin >> n;
  while (n > 0) {
    string s;
    cin >> s;
    if (s.find("++") != string::npos) {
      x++;
    } else {
      x--;
    }
    n--;
  }
  printf("%d\n", x);
  return 0;
}
