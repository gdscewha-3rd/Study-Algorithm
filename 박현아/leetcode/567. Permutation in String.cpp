//220519
//leetcode #567 Permutation in string /Medium
//https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        
        int alpha1[26] = {0};
        int alpha2[26] = {0};
        bool startFlag = false;
        
        for(char c : s1){
            alpha1[c-'a']++;
        }
        
        int i = 0;
        int j = 0;
        
        while(j < s2.size()){
            //add new character
            alpha2[s2[j]-'a']++;
            
            if(j-i+1==s1.size()){
                //if the substring length is same with s1, compare its characters
                if(checkAlphas(alpha1,alpha2))
                    return true;;
            }
            
            //if it is the long enough, make it longer
            if(j-i+1 < s1.size())
                j++;
            //if its length is sufficient but its characters are not same with s1
            //move it to the right
            else{
                alpha2[s2[i]-'a']--;
                i++;
                j++;
            }
                
        }
        
        return false;
    }
    
    //check if the characters are same
    bool checkAlphas(int a[26], int b[26]){
        for(int i = 0; i<26; i++){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
};
