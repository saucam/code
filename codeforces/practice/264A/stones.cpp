#include <bits/stdc++.h>

using namespace std;

int arr[1000001];
int main() {
  string s;
  cin >> s;
  int i = 0;
  int right = s.size() - 1;
  int left = 0; 
  while(s[i]!='\0') {
    switch(s[i]) {
      case 'l':
        arr[right] = i + 1;
        right--;
        break;
      case 'r':
        arr[left] = i + 1;
        left++;    
        break;
    }
    i++;
  }

  for(int i=0; i<s.size(); i++) {
    printf("%d\n", arr[i]);
  }
  return 0;
}
