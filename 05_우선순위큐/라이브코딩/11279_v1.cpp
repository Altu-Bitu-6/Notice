#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, x;
	priority_queue<int> max_heap;

	//입력
	cin >> n;

	//연산 & 출력
	while (n--) {
		cin >> x;

		//x가 0인 경우 max_heap에서 가장 큰 값 출력
		if (x == 0) {
			//max_heap이 비어있는 경우 0 출력
			if (max_heap.empty()) {
				cout << "0\n";
			}
			else {
				cout << max_heap.top() << "\n";
				max_heap.pop();
			}
		}
		//x가 자연수인 경우 max_heap에 x 삽입
		else {
			max_heap.push(x);
		}
	}

	return 0;
}