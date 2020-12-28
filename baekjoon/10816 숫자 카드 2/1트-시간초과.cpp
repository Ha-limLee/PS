#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int>& v1, vector<int>& v2){
    sort(v1.begin(), v1.end());

    int cnt, left, right, mid;
    int v1_size = v1.size();

    for (auto& ref : v2){
        cnt = 0;
        left = 0; right = v1_size - 1;

        while (left <= right){
            mid = (left + right)/2;
            if (v1[mid] < ref)
                left = mid + 1;
            else if (v1[mid] > ref)
                right = mid - 1;
            else{
                ++cnt;
                int i = 1;
                while(mid + i < v1_size && v1[mid + i] == ref){
                    ++cnt; ++i;
                }
                i = 1;
                while(mid - i >= 0 && v1[mid - i] == ref){
                    ++cnt; ++i;
                }

                break;
            }
        }
        cout << cnt << ' ';
    }
}

int main(){
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N;
    vector<int> v1(N, 0);

    for (auto& ref : v1)
        cin >> ref;
    
    cin >> M;
    vector<int> v2(M, 0);

    for (auto& ref : v2)
        cin >> ref;

    solve(v1, v2);

    return 0;
}

//결과 : 50% 정도에서 시간초과