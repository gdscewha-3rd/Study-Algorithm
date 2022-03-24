//220324
//백준 2562번 최댓값 문제 (브론즈 2)
//https://www.acmicpc.net/problem/2562
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    const int NUM_OF_NUM= 9;
    
    int maxNum = 0;
    int maxIdx = 0;
    for(int i =0; i<NUM_OF_NUM; i++)
    {
        int num =0;
        scanf("%d", &num);
        
        if(num > maxNum)
        {
            maxNum = num;
            maxIdx = i+1;
        }
        
    }
    
    printf("%d\n%d", maxNum, maxIdx);
}