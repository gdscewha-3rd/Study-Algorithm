//220319
//백준 10871번 X보다 작은 수 문제 (브론즈 3)
//https://www.acmicpc.net/problem/10871

#include <iostream>
#include <vector>
using namespace std;

//작은 수 탐색시 lower_bound 사용해서 시간복잡도 줄일 수 있을지 
//=> 문제 조건에서 입력받은 순서대로 출력해야함 즉, 정렬하는게 더 복잡해짐..
//그냥 모든 원소 방문하는 방식 사용

void printSmallerNum(vector<int> v, int x)
{
    for (int i = 0; i < v.size(); i++)
        if (v[i] < x) printf("%d ", v[i]);
}
int main(void)
{
    int n = 0, x = 0;
    scanf("%d %d", &n, &x);

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    printSmallerNum(v, x);

}