#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> parent;
vector<int> cost;

int friendshipCost(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] < 0) { //루트 정점이라면
            //루트 정점의 친구비를 더해줌
            sum += cost[i];
        }
    }
    return sum;
}

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) { //값이 음수면 루트 정점
        return node;
    }
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) { //이미 같은 집합에 있는 경우
        return;
    }
    
    if (cost[xp] > cost[yp]) { //xp의 cost가 더 작게 만들기
        swap(xp, yp);
    }
    
    parent[yp] = xp;    //새로운 루트 xp
}

int main() {
    int n, m, k, v, w;

    //입력
    cin >> n >> m >> k;
    parent.assign(n + 1, -1);
    cost.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    while (m--) {
        cin >> v >> w;
        unionInput(v, w);
    }

    //연산
    int ans = friendshipCost(n);

    //출력
    cout << (ans <= k ? to_string(ans) : "Oh no"); //삼항 연산자 사용 시 자료형 맞춰야 함
    return 0;
}
