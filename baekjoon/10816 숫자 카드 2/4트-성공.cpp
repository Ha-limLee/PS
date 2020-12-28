#include <iostream>
#include <vector>
//#include <chrono>

using namespace std;

class node{
public:
    int first;
    int second;

    node* left;
    node* right;

    node(int first) : first(first), second(1), left(NULL), right(NULL){}
};

class binary_search_tree{
private:
   node* head;
public:
    binary_search_tree() : head(NULL){}
    ~binary_search_tree(){}

    node* get_head(){
        return this->head;
    }
    void insert(int elm){
        if (this->head == NULL){
            head = new node(elm);
            return;
        }

        node* parent = this->head;
        node* ptr = parent;
        bool left = false;

        while(ptr != NULL){
            if (ptr->first > elm){
                parent = ptr;
                ptr = ptr->left;
                left = true;
            }
            else if (ptr->first < elm){
                parent = ptr;
                ptr = ptr->right;
                left = false;
            }
            else{
                ++ptr->second;
                return;
            }
        }
        if (left == true)
            parent->left = new node(elm);
        else
            parent->right = new node(elm);
    }
};

void solve(binary_search_tree& bst, vector<int>& v){
    node* ptr;
    for (auto& ref : v){
        ptr = bst.get_head();
        while(ptr != NULL){
            if (ptr->first == ref)
                break;
            else if (ptr->first > ref)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        if (ptr == NULL)
            cout << 0 << ' ';
        else
            cout << ptr->second << ' ';
    }
}

int main(){
    //auto start = chrono::system_clock::now();

    ios::sync_with_stdio(false);
    int N, M, temp;
    cin >> N;

    binary_search_tree bst;

    for (int i = 0; i < N; ++i){
        cin >> temp;
        bst.insert(temp);
    }
    
    cin >> M;
    vector<int> v(M, 0);   //to search

    for (auto& ref : v)
        cin >> ref;

    solve(bst, v);

    //auto duration = chrono::system_clock::now() - start;
    //cout << '\n' << "duration : " << duration.count();

    return 0;
}