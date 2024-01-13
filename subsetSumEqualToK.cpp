bool subsetSumEqualToK(int ind, int target, vector<int> &a){
	int n = a.size();
	if(ind == 0){
		return (a[0] == target);
	}
	if(target == 0) return true;


	bool notPick = f(ind-1, target, a);
	bool pick = false;
	if(a[ind] <= target){
		pick = f(ind-1, target-a[ind], a);
	}

	return (pick or notPick);
}