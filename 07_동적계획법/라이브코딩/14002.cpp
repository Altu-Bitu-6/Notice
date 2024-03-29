#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,tmp,idx,len;
int a[1001],dp[1001];
vector<int> arr;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        len = 0;

        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) {
                len = max(dp[j], len);
            }
        }
        dp[i] = len + 1;

        if(tmp < dp[i]) {
            tmp = dp[i];
            idx = i;
        }
    }

    for(int i = idx;i >= 0;i--) {
        if(tmp == dp[i]) {
            arr.push_back(a[i]);
            tmp--;
        }
    }

    int size = arr.size();
    cout << size << "\n";

    for(int i = 0; i < size; i++) {
		cout << arr.back() << " ";
        arr.pop_back();
    }

    return 0;
}
