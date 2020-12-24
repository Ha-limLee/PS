#include <iostream>

using namespace std;

int funcVer2(int N) {
    int first, min, max, diff;
    first = 1; min = 1; max = N; diff = 1;

    while (N != 1) {
        if (diff == 1) {
            if (N % 2 == 1) {
                first = max; min = min + 1; max = max - 1; N = N / 2 + 1; diff = diff + 1;
            }
            else {
                first = min + 1; min = min + 1; N = N / 2; diff = diff + 1;
            }
            continue;
        }

        if (N % 2 == 1) {
            if (first == min) {
                first = max; min = min + diff; max = max - diff; N = N / 2 + 1; diff = diff * 2;
            }
            else {
                first = max; max = max - diff; N = N / 2 + 1; diff = diff * 2;
            }
        }
        else {
            if (first == min) {
                first = min + diff; min = min + diff; N = N / 2; diff = diff * 2;
            }
            else {
                first = min; N = N / 2; diff = diff * 2;
            }
        }
    }
    return max;
}
int main() {
    int N;
    cin >> N;
    cout << funcVer2(N) << endl;
    
    return 0;
}

/*
결과
맞았습니다!!
1트에서 틀린 이유는 스택보단 로직을 틀린게 크다.
1트의 경우 main에서 함수를 한 번 호출하면 한 번만 반환하는게 아니라 여러번 한다.
조건문을 모두 if-else if로 묶어야 했다. if가 여러개여서 틀렸다.
*/