
/*
    Given an integer array nums & an integer k, return the k most frequent elements
    Ex. nums = [1,1,1,2,2,3] k = 2 -> [1,2], nums = [1] k = 1 -> [1]
    
    Heap -> optimize w/ freq map & bucket sort (no freq can be > n), get results from end
*/

// Time: O(n log k)
// Space: O(n + k)

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> m;
//         for (int i = 0; i < nums.size(); i++) {
//             m[nums[i]]++;
//         }
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         for (auto it = m.begin(); it != m.end(); it++) {
//             pq.push({it->second, it->first});
//             if (pq.size() > k) {
//                 pq.pop();
//             }
//         }
//         vector<int> result;
//         while (!pq.empty()) {
//             result.push_back(pq.top().second);
//             pq.pop();
//         }
//         return result;
//     }
// };

// Time: O(n)
// Space: O(n)

//*****SOLUTION 2 ----BUCKET SORT *****//////
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> m;

        for(int i =0; i<n; i++){
            m[nums[i]]++;
        }

        vector<vector<int>> buckets(n+1);

        for(auto it : m){
            buckets[it.second].push_back(it.first);
        }

        vector <int> result;

        for (int i = n; i >= 0; i--) {
            if (result.size() >= k) {
                break;
            }
            if (!buckets[i].empty()) {
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        
        return result;
    }
};

/*In this code snippet, buckets is a vector of vectors. Each bucket in the buckets vector stores elements that have the same frequency. The outer vector has a size of n + 1, where n is the number of elements in the input array nums. The idea is that elements with the same frequency are stored in the same bucket, and the bucket index corresponds to the frequency.

The for loop preceding this code snippet iterates over the buckets in reverse order, starting from the maximum possible frequency (which is n in this case). It's done in reverse order because the goal is to find the top k frequent elements.

Here's how the code works:

For each bucket buckets[i], which holds elements with frequency i, the code checks if the bucket is not empty using !buckets[i].empty().

If the bucket is not empty (i.e., it contains elements with frequency i), the code proceeds inside the if block.

result.insert(result.end(), buckets[i].begin(), buckets[i].end()) is used to insert the elements from the current bucket buckets[i] into the result vector.

result.end() returns an iterator pointing to the end of the result vector.
buckets[i].begin() returns an iterator pointing to the beginning of the current bucket.
buckets[i].end() returns an iterator pointing to the end of the current bucket.
The insert function is used to insert elements from the current bucket at the end of the result vector.

This process is done for each bucket in decreasing order of frequency. Since we want to find the top k frequent elements, the loop continues until the size of the result vector reaches at least k or until all buckets have been considered.

In summary, this line of code efficiently inserts elements from the buckets into the result vector, which is used to collect the top k most frequent elements in the input array.





*/





