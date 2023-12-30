Node* bstFromPreorder(vector<int> &preorder){
	int i = 0;
	buildBST(preorder, i, INT_MAX);
}

Node* buildBST(vector<int>&preorder, int &i, int bound){
	if(preorder.size() == i || preorder[i] > bound) return NULL;
	Node* root = new Node(preorder[i++]);
	root->left = buildBST(preorder, i, root->val);
	root->right = buildBST(preorder, i, bound);
	return root;
}