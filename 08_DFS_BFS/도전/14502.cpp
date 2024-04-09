#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> li;
vector<pair<int, int>> virus;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int ans = 0;

void checkSafeZone(const vector<vector<int>>& tmp_map) { //바이러스가 퍼지지 않은 지역 계산
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmp_map[i][j] == 0) {
                count++;
            }
        }
    }
    ans = max(ans, count);
}

void bfs() {
    queue<pair<int, int>> q;
    vector<vector<int>> tmp_map = li;
    for (auto& v : virus) {
        q.push(v);
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (0 <= newx && newx < n && 0 <= newy && newy < m && tmp_map[newx][newy] == 0) {
                tmp_map[newx][newy] = 2;
                q.push(make_pair(newx, newy));
            }
        }
    }
    checkSafeZone(tmp_map);
}

void wall(int cnt) { //벽을 3개 세우는 경우를 전부 계산
    if (cnt == 3) { // 벽을 3개 세웠다면, 바이러스 퍼지는 것을 계산
        bfs();
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (li[i][j] == 0) {
                li[i][j] = 1;
                wall(cnt + 1);
                li[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    li.assign(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> li[i][j];
            if (li[i][j] == 2) {
                virus.push_back(make_pair(i, j));
            }
        }
    }

    wall(0);
    cout << ans << "\n";

    return 0;
}
