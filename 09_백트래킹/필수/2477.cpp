#include <iostream>

using namespace std;

pair<int, int> li[12];

int findArea() { // 육각형 모양의 영역 너비를 구하는 함수
    int big_square;
    int small_square;
    for (int i = 0; i < 9; i++) {
        if (li[i].first == li[i + 2].first && li[i + 1].first == li[i + 3].first) { // 같은 방향이 한 칸을 건너뛰고 나타나는 형태이면
            big_square = (li[i].second + li[i + 2].second) * (li[i + 1].second + li[i + 3].second); // 전체 사각형 갱신
            small_square = li[i + 2].second * li[i + 1].second; // 작은 사각형(영역이 없는 구역 갱신)
        }
    }
    return big_square - small_square;
}

int main() {
    int k;
    cin >> k;

    int direction, length;
    for (int i = 0; i < 6; i++) {
        cin >> direction >> length;
        li[i] = {direction, length};
    }

    for (int i = 0; i < 6; i++) { //어디서부터 입력이 들어오는지 모르기 때문에 6개 변을 추가해줌
        li[i + 6] = li[i];
    }

    int area = findArea();
    cout << k * area << "\n";
    
    return 0;
}