class Solution {
public:
    void solve(int ind, int target, vector<int> &v, vector<vector<int>> &ans, vector<int> &candidates){
      if(target == 0){
        ans.push_back(v);
        return;
      }

      for(int i=ind; i<candidates.size(); i++){
        if(i > ind and candidates[i] == candidates[i-1]) continue;
        if(candidates[i] > target) break;
        v.push_back(candidates[i]);
        solve(i+1, target-candidates[i], v, ans, candidates);
        v.pop_back();
      }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(0, target, v, ans, candidates);
        return ans;
    }
};