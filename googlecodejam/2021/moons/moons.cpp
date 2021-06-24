#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main() {
  const long long INF = 1e18 + 5;
  int t, i=1;
  cin >> t;
  
  while(i <= t) {
     string s;
     int x, y;
     cin >> x >> y >> s;
     vector<array<long long, 2>> v(s.length() + 1, {INF, INF});
     v[1][0] = 0;
     v[1][1] = 0;
     // 0 is C
     // 1 is J
     for(int k=1; s[k]!='\0';k++) {
       if(s[k - 1] == 'C') {
         if (s[k] == 'C') {
           v[k+1][0] = v[k][0];
         } else if (s[k] == 'J') {
           v[k+1][1] = v[k][0] + x; 
         } else { 
           v[k+1][0] = v[k][0];
           v[k+1][1] = v[k][0] + x; 
         }
       } else if (s[k - 1] == 'J') {
         if (s[k] == 'C') {
           v[k+1][0] = v[k][1] + y;
         } else if (s[k] == 'J') {
           v[k+1][1] = v[k][1];
         } else {
           v[k+1][0] = v[k][1] + y;
           v[k+1][1] = v[k][1];
         }
       } else {
         if (s[k] == 'C') {
           v[k+1][0] = min(v[k][1] + y, v[k][0]);
         } else if (s[k] == 'J') { 
           v[k+1][1] = min(v[k][0] + x, v[k][1]);
         } else {
           v[k+1][0] = min(v[k][1] + y, v[k][0]);
           v[k+1][1] = min(v[k][0] + x, v[k][1]);
         }
       }  
     }

     long long ans = min(v[s.length()][0], v[s.length()][1]);
     cout << "Case #"<<i<<": "<<ans<<"\n"; 
     i++;
  }
}
