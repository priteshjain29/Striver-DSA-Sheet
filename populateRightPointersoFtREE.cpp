Node* connect(Node* root){
	if(root == NULL) return NULL;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		int len = q.size();
		for(int i = 0; i<len; i++){
			Node* temp = q.front();
			q.pop();
			if(i<len-1){
				temp -> next = q.front();
			}
			else{
				temp->next = NULL;
			}
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
	}
	return root;
}