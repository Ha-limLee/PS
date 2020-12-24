//백준 2609 최대공약수와 최소공배수

#include <iostream>
#include <vector>

using namespace std;

auto GCD(int N, int M)->int{
    int min = (N > M) ? M : N;
    int max = (N == min) ? M : N;

    vector<bool> primeCheck(min, true);

    if (max % min == 0) return min;

    int gcd = 1;
    int index = 2;
    for (auto it = primeCheck.begin(); it != primeCheck.end(); ++it){
        if (primeCheck[index] == true && N % index == 0 && M % index == 0) {gcd = index++; continue;}
        for (int j = 2; j <= min / index; ++j){
            primeCheck[index * j] = false;
        }
        index++;
    }

    return gcd;
}

auto main()->int{
    ios::sync_with_stdio(false);
    int num1, num2;
    cin >> num1 >> num2;
    int gcd = GCD(num1, num2);
    int lcm = num1*num2/gcd;
    
    cout << gcd << '\n' << lcm;
    return 0;
}
