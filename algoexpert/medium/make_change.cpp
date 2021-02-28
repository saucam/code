#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  // Write your code here.
	if (n == 0) return 1;
	vector <int> dp(n+1, 0);
	dp[0] = 1;
	
	for (int k=1; k<=denoms.size();k++) {
		int c = denoms[k-1];
		for (int j=0; j<=n; j++) {
			if (c <= j ) {
				dp[j] += dp[j - c];
			}
		}
	}
	
	
  return dp[n];
}
