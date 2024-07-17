class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        // unordered_map<int,TreeNode*> node;
        // unordered_map<int,bool> isChild;

        vector<TreeNode*> node(100001, NULL);
        vector<bool> isChild(100001, false);

        for(auto desc : descriptions){
            TreeNode* parent = node[desc[0]];
            TreeNode* child = node[desc[1]];
            bool isLeft = desc[2];

            isChild[desc[1]] = true;

            if(parent == NULL){
                parent = new TreeNode(desc[0]);
                node[desc[0]] = parent; 
            }
            if(child == NULL){
                child = new TreeNode(desc[1]);
                node[desc[1]] = child;
            }

            if(isLeft) parent->left = child;
            else parent->right = child;
        }

        TreeNode* root;
        for(auto desc : descriptions){
            if(isChild[desc[0]] == false){
                root = node[desc[0]];
                break;
            }
        }

        return root;
    }
};
