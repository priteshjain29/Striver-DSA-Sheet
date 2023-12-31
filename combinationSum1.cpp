class Solution {
private:
    void findCombination(int ind, vector<int> &candidates, int target, vector<int> &ds, vector<vector<int>> &ans){
        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        if(candidates[ind] <= target){
            ds.push_back(candidates[ind]);
            findCombination(ind, candidates, target-candidates[ind], ds, ans);
            ds.pop_back();
        }

        findCombination(ind+1, candidates, target, ds, ans);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        findCombination(0, candidates, target, ds, ans);
        return ans;
    }
};