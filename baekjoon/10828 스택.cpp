#include <iostream>

using namespace std;

namespace cst{

class stack{
private:
    int* data;
    int top;
    int capacity;
public:
    stack() : top(-1), capacity(1){
        data = new int[capacity];
    }
    bool is_full(){
        if (this->top + 1 == this->capacity)
            return true;
        return false;
    }
    void reserve(int capacity){
        if (this->capacity < capacity){
            this->capacity = capacity;
            int* temp = this->data;
            this->data = new int[this->capacity];
            for (int i = 0; i <= this->top; ++i)
                this->data[i] = temp[i];
            delete[] temp;
        }
    }
    void push(int elm){
        if (is_full())
            reserve(this->capacity * 2);
        this->data[++this->top] = elm;
    }
    int pop(){
        if (empty())
            return -1;
        return this->data[this->top--];
    }
    int size(){
        return (this->top+1);
    }
    bool empty(){
        if (this->top == -1)
            return true;
        return false;
    }
    int peek(){
        if (!empty())
            return this->data[this->top];
        else
            return -1;
    }
};

}

int main(){
    ios::sync_with_stdio(false);
    int N, arg;
    cin >> N;

    cst::stack stk;

    string method;
    for (int i = 0; i < N; ++i){
        cin.ignore();
        cin >> method;

        if (method == "push"){
            cin >> arg;
            stk.push(arg);
        }
        else if (method == "pop")
            cout << stk.pop() << '\n';
        else if (method == "size")
            cout << stk.size() << '\n';
        else if (method == "empty")
            cout << stk.empty() << '\n';
        else if (method == "top")
            cout << stk.peek() << '\n';
    }

    return 0;
}