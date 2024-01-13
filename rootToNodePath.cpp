bool f(TreeNode *root, vector<int> &ans, int x){
	if(root == NULL) return false;

	ans.push_back(root->val);

	if(root->val == x){
		return true;
	}

	if(f(root->left, ans, x) || f(root->right, ans, x)) return true;

	ans.pop_back();
	return false;
}
vector<int> getPath(TreeNode* root, int x){
	vector<int> ans;
	if(root == null) return ans;
	f(root, ans, x);
	return ans;
}