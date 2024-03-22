#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, cnt = 0;
    vector<int> v;

    //입력
    cin >> n >> k;
    //동전 가치 개수만큼 벡터 크기 할당
    v.assign(n, 0);

    //동전 가치 입력
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    while (n--) { //큰 가치부터 검사하기 (동전 개수의 '최솟값'을 구해야하므로)
        cnt += k/v[n];
        k %= v[n];
    }

    //출력
    cout << cnt;
}