/**
 * https://www.acmicpc.net/problem/14888
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MAX_N = 11;
const int ADD = 0, SUB = 1, MUL = 2, DIV = 3;
const int EXP_NUM = 4;

int n;
int nums[MAX_N]; // 입력한 수열 저장
int expression[EXP_NUM]; // 입력한 연산자 개수 저장
int max_val = -INF, min_val = INF;

/**
 * 연산자를 하나씩, 총 (N-1)개 뽑는다.
 *
 * cnt: 뽑은 연산자의 개수
 * cur_val: 현재 연산 결과
*/
void backtrack(int cnt, int cur_val) {
    // (N-1)개의 연산자를 다 뽑은 경우 -> 재귀 호출 종료
    if (cnt == n - 1) {
        // 최댓값, 최솟값 갱신
        max_val = max(max_val, cur_val);
        min_val = min(min_val, cur_val);
        return;
    }

    // i: 연산자 번호
    for (int i = 0; i < EXP_NUM; i++) {
        // 해당 연산자가 0개면, 사용 불가
        if (expression[i] == 0) {
            continue;
        }

        // 연산자 사용
        expression[i]--;
        // 해당 연산자 연산 후, 재귀 호출
        switch(i) {
            case ADD:
                backtrack(cnt + 1, cur_val + nums[cnt + 1]);
                break;
            case SUB:
                backtrack(cnt + 1, cur_val - nums[cnt + 1]);
                break;
            case MUL:
                backtrack(cnt + 1, cur_val * nums[cnt + 1]);
                break;
            case DIV:
                backtrack(cnt + 1, cur_val / nums[cnt + 1]);
                break;
        }

        // 위의 재귀 호출 완료 시, 연산자 반납
        expression[i]++;
    }
}

int main() {
    // 입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < EXP_NUM; i++) {
        cin >> expression[i];
    }

    // 연산
    backtrack(0, nums[0]);

    // 출력
    cout << max_val << '\n' << min_val;

    return 0;
}
