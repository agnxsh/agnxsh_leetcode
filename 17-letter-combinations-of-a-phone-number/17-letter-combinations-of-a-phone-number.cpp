class Solution {
public:
    
    const vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> result;
        result.push_back("");
        
        for(auto digit : digits)
        {
            vector<string> temp;
            for(auto candidate : pad[digit-'0'])
            {
                for(auto s : result)
                {
                    temp.push_back(s+candidate);
                    
                }
            }
            result.swap(temp);
        }
        return result;
    }
};