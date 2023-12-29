int maxWidth(Node* root){
	queue<pair<Node*, int>> q;
	q.push({root, 0});
	int ans = 0;
	while(q.empty() == false){
		int n = q.size();
		int start = q.front().second;
		int end = q.back().second;
		ans = max(ans, end - start + 1);
		for(int i = 0; i<n; i++){
			pair<Node*, int> p = q.front();
			Node* temp = p.first;
			int index = p.second;
			q.pop();
			if(temp->left) q.push({temp->left, 2*index+1});
			if(temp->right) q.push({temp->right, 2*index+2});
		}
	}
	return ans;
}