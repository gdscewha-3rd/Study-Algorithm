#include <bits/stdc++.h>
using namespace std;
long long reverseNum(long long target)
{
    string str = to_string(target);
    long long end = str.length();
    for(long long i = str.length()-1; i > 0; i--)
    {
        if(str[i] == '0')
            end = i;
        else break;
    }
    
    str = str.substr(0, end);
    reverse(str.begin(), str.end());
    return stoll(str);
    
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<long long> nums;
    
    for(int i = 0; i<n; i++)
    {
        long long num;
        cin >> num;
        nums.push_back(reverseNum(num));
    }
    
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i<n; i++)
        cout << nums[i] << "\n";

}
