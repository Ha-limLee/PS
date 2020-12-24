#include <iostream>

using namespace std;

int play(int* numbers, int N, int M){
    int result = 0;
    int sum = 0;
    for (int i = 0; i < N-2; ++i){
        for (int j = i+1; j < N-1; ++j){
            for (int k = j+1; k < N; ++k){
                sum = numbers[i] + numbers[j] + numbers[k];
                if (sum == M) return sum;
                else if (sum > M) continue;

                if (result == 0) result = sum;
                else if (result < sum) result = sum;
            }
        }
    }
    return result;
}

int main(){
    
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    
    int numbers[100];
    for (int i = 0; i < N; ++i){
        cin >> numbers[i];
    }

    cout << play(numbers, N, M);
    
    return 0;
}