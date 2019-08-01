/*
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

    void levelOrder(Node * root) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* p = q.front();
            q.pop();
            cout << p->data << " ";
            if(p->left) {
                q.push(p->left);
            }
            if(p->right){
                q.push(p->right);
            }
        }

    }
