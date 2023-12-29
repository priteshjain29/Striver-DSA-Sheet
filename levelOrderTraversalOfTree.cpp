vector<vector<int>> levelOrder(Node* root){
	if(root == NULL) return;
	vector<vector<int>> ans;
	queue <Node*> q;
	q.push(root);
	while(q.empty() ==false){
		int len = q.size();
		vector<int> level;
		for(int i = 0; i<n; i++){
			Node* temp = q.front();
			q.pop();
			level.push_back(temp->val);

			if(temp->left) q.push(temp->left);
			if(temop->right) q.push(temp->right);
		}
		ans.push_back(level);
	}
	return ans;
}