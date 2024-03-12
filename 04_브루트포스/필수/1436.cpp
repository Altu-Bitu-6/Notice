// 1436: 영화감독 숌 (실버5/브루트포스)
#include <iostream>

using namespace std;

/** 해당 수(cur)가 종말의 수인지 여부 반환 */
bool isValid(int cur) {
    while (cur >= 666) {
        if (cur % 1000 == 666) {
            return true;
        }
        cur /= 10;
    }
    return false;
}

int solution(int &n) {
    int cur = 666; // 현재 탐색하는 수
    int cnt = 0;   // 종말의 수 개수
    
    while (true) {
        if (isValid(cur)) {
            cnt++;
        }
        if (cnt == n) { // 현재 수가 n번재 종말의 수라면
            return cur;
        }
        cur++;
    }
}

/**[백준 1436: 영화감독 숌]
/* - 종말의 수: 6이 3개 연달아 나오는 수
/*   => 해당 수를 10으로 나눠가면서 현재 값을 1000으로 나눴을 때의 나머지가 666이면 종말의 수
/* - 첫번째 종말의 수인 666부터 1씩 늘려가며 해당 숫자가 종말의 수인지 판단
 */

int main() {
    int n;
    cin >> n;
    cout << solution(n);
    
    return 0;
}