#include <bits/stdc++.h>

using namespace std;

int n[51];

bool resolve(string &s, int i, vector<int> &out) {
  if (i == s.size()) return true;
  int sing = s[i] - '0';
  if (sing == 0) return false;
  if (n[sing] == 0) {
    // cout << "setting sing = " << sing<<"\n";
    n[sing] = 1;
    out.push_back(sing);
    bool p = resolve(s, i + 1, out);
    if (p == true) return true;
    n[sing] = 0;
    out.pop_back();
  }
  if (i < s.size() - 1) {
    int d = s[i + 1] - '0';
    int num = (sing*10 + d);
    if (num <= 50 && n[num] == 0) {
      // cout << "setting num = " << num<<"\n";
      n[num] = 1;
      out.push_back(num);
      bool p = resolve(s, i + 2, out);
      if (p == true) return true;
      n[num] = 0;
      out.pop_back();
    }
  }
  return false;
}

int main() {
  vector<int> out;
  string s;
  int k = 0;
  cin >> s;
  resolve(s, 0, out);
  for(auto &e: out) {
     cout << e << " ";
  }
  cout << "\n";  
  return 0;
}
