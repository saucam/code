vector<int> spiralTraverse(vector<vector<int>> array) {
  // Write your code here.
	vector<int> res;
	
	int c = array[0].size();
	int r = array.size();
	
	int sc = 0, ec = c - 1 ;
	int sr = 0, er = r - 1 ;
	
	while (ec >= sc && er >= sr) {
		// traverse perimeter
		for (int i=sc; i <= ec; i++) {
			res.push_back(array[sr][i]);
		}
		  for (int i=sr+1; i <= er;i++) {
			  res.push_back(array[i][ec]);
		  }
		if (er != sr) {
		    for (int i=ec - 1; i>=sc; i--){
			    res.push_back(array[er][i]);
		    }
		}
		
		if (ec != sc) {
		    for (int i=er-1; i>sr;i--){
			    res.push_back(array[i][sc]);
		    }
		}
		
		sr = sr + 1;
		er = er - 1;
		sc = sc + 1;
		ec = ec - 1;
		
	}
	
  return res;
}
