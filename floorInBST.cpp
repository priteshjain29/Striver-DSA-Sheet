int floor(Node* root, int key){
	int floor = -1;
	while(root != NULL){
		if(root->val == key){
			floor = root->val;
			return floor;
		}
		if(root->val < key){
			//it may be a possible floor so store it
			floor = root -> val;
			//now look if there is exists another node with value higher than
			//current node and less than key
			root = root -> right;
		}
		else{
			root = root -> left;
		}
	}
	return root;
}