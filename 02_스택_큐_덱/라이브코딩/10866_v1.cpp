#include <iostream>
#include <vector>

#define MAX_SIZE 10000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; //명령의 수
    cin >> n;

    vector<int> arr(MAX_SIZE); //덱 선언
    int front = 0, back = 0;

    string cmd;
    int x;

    while (n--) {
        cin >> cmd; //명령 입력

        //push_front: 덱의 front에 x 삽입
        if (cmd == "push_front") {
            cin >> x;
            front = (front + 1) % MAX_SIZE;
            arr[front] = x;
        }

        //push_back: 덱의 back에 x 삽입
        else if (cmd == "push_back") {
            cin >> x;
            arr[back] = x;
            back = (back - 1 + MAX_SIZE) % MAX_SIZE;
        }

        //pop_front: 덱에서 front 원소 삭제하고 출력
        else if (cmd == "pop_front") {
            if (front == back) { //덱이 비어 있을 시 -1 리턴
                cout << "-1\n";
            }
            else {
                cout << arr[front] << "\n";
                front = (front - 1 + MAX_SIZE) % MAX_SIZE;
            }
        }

        //pop_back: 덱에서 back 원소 삭제하고 출력
        else if (cmd == "pop_back") {
            if (front == back) { //덱이 비어 있을 시 -1 리턴
                cout << "-1\n";
            }
            else {
                back = (back + 1) % MAX_SIZE; 
                cout << arr[back] << "\n";
            }
        }

        //size: 덱의 크기 출력
        else if (cmd == "size") {
            cout << (front + MAX_SIZE - back) % MAX_SIZE << "\n";
        }

        //empty: 덱이 비어있는지 확인
        else if (cmd == "empty") {
            cout << (front == back) << "\n";
        }

        //front: 덱의 front 출력
        else if (cmd == "front") {
            if (front == back) { //덱이 비어 있을 시 -1 리턴
                cout << "-1\n";
            }
            else {
                cout << arr[front] << "\n";
            }
        }

        //back: 덱의 back 출력
        else if (cmd == "back") {
            if (front == back) { //덱이 비어 있을 시 -1 리턴
                cout << "-1\n";
            }
            else {
                cout << arr[(back + 1) % MAX_SIZE] << "\n";
            }
        }
    }
    
    return 0;
}