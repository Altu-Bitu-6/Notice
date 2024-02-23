#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; //명령의 수
    cin >> n;

    deque<int> dq; //덱 선언

    string cmd;
    int x;

    while (n--) {
        cin >> cmd; //명령 입력

        //push_front: 덱의 front에 x 삽입
        if (cmd == "push_front") {
            cin >> x;
            dq.push_front(x);
        }

        //push_back: 덱의 back에 x 삽입
        else if (cmd == "push_back") {
            cin >> x;
            dq.push_back(x);
        }

        //pop_front: 덱에서 front 원소 삭제하고 출력
        else if (cmd == "pop_front") {
            if (dq.empty()) { //덱이 비어 있을 시 -1 리턴
                cout << "-1\n";
            }
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }

        //pop_back: 덱에서 back 원소 삭제하고 출력
        else if (cmd == "pop_back") {
            if (dq.empty()) { //덱이 비어 있을 시 -1 리턴
                cout << "-1\n";
            }
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }

        //size: 덱의 크기 출력
        else if (cmd == "size") {
            cout << dq.size() << "\n";
        }

        //empty: 덱이 비어있는지 확인
        else if (cmd == "empty") {
            cout << dq.empty() << "\n";
        }

        //front: 덱의 front 출력
        else if (cmd == "front") {
            if (dq.empty()) { //덱이 비어 있을 시 -1 리턴
                cout << "-1\n";
            }
            else {
                cout << dq.front() << "\n";
            }
        }

        //back: 덱의 back 출력
        else if (cmd == "back") {
            if (dq.empty()) { //덱이 비어 있을 시 -1 리턴
                cout << "-1\n";
            }
            else {
                cout << dq.back() << "\n";
            }
        }
    }
    
    return 0;
}