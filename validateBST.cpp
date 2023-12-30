bool validateBST(TreeNode* root){
	return valid(root, LONG_MIN, LONG_MAX);
}

bool valid(TreeNode* root, long long minval, long long maxval){
	if(root == NULL) return true;
	if(root -> val >= maxval or root -> val <= minval) return false;
	return (valid(root->left, minval, root->val),
			valid(root->right, root->val, maxval));
}