bool checkBST(Node* node, int min, int max){
    if (node == NULL) {
        return true;
    } else if (node->data < min || node->data > max) {
        return false;
    } else {
        return checkBST(node->left, min, node->data - 1) && checkBST(node->right, node->data + 1, max);
    }
}
	bool checkBST(Node* root) {
        return checkBST(root,0,10000);
		
	}
