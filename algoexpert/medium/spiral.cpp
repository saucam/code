vector<int> spiralTraverse(vector<vector<int>> array) {
  // Write your code here.
	vector<int> res;
	
	int c = array[0].size();
	int r = array.size();
	
	int sc = 0, ec = c ;
	int sr = 0, er = r ;
	
	while (ec - 1 >= sc && er - 1 >= sr) {
		// traverse perimeter
		for (int i=sc; i < ec; i++) {
			res.push_back(array[sr][i]);
		}
		if (sr + 1 <= er - 1) {
		  for (int i=sr+1; i < er;i++) {
			  res.push_back(array[i][ec - 1]);
		  }
		}
		if (er - 1 != sr) {
		  if (ec - 2 >= sc) {
		    for (int i=ec - 2; i>=sc; i--){
			    res.push_back(array[er - 1][i]);
		    }
		  }
		}
		
		if (ec - 1 != sc) {
		  if (er - 2 >= sr) {
		    for (int i=er-2; i>sr;i--){
			    res.push_back(array[i][sc]);
		    }
		  }
		}
		
		sr = sr + 1;
		er = er - 1;
		sc = sc + 1;
		ec = ec - 1;
		
	}
	
  return res;
}

