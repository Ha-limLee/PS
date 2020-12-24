#include <iostream>
#include <random>

using namespace std;

#define SWAP(x, y, TYPE) do{TYPE temp = (x); (x) = (y); (y) = temp;}while(0)

class Rand{ //for test
private:
    random_device rd;
    mt19937 mt;
    uniform_int_distribution<> ud;
public:
    Rand(int inf, int sup) : mt(rd()), ud(uniform_int_distribution<>(inf, sup)) {}
    int operator()(){
        return ud(mt);
    }
};

void insertion_sort(int* arr, int N){
    int temp;
    for (int i = 1, j; i < N; ++i){
        temp = arr[i];
        for (j = 1; j <= i; ++j){
            if (temp < arr[i - j])
                arr[i-j+1] = arr[i-j];
            else{
                arr[i-j+1] = temp;
                break;
            }
        }
        if (arr[i-j+1] == arr[i-j+2])
            arr[i-j+1] = temp;
    }
}

int partition(int* arr, int left, int right){
    int pivot = (left + right) / 2;
    do
    {
        do{
            if (arr[left] >= arr[pivot]) break;
        }while(left++ < pivot);

        do{
            if (arr[pivot] >= arr[right]) break;
        }while(pivot < right--);

        if (arr[left] == arr[right])
            ++left;
        else if (left < right){
            SWAP(arr[left], arr[right], int);
            if (pivot == right) pivot = left;
            else if (pivot == left) pivot = right;
        }
    }while(left < right);

    return pivot;
}

void quick_sort(int* arr, int left, int right){
    if (left >= right) return;
    int pivot = partition(arr, left, right);
    quick_sort(arr, left, pivot-1);
    quick_sort(arr, pivot+1, right);
}

void heapify(int* arr, int N){
    if (N == 1)
        return;

    int child = N-1;
    int parent = (child-1)/2;

    if (arr[parent] < arr[child]){
        swap(arr[parent], arr[child]);
        heapify(arr, parent+1);
    }
    heapify(arr, N-1);
}

void heap_sort(int* arr, int N){
    heapify(arr, N);
    
    for (int i = 0; i < N; ++i){
        if (arr[0] > arr[N-(i+1)]) {
            swap(arr[0], arr[N-(i+1)]);
            heapify(arr, N-(i+1));
        }
    }
    
}

void introsort(int* arr, int* begin, int* end, int depth){//quick_sort + heap_sort
    if ((end - begin) < 16)
        insertion_sort(begin, end - begin + 1);
    else if (depth == 0) heap_sort(begin, end - begin + 1);
    else{
        int pivot = partition(arr, begin-arr, end-arr);

        introsort(arr, begin, arr + pivot - 1, depth-1);
        introsort(arr, arr + pivot + 1, end, depth-1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    //Rand rand(1, 99);

    int N;
    cin >> N;

    int* nums = new int[N];
    for (int i = 0; i < N; ++i)
        cin >> nums[i];

    int depth = 2*ceil(log2(N));
    
    introsort(nums, nums, nums+N-1, depth);
    for (int i = 0; i < N; ++i)
        cout << nums[i] << '\n';

    return 0;
}

//결과 : 시간초과, 삽입 정렬을 추가해서 조금은 더 빨라졌으나 퀵 정렬만 쓴 것과 비슷하거나 조금 더 느림