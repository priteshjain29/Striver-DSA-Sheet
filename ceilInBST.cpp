int ceil(Node* root, int key){
	int ceil = -1;
	while(root){
		if(root->val == key){
			ceil = root->val;
			return ceil;
		}
		if(root->val > key){
			//it is a possible ceil value so store it
			ceil = root -> val;
			//now look for values smaller than the current ceil value
			root = root -> left;
		}
		else{
			root = root -> right;
		}
	}
	return ceil;
}