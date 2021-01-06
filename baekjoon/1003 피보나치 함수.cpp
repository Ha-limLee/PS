#include <iostream>

namespace cst{

using namespace cst;
template<typename T1, typename T2>
class pair{
public:
    T1 first;
    T2 second;
    pair(){}
    pair(T1 first, T2 second) : first(first), second(second){}
    pair(const pair<T1, T2> &other) : first(other.first), second(other.second){}
    pair(pair<T1, T2>&& other) : first(other.first), second(other.second){}

    pair<T1, T2> operator+(pair<T1, T2>& other){
        return pair<T1, T2>(first + other.first, second + other.second);
    }
    void operator=(pair<T1, T2>&& other){
        first = other.first;
        second = other.second;
    }
};

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, pair<T1, T2>& other){
    os << other.first << ' ' << other.second;
    return os;
}
}

int main(){
    std::ios::sync_with_stdio(false);
    int T, N;
    cst::pair<int, int> array[41];
    array[0] = cst::pair<int, int>(1, 0);
    array[1] = cst::pair<int, int>(0, 1);
    for (int i = 2; i < 41; ++i)
        array[i] = array[i-1] + array[i-2];

    std::cin >> T;
    
    for (int i = 0; i < T; ++i){
        std::cin >> N;
        std::cout << array[N] << '\n';
    }

    return 0;
}