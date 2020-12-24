#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int* nums = new int[N];

    for (int i = 0; i < N; ++i)
        cin >> nums[i];
    
    sort(nums, nums+N);
    
    for (int i = 0; i < N; ++i)
        cout << nums[i] << '\n';

    return 0;
}

//성공. 이 문제의 의도는 input 속도를 빠르게 할 수 있냐를 묻는 걸까?