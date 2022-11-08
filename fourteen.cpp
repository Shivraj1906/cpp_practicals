#include<iostream>

using namespace std;

class Matrix {
    int row, column;
    int **matrix;

    public:
    Matrix(int row, int column) {
        this->row = row;
        this->column = column;
        matrix = new int *[row];
        for(int i = 0; i < row; i++) {
            matrix[i] = new int[column];
        }
    }

    //Not the ideal implementation
    Matrix() {
        cout << "Enter the number of rows: ";
        cin >> row;

        cout << "Enter the number of columns: ";
        cin >> column;

        matrix = new int *[row];
        for(int i = 0; i < row; i++) {
            matrix[i] = new int[column];
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    //return index in form of i * column + j
    int max() {
        int max = 0;
        for(int i = 0; i < row * column; i++) {
            if(matrix[i / column][i % column] > matrix[max / column][max % column])
                max = i;
        }

        cout << "Max: " << matrix[max / column][max % column] << endl;

        return max;
    }

    Matrix multiply(Matrix &m) {
        Matrix answer(row, m.column);

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < m.column; j++) {
                int sum = 0;
                for(int k = 0; k < m.row; k++) {
                    sum += matrix[i][k] * m.matrix[k][j];
                }
                answer.matrix[i][j] = sum;
            }
        }

        return answer;
    }

    void display() {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                cout << matrix[i][j] << " ";
            }

            cout << endl;
        }
    }

    ~Matrix() {
        for(int i = 0; i < row; i++)
            delete[] matrix[i];

        delete[] matrix;
    }
};

int main() {
    Matrix m1, m2;

    int max_index = m1.max();
    
    m1.multiply(m2).display();
    return 0;
}