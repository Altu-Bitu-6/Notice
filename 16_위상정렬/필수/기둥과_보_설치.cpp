#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 1001;
const int REMOVE = 0, ADD = 1;
const int VERTICAL = 0, HORIZONTAL = 1; // 기둥이 VERTICAL, 보는 HORIZONTAL

int N;
bool vertical[MAX][MAX]; // vertical[i][j]: (i,j)에 기둥이 존재하는지 여부
bool horizontal[MAX][MAX]; // horizontal[i][j]: (i,j)에 보가 존재하는지 여부

// validateVertical(x, y): (x,y)에 기둥을 놓을 수 있는지 확인
bool validateVertical(int x, int y) {
    if (y == 0) { // 바닥에
        return true;
    }
    if (horizontal[x][y]) { // 보의 왼쪽 끝 부분 위에
        return true;
    }
    if (x > 0 && horizontal[x-1][y]) { // 보의 오른쪽 끝 부분 위에
        return true;
    }
    if (vertical[x][y-1]) { // 다른 기둥 위에
        return true;
    }
    
    return false;
}

// validateHorizontal(x, y): (x,y)에 보를 놓을 수 있는지 확인
bool validateHorizontal(int x, int y) {
    if (vertical[x][y-1]) { // 왼쪽 끝이 기둥 위에
        return true;
    }
    if (x < N && vertical[x+1][y-1]) { // 오른쪽 끝이 기둥 위에
        return true;
    }
    if (x > 0 && horizontal[x-1][y] && x < N && horizontal[x+1][y]) { // 양쪽 끝 부분이 다른 보와 동시에 연결
        return true;
    }
    
    return false;
}

// validateAdjs(x, y): (x,y)에 인접한 기둥과 보들이 규칙을 만족하는지 확인
bool validateAdjs(int x, int y) {
    for (int i=x-1; i<=x+1; i++) {
        for (int j=y-1; j<=y+1; j++) {
            if (vertical[i][j] && !validateVertical(i, j)) {
                return false;
            }
            if (horizontal[i][j] && !validateHorizontal(i, j)) {
                return false;
            }
        }
    }
    return true;
}

void removeVertical(int x, int y) {
    vertical[x][y] = false;
    if (!validateAdjs(x, y)) {
        vertical[x][y] = true;
    }
}

void removeHorizontal(int x, int y) {
    horizontal[x][y] = false;
    if (!validateAdjs(x, y)) {
        horizontal[x][y] = true;
    }
}

void addVertical(int x, int y) {
    if (validateVertical(x, y)) {
        vertical[x][y] = true;
    }
}

void addHorizontal(int x, int y) {
    if (validateHorizontal(x, y)) {
        horizontal[x][y] = true;
    }
}

void remove(int x, int y, int a) {
    if (a == VERTICAL) {
        removeVertical(x, y);
    }
    else {
        removeHorizontal(x, y);
    }
}

void add(int x, int y, int a) {
    if (a == VERTICAL) {
        addVertical(x, y);
    }
    else {
        addHorizontal(x, y);
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;
    
    for (auto bf: build_frame) {
        int x = bf[0];
        int y = bf[1];
        int a = bf[2];
        int b = bf[3];
        
        if (b == REMOVE) {
            remove(x, y, a);
        }
        else {
            add(x, y, a);
        }
    }
    
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            if (vertical[i][j]) {
                answer.push_back({i, j, VERTICAL});
            }
            if (horizontal[i][j]) {
                answer.push_back({i, j, HORIZONTAL});
            }
        }
    }
    
    return answer;
}

/*
    1. 각 쿼리를 수행하는 함수를 만들어두고 순차적으로 처리
    2. 쿼리 수행 후에는 남은 구조물들이 규칙을 만족하는 지 확인
    3. 만약 규칙을 만족하지 않는다면 쿼리 수행 전으로 되돌리기
 */

int main() {
    int n = 5;
    vector<vector<int>> build_frame = {{1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1}};
    vector<vector<int>> answer = solution(n, build_frame);
    
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i][0] << "    " << answer[i][1] << "    " << answer[i][2] << "\n";
    }
    return 0;
}
