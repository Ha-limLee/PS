#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int N;

    multimap<int, string> data;
    int age;
    string name;
    
    pair<int, string> p1 = make_pair(1, "Block");

    cin >> N;

    for (int i = 0; i < N; ++i){
        cin >> age >> name;
        data.emplace(age, name);
    }

    for (auto& ref : data)
        cout << ref.first << ' ' << ref.second << '\n';

    return 0;
}