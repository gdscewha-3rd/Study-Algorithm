#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> nums(n);
     
    for(int i = 0; i<n; i++)
        cin >> nums[i];
        
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i<n; i++)
        cout << nums[i] << "\n";
}
