//220501
//���� 11047�� ����0 (�ǹ� 3)
//https://www.acmicpc.net/problem/11047


#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int i, arr[10];
	for (i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	int num = 0;
	for (i = N; i >= 1; i--) {
		if (K >= arr[i]) {
			K -= arr[i];
			num++;
			i++; //��� ���� ������ �ٽ� �ѹ� �� ��
		}
	}

	cout << num;
	return 0;
}
