class Solution
{
private:
    void subsetSumsHelper(vector<int> arr, int n, int ind, int sum, vector<int> &ans){
        if(ind == n){
            ans.push_back(sum);
            return;
        }
        subsetSumsHelper(arr, n, ind+1, sum+arr[ind], ans);
        subsetSumsHelper(arr, n, ind+1, sum, ans);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        subsetSumsHelper(arr, N, 0, 0, ans);
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};