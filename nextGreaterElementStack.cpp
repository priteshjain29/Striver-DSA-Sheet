vector<int> nextGreaterElement(vector<int>&nums1, vector<int>&nums2){
	unordered_map<int, int> m;
	stack<int> s;
	int n = nums2.size();
	for(int i = n-2; i>=0; i--){
		int elem = nums2[i];
		while(s.empty() == false and s.top()<=elem){
			s.pop();
		}
		int res = s.empty() ? -1 : s.top();
		m.insert({elem, res});
		s.push(elem);
	}
	std::vector<int> ans;
	for(auto it : nums1){
		ans.push_back(m[it]);
	}
	return ans;
}


//instead of traversing nums1 and then answering queries 
        // we are storing next greater of every element of nums2 in an unordered map