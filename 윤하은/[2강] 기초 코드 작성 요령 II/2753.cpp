//220322
//���� 2753�� ���� ���� (����� 4)
//https://www.acmicpc.net/problem/2753

#include <iostream>
using namespace std;

int isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;

    else return 0;
}
int main(void)
{
    int year = 0;
    scanf("%d", &year);
    printf("%d", isLeapYear(year));

}