#include <string>
#include <vector>
#include <set>

using namespace std;

//프로그래머스의 솔루션 함수를 그대로 옮김.
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> clothes_cnt (n+1, 1); //옷의 개수를 저장하는 벡터. 초기 설정값 1.
    
    //잃어버린 인덱스 -> --
    for (int i = 0; i < lost.size(); i++) {
        clothes_cnt[lost[i]]--;    
    }    
    //여벌 인덱스 -> ++
    for (int i = 0; i < reserve.size(); i++) {
        clothes_cnt[reserve[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (clothes_cnt[i]) { //체육복 개수 >= 1일 때 -> 스킵
            continue;
        }
        
        //아닐 시 -> 앞뒤에 여벌을 가져온 사람이 있는지 확인하고, 있을 시 자기 +1, 여벌 -1.
        if (clothes_cnt[i-1] == 2) { 
            clothes_cnt[i]++;
            clothes_cnt[i-1]--;
        } else if (clothes_cnt[i+1] == 2) {
            clothes_cnt[i]++;
            clothes_cnt[i+1]--;
        }
    }
    
    //체육복 개수 >=1 -> 정답++.
    for (int i = 1; i <= n; i++) {
        if (clothes_cnt[i]) {
            answer++;
        }
    }
    
    return answer;
}