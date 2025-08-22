#include <unordered_set>
#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> matches;
        int longest = 0;
        // using sliding window
        int l = 0; // r and l are indexes of left and right of the window
        for (int r = 0; r < s.length(); r++){
            while (matches.contains(s[r])){
                matches.erase(s[l]);
                l++;
            }
            matches.insert(s[r]);
            longest = (r-l+1>longest) ? r-l+1 : longest;
        }
        return longest;
    }
};