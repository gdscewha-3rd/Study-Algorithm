#include "iostream"
#include "vector"
#include "queue"

using namespace std;

int n, m;
int cheese = 0;
int di[] = {0,0,-1,1};
int dj[] = {-1, 1,0,0};
vector<vector<int>> vec;
queue<pair<int, int>> airQue; // 외부 공기 체크할 큐

// BFS 방식으로 돌면서 외부 공기는 -1로 체크 (외부 공기와 내부 공기 구분)
void air() {
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    visit[0][0] = true;
    vec[0][0] = -1;
    while (!airQue.empty()) {
        int ci = airQue.front().first;
        int cj = airQue.front().second;
        airQue.pop();
        for (int k = 0; k < 4; k++) {
            int ni = ci + di[k];
            int nj = cj + dj[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m || visit[ni][nj]) {
                // 칸 범위를 넘어갔거나 방문했다면 패
                continue;
            }
            // 외부 공기인데 0으로 표시되어 있으면
            if (vec[ni][nj] == 0) {
                vec[ni][nj] = -1;
                // airQue에 담아서 다음 차례에 새롭게 추가된 외부 공기부터 체크
                airQue.push(make_pair(ni, nj));
                visit[ni][nj] = true;
            }
        }
    }
}

void melt() {

    queue<pair<int, int>> melt; // 녹을 치즈들 담는 큐
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vec[i][j] == 1) {
                int cnt = 0; // 접해있는 외부 공기 수
                for (int k = 0; k < 4; k++) {
                    if (vec[i + di[k]][j + dj[k]] == -1) {
                        cnt++;
                    }
                }
                if (cnt >= 2) {
                    cheese--;
                    melt.push(make_pair(i, j));
                }
            }
        }
    }

    while (!melt.empty()) {
        // 치즈가 녹으면 외부 공기로 표시하고 airQue에 추가
        vec[melt.front().first][melt.front().second] = -1;
        airQue.push(make_pair(melt.front().first, melt.front().second));
        melt.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vec.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
            if (vec[i][j] == 1) {
                cheese++;
            }
        }
    }

    int ans = 0;
    airQue.push(make_pair(0, 0));

    while (cheese > 0) { // 치즈가 0일때까지 반복
        // 외부 공기 체크
        air();
        // 치즈 녹이기
        melt();
        // 시간 +1
        ans++;
    }
    cout << ans;

    return 0;
}
