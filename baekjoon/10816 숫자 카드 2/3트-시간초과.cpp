#include <iostream>
#include <vector>
#include <algorithm>
//#include <chrono>
#include <random>

using namespace std;

class rand_gen{
private:
    random_device rd;
    mt19937 mt;
    uniform_int_distribution<> ud;
public:
    rand_gen(int inf, int sup) : mt(rd()), ud(uniform_int_distribution<>(inf, sup)){}
    int operator()(){
        return ud(mt);
    }
};

void solve(vector<int>& v1, int card, int rand_val){
    sort(v1.begin(), v1.end());

    int cnt, left, right, mid, flag;
    int v1_size = v1.size();

    cnt = 0;
    left = 0; right = v1_size - 1;

    flag = 0;
    while (left <= right){
        if (flag == 0){
            mid = rand_val;
            ++flag;
        }
        else
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
    //auto start = chrono::system_clock::now();

    ios::sync_with_stdio(false);
    int N, M, card;
    cin >> N;
    vector<int> v1(N);

    for (auto& ref : v1)
        cin >> ref;
    
    cin >> M;
    
    rand_gen gen(0, v1.size() - 1);
    int rand_val = gen();

    for (int i = 0; i < M; ++i){
        cin >> card;
        solve(v1, card, rand_val);
    }

    //auto end = chrono::system_clock::now();
    //cout << '\n' << "duration : " << (end - start).count();

    return 0;
}