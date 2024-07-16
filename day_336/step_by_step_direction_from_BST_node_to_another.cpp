class Solution {
public:
    bool find(TreeNode* node, int val, string& path) {
        if (node->val == val)
            return true;

        if (node->left && find(node->left, val, path))
            path.push_back('L');

        else if (node->right && find(node->right, val, path))
            path.push_back('R');

        return !path.empty();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string start, end;
        find(root, startValue, start);
        find(root, destValue, end);
        while (!start.empty() && !end.empty() && start.back() == end.back()) {
            start.pop_back();
            end.pop_back();
        }

        reverse(end.begin(), end.end());
        return string(start.size(), 'U') + end;
    }
};
