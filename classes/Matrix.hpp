#include <iostream>
#include <string>

using namespace std;

class Matrix {
    public:
        int rows;
        int columns;
        int **data;

        Matrix(int r, int c): rows(r), columns(c) {
            data = new int*[rows];
            for(int i = 0; i < rows; i++) {
                data[i] = new int[columns];
                for(int j = 0; j < columns; j++) {
                    data[i][j] = 0;
                }
            }
        }
        ~Matrix() {
            for(int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;
        }

        Matrix operator+ (const Matrix &other) {
            const int otherRows = other.rows;
            const int otherCols = other.columns;
            int **otherData = other.data;

            if(otherRows == rows && otherCols == columns){
                Matrix newMatrix = Matrix(rows, columns);
                int **newArr = newMatrix.data;

                for(int i = 0; i < rows; i++){
                    for(int j = 0; j < columns; j++) {
                        newArr[i][j] = data[i][j] + otherData[i][j];
                    }
                }
                return newMatrix;
            }else{
                throw invalid_argument("Matrix sizes do not match for addition.");
            }
        }

        Matrix operator* (const Matrix& other) {
            const int otherRows = other.rows;
            const int otherCols = other.columns;
            int** otherData = other.data;
            
            if(columns == otherRows){
                Matrix result = Matrix(rows, otherCols);

                for(int i = 0; i < rows; i++){
                    for(int j = 0; j < otherCols; j++){
                        result.data[i][j] = 0;

                        for(int k = 0; k < columns; k++){
                            result.data[i][j] += data[i][k] * otherData[k][j];
                        }
                    }
                }
                return result;
            }else{
                throw invalid_argument("Matrix sizes do not match for multiplication.");
            }
        }

        Matrix Transpose () {
            Matrix result = Matrix(columns, rows);
            int** newData = result.data;

            for(int i = columns - 1; i >= 0; i--){
                for(int j = 0; j < rows; j++) {
                    newData[i][j] = data[j][i];
                }
            }
            return result;
        }

        friend ostream& operator<< (ostream& out, const Matrix &other){
            const int otherRows = other.rows;
            const int otherCols = other.columns;
            int **otherData = other.data;

            for(int i = 0; i < otherRows; i++){
                for(int j = 0; j < otherCols; j++){
                    out << otherData[i][j] << " ";
                }
                out << endl;
            }
            return out;
        }
};