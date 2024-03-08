// 1091: 배고파(Easy) (브론즈1/비트마스킹)
#include <iostream>

using namespace std;

typedef long long ll;
const int MAX = 60;

pair<int, int> getPair(ll m) {
    int x, y;
    
    // m이 2의 제곱수인 경우 (m == 2^i)
    // m = 2^(i-1) + 2^(i-1) (x == y == i)
    for (ll i = 1; i < MAX; i++) {
        if (m == ((ll)1 << i)) {
            return {i - 1, i - 1};
        }
    }
    
    // m이 2의 제곱수가 아닌 경우
    // m = 2^x + 2^y (x < y)
    for (x = 0; x < MAX; x++) {
        if (m & ((ll)1 << x)) {
            m -= (ll)1 << x;
            break;
        }
    }

    for (y = x + 1; y < MAX; y++) {
        if (m & ((ll)1 << y)) {
            break;
        }
    }
    return {x, y};
}

int main() {
    int n;
    ll m;
    
    cin >> n;
    while (n--) {
        cin >> m;
        pair<int, int> ans = getPair(m);
        cout << ans.first << " " << ans.second << "\n";
    }
    
    return 0;
}