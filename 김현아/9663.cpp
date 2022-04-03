//210327
//���� 9663�� N-Queen (��� 5)
//https://www.acmicpc.net/problem/9663


#include <stdio.h>
#include <stdlib.h>

int board[15];
int n, count = 0;

int checkCondition(int row) {
    for (int i = 0; i < row; i++) { // ���� ��鿡 ���� �ݺ�
        // ���� ���� �� == ���� ���� �� (���� ���� �ִ� ���) Ȥ�� ���� �� - ���� �� == ���� �� - ���� ��(���� �밢���� �ִ� ���) �̸�
        if (board[row] == board[i] || row - i == abs(board[row] - board[i])) {
            return 0; // row �࿡ col��° ���� �Ұ���. �ٽ� ���ư���.
        }
    }
    return 1; // for���� ������ ����ߴٸ� �� ���� ���
}

void nQueen(int row) {
    if (row == n) { // ��� ���� �� ����ߴٸ�
        count++; // Ƚ�� �ϳ� ����
        return;
    }

    for (int col = 0; col < n; col++) {
        board[row] = col; // row �࿡ col��° ���� �־��
        if (checkCondition(row)) { // �� �࿡�� �������� �˻�
            nQueen(row + 1); // �����ϸ� ���� ������ �Ѿ
        }
    }
}

int main() {
    scanf("%d", &n);
    nQueen(0);
    printf("%d", count);
    return 0;
}