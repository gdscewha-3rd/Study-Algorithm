//220324
//백준 1267번 핸드폰 요금 문제 (브론즈 3)
//https://www.acmicpc.net/problem/1267
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int callNum =0;
    scanf("%d", &callNum);
    
    int yFee = 0, mFee =0;
    
    for(int i =0; i<callNum; i++)
    {
        int fee =0;
        scanf("%d", &fee);
        yFee += (10 * ((int)floor(fee/30.0)+1));
        mFee += (15 * ((int)floor(fee/60.0)+1));
    }
    
    if(mFee == yFee)
        printf("Y M %d", mFee);
    else if(mFee > yFee) printf("Y %d", yFee);
    else printf("M %d", mFee);
    
}