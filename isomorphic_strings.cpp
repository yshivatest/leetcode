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
