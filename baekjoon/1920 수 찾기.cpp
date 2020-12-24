#include <iostream>
#include <algorithm>

using namespace std;

class DataSet {
public:
    DataSet(int size) : size(size) {
        this->data = new int[size];
    }
    ~DataSet() {
        delete[] this->data;
    }

    int* data;
    int size;
};

void search(const DataSet& key, const DataSet& dataSet) {
    bool check;
    int left, mid, right;
    int target;

    for (int i = 0; i < key.size; ++i) {
        check = false;

        left = 0;
        right = dataSet.size - 1;
        target = key.data[i];

        while (left <= right) {
            mid = (left + right) / 2;
            if (dataSet.data[mid] < target) {
                left = mid + 1;
            }
            else if (dataSet.data[mid] > target) {
                right = mid - 1;
            }
            else {
                check = true;
                break;
            }
        }
        cout << check << '\n';
    }
}

int main() {
    int N, M;

    ios::sync_with_stdio(false);
    cin >> N;
    DataSet dataSet = DataSet(N);
    for (int i = 0; i < N; ++i)
        cin >> dataSet.data[i];
    stable_sort(dataSet.data, dataSet.data + N);

    cin >> M;
    DataSet key = DataSet(M);
    for (int i = 0; i < M; ++i)
        cin >> key.data[i];

    search(key, dataSet);

    return 0;
}