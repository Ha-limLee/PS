#include <iostream>

namespace cst{

class queue{
private:
    int* data;
    int front;
    int back;
    int capacity;
public:
    queue() : front(0), back(-1), capacity(1) {
        data = new int[capacity];
    }
    bool full(){
        if (back+1 == capacity)
            return true;
        return false;
    }
    bool empty(){
        if (front > back)
            return true;
        return false;
    }
    void reserve(int reserved){
        if (capacity >= reserved)
            return;
        capacity = reserved;
        int* temp = data;
        data = new int[reserved];
        for (int i = front; i <= back; ++i)
            data[i] = temp[i];
        delete[] temp;
    }
    void push(int elm){
        if (full())
            reserve(this->capacity * 2);
        this->data[++back] = elm;
    }
    int pop(){
        if (empty())
            return -1;
        return this->data[front++];
    }
    int get_size(){
        return (this->back - this->front + 1);
    }
    int get_front(){
        if (empty())
            return -1;
        return this->data[front];
    }
    int get_back(){
        if (empty())
            return -1;
        return this->data[back];
    }
};

}

using namespace std;

int main(){
    ios::sync_with_stdio(false);

    cst::queue q;
    string method;
    int N, arg;
    cin >> N;
    
    for (int i = 0; i < N; ++i){
        cin.ignore();
        cin >> method;
        if (method == "push"){
            cin >> arg;
            q.push(arg);
        }
        else if (method == "pop")
            cout << q.pop() << '\n';
        else if (method == "size")
            cout << q.get_size() << '\n';
        else if (method == "empty")
            cout << q.empty() << '\n';
        else if (method == "front")
            cout << q.get_front() << '\n';
        else if (method == "back")
            cout << q.get_back() << '\n';
    }

    return 0;
}