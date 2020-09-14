// Return closes value to the target value contained in a BST
#include <algorithm>

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target) {
  // Write your code here.
	int ans = tree->value;
	int left = ans; int right = ans;
	
	if (tree->left != NULL) {
		left = findClosestValueInBst(tree->left, target);
	}
	if (tree->right != NULL) {
		right = findClosestValueInBst(tree->right, target);
	}
	if (abs(target - left) < abs(target - right)) ans = left; else ans = right;
	if (abs(target - tree->value) < abs(target - ans)) ans = tree->value;
  return ans;
}
