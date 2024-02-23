#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; //명령의 수
    cin >> n;

    queue<int> q; //큐 선언

    string cmd;
    int x;

    while (n--) {
        cin >> cmd; //명령 입력

        //push: 큐에 x 삽입
        if (cmd == "push") {
            cin >> x;
            q.push(x);
        }

        //pop: 큐에서 front 원소 삭제하고 출력
        else if (cmd == "pop") {
            if (q.empty()) { //큐가 비어 있을 시 -1 리턴
                cout << "-1\n"; 
            }
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }

        //size: 큐의 크기 출력
        else if (cmd == "size") {
            cout << q.size() << "\n";
        }

        //empty: 큐가 비어있는지 확인
        else if (cmd == "empty") {
            cout << q.empty() << "\n";
        }

        //front: 큐의 front 출력
        else if (cmd == "front") {
            if (q.empty()) { //큐가 비어 있을 시 -1 리턴
                cout << "-1\n";
            }
            else {
                cout << q.front() << "\n";
            }
        }

        //back: 큐의 back 출력
        else if (cmd == "back") {
            if (q.empty()) { //큐가 비어 있을 시 -1 리턴
                cout << "-1\n";
            }
            else {
                cout << q.back() << "\n";
            }
        }
    }
    
    return 0;
}