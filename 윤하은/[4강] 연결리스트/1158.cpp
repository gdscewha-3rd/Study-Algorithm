//220411
//백준 1158번 요세푸스 문제 (실버 4)
//boj.kr/1158

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int peopleNum, target;
    cin >> peopleNum >> target;
    
    list<int> nums;
    int num =0;
    for(int i =1;i<=peopleNum; i++)
        nums.push_back(i);
    
    auto p = nums.begin();
    cout << "<";
    while(!nums.empty())
    {
        for(int i = 0; i<target-1; i++)
        {    
            p++;
            if(p == nums.end()) p = nums.begin();
        }
        
        num = *p;
        p = nums.erase(p);
        if(!nums.empty()) cout << num << ", ";
        if(p==nums.end()) p = nums.begin();
    }
    
    cout << num << ">";
    
        
}
