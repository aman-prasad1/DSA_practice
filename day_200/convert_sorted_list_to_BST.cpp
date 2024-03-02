class Solution {
    TreeNode* solve(vector<int>& nums) {
        if(nums.size()==0)return NULL;

        if(nums.size()==1) return new TreeNode(nums[0]);

        int middle = nums.size()/2;

        TreeNode* root = new TreeNode(nums[middle]);

        vector<int> leftsub(nums.begin(), nums.begin()+middle);
        vector<int> rightsub(nums.begin()+ middle+1, nums.end());

        root->left = solve(leftsub);
        root->right = solve(rightsub);

        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;

        vector<int> nums;
        ListNode* curr = head;
        
        while(curr){
            nums.push_back(curr->val);
            curr = curr->next;
        }

        TreeNode* root = solve(nums);

        return root;
    }
};