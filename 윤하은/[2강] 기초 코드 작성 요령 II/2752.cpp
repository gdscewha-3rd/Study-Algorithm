//220322
//���� 2752�� �������� ���� (����� 4)
//https://www.acmicpc.net/problem/2752

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v(3);

	for (int i = 0; i < 3; i++)
		scanf("%d", &v[i]);

	sort(v.begin(), v.end());

	for (int i = 0; i < 3; i++)
		printf("%d ", v[i]);


}