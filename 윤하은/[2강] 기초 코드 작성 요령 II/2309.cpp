//220325
//백준 2309번 일곱난쟁이 문제
//https://www.acmicpc.net/problem/2309
#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> v, int target)
{
    int start = 0;
    int end = v.size()-1;
    int mid = 0;
    
    while(start >= 0 && end <= v.size()-1 && start <= end)
    {
        mid = (start+end)/2;
        
        if(v[mid] == target)
            return mid;
            
        else if(v[mid] > target)
            end = mid-1;
        else//v[mid] < target
            start = mid+1;
    }
    
    //v의 원소 중 target을 찾을 수 없을 때
    return -1;
    
    
}
void PrintDwarf(vector<int> v, int idxA, int idxB)
{
    for(int i =0; i<v.size(); i++)
    {
        if(i == idxA || i == idxB)
            continue;
        
        printf("%d\n", v[i]);
    }
    
    return;
}
int main(void)
{
    const int DWARF_NUM = 9;
    const int REAL_SUM = 100;
    int sum =0, target =0;
    
    vector<int> list(DWARF_NUM);
    
    for(int i =0; i<DWARF_NUM; i++)
    {
        scanf("%d", &list[i]);
        sum += list[i];
    }
    
    target = sum - REAL_SUM;
    sort(list.begin(), list.end());
    
    for(int i =0; i<DWARF_NUM; i++)
    {
        int resultIdx = BinarySearch(list, target - list[i]);
        if(resultIdx != -1)
        {
            PrintDwarf(list, i, resultIdx);
            break;
        }
    }
    
    
    return 0;
}