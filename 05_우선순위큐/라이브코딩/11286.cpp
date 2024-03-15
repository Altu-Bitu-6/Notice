#include <iostream>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(const int& x1, const int& x2) {
		//절댓값이 다른 경우 절댓값이 작은 수를 앞으로
		if (abs(x1) != abs(x2)) {
			return abs(x1) > abs(x2);
		}
		//절댓값이 같은 경우 값이 작은 수를 앞으로
		return x1 > x2;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, x;
	priority_queue<int, vector<int>, cmp> pq;

	//입력
	cin >> n;

	//연산 & 출력
	while (n--) {
		cin >> x;

		//x가 0인 경우 절댓값이 가장 작은 값 출력
		if (x == 0) {
			//pq가 비어있는 경우 0 출력
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		//x가 0이 아닌 경우 pq에 x 삽입
		else {
			pq.push(x);
		}
	}

	return 0;
}