/**
 * https://www.acmicpc.net/problem/2473
*/
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = 3 * 1e9 + 1;

ll min_diff = INF;

/**
 * 세 용액 중 하나(fixed)는 고정하고, 나머지 두 용액을 투 포인터로 탐색
 * 앞은 중복이기 때문에 fixed 이후만 탐색
*/
pair<ll, ll> findLiquid(vector<ll> &liquid, ll fixed, int left, int right) {
    pair<ll, ll> ans = {INF, INF};

    while (left < right) {
        // 세 용액 혼합
        ll mix = fixed + liquid[left] + liquid[right];

        // 0이면 바로 리턴 (0에 제일 가까운 값이므로)
        if (mix == 0) {
            return {liquid[left], liquid[right]};
        }

        // 새로운 혼합 값이 현재 min_diff보다 0에 가깝다면 답 갱신
        if (abs(mix) < min_diff) {
            min_diff = abs(mix);
            ans = {liquid[left], liquid[right]};
        }

        // 투 포인터 이동
        if (mix > 0) {  // 0보다 크면 더 작은 값을 만들어야함 -> right 감소
            right--;
        } else {  // 0보다 작으면 더 큰 값을 만들어야함 -> left 증가
            left++;
        }
    }
    return ans;
}

/**
 * [세 용액]
 * 1. 하나의 용액을 반드시 사용한다고 가정 -> 용액 하나 고정
 * 2. 해당 용액 이후의 범위에 대해 투 포인터 알고리즘 적용
 * 주의! 세 용액의 최댓값은 1e9(=10억)이기 때문에 3개를 섞은 최댓값은 30억이므로, int를 넘어간다
*/
int main() {
    int n;

    // 입력
    cin >> n;
    vector<ll> liquid(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> liquid[i];
    }

    // liquid 오름차순 정렬
    sort(liquid.begin(), liquid.end());

    tuple<ll,ll,ll> ans;  // tuple : 3개의 값 지정
    // 0부터 n-2까지 고정 용액 지정 후 투포인터 탐색
    for (int i = 0; i < n - 2; i++) {
        pair<ll, ll> p = findLiquid(liquid, liquid[i], i + 1, n - 1);  // liquid[i] 용액 고정

        // 최솟값이 갱신된 경우 답 갱신
        if ((p.first != INF) && (p.second != INF)) {
            ans = {liquid[i], p.first, p.second};
        }
    }

    // 출력
    cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans);
    
    return 0;
}
