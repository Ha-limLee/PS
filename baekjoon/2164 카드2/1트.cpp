#include <iostream>

using namespace std;

    
/*
    oddCaseInit(arr, int N){
    arr[0] = N;
    for (int i = 1; i <= N/2; ++i){
        arr[i] = i*2;
    }
}
arr func(arr, ȣ��Ƚ��, ����){
    if (���� == 1){
        return arr[0];
    }
    else if (���� == 3 || ���� == 2){
        return arr[1];
    }

    if (������ Ȧ��){
        ��arr[0] = ����arr[����-1];
        int j = 1;
        for (int i = 1; i < ����; i+2){
            ��arr[j++] = ����arr[i];
        }
        func(��arr, ȣ��Ƚ��+1, �� ����);
    }
    else {
        int j = 0;
        for (int i = 1; i< ����; i+2){
            ��arr[j] = ����arr[i];
        }
    }
}
auto func(arr, ȣ��Ƚ��, ����){
    
    if (������ Ȧ��){
        ��arr[0] = pop(����arr[����-1]);
        ��arr[1~] = �ּ�n�ִ�(����arr[1~], ������ ȣ��Ƚ��+1);
        func(��arr, ȣ��Ƚ��+1, ����/2 + 1);
    }
    else{
        ��arr[0~] = �ּ�n�ִ�(����arr[1~], ������ ȣ��Ƚ��+1);
        func(��arr, ȣ��Ƚ��+1, ����/2);
    }
}
auto func(����, min, max, ����, ���� = 1){
    if (���� == 1){
        return max;
    }

    if (���� == 1){
        if (������ Ȧ��){
            func(max, min+1, max-1, ����/2 + 1, ����+1);
        }
        else {
            func(min+1, min+1, max, ����/2, ����+1);
        }
    }
    if (������ Ȧ��){
        if (���� == min){
            func(max, min+����, max-����, ����/2 + 1, ����*2);
        }
        else func(max, min, max-����, ����/2 + 1, ����*2);
    }
    else{
        if (���� == min){
            func(min+����, min+����, max, ����/2, ����*2);
        }
        else func(min, min, max, ����/2, ����*2);
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
���
�޸� �ʰ�
���� ����?
*/