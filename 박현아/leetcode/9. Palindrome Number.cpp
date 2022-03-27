//220327
//leetcode #9 Palindrome Number /Easy
//https://leetcode.com/problems/palindrome-number/


//1
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        string x_s = to_string(x);
        string x_reversed(x_s);
        
        std::reverse(x_reversed.begin(), x_reversed.end());
        
        return (x_s == x_reversed);
    }
};


//2 faster
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        string x_s = to_string(x);
        
        if(x_s[0] == '-')
                return false;
        
        for(int i = 0; i<(x_s.size()/2); i++){
            //be careful for the last index of x_s. It is not x_s.size() but x_s.size()-1
            if(x_s[i] != x_s[x_s.size()-i-1])
                return false;
        }
        
        return true;
    }
};
