/**
 * https://www.acmicpc.net/problem/9663
*/
#include <iostream>

using namespace std;
const int SIZE = 15;

int n, ans;
int queen_loc[SIZE];

/**
 * 현재 할당한 위치가 퀸의 위치로 가능한지 확인
*/
bool possible_loc(int r) {
    // 이전까지의 행(0~(r-1))들을 탐색
    for (int i = 0; i < r; i++) {
        if ((queen_loc[i] == queen_loc[r]) || // 같은 열 위치에 퀸이 존재할 경우
            (r - i == (abs(queen_loc[r] - queen_loc[i])))) { // 대각선 위치에 퀸이 존재할 경우
            return false; // 불가능
            }
    }
    return true;
}

/**
 * 각 행 당 하나의 퀸이 존재하므로 행마다 퀸을 하나씩 놓아본다.
 *
 * r: 현재 놓으려는 행
*/
void backtrack(int r) {
    // N개의 퀸이 모두 놓임 -> 재귀 호출 종료
    if (r == n) {
        ans++;
        return;
    }

    // c: 열
    for (int c = 0; c < n; c++) {
        // 행 위치에 열 값 할당
        queen_loc[r] = c;

        // 방금 할당한 위치가 문제없다면, 다음 행 검사
        if (possible_loc(r)) {
            backtrack(r + 1);
        }
    }
}

int main() {
    // 입력
    cin >> n;

    // 연산
    backtrack(0);

    // 출력
    cout << ans;

    return 0;
}
