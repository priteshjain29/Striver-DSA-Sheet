vector<int> morrisInorder(TreeNode *root){
	std::vector<int> inorder;
	TreeNode *curr = root;
	if(curr -> left == NULL){
		inorder.push_back(root -> val);
		curr = curr->right;
	}
	else{
		TreeNode *prev = curr->left;
		while(prev->right != NULL and prev->right != curr){
			prev = prev -> right;
		}
		if(prev -> right == NULL){
			prev -> right = curr;
			curr = curr -> left;
		}
		else{
			prev -> right = NULL;
			inorder.push_back(cuur -> val);
			curr = curr->right;
		}
	}
	return inorder;
	
}