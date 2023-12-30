TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
	if(root == NULL) return NULL;
	if(p->val > root->val and q->val > root->val){
		return LCA(root->right, p, q);
	}
	if(p->val < root->val and q->val < root->val){
		return LCA(root->left, p, q);
	}
	return root;
}