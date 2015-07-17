/*
My Submissions Question Solution 
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_map<char, char> charmap, charmap2;
        for (int i = 0; i < s.length(); i++) {
            auto x = charmap.insert(std::pair<char,char>(s[i], t[i]));
            if (x.second == false && x.first->second != t[i])
                return false;
            auto y = charmap2.insert(std::pair<char,char>(t[i], s[i]));
            if (y.second == false && y.first->second != s[i])
                return false;
        }
        return true;
    }
};
