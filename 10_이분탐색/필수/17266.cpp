/**
 * https://www.acmicpc.net/problem/17266
*/
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> light; // 가로등 위치 저장
int ans;

/**
 * 굴다리 전체를 비추는지 확인
*/
bool check(int length) {
    if (light[0] > length) {  // 첫 번째 가로등 처리
        return false;
    }

    for (int i = 1; i < M; i++) {
        if (light[i] - light[i - 1] > 2 * length) {
            return false;
        }
    }

    if (N - light[M - 1] > length) {  // 마지막 가로등 처리
        return false;
    }

    return true;
}

/**
 * 이분 탐색 함수
*/
void binary_search() {
    // 초기화
    int start = 0;
    int end = N;
    int mid = (start + end) / 2;

    while (start <= end) {
        // mid가 조건에 부합한다면
        if (check(mid)) {
            ans = mid; // 정답 처리
            // 더 짧은 길이로 다음 탐색
            end = mid - 1;
        } else {
            // 조건에 부합하지 않는다면, 더 긴 길이로 다음 탐색
            start = mid + 1;
        }

        mid = (start + end) / 2;
    }
}

int main() {
    // 입력
    cin >> N >> M;
    light.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> light[i];
    }

    // 연산
    binary_search();

    // 출력
    cout << ans;

    return 0;
}
