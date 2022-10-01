class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n<=1)
        {
            return "";
        }
        for (int i=0;i<(n/2);i++)
        {
            if(palindrome[i]>'a')
            {
                palindrome[i]='a';
                return palindrome;           
                    
            }
        }
        
        for(int i = n-1;i>=0;i--)           
        {
            if(palindrome[i]<'z')
            {
                palindrome[i]++;
                return palindrome;
            }
        }
        return "";
    }
};