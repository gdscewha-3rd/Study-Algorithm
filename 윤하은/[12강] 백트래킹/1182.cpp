#include <bits/stdc++.h>
using namespace std;

int targetSum;
int n;
int result;
int sum;
vector<int> resultSeq;
vector<pair<int, bool>> nums;

bool cmp(pair<int, bool> a, pair<int, bool> b)
{
    return a.first < b.first;
}
void func(int k)
{

    if(k == n+2) return;
    
    else if(sum > targetSum)
        return;
    
    else if(sum == targetSum)
    {
        result++;
        for(int i = 1; i<k; i++)
        {
            cout << resultSeq[i] <<" ";
        }
        cout << "\n";
        return;
    }
    else
    {
        for(int i = 0; i<n; i++)
        {
            if(!nums[i].second && resultSeq[k-1] <= nums[i].first)
            {
                nums[i].second = true;
                resultSeq[k] = nums[i].first;
                sum += nums[i].first;
                func(k+1);
                nums[i].second = false;
                sum -= nums[i].first;
            }
        

        }

    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> targetSum;
    resultSeq = vector<int>(n+5);

    for(int i = 0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        nums.push_back(make_pair(tmp, false));
    }
    
    //nums 오름차순 정렬
    sort(nums.begin(), nums.end(), cmp);

    func(1);

    cout << result;

}