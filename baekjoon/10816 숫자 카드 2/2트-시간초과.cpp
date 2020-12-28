#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int>& v1, int card){
    sort(v1.begin(), v1.end());

    int cnt, left, right, mid;
    int v1_size = v1.size();

    cnt = 0;
    left = 0; right = v1_size - 1;

    while (left <= right){
        mid = (left + right)/2;
        if (v1[mid] < card)
            left = mid + 1;
        else if (v1[mid] > card)
            right = mid - 1;
        else{
            ++cnt;
            int i = 1;
            while(mid + i < v1_size && v1[mid + i] == card){
                ++cnt; ++i;
            }
            i = 1;
            while(mid - i >= 0 && v1[mid - i] == card){
                ++cnt; ++i;
            }

            break;
        }
    }
    cout << cnt << ' ';
}

int main(){
    ios::sync_with_stdio(false);
    int N, M, card;
    cin >> N;
    vector<int> v1(N, 0);

    for (auto& ref : v1)
        cin >> ref;
    
    cin >> M;
    
    for (int i = 0; i < M; ++i){
        cin >> card;
        solve(v1, card);
    }

    return 0;
}
//결과 : 1%에서 시간초과