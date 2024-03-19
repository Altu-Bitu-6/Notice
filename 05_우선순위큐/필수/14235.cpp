#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, a, gift;
	priority_queue<int> pq;

	//입력
	cin >> n;

	//연산 & 출력
	while (n--) {
		cin >> a;

		//아이들을 만난 경우
		if (a == 0) {
			//줄 선물이 없는 경우
			if (pq.empty()) {
				cout << "-1\n";
			}
			//가치가 가장 큰 선물 주기
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		//선물 충전
		else {
			while (a--) {
				cin >> gift;
				pq.push(gift);
			}
		}
	}

	return 0;
}