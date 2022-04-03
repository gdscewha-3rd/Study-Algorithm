// 220326
// 백준 11123 양 한마리... 양 두마리... (실버 1)
// https://www.acmicpc.net/problem/11123

#include "iostream"
#include "vector"
#include "string"
#include "queue"
using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visit;
int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};

void BFS(int i, int j) {
    queue<pair<int, int>> que;
    que.push(make_pair(i, j));
    visit[i][j] = true; // 시작 지점 방문 체크
    while (!que.empty()) {
        int ii = que.front().first;
        int jj = que.front().second;
        que.pop();
        for (int k = 0; k < 4; k++) {
            int ni = ii + di[k];
            int nj = jj + dj[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m || visit[ni][nj] || grid[ni][nj] == 0)
                continue; // grid 칸을 넘어갔거나, 방문했거나, 풀이라면 패쓰
            que.push(make_pair(ni, nj));
            visit[ni][nj] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        grid.assign(n, vector<int>(m, 0)); // 양 = 1, 풀 = 0
        visit.assign(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            for (int j = 0; j < m; j++) {
                if (str[j] == '#')
                    grid[i][j] = 1; // 양이면 1
                else
                    visit[i][j] = true; // 풀이면 탐색시 방문할 필요 없으므로 미리 visit 체크
            }
        }
        int cnt = 0; // 양무리 카운트
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visit[i][j]) { // 양이고 방문한적 없으면 여기서부터 하나의 양무리 탐색
                    cnt++;
                    BFS(i, j);
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
