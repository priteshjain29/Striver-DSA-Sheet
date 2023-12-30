class Solution {
public:
    vector <int> ans;
    void inorder(TreeNode* root) {
        if(root == NULL) return;
        inorder(root -> left);
        ans.push_back(root -> val);
        inorder(root -> right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        vector <int> v = ans;
        int low = 0;
        int high = v.size() - 1;
        while(low < high)
        {
            if(v[low] + v[high] == k) return true;
            else {
                if (v[low] + v[high] < k) low++;
                else high--;
            }
            
        }
        return false;
    }
};