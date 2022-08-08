#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
vector<int> nums;

void func(int k)
{
    if(k == m+1)
    {
        for(int i = 1; i<= m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    else
    {
        for(int i = 0; i< n; i++)
        {
            if(arr[k-1] <= nums[i])
            {
                arr[k] = nums[i];
                func(k+1);
            }
        }
        
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for(int i = 0; i<n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    
    sort(nums.begin(), nums.end());
    
    func(1);
}
