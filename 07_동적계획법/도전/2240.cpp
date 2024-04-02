#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int t, w;
    cin >> t >> w;

    vector<int> plum(t+1);

    for (int i = 1; i <= t; i++) {
        cin >> plum[i];
    }
    vector<vector<int> > dp(t + 1, vector<int>(w+1, 0));

    for (int i = 1; i <= t; i++) {
        if (plum[i] == 1) { //첫번째나무에서 자두가 떨어짐
            dp[i][0]=dp[i - 1][0] + 1; //한 번도 안움직이고, 자두가 떨어지는 경우
        }
        else {
            dp[i][0]=dp[i - 1][0]; // 한 번도 안움직이고, 자두가 떨어지는 경우
        }

        for (int j = 1; j <= w; j++) { 
            if (plum[i] == 2 && j % 2 == 1) { //2개밖에 없기 때문에, 홀수 번 움직이면 2번 나무에 있는 것
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + 1;
            }
            else if (plum[i] == 1 && j % 2 == 0) { // 짝수 번 움직이면 1번 나무에 있는 것
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + 1;
            }
            else { // 자두를 잡을 수 없는 경우
                dp[i][j] = max(dp[i - 1][j-1], dp[i - 1][j]);
            }
        }
    }
    
    cout << *max_element(dp[t].begin(),dp[t].end()) << "\n";

    return 0;
}
