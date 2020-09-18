#include <bits/stdc++.h>

using namespace std;

int arr[26];
int main() {
  string s;
  int i = 0, d = 0;
  cin >> s;
  while(s[i]!='\0') {
    int c = s[i] - 'a';
    if (arr[c] == 0) { d++; arr[c] = 1; } else arr[c] = 1;
    i++;
  }
  if (d % 2 == 0) printf("%s\n", "CHAT WITH HER!"); else printf("%s\n", "IGNORE HIM!");
  return 0;
}
