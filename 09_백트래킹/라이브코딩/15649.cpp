/**
 * https://www.acmicpc.net/problem/15649
*/
#include<iostream>

using namespace std;
const int MAX_N = 8;

int n, m;
int sequence[MAX_N]; // 선택된 숫자 수열 저장용
bool is_used[MAX_N + 1]; // 해당 숫자가 사용되었는지 확인용

/**
 * 수열 출력 함수
*/
void printSequence() {
    for (int i = 0; i < m; i++) {
        cout << sequence[i] << " ";
    }
    cout << "\n";
}

/**
 * 숫자를 하나 씩, 총 M개가 될 때까지 중복 없이 뽑는다.
 *
 * cnt: 현재까지 고른 숫자의 개수
*/
void backtrack(int cnt) {
    // M개의 숫자를 다 뽑은 경우 -> 결과 프린트 후 재귀 호출 종료
    if (cnt == m) {
        printSequence();
        return;
    }

    // i: 고르려는 수 (1~N 자연수), i를 1부터 순차적으로 탐색하므로 수열은 자동 오름차순 정렬된다.
    for (int i = 1; i <= n; i++) {
        // 이미 사용한 숫자라면, 사용 불가 (중복X 조건)
        if (is_used[i]) {
            continue;
        }

        // 선택한 숫자 기록
        sequence[cnt] = i;
        is_used[i] = true;

        // 다음 숫자 고르기
        backtrack(cnt + 1);

        // 위의 백트래킹 재귀 호출 종료 시, 숫자 i 사용 완료 반납
        is_used[i] = false;
    }
}

int main() {
    // 입력
    cin >> n >> m;

    // 백트래킹
    backtrack(0);

    return 0;
}
