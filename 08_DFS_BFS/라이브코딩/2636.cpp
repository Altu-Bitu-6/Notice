#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<bool>> visited;
int total_time, cheese_cnt;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1}; //dx,dy 네 방향에 대해 갱신

void bfs() {
    queue<pair<int, int>> q;
    queue<pair<int, int>> tmp;

    q.push(make_pair(0, 0));

    while (!q.empty()) {
        cheese_cnt = q.size();
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();//지금 검사하는 요소 제거

            for (int i = 0; i < 4; i++) { //동서남북으로 검사
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                
                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) {
                    //인덱스 내에 있는지 검사
                    if (!visited[new_x][new_y] && board[new_x][new_y] == 1) { 
                        //방문한 적 없고,녹을 수 있는 치즈 
                        tmp.push(make_pair(new_x,new_y));
                    }
                    else if(!visited[new_x][new_y] && board[new_x][new_y] == 0) {
                        //방문한 적 없는 공기 -> bfs로 동서남북에
                        //이번 턴에 녹을 수 있는 치즈가 있는지 검사
                        q.push(make_pair(new_x,new_y));
                    }
                    visited[new_x][new_y] = true;
                }
            }
        } // 안에 검사한 while 문 -> 이번 턴에 녹일 수 있는 치즈에 대한 검사

        while (!tmp.empty()) {
            q.push(tmp.front());
            tmp.pop();
        }
        total_time++;
    }
}

int main() {
    cin >> n >> m;

    total_time = 0;
    cheese_cnt = 0;

    board.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    //입력 끝
    
    visited[0][0] = true; // 첫 번째
    bfs();

    //출력
    cout << total_time - 1 << '\n';
    cout << cheese_cnt << '\n';

    return 0;
}
