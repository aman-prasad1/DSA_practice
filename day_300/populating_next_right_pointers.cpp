// Quesion :- 117. Populating Next Right Pointers in Each Node II

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            Node* front = q.front();
            q.pop();

            if(!front){
                if(!q.empty()){
                    q.push(NULL);
                }
                continue;
            }

            Node* r = q.front();
            if(r){
                front->next = r;
            }

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        return root;
    }
};
