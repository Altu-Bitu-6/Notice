#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//오큰수 반환
vector<int> getNGE(int n, vector<int>& v) {
	vector<int> answer(n);
	stack<int> s;

	for (int i = 0; i < n; i++) {
		//새로 들어오는 값(오른쪽에 있는 값)이 해당 값보다 크면 해당값의 오큰수가 될 수 있음
		while (!s.empty() && v[s.top()] < v[i]) {
			answer[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	//스택에 남아있는 숫자들은 오큰수가 없으므로 -1 저장
	while (!s.empty()) {
		answer[s.top()] = -1;
		s.pop();
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	//연산
	vector<int> answer = getNGE(n, v);

	//출력
	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}

	return 0;
}