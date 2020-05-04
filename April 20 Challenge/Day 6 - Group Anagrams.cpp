/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for(const auto& str : strs){
            string s = str;
            sort(begin(s), end(s));
            map[s].push_back(move(str));
        }

        vector<vector<string>> result;
        for(auto& kv : map)
            result.push_back(move(kv.second));

        return result;
    }
};