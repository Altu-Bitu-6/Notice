#include <iostream>
#include <vector>

using namespace std;

int n, a, b, m;
vector<vector<int>> li; // 그래프를 나타내는 인접 리스트
vector<bool> visited; // 방문 여부를 체크하는 벡터
int ans = -1; // 최종 촌수 저장, 기본값은 -1(친척 관계 없음)

void dfs(int v, int num) {
    visited[v] = true; // 현재 노드 방문 처리

    if (v == b) { // 촌수를 구한 경우
        ans = num;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (li[v][i] == 1 && !visited[i]) { // 인접하고 아직 방문하지 않은 것에 대해 dfs 실행 
            dfs(i, num + 1);
        }
    }
}

int main() {
    cin >> n;
    cin >> a >> b;
    cin >> m;

    li.assign(n + 1, vector<int>(n + 1, 0));
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int c, d;
        cin >> c >> d;
        li[c][d] = li[d][c] = 1; // 양방향 그래프로 구성
    }

    dfs(a, 0);

    if (ans == -1) {
        cout << -1 << "\n"; // 경로가 없는 경우
    } else {
        cout << ans << "\n"; // 최소 거리 출력
    }

    return 0;
}
