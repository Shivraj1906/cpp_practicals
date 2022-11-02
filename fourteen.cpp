#include<iostream>

using namespace std;

class Matrix {
    int row;
    int column;
    int **matrix;

    public: 
    Matrix(int row, int column, int **arr) {
        this->row = row;
        this->column = column;

        matrix = new int*[row];

        for(int i = 0; i < row; i++) {
            matrix[i] = new int[column];
            for(int j = 0; j < column; j++)
                matrix[i][j] = arr[i][j];
        }
    }

    Matrix(int row, int column) {
        this->row = row;
        this->column = column;

        matrix = new int*[row];

        for(int i = 0; i < row; i++) {
            matrix[i] = new int[column];
        }
    }

    int get_row() {
        return row;
    }

    int get_column() {
        return column;
    }

    int get_element(int u, int v) {
        return matrix[u][v];
    }

    int set_element(int u, int v, int value) {
        matrix[u][v] = value;
    }

    void max() {
        int max = matrix[0][0];

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                if(matrix[i][j] > max) {
                    max = matrix[i][j];
                }
            }
        }
    }

    //assuming that matrices are compatible for multiplication
    Matrix multiply(Matrix& m) {
        Matrix answer(row, m.get_column());

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                for(int k = 0; k < row; k++) {
                    
                }
            }
        }
    }

    void print() {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Matrix() {
        for(int i = 0; i < row; i++) {
            delete[] matrix[i];
        }

        delete[] matrix;
    }
};

int main() {

    return 0;
}