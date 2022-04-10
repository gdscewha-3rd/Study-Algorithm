//210327
//백준 9663번 N-Queen (골드 5)
//https://www.acmicpc.net/problem/9663


#include <stdio.h>
#include <stdlib.h>

int board[15];
int n, count = 0;

int checkCondition(int row) {
    for (int i = 0; i < row; i++) { // 상위 행들에 대해 반복
        // 현재 행의 열 == 상위 행의 열 (같은 열에 있는 경우) 혹은 현재 행 - 상위 행 == 현재 열 - 상위 열(같은 대각선상에 있는 경우) 이면
        if (board[row] == board[i] || row - i == abs(board[row] - board[i])) {
            return 0; // row 행에 col번째 열은 불가능. 다시 돌아간다.
        }
    }
    return 1; // for문을 무사히 통과했다면 이 행은 통과
}

void nQueen(int row) {
    if (row == n) { // 모든 행을 다 통과했다면
        count++; // 횟수 하나 세기
        return;
    }

    for (int col = 0; col < n; col++) {
        board[row] = col; // row 행에 col번째 열을 넣어보고
        if (checkCondition(row)) { // 이 행에서 가능한지 검사
            nQueen(row + 1); // 가능하면 다음 행으로 넘어감
        }
    }
}

int main() {
    scanf("%d", &n);
    nQueen(0);
    printf("%d", count);
    return 0;
}