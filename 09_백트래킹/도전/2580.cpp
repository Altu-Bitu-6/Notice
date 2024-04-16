/**
 * https://www.acmicpc.net/problem/2580
*/
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 9;

bool is_finished;
int sudoku[MAX][MAX];
bool is_in_row[MAX][MAX + 1]; // r번 행에 n이 존재하는지 여부
bool is_in_col[MAX][MAX + 1]; // c번 열에 n이 존재하는지 여부
bool is_in_square[MAX][MAX + 1]; // s번 정사각형에 n이 존재하는지 여부

/**
 * (r, c)가 속한 3*3 정사각형의 번호를 리턴
*/
int calcSquare(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

/**
 * 스도쿠 채우기
 * r번 행, c번 열, (r, c)가 속한 정사각형에 n이 존재함을 표시한다.
*/
void fill(int r, int c, int n) {
    sudoku[r][c] = n;
    is_in_row[r][n] = true;
    is_in_col[c][n] = true;
    is_in_square[calcSquare(r, c)][n] = true;
}

/**
 * (r, c)에 숫자 n을 놓을 수 있는지 확인한다.
*/
bool check(int r, int c, int n) {
    return !is_in_row[r][n] && !is_in_col[c][n] && !is_in_square[calcSquare(r, c)][n];
}

/**
 * 스도쿠에 숫자 빼기
 * r번 행, c번 열, (r, c)가 속한 정사각형에 n이 없다고 표시한다.
*/
void empty(int r, int c) {
    int n = sudoku[r][c];
    sudoku[r][c] = 0;
    is_in_row[r][n] = false;
    is_in_col[c][n] = false;
    is_in_square[calcSquare(r, c)][n] = false;
}

/**
 * (0, 0)부터 차례로 빈칸을 채워나간다.
 *
 * idx: 왼쪽 상단부터 매긴 칸 번호, (row * 9) + col
*/
void fillSudoku(int idx) {
    // 스도쿠 판을 다 채운 경우 -> 재귀 호출 종료
    if (idx == MAX * MAX) {
        is_finished = true;
        return;
    }

    int r = idx / MAX;
    int c = idx % MAX;

    // 빈칸이 아닌 경우
    if (sudoku[r][c] != 0) {
        // 바로 다음 칸 탐색
        fillSudoku(idx + 1);
    }
    // 빈칸인 경우
    else {
        // i: 이번 빈칸에 넣을 수 (1~9)
        for (int i = 1; i <= MAX; i++) {
            // 불가능한 경우 skip
            if (!check(r, c, i)) {
                continue;
            }

            fill(r, c, i);  // (r, c)에 i
            fillSudoku(idx + 1);  // 다음 칸 채우기
            // 스도쿠 채우기에 성공했으면 종료
            if (is_finished) {
                return;
            }
            // 스도쿠 채우기에 성공하지 못했으면, (r, c)에 i 반납
            empty(r, c);
        }
    }



}

int main() {
    int n;

    // 입력
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> n;
            fill(i, j, n);
        }
    }

    // 연산
    fillSudoku(0);

    // 출력
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cout << sudoku[i][j] <<  " ";
        }
        cout << '\n';
    }

    return 0;
}
