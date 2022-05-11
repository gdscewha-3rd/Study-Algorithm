//220508
//38 count and say leetcode /Medium
//https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for(int i = 2; i<=n; i++){
            str = countAndSay_(str);
        }
        
        return str;
    }
    
    string countAndSay_(string s){
        string result = "";
        
        if(s.size() == 1){
            result+=("1");
            result+=(s[0]);
            
            return result;
        }
        
        int cnt = 1;
        
        for(int i = 0; i<(s.size()-1); i++){
            if(s[i] == s[i+1])
                cnt++;
            else{
                result+=(to_string(cnt));
                result+=(s[i]);
                cnt = 1;
            }
        }
        
        if(cnt){
            result+=(to_string(cnt));
            result+=(s[s.size()-1]);
        }
        
        return result;
    }
};
