vector<int> left(TreeNode *root){
	vector<int> res;

	if(root == NULL) return res;
	queue < TreeNode* > q;
	q.push(root);
	while(q.empty() == false){
		
		int n = q.size();
		for (int i = 1; i < n; i++)
		{
			TreeNode* temp = q.front();
			q.pop();
			if(i == 1) res.push_back(temp->val);

			if(temp->left != NULL) q.push(temp->left);
			if(temp->right != NULL) q.push(temp->right);
		}
	}
	return res;
}