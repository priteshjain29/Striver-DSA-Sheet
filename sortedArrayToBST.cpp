Node* sortedArrayToBST(vector<int> &nums){
	int n = nums.size();
	if(n == NULL) return NULL;
	if(n == 1) return new Node(nums[0]);
	int mid = n/2;
	Node* root = new Node(nums[mid]);
	vector<int> leftSubtree(nums.begin(), nums.begin() + mid);
	vector<int> rightSubtree(nums.begin() + mid + 1, nums.end());
	root->left = sortedArrayToBST(leftSubtree);
	root->right = sortedArrayToBST(rightSubtree);
	return root;
}