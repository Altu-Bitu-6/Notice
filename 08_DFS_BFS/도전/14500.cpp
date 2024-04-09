// 브루트포스 기반 dfs 문제
// 우측 하단의 테트로미노에 유의해서 조건을 잘 생각해야함
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> li;
vector<vector<bool>> board;
int ans = 0;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void dfs(int a, int b, int total, int depth) {
    if (depth == 3) {
        ans = max(ans, total);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = dx[i] + a;
        int ny = dy[i] + b;
        if (0 <= nx && nx < n && 0 <= ny && ny < m && !board[nx][ny]) {
            if (depth == 1) { // 'ㅗ' 모양 예외처리를 위한 것
                board[nx][ny] = true;
                dfs(a, b, total + li[nx][ny], depth + 1); // 원래 워치에서 다시 dfs 실행
                board[nx][ny] = false;
            }
            board[nx][ny] = true; // 해당 칸 방문 처리
            dfs(nx, ny, total + li[nx][ny], depth + 1); // dfs 실행
            board[nx][ny] = false; // 해당 칸 방문 처리 해제
        }
    }
}

int main() {
    cin >> n >> m;
    li.assign(n, vector<int>(m));
    board.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> li[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = true;
            dfs(i, j, li[i][j], 0);
            board[i][j] = false;
        }
    }

    cout << ans << "\n";

    return 0;
}
