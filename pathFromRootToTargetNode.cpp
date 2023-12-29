bool getPath(node* root, vector<int> &ans, int target){
	if(root == NULL) return false;

	ans.push_back(root->val);
	if(root -> val == target) return true;

	if(getPath(root->left, ans, target) or getPath(root->right, ans, target)) return true;
	
	ans.pop_back();
	return false;	
}