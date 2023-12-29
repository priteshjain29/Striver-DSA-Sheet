vector < int > maxSlidingWindow(vector < int > & nums, int k) {
  deque < int > dq;
  vector < int > ans;
  for (int i = 0; i < nums.size(); i++) {
    if (!dq.empty() && dq.front() == i - k) dq.pop_front();

    while (!dq.empty() && nums[dq.back()] < nums[i])
      dq.pop_back();

    dq.push_back(i);
    if (i >= k - 1) ans.push_back(nums[dq.front()]);
  }
  return ans;
}

The function takes a vector of integers (nums) and an integer k as input, representing the size of the sliding window.

It uses a deque (dq) to keep track of indices of elements in the current window.

It iterates through the elements of the input vector (nums) using the variable i as the current index.

In each iteration:

It checks and removes elements from the front of the deque that are no longer in the current window.
It removes elements from the back of the deque if they are smaller than the current element (nums[i]), ensuring that the deque stores indices of elements in non-decreasing order of values.
It adds the current index i to the deque.
If the current index is at least k - 1, it means the window has reached its full size, so it adds the maximum element in the current window (located at the front of the deque) to the result vector (ans).
Finally, the function returns the vector ans containing the maximum elements for each sliding window.

This algorithm efficiently maintains the maximum element in the sliding window as it moves through the array, and the deque helps in efficiently updating the maximum element as well as removing indices that are no longer in the current window.