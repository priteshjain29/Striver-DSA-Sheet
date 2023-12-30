vector<int> slidingWindowMax(vector<int> &nums, int k){
    deque<int> dq;
    vector<int> res;
    int n = nums.size();

    for(int i = 0; i<k; i++){
        while(dq.size() > 0 and dq.back() < nums[i]){
            dq.pop_back();
        }
        dq.push_back(nums[i]);
    }

    res.push_back(dq.front());

    for(int i = k; i<n; i++){
        int addIndex = i;
        int remIndex = i-k;

        while(dq.size() > 0 and dq.back() < nums[addIndex]){
            dq.pop_back();
        }
        dq.push_back(nums[addIndex]);
    }

    if(dq.front() == nums[remIndex]){
        dq.pop_front();
    }

    res.push_back(dq.front());
}