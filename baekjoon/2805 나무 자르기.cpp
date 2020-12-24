#include <iostream>
#include <algorithm>

using namespace std;

long long maxHeight(int* numArr, int arrSize, int required) {
    long long min = 0;
    long long max = numArr[arrSize - 1];
    long long height = -1;

    long long result = 0;

    while (min <= max) {
        result = 0;
        height = (min + max + 1) / 2;

        for (int i = 0; i < arrSize; ++i) {
            if (numArr[i] > height) {
                result += numArr[i] - height;
            }
        }

        if (result > required) {
            min = height + 1;
        }
        else if (result < required) {
            max = height - 1;
        }
        else break;

        if (min > max) {
            result = 0;
            for (int i = 0; i < arrSize; ++i) {
                if (numArr[i] > height) {
                    result += numArr[i] - height;
                }
            }
            if (result >= required)
                break;
            else
                return max;
        }
    }
    return height;
}

int main() {
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    int* numArr = new int[N];

    for (int i = 0; i < N; ++i) {
        cin >> numArr[i];
    }

    stable_sort<int*>(numArr, numArr + N);

    cout << maxHeight(numArr, N, M);

    delete[] numArr;

    return 0;
}