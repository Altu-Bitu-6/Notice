/**
 * https://www.acmicpc.net/problem/2470
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
const int INF = 2e9 + 1;

/**
 * 서로 다른 위치에서 시작해서 서로를 향해 가까워지는 투 포인터
 * 두 용액의 합이 가장 0에 가까운 용액의 쌍 리턴
*/
ci findLiquid(int left, int right, vector<int> &liquid) {
    // 초기화
    ci ans = {0, 0}; // 합이 가장 0에 가까운 용액의 쌍
    int value = INF; // 0에 가장 가까운 값을 찾기 위해, INFINITE로 초기화

    // left는 항상 right 보다 작아야함 (두 포인터가 같은 용액을 가리키면 종료)
    while (left < right) {
        // 두 용액을 혼합
        int mix = liquid[left] + liquid[right];

        // 0이면 바로 종료. 가장 0에 가까운 값 = 0
        if (mix == 0) {
            return {liquid[left], liquid[right]};
        }

        // 현재 mix가 기준값인 value보다 0에 가까우면 갱신
        if (abs(mix) < value) {
            value = abs(mix);
            ans = {liquid[left], liquid[right]};
        }

        // mix가 0보다 크면 더 작은 값으로 만들어야함 -> right 왼쪽으로
        if (mix > 0) {
            right--;
        } else {  // mix가 0보다 작으면 더 큰 값으로 만들어야함 -> left 오른쪽으로
            left++;
        }
    }

    return ans;
}

int main() {
    int n;

    // 입력
    cin >> n;
    vector<int> liquid(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> liquid[i];
    }

    // liquid 배열 오름차순 정렬
    sort(liquid.begin(), liquid.end());

    // 0에 가장 가까운 용액을 만들어내는 두 용액 찾기
    ci answer = findLiquid(0, n - 1, liquid);

    // 오름차순으로 출력됨
    cout << answer.first << " " << answer.second;
    return 0;
}
