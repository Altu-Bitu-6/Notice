/**
 * https://www.acmicpc.net/problem/15665
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int m;
set<int> nums;  // 입력 받은 수 (정렬O, 중복X)
vector<int> sequence;

/**
 * 뽑은 수열 출력
*/
void printSequence() {
    for (int i = 0; i < m; i++) {
        cout << sequence[i] << ' ';
    }
    cout << '\n';
    return;
}

/**
 * 입력 받은 수에서 중복 수열을 만든다.
 *
 * cnt: 현재 뽑은 수의 개수
*/
void backtrack(int cnt) {
    // m개의 수를 모두 뽑음 -> 재귀 호출 종료
    if (cnt == m) {
        printSequence();
        return;
    }

    // 중복을 허용해서 하나씩 수를 뽑아 수열에 저장
    for (int num : nums) {
        sequence[cnt] = num;
        backtrack(cnt + 1);
    }
}

int main() {
    // 입력
    int n;
    cin >> n >> m;
    while (n--) {
        int num;
        cin >> num;
        nums.insert(num);
    }

    // 초기화
    sequence.assign(m, 0);

    // 연산
    backtrack(0);
}
