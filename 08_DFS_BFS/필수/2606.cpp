#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> li; // 그래프를 나타내는 인접 리스트
vector<bool> visited; // 방문 여부를 체크하는 벡터

void dfs(int num) {
    for (int i = 1; i <= N; i++) {
        if (li[num][i] == 1 && !visited[i]) {
            visited[i] = true; // 방문 처리
            dfs(i); // DFS 진행
        }
    }
}

int main() {
    cin >> N >> M;
    li.assign(N + 1, vector<int>(N + 1, 0));
    visited.assign(N + 1, false);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        li[a][b] = li[b][a] = 1; // 양방향 그래프 구성
    }

    visited[1] = true;
    dfs(1);

    int count = 0;
    for (int i = 2; i <= N; i++) {
        if (visited[i])
            count++; // 연결된 노드 수 계산
    }
    
    cout << count << "\n";

    return 0;
}
