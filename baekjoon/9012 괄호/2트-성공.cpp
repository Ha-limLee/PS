#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool solve(string& str){
    stack<char> stk;
    for (auto& ref : str){
        if (ref == '(')
            stk.push(ref);
        else if (!stk.empty())
            stk.pop();
        else
            return false;
    }
    if (!stk.empty())
        return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    int N;
    (cin >> N).ignore(1, '\n');
    
    string str;
    for (int i = 0; i < N; ++i){
        cin >> str;

        if(solve(str))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}