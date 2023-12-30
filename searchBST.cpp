Node* searchBST(Node* root, int target){
	if(root == NULL) return NULL;
	if(root -> val == target){
		return root;
	}
	else if(root->val < target){
		return searchBST(root->left);
	}
	else{
		return searchBST(root->right);
	}
}