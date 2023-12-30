class BSTIterator {
public:
	stack <Node*> s;

	BSTIterator(Node* root){
		partialInorder(root);
	}

	void partialInorder(Node* root){
		while(root != NULL){
			s.push(root);
			root = root -> left;
		}
	}

	int next() {
		Node* top = s.top();
		s.pop();
		partialInorder(top->right);
		return top -> val;
	}

	bool hasNext(){
		return !isEmpty();
	}
};