vector<int> insertionSort(vector<int> array) {
  // Write your code here.
	for(int i=1; i<array.size(); i++) {
		int k = i - 1;
		int t = array[i];
		while (k >= 0 && array[k] >= t) {
			array[k + 1] = array[k];
			k--;
		}
		array[k + 1] = t;
	}
  return array;
}
