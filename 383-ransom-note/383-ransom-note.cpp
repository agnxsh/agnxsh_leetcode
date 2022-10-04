class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mag;
        for(auto c: magazine)
        {
           if(mag.find(c)!=mag.end())
           {
            int count = mag[c]+1;
            mag[c]=count;             
           }
        else
        {
            mag.insert({c,1});
        }
        }
        
        for(char c : ransomNote)
        {
            if(mag.find(c)==mag.end())
            {
                return false;
            }
            int count = mag[c];
            if(count==0)
            {
                return false;
                
            }
            mag[c]=count-1;
        }
        return true;
    }
};