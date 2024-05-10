/**
 * https://www.acmicpc.net/problem/21921
*/
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

/**
 * 슬라이딩 윈도우로 최대 방문자 수 (max_visitor)와 그 기간의 개수 (cnt_period)를 pair로 반환
*/
ci calcMaxVisitor(vector<int> &visitor, int n, int x) {
    // 초기화
    int cnt_visitor = 0; // 방문자 수 합
    int cnt_period = 1; // 방문자 수가 최대인 기간의 개수
    for  (int i = 0; i < x; i++) { // 첫날 ~ x일 동안 방문자 수
        cnt_visitor += visitor[i];
    }
    int max_visitor = cnt_visitor; // 최대 방문자 수

    // 슬라이딩
    for (int i = x; i < n; i++) { // 슬라이드 엔드 포인트
        // 윈도우 계산
        cnt_visitor -= visitor[i - x]; // 이번 윈도우에서 제외되는 값
        cnt_visitor += visitor[i]; // 이번 윈도우에서 추가되는 값

        // 답 갱신
        if (cnt_visitor > max_visitor) {
            max_visitor = cnt_visitor;
            cnt_period = 1;
        } else if (cnt_visitor == max_visitor) {
            cnt_period++;
        }
    }
    return {max_visitor, cnt_period};
}

int main() {
    int n, x;

    // 입력 n = 총 일수, x = 기간 길이
    cin >> n >> x;
    vector<int> visitor(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> visitor[i];
    }

    ci answer = calcMaxVisitor(visitor, n, x);

    if (answer.first == 0) {
        cout << "SAD\n";
        return 0;
    }

    cout << answer.first << '\n' << answer.second;
    return 0;
}
