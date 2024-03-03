class Solution {
    Node* solve(Node* root, unordered_map<Node*, Node*>& mp){
        Node* node = new Node(root->val);
        mp[root] = node;
        vector<Node*> nbr;
        for(auto i : root->neighbors){
            if(mp[i]){
                nbr.push_back(mp[i]);
            }
            else{
                nbr.push_back(solve(i, mp));
            }
        }
        node->neighbors = nbr;
        return node;
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(node->neighbors.size() == 0){
            Node* root= new Node(node->val);
            return root; 
        }

        unordered_map<Node*, Node*> mp;
        Node* ans = solve(node, mp);
        return ans;
    }
};