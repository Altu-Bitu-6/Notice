/**
 * https://school.programmers.co.kr/learn/courses/30/lessons/42839
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAX_VAL = 1e8;
const int MAX_N = 7;

int n;
int ans = 0;
int nums[MAX_N];
bool is_used[MAX_N];  // i번 조각을 현재 사용중인지 확인용
bool is_counted[MAX_VAL];  // 숫자 i를 카운트 여부 확인용

/**
 * x가 소수인지 판별한다.
*/
bool isPrime(int x) {
    if (x == 0 || x == 1) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

/**
 * 총 N개가 될 때까지 종이 조각을 하나씩 뽑아서 이어 붙인다.
 * N개를 뽑는 중간 과정에서 만들어지는 수(1~ (N-1)개의 조각으로 만든)도 체크해주면서 지나가면,
 * 종이 조각들로 만들 수 있는 모든 수를 고려하게 된다.
 *
 * cnt: 현재까지 뽑은 종이 조각 개수
 * val: 현재까지 뽑은 종이 조각으로 만든 수
*/
void backtrack(int cnt, int val) {
    // 현재까지 만든 수가 소수인지 체크, 뽑지 않은 경우(cnt == 0) 제외
    if (cnt > 0 && !is_counted[val] && isPrime(val)) {
        ans++;
        is_counted[val] = true;
    }

    // 숫자 N개를 다 뽑은 경우 -> 재귀 호출 종료
    if (cnt == n) {
        return;
    }

    // i: 다음으로 뽑을 수 인덱스
    for (int i = 0; i < n; i++) {
        // 이미 사용한 조각이면 skip
        if (is_used[i]) {
            continue;
        }

        // 사용하지 않은 조각을 마지막 자리에 추가한 후, 백트래킹 호출
        is_used[i] = true;
        backtrack(cnt + 1, val * 10 + nums[i]);

        // 위의 백트래킹 재귀 호출 완료 시, 사용한 숫자 반납
        is_used[i] = false;
    }
}

int solution(string numbers) {
    // 입력 처리
    n = numbers.size();
    for (int i = 0; i < n; i++) {
        nums[i] = numbers[i] - '0';
    }

    // 연산
    backtrack(0, 0);

    return ans;
}

int main() {
    // 출력
    cout << solution("011");
    return 0;
}
