#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
HINT: 현재 시각에서 요청된 task 중 소요시간이 가장 적은 task를 우선으로 실행해야 해요!
시간이 흘러감에 따라 수행돼야 하는 기능을 생각해보세요!
*/

//소요시간이 작은 순으로 sort
struct sortMinTime {
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int curt_time = 0; //현재 시간
	int total_time = 0; //대기 시간
	int next_job = 0; //다음으로 요청되는 task의 번호
	int job_cnt = jobs.size();

	//소요시간이 작은 task가 top이 되는 우선순위 큐
	priority_queue<vector<int>, vector<vector<int>>, sortMinTime> pq;

	sort(jobs.begin(), jobs.end()); //요청시간 순으로 sort

	//job이나 pq가 끝날 때까지 실행
	while (next_job < job_cnt || !pq.empty()) {
		//현재 요청된 task가 없지만 task가 남아있는 경우
		if (pq.empty()) {
			curt_time = jobs[next_job][0]; //현재시간을 가장 빠른 task의 요청시간으로 변경
			pq.push(jobs[next_job++]);
		}

		//현재 요청된 task 중 소요시간이 가장 빠른 task 수행
		vector<int> curt_job = pq.top();
		pq.pop();

		total_time += ((curt_time - curt_job[0]) + curt_job[1]); //(요청부터 실행까지 delay된 시간) + (작업의 소요시간)
		curt_time += curt_job[1];

		//현재 시간까지 요청된 task를 pq에 삽입
		while (next_job < job_cnt && jobs[next_job][0] <= curt_time) {
			pq.push(jobs[next_job++]);
		}
	}
	answer = int(total_time / job_cnt);
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	vector<vector<int>> jobs(n, vector<int>(2)); //jobs[i]: { i 작업이 요청되는 시점, i 작업의 소요시간 }

	//입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> jobs[i][0] >> jobs[i][1];
	}

	//연산 & 출력
	cout << solution(jobs);

	return 0;
}