#include <iostream>
#include <cmath>

using namespace std;
int solve(int H, int W, int N){
    int y = (N-1) % H + 1;
    int x = (N-1) / H + 1;

    return (y * 100 + x);
}
int main(){
    int T, H, W, N;
    cin >> T;

    for (int i = 0; i < T; ++i){
        cin >> H >> W >> N;
        cout << solve(H, W, N) << '\n';
    }

    return 0;
}