// 2309: 일곱난쟁이 (브론즈1/브루트포스, 정렬)
#include <iostream>
#include <vector>
#include <algorithm> // sort()

using namespace std;

const int CNT = 9;

void select(vector<int> &arr) {
    int sum = 0;
    for (int i = 0; i < CNT; i++) {
        sum += arr[i];
    }
    
    for (int i = 0; i < CNT - 1; i++) {
        for (int j = i + 1; j < CNT; j++) {
            if (sum - (arr[i] + arr[j]) == 100) {
								// i < j. arr[i]를 먼저 삭제할 경우 arr[j] 값이 arr[j-1]로 옮겨짐
                arr.erase(arr.begin() + j);
                arr.erase(arr.begin() + i);
                return;
            }
        }
    }
}

int main() {
    vector<int> arr(CNT);
    for (int i = 0; i < CNT; i++) {
        cin >> arr[i];
    }
    
    select(arr);
    sort(arr.begin(), arr.end()); // 오름차순 출력
    
    for (auto it : arr) {
        cout << it << "\n";
    }
    
    return 0;
}