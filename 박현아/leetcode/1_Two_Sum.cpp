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
            //it has to be different from the num
            int index = std::find(nums.begin()+i+1, nums.end(), pair) - nums.begin();

            if((index < nums.size())){
                output.push_back(i);
                output.push_back(index);
                break;
            }
        }
        
        return output;
    }
};
