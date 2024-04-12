/**
 * https://www.acmicpc.net/problem/2529
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<bool> check(10, false); // 0부터 10까지의 정수 중복 체크용
vector<int> choose;
string max_num = "0123456789"; // 최솟값으로 초기화
string min_num = "9876543210"; // 최댓값으로 초기화

/**
 * 선택한 숫자들(choose)을 문자열로 반환한다.
*/
string chooseToString() {
    string num = "";
    for (int i = 0; i < choose.size(); i++) {
        num += to_string(choose[i]);
    }
    return num;
}

/**
 * 최댓값, 최솟값 갱신
*/
void updateAnswer() {
    string num = chooseToString(); // 현재 선택한 숫자
    max_num = max(max_num, num);
    min_num = min(min_num, num);
}

/**
 * 부등호 방향에 맞게 k + 1개의 수를 뽑는다.
 *
 * brackets: 부등호가 담긴 벡터
 * cnt: 현재 뽑은 수의 개수
*/
void findMinMax(vector<char> brackets, int cnt) {
    // k + 1개의 숫자를 다 뽑은 경우 -> 재귀 호출 종료
    if (cnt == brackets.size() + 1) {
        // 최댓값, 최솟값 갱신
        updateAnswer();
        return;
    }

    // i: 고르려는 수 (0~9 사이의 정수)
    for (int i = 0; i < 10; i++) {
        // 이미 선택한 숫자인 경우 skip
        if (check[i]) {
            continue;
        }

        // 선택한 숫자 저장
        check[i] = true;
        choose.push_back(i);

        if (cnt == 0 ||  // 처음 숫자를 뽑는 경우
            (brackets[cnt - 1] == '<' && choose[choose.size() - 2] < i) ||  // (이전 숫자 < 현재 숫자)인 경우
            (brackets[cnt - 1] == '>' && choose[choose.size() - 2] > i)) {  // (이전 숫자 > 현재 숫자)인 경우
            findMinMax(brackets, cnt + 1);
        }

        // 위의 백트래킹 재귀 호출 종료 시, 숫자 i 사용 완료 반납
        check[i] = false;
        choose.pop_back();
    }
}

int main() {
    int k;

    // 입력
    cin >> k;
    vector<char> brackets(k, '<');
    for (int i = 0; i < k; i++) {
        cin >> brackets[i];
    }

    // k + 1자리 수에 맞게 최댓값, 최솟값 조정
    min_num = min_num.substr(0, k + 1);
    max_num = max_num.substr(0, k + 1);

    findMinMax(brackets, 0);

    // 출력
    cout << max_num << '\n' << min_num;

    return 0;
}
