//220322
//백준 2480번 주사위 세개 문제 (브론즈 4)
//https://www.acmicpc.net/problem/2480

#include <iostream>
#include <algorithm>
using namespace std;
int calculateReward(int a, int b, int c)
{
    int reward = 0;

    //같은 눈이 3개 나오는 경우
    if (a == b && b == c)
        reward = 10000 + a * 1000;

    //같은 눈이 2개 나오는 경우
    else if (a == b || b == c || a == c)
    {
        if (a == b || a == c)
            reward = 1000 + a * 100;
        else//b == c
            reward = 1000 + b * 100;
    }

    //모두 다른 눈이 나오는 경우
    else
        reward = max({ a, b, c }) * 100;


    return reward;

}
int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", calculateReward(a, b, c));

}