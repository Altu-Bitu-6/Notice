/**
 * https://www.acmicpc.net/problem/20437
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
const int ALPHA_NUM = 26;  // 알파벳 개수

/**
 * 문자열 w에서 어떤 문자를 정확히 k개 포함하는 연속 문자열 구하기
 * 그 중 "가장 짧은 문자열"과 "가장 길면서 처음과 끝이 같은 문자인 문자열"의 길이 쌍을 반환
*/
pair<int, int> game(string w, int k) {
    // 초기화
    vector<vector<int>> char_idx(ALPHA_NUM);  // 각 문자별로 w에서의 인덱스 배열

    int min_len = w.size();  // 가장 짧은 문자열 길이 초기화
    int max_len = -1;  // 가장 긴 문자열 길이 초기화

    for (int i = 0; i < w.size(); i++) {
        char_idx[w[i] - 'a'].push_back(i);  // w 속 문자들 인덱스를 배열에 저장
    }

    // 각 문자를 포함하는 문자열 확인
    for (int i = 0; i < ALPHA_NUM; i++) {
        int cnt = char_idx[i].size();

        // 해당 알파벳이 k번 이상 등장하지 않으면 탐색 X
        if (cnt < k) {
            continue;
        }

        // 포인터 초기화
        int left = 0, right = k - 1;  // 해당 알파벳 갯수 k개

        // 해당 알파벳 갯수(cnt)까지 탐색
        while (right < cnt) {
            int tmp_len = char_idx[i][right] - char_idx[i][left] + 1;  // 처음과 끝이 char_idx[i] 알파벳인 문자열의 길이
            min_len = min(min_len, tmp_len);
            max_len = max(max_len, tmp_len);
            left++;
            right++;
        }
    }

    return {min_len, max_len};
}

int main() {
    int t, k;
    string w;

    // 입력
    cin >> t;
    
    // t번 실행
    while (t--) {
        cin >> w >> k;

        // 연산
        pair<int, int> ans = game(w, k);

        // 출력
        if (ans.second == -1) {  // 만족하는 문자열이 없는 경우
            cout << -1 << '\n';
        } else {
            cout << ans.first << " " << ans.second << "\n";
        }
    }

    return 0;
}
