Node* connect(Node* root){
	if(root == NULL) return NULL;
	queue<Node*> q;
	q.push(root);
	while(q.empty() == false){
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			Node* temp = q.front();
			if(i<size-1){
				temp->next = q.front();
			}
			else{
				temp->next = NULL;
			}
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
		}
		return root;
	}
}