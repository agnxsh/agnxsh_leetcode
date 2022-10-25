class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1, str2;
        for(auto a1:word1)
        {
            str1+=a1;
        }
        for(auto a2:word2)
        {
            str2+=a2;
        }
        return str1==str2;
    }
};