#include <iostream>
#include <cstring>

using namespace std;

class Container{
private:
    int x_width;
    int y_width;
    int** arr;
public:
    Container(int x_width, int y_width) : x_width(x_width), y_width(y_width){
        this->arr = new int*[x_width+2];
        for (int i = 0; i < x_width+2; ++i){
            this->arr[i] = new int[y_width+2];
            memset(this->arr[i], 0, sizeof(int)*(y_width+2));
        }
    }
    void addAt(int x, int y){
        this->arr[x+1][y+1] = 1;
    }
    void checkAround(int i, int j){
        if (this->arr[i][j] != 0){
            this->arr[i][j] = 0;

            this->checkAround(i, j+1);
            this->checkAround(i, j-1);
            this->checkAround(i-1, j);
            this->checkAround(i+1, j);
        }
        else
            return;
    }
    int solve(){
        int total = 0;
        for (int i = 1; i <= this->x_width; ++i){
            for (int j = 1; j <= this->y_width; ++j){
                if (this->arr[i][j] != 0){
                    ++total;
                    this->checkAround(i, j);
                }
            }
        }
        return total;
    }
};


int main(){
    ios::sync_with_stdio(false);

    int T, x_width, y_width, k;
    int x, y;
    cin >> T;
    for (int i = 0; i < T; ++i){
        cin >> x_width >> y_width >> k;
        auto container = new Container(x_width, y_width);

        for (int j = 0; j < k; ++j){
            cin >> x >> y;
            container->addAt(x, y);
        }
        cout << container->solve() << '\n';
        delete container;
    }
    return 0;
}