#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string input) {
    int strLen = input.length();
    for (int i = 0; i < strLen/2; ++i) {
        if (input[i] != input[strLen-1 - i]) return false;
    }
    return true;
}

int main() {
    string input = "";

    getline(cin, input);
    while (input[0] != '0') {
        if (isPalindrome(input) == true)
            cout << "yes\n";
        else
            cout << "no\n";
        getline(cin, input);
    }
    return 0;
}