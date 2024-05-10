/**
 * https://www.acmicpc.net/problem/11659
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * 누적 합 구하기
*/
void calSum(int n, vector<int> &sum) {
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1]; // 이전 누적합에 현재 값 더하기 => 현재 누적합
    }
}

/**
 * i번째 수부터 j번째 수까지의 합 = (1~j까지의 누적합) - (1~i-1까지의 누적합)
*/
int getRangeSum(int i, int j, vector<int> &sum) {
    return sum[j] - sum[i - 1];
}


int main() {
    int n, m, i, j;

    // 입력
    cin >> n >> m;
    vector<int> sum(n + 1, 0);  // sum[0] = 0 으로 설정
    // i ~ n 배열에 초기 입력값 세팅
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
    }

    // 누적합 구하기
    calSum(n, sum);

    while (m--) {
        cin >> i >> j;
        // 출력
        cout << getRangeSum(i, j, sum) << "\n";
    }

    return 0;
}
