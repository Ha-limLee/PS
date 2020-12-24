#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void check_same(string* arr, int sizeOfArr) {
    for (int i = 0; i < sizeOfArr-1; ++i) {
        for (int j = i + 1; j < sizeOfArr; j++) {
            if (arr[i] == arr[j]) arr[j] = "";
        }
    }
}

bool compare(const string& a, const string& b) {
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

int main() {
    int numOfWords;
    cin >> numOfWords;

    string* arr = new string[numOfWords];

    for (int i = 0; i < numOfWords; ++i) {
        cin >> arr[i];
    }
    
    stable_sort(arr, arr+numOfWords, compare);
    check_same(arr, numOfWords);
    for (int i = 0; i < numOfWords; ++i) {
        if (arr[i] == "") continue;
        cout << arr[i] << "\n";
    }

    delete[] arr;
    return 0;
}