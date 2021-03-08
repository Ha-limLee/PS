#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix){
    const int rows = matrix.size();
    const int columns = matrix[0].size();

    for (int i = 0; i < rows/2; ++i)
        swap(matrix[i], matrix[rows-1-i]);

    for (int start_colum = 1; start_colum < columns; ++start_colum){
        for (int i = 0, j = start_colum; i < j; ++i, --j)
            swap(matrix[i][j], matrix[j][i]);
    }

    for (int start_row = 1; start_row < rows; ++start_row){
        for (int i = start_row, j = columns-1; i < j ; ++i, --j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

void print_matrix(vector<vector<int>>& matrix){
    //for debug
    for (auto& row : matrix){
        for (auto& elm : row)
            cout << elm;
        cout << '\n';
    }
}

int main(){
    //for debug
    vector<vector<int>> matrix({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    });

    rotate(matrix);
    print_matrix(matrix);
    
    return 0;
}