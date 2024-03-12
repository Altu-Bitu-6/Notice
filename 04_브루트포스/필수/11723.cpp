// 11723: 집합 (실버5/비트마스킹)
#include <iostream>

using namespace std;

/**[백준 11723] 집합
/* - vector나 map으로 각 원소의 유무를 판단할 경우 시간초과 발생!
/*   => 총 원소의 개수는 20. 32비트 크기 int의 각 bit에 원소의 유무를 저장
/* - value의 i번째 bit가 1이면: 현재 집합에 i 존재 O
/* - value의 i번째 bit가 1이면: 현재 집합에 i 존재 X
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, x, value = 0;
    string op;
    cin >> m;
    while (m--) {
        cin >> op;

				// x 피연산자가 입력되지 않는 연산자: all, empty
        if (op == "all") {
            for (int i = 1; i <= 20; i++) {
                value = value | (1 << i);
            }
        }
        else if (op == "empty") {
            value = 0;
        }

				// x 피연산자가 입력되는 연산자: add, remove, check, toggle
        else {
            cin >> x;
            if (op == "add") {
                value = value | (1 << x);
            }
            else if (op == "remove") {
                value = value & ~(1 << x);
            }
            else if (op == "check") {
                if (value & (1 << x)) {
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
            }
            else if (op == "toggle") {
                value = value ^ (1 << x);
            }
        }
    }
    return 0;
}