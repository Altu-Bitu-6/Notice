/**
 * https://www.acmicpc.net/problem/1063
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef pair<char, char> cc;

/**
 * input에 따라 이동한다.
*/
cc move(string input, char x, char y) {
    for (char how : input) {
        if (how == 'R') {
            x++;
        } else if (how == 'L') {
            x--;
        } else if (how == 'B') {
            y--;
        } else {  // (how == 'T')
            y++;
        }
    }
    return {x, y};
}

/**
 * 두 좌표의 위치가 일치하는지 확인한다.
*/
bool isSame(cc k, cc s) {
    return (k.first == s.first && k.second == s.second);
}

/**
 * 체스판 범위를 넘어서는지 확인한다.
*/
bool checkRange (cc pos) {
    if (pos.first < 'A' || pos.first > 'H' || pos.second < '1' || pos.second > '8') {
        return false;
    }
    return true;
}

int main() {
    cc k, s;  // king, stone 위치
    int n;
    string input;

    // 입력
    cin >> k.first >> k.second >> s.first >> s.second >> n;

    // 연산
    while (n--) {
        cin >> input;

        cc next_k, next_s;

        // king 이동
        next_k = move(input, k.first, k.second);

        // stone 이동
        if (isSame(next_k, s)) {  // 이동한 king과 stone 위치가 일치하면
            // king이 움직인 방향과 같은 방향으로 이동
            next_s = move(input, s.first, s.second);
        }
        else {
            next_s = s;
        }

        // 체스판 밖으로 나가지 않을 경우만 이동
        if (checkRange(next_k) && checkRange(next_s)) {
            k = next_k;
            s = next_s;
        }
    }

    // 출력
    cout << k.first << k.second << '\n' << s.first << s.second;

    return 0;
}
