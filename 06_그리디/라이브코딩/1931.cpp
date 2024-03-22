#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int main() {
    int n, cnt = 0;
    vector<pi> arr;
    cin >> n;
    arr.assign(n, {0, 0});

    //시간 입력 : 끝나는 시간 기준으로 문제를 푸므로 편의상 끝나는 시간을 first로 입력.
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second >> arr[i].first;
    }
    //끝나는 시간 오름차순으로 정렬.
    sort(arr.begin(), arr.end());

    int finish_conference = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].second < finish_conference) { //회의의 시작시간이 이전 회의의 종료시간보다 작을 때 == 빠를 때
            continue; //건너뛰기
        }
        finish_conference = arr[i].first; //회의 종료시간 갱신
        cnt++; //회의 수 추가 -> 카운트 증가.
    }

    //출력
    cout << cnt;
}