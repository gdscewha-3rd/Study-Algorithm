#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, bool>> nums;
int seq[10];

bool cmp(pair<int, bool> a, pair<int, bool> b)
{
    return a.first <= b.first;
}
void func(int k)
{
    if(k == m)
    {
        for(int i = 0; i<m; i++)
            cout << seq[i] << " ";
        cout << "\n";
        return;
    }
    else
    {
        for(int i = 0; i<n; i++)
        {
            if(!nums[i].second)
            {
                nums[i].second = true;
                seq[k] = nums[i].first;
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
    func(0);
}
