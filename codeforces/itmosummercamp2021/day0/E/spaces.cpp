#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int k = 0;
  set<char> ops { '+', '-', '/', '*' };
  while(s[k] != '\0') {
    if (ops.find(s[k]) != ops.end()) {
      cout << " " << s[k] << " ";
    } else {
      cout << s[k];
    }
    k++;
  }
  return 0;
}
