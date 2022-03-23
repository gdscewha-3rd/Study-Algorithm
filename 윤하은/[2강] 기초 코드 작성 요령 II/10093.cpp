//220323
//백준 10093 숫자 문제
//https://www.acmicpc.net/problem/10093

#include <iostream>
using namespace std;

int main(void)
{
    long long a, b;
    scanf("%lld %lld", &a, &b);
    long long maxNum = max(a, b);
    long long minNum = a+b-maxNum;//min(a, b)
    
    if(a == b) printf("0\n");
    else printf("%lld\n", maxNum - minNum -1);
    for(long long i = minNum+1; i<maxNum; i++)
        printf("%lld ", i);
    
}