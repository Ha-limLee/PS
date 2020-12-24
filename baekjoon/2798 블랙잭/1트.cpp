#include <iostream>
#include <algorithm>

using namespace std;

class BinaryTree{
public:
    BinaryTree(int M) : array{0, M, 0,}{}
    void insert(int elm){
        for (int i = 1; i < MAX_SIZE;){
            if (this->array[i] == 0){
                this->array[i] = elm;
                return;
            }

            if (elm == this->array[i])
                return;
            else if (elm < this->array[i]){
                i *= 2;
            }
            else{
                i = i*2 + 1;
            }
        }
    }
    int leftMost(){
        for (int i = 2;;){
            if (this->array[i] == 0) return this->array[i/2];
            i = i*2 + 1;
        }
    }
private:
    enum{MAX_SIZE = 100};
    int array[MAX_SIZE+1];
};

int play(BinaryTree tree, int* numbers, int N, int M){
    int sum = 0;
    for (int i = 0; i < N-2; ++i){
        for (int j = i+1; j < N-1; ++j){
            for (int k = j+1; k < N; ++k){
                sum = numbers[i] + numbers[j] + numbers[k];
                if (sum == M)
                    return sum;
                else if (sum < M)
                    tree.insert(sum);
            }
        }
    }

    return tree.leftMost();
}

int main(){
    
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    
    BinaryTree tree(M);
    int* numbers = new int[N];

    for (int i = 0; i < N; ++i){
        cin >> numbers[i];
    }

    cout << play(tree, numbers, N, M);
    
    return 0;
}