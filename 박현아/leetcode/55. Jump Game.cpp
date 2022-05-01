//220429
//leetcode #55 Jump Game /Medium
//https://leetcode.com/problems/jump-game/

//wrong answer
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool dp[10001] = {false};
        
        dp[0] = true;
        
        for(int i = 0; i<(nums.size()-1); i++){
            if(dp[i]){
                if(!dp[i+nums[i]])
                        dp[i+nums[i]]= true;
            }
        }
        
        return dp[nums.size()-1];
    }
};

//solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dis = 0;
        for (int i = 0; i <= dis; i++) {
            dis = max(dis, i + nums[i]);
            if (dis >= nums.size()-1) {
                return true;
            }
        }
        return false;
    }
};
