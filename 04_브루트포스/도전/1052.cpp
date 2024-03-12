// 1052: 물병 (골드5/비트마스킹)
#include <iostream>

using namespace std;

const int MAX = 26; // 2^26 = 67,108,864 > 10^7

/** n리터의 물을 담는 데 필요한 최소 물병 개수 */
int bitCount(int n) {
    int cnt = 0;
    for (int i = 0; i < MAX; i++) {
        if (n & (1 << i)) {
            cnt++;
        }
    }
    return cnt;
}

int minCount(int n, int k) {
    int required = 0;   // 상점에서 사야하는 최소 물병 개수
    while (true) {
        if (bitCount(n + required) <= k) {
            return required;
        }
        required++;
    }
}

/**[백준 1052: 물병]
 * - 같은 양의 물이 들어있는 물병 두 개를 합쳐 하나의 물병을 만듦
 *   => 각 물병이 담을 수 있는 물의 양은 모두 2의 거듭제곱!
 * - (1) n보다 크거나 같은 양의 물을
 *   (2) k개 이하의 물병에
 *   (3) 2의 거듭제곱만큼 씩 담으면 성공!
 * - 현재 양의 물을 담는 데 필요한 물병의 개수 = 물의 양을 이진수로 표현했을 때 1의 개수
 * - n에 1씩 추가해가면서 현재 양의 물을 담는 데 필요한 물병의 개수를 세고
 *   그 개수가 k보다 작거나 같으면 출력
 */

int main() {
    int n, k;

		// 입력
    cin >> n >> k;
    
		// 연산 & 출력
    cout << minCount(n, k);
    
    return 0;
}
