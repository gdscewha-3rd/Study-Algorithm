#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int numOfNum = 0;
    scanf("%d", &numOfNum);
    vector<int> nums(numOfNum, 0);
    
    for(int i =0; i<numOfNum; i++)
        scanf("%d", &nums[i]);
        
    sort(nums.begin(), nums.end());
    
    int target =0;
    scanf("%d", &target);
    
    int result = upper_bound(nums.begin(), nums.end(), target) - lower_bound(nums.begin(), nums.end(), target);
    printf("%d", result);
    
    
}