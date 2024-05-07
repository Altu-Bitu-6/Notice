// 3079: 입국심사 (골드 5/이분탐색, 매개 변수 탐색)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 모든 사람 m 명이 심사를 받는데 걸리는 최소 시간 구하기
 * 시간을 기준으로 각 시간마다 몇 명을 통과시킬 수 있는지 -> 만족하는 시간 중 최소값
*/
long long countPeople(long long n, long long mid, vector<long long> &time){
    // mid 시간에 검사할 수 있는 최대 인원 수
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += mid / time[i];
    }
    return cnt;
}

long long binarySearch(long long n, long long m, vector<long long> &time) {
    // 초기화
    long long left = 1;
    long long right = m * time[0];  // 심사 시간이 제일 짧은 데스크에 모든 사람이 검사 받는 경우를 최댓값으로 초기화
    long long mid;
    long long people;

    // 이분 탐색
    while (left <= right) {
        mid = (left + right) / 2;
        // mid에서 검사 가능 인원이 m 명 이상일 시 -> 조건 만족
        people = countPeople(n, mid, time);
        if (people >= m) {
            // 최솟값을 찾기 위해 mid 밑으로 이분탐색 진행
            right = mid - 1;
        } else {
            // mid에서 검사 가능 인원이 m 명 미만으로 조건 만족 X -> mid 위로 탐색
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    // 입력
    long long n, m;
    cin >> n >> m;
    vector<long long> time(n);
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }

    // 정렬
    sort(time.begin(), time.end());

    // 이분 탐색 후 출력
    cout << binarySearch(n, m, time);
    
    return 0;
}