//220319
//���� 10871�� X���� ���� �� ���� (����� 3)
//https://www.acmicpc.net/problem/10871

#include <iostream>
#include <vector>
using namespace std;

//���� �� Ž���� lower_bound ����ؼ� �ð����⵵ ���� �� ������ 
//=> ���� ���ǿ��� �Է¹��� ������� ����ؾ��� ��, �����ϴ°� �� ��������..
//�׳� ��� ���� �湮�ϴ� ��� ���

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