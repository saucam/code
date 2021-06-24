#include <bits/stdc++.h>

using namespace std;

int n[51];
int main() {
  string s;
  int k = 0;
  cin >> s;
  string num = "";
  while(s[k] != '\0') {
    if (num.size() == 2) {
      int j = stoi(num);
      if ((n[j] == 0) && (j <= 50) ) {
        n[j] = 1;
        cout << num << " ";
        num = ""; 
      } else {
        int a = num[0] - '0';
        int b = num[0] = '0';
        n[a] = 1;
        if (b == 0) {
          cout << a << " " << b << " ";
          num = "";
          n[b] = 1;
        } else {
          num = num[1];
          cout << a << " "; 
        }
      }
    } else if ((num.size() == 0) && ((s[k] - '0') > 5)) {
       cout << s[k] << " ";
       n[s[k] - '0'] = 1;
    } else {
      num = num + s[k];
    }
    k++;
  }
  cout << num << "\n";  
  return 0;
}
