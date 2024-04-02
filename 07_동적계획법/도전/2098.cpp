#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int n;
vector<vector<int> > li; //입력 받은 도시 간 비용 저장
vector<vector<int> > dp;

int dfs(int x, int visited) // 방문 하지 않은 도시들에 대해 최소 비용을 갱신
{
    if (visited == (1 << n) - 1) { // 도시를 전부 방문한 경우
        if (li[x][0]) { //원래 도시로 돌아갈 수 있는 경우
            return li[x][0];
        }
        else { // 원래 도시로 돌아갈 수 없는 경우
            return INF;
        } 
    }

    if (dp[x][visited] != -1) { // 이미 계산(방문)된 경우, 그 값을 반환
        return dp[x][visited];
    }

    int min_dist = INF;

    for (int i = 1; i < n; i++) {
        if (!(visited & (1 << i)) && li[x][i] != 0) { // 방문 하지 않은 도시의 경우, 최소 비용을 갱신
            min_dist = min(min_dist, dfs(i, visited | (1 << i)) + li[x][i]);
        }
    }

    dp[x][visited] = min_dist;
    return min_dist;
}

int main()
{
    cin >> n;
    li.assign(n, vector<int>(n));
    dp.assign(n, vector<int>(1 << n, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> li[i][j];
        }
    }
	
    cout << dfs(0, 1) << "\n";

    return 0;
}
