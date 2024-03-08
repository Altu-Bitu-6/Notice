// 2231: 분해합 (브론즈2/브루트포스)
#include <iostream>

using namespace std;

int bruteforce(int n) {
    for (int i = 1; i < n; i++) {
        int tmp = i;
        int sum = i; // 분해합 저장
        while (tmp) { // i의 각 자리수를 sum에 더하기
            sum += tmp % 10; // tmp의 1의 자리수를 sum에 추가
            tmp /= 10;
        }
        if (sum == n) {
            return i;
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    cout << bruteforce(n);
    
    return 0;
}