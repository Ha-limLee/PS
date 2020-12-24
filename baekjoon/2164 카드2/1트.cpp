#include <iostream>

using namespace std;

    
/*
    oddCaseInit(arr, int N){
    arr[0] = N;
    for (int i = 1; i <= N/2; ++i){
        arr[i] = i*2;
    }
}
arr func(arr, 호출횟수, 개수){
    if (개수 == 1){
        return arr[0];
    }
    else if (개수 == 3 || 개수 == 2){
        return arr[1];
    }

    if (개수는 홀수){
        새arr[0] = 기존arr[개수-1];
        int j = 1;
        for (int i = 1; i < 개수; i+2){
            새arr[j++] = 기존arr[i];
        }
        func(새arr, 호출횟수+1, 새 개수);
    }
    else {
        int j = 0;
        for (int i = 1; i< 개수; i+2){
            새arr[j] = 기존arr[i];
        }
    }
}
auto func(arr, 호출횟수, 개수){
    
    if (개수는 홀수){
        새arr[0] = pop(기존arr[개수-1]);
        새arr[1~] = 최소n최대(기존arr[1~], 간격은 호출횟수+1);
        func(새arr, 호출횟수+1, 개수/2 + 1);
    }
    else{
        새arr[0~] = 최소n최대(기존arr[1~], 간격은 호출횟수+1);
        func(새arr, 호출횟수+1, 개수/2);
    }
}
auto func(초항, min, max, 개수, 간격 = 1){
    if (개수 == 1){
        return max;
    }

    if (간격 == 1){
        if (개수는 홀수){
            func(max, min+1, max-1, 개수/2 + 1, 간격+1);
        }
        else {
            func(min+1, min+1, max, 개수/2, 간격+1);
        }
    }
    if (개수는 홀수){
        if (초항 == min){
            func(max, min+간격, max-간격, 개수/2 + 1, 간격*2);
        }
        else func(max, min, max-간격, 개수/2 + 1, 간격*2);
    }
    else{
        if (초항 == min){
            func(min+간격, min+간격, max, 개수/2, 간격*2);
        }
        else func(min, min, max, 개수/2, 간격*2);
    }
}
*/
int func(int first, int min, int max, int N, int diff = 1) {
    if (N == 1) return max;

    if (diff == 1) {
        if (N % 2 == 1) func(max, min + 1, max - 1, N / 2 + 1, diff + 1);
        else func(min + 1, min + 1, max, N / 2, diff + 1);
    }

    if (N % 2 == 1) {
        if (first == min) func(max, min + diff, max - diff, N / 2 + 1, diff * 2);
        else func(max, min, max - diff, N / 2 + 1, diff * 2);
    }
    else {
        if (first == min) func(min + diff, min + diff, max, N / 2, diff * 2);
        else func(min, min, max, N / 2, diff * 2);
    }
}

int main() {
    int N;
    cin >> N;
    cout << func(1, 1, N, N);
    
    return 0;
}

/*
결과
메모리 초과
스택 터짐?
*/