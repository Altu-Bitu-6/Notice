#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inputSteps(int n) // 계단 점수 입력 처리 함수
{
    vector<int> num(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    return num;
}

int calculateMaxScore(const vector<int>& num, int n) // 계단 최대 점수 계산
{
    if (n == 1) {
        return num[0]; // 계단이 하나일 경우
    }
    else if (n == 2) {
        return num[0] + num[1]; // 계단이 두 개일 경우
    }
    else { // 계단이 세 개 이상일 경우
        vector<int> dp(n + 1);
        dp[0] = num[0]; // 첫 번째 계단 점수 갱신
        dp[1] = num[0] + num[1]; // 첫 번째와 두 번째 계단 전부 밟은 경우 갱신
        dp[2] = max(num[0] + num[2], num[1] + num[2]); // 첫 번째와 세 번째, 두 번째와 세 번째 계단을 밟은 경우 갱신
        for (int i = 3; i < n; i++) {
            dp[i] = max(dp[i - 3] + num[i - 1] + num[i], dp[i - 2] + num[i]);
        }
        return dp[n - 1];
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> num = inputSteps(n);
    cout << calculateMaxScore(num, n) << endl;

    return 0;
}
