#include <bits/stdc++.h>

using namespace std;

int main() {
   int t;
   ios_base::sync_with_stdio(0), cin.tie(0);
   cin >> t;
   while (t--) {
     string s;
     cin >> s;
     int k=1, ans=0;
     vector<int> v(s.size(), 0);
     while(s[k] != '\0') {
       if (k > 0) {
         if (s[k-1] == s[k] && ((v[k] == 0) && v[k - 1] == 0)) {
            ans++;
            v[k] = 1;
         }
       }

       if (k > 1) {
          if (s[k-2] == s[k] && ((v[k-2] == 0) && v[k] == 0)) {
             ans++;
             v[k] = 1;
          } 
       }
       k++;
     }
     cout << ans << "\n";
   }
   return 0;
}
