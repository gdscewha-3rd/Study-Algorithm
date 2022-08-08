#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int nums[10];

void func(int k)
{
    if(k==m)
    {
        for(int i = 0; i<m; i++)
            cout << arr[i] << " ";
        cout << "\n";    
        return;
    }
    else
    {
        for(int i = 0; i<n; i++)
        {
            arr[k] = nums[i];
            func(k+1);
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for(int i= 0; i<n; i++)
        cin >> nums[i];
    
    sort(nums, nums+n);
    
    func(0);
}
