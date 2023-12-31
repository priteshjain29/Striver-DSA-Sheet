class Solution {
private:
    void f(int ind, vector<int> &nums, vector<int> &subset, vector<vector<int>> &allSubsets){
        allSubsets.push_back(subset);

        for(int i = ind; i<nums.size(); i++){
            if(i != ind and nums[i] == nums[i-1]) continue;

            subset.push_back(nums[i]);
            f(ind+1, nums, subset, allSubsets);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        f(0, nums, subset, allSubsets);
        return allSubsets;
    }
};