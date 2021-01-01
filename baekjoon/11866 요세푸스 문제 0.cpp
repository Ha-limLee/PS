#include <iostream>

using namespace std;

#define visited true
#define yet false

void solve(bool arr[], int N, int K){
    int cur = 0;
    int count_visited = 0;
    cout << '<';
    while(true){
        for (int i = K; i > 0; --i){
            ++cur;
            if (cur > N)
                cur = cur % N;
            while(arr[cur] == visited){
                ++cur;
                if (cur > N)
                    cur = cur % N;
            }
        }
        arr[cur] = visited;
        ++count_visited;
        if (count_visited == N){
            cout << cur << '>';
            return;
        }
        cout << cur << ", ";
    }
}

int main(){
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    bool arr[1001] = {false,};

    solve(arr, N, K);

    return 0;
}