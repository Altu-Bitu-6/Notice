#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i]; // 입력 처리
    }

    vector<int> ans(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) { //현재 인덱스 이전 요소 모두 확인
            if (num[i] > num[j]) {
                ans[i] = max(ans[i], ans[j] + 1); // 최대 수열 길이 갱신
            }
        }
    }

    cout << *max_element(ans.begin(), ans.end()) << endl;

    return 0;
}
