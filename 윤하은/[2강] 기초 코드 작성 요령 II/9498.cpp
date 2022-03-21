//211027
//백준 9498번 시험성적 문제 (브론즈 4)
//https://www.acmicpc.net/problem/9498

#include <iostream>
using namespace std;

char calculateGrade(int score)
{
    switch(score/10)
    {
        case 10:
        case 9:
            return 'A';
        case 8:
            return 'B';
        case 7:
            return 'C';
        case 6:
            return 'D';
        default:
            return 'F';
    }
}
int main(void)
{
    int score = 0;
    char grade;
    scanf("%d", &score);
    printf("%c", calculateGrade(score));
}
