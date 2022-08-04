#include <bits/stdc++.h>
//#define NUM "first"
//#define ISUSED "second"
using namespace std;

int n, m;
vector<pair<int, bool>> nums;
int arr[10];

bool cmp(pair<int, bool> a, pair<int, bool> b)
{
    return a.first < b.first;
}
void func(int k)
{
    if(k==m+1)
    {
        for(int i = 1; i<=m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    else
    {
        for(int i = 0; i< n; i++)
        {
            if((!nums[i].second) && (nums[i].first > arr[i]))
            {
                nums[i].second = true;
                arr[k] = nums[i].first;
                func(k+1);
                nums[i].second = false;
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
        nums.push_back(make_pair(num, false));
    }
    
    sort(nums.begin(), nums.end(), cmp);
    
    func(1);
}
