//220322
//leetcode #1 Two Sum /Easy
//https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
      
        for (int i = 0; i<nums.size(); i++){
            int num = nums[i];
            int pair = target - num;
          
            //find the pair that makes the target number when it is added with the num
            int index = std::find(nums.begin(), nums.end(), pair) - nums.begin();
          
            //it has to be a different number with the num
            if((index < nums.size()) && (index != i)){
                output.push_back(i);
                output.push_back(index);
                break;
            }
        }
        
        return output;
    }
};
