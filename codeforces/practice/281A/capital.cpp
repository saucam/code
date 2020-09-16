#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  char c = toupper(s[0]);
  s.replace(0, 1, 1, c);
  printf("%s\n", s.c_str());
  return 0;
}
