#include <iostream>
#include <tuple>
#include <cmath>
using namespace std;
tuple<int, int, int> diet(int w0, int i0, int i, int a, int d, int t) {
    // w: 몸무게, m: 기초대사량
    int w1 = w0, m1 = i0; // 기초대사량 변화 고려 X
    int w2 = w0, m2 = i0; // 기초대사량 변화 고려 O

    while (d--) {
        // 체중 += 일일 에너지 섭취량 - 일일 에너지 소비량
        // 일일 에너지 소비량 = 일일 기초 대사량 + 일일 활동 대사량
        w1 += i - (m1 + a);
        w2 += i - (m2 + a);

        // 일일 기초대사량 변화 (m2만 변화)
        if (abs(i - (m2 + a)) > t) {
            // [주의] 음수의 나눗셈에 주의: ⌊−5 / 2⌋를 수행하면 3이 나와야 하지만
            //                              C++에서 int i = (-5) / 2를 수행할 경우 -2가 나옴
            //                              => float끼리의 나눗셈으로 수행하고 소숫점 버림
            m2 += float(i - (m2 + a)) / 2.0;
        }
    }
    return {w1, w2, m2};
}
int main() {
    int w0, i0, i, a;
    int d, t;
    int final_weight, final_meta;
    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;

    tuple<int, int, int> tmp = diet(w0, i0, i, a, d, t);
    int w1 = get<0>(tmp), m1 = i0;          // 기초대사량 변화 고려 X
    int w2 = get<1>(tmp), m2 = get<2>(tmp); // 기초대사량 변화 고려 O 

    if (w1 <= 0) {
        // m1은 i0에서 변화하지 않고, i0는 0보다 크므로 기초대사량이 0kcal 이하가 되지 않음
        cout << "Danger Diet\n";
    } else {
        cout << w1 << " " << m1 << "\n";
    }

    if (w2 <= 0 || m2 <= 0) {
        cout << "Danger Diet";
    } else {
        cout << w2 << " " << m2 << " ";
        if (m2 < i0) {
            cout << "YOYO";
        } else {
            cout << "NO";
        }
    }
    return 0;
}