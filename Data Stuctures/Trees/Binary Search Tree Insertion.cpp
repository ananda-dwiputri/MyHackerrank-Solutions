/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
Node * newnode(int v) {
    Node* t = (struct Node*) malloc(sizeof(struct Node));
    t->data = v;
    t->left = NULL;
    t->right = NULL;
    return t;
}
    Node * insert(Node * root, int data) {
        if(!root) return newnode(data);
    if(data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);

        return root;
    }
