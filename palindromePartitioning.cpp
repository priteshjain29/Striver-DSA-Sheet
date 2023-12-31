/*
Function partitionHelper:

This is a recursive helper function that explores all possible partitions.
Takes four parameters: index (the current position in the string), s (the input string), path (the current partition being explored), and res (the vector to store the final result).
Base case: If index reaches the end of the string, it means a valid partition has been found. The current path is added to the result vector res.
Iterates through the string starting from the current index.
Checks if the substring from the current index to the current iteration index is a palindrome using the isPalindrome function.
If it is a palindrome, adds the substring to the path vector and recursively calls partitionHelper with the updated index (i + 1).
After the recursive call, removes the last added substring from the path vector to explore other possibilities (backtracking).
*/



class Solution {
  public:
    vector < vector < string >> partition(string s) {
      vector < vector < string > > res;
      vector < string > path;
      partitionHelper(0, s, path, res);
      return res;
    }

  void partitionHelper(int index, string s, vector < string > & path,
    vector < vector < string > > & res) {
    if (index == s.size()) {
      res.push_back(path);
      return;
    }
    for (int i = index; i < s.size(); i++) {
      if (isPalindrome(s, index, i)) {
        path.push_back(s.substr(index, i - index + 1));
        partitionHelper(i + 1, s, path, res);
        path.pop_back();
      }
    }
  }

  bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
};