//220324
//백준 1267번 핸드폰 요금 문제 (브론즈 3)
//https://www.acmicpc.net/problem/1267
#include <bits/stdc++.h>
using namespace std;

//1~29 : 1
//30~59 : 2
//60 ~ 89 : 3
//1~59 : 1
//60 ~ 119 : 2
int calculateYFee(vector<int> v)
{
    int fee =0;
    for(int i =0; i<v.size(); i++)
        fee += (10 * ((int)floor(v[i]/30.0)+1));
    return fee;
}
int calculateMFee(vector<int> v)
{
    int fee =0;
    for(int i =0; i<v.size(); i++)
        fee += (15 * ((int)floor(v[i]/60.0)+1));
    return fee;
}
void printResult(int mFee, int yFee)
{
    if(mFee == yFee)
    {
        printf("Y M %d", mFee);
    }
    else
    {
        int result = 0;
        if(mFee > yFee) 
        {
            printf("Y ");
            result = yFee;
        }
        else 
        {
            printf("M ");
            result = mFee;
        }
        printf("%d", result);
    }
    return;
    
}
int main(void)
{
    int callNum =0;
    scanf("%d", &callNum);
    
    vector<int> v(callNum);
    
    for(int i =0; i<callNum; i++)
        scanf("%d", &v[i]);
        
    int yFee = calculateYFee(v);
    int mFee = calculateMFee(v);
    
    printResult(mFee, yFee);
}