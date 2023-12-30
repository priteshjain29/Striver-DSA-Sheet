int height(TreeNode* root){
	if(root == NULL) return 0;
	int leftHeight = height(root -> left);
	int rightHeight = height(root -> right);
	if(leftHeight== -1 or rightHeight==-1 or abs(leftHeight - rightHeight) > 1)
		return -1;
	return max(leftHeight, rightHeight) + 1;
}

bool heightBalancedBinaryTree(TreeNode* root){
	if(root == NULL) return true;
	if(height(root) == -1) return false;
	else return true;
}