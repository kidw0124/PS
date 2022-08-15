#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <vector>
using namespace std;

class MatrixInt{
private:
    vector<vector<int>> matrix;
public:
    // Constructors
    MatrixInt(int rows, int columns);
    MatrixInt(const MatrixInt& other);
    MatrixInt(MatrixInt&& other);
    MatrixInt();

    void add(const MatrixInt& other);
    void input();
    void print();

};
#ifndef __MATRIX_CPP__
#define __MATRIX_CPP__

#include <iostream>


MatrixInt::MatrixInt(int rows, int columns) : matrix(rows, vector<int>(columns)) {}
MatrixInt::MatrixInt(const MatrixInt& other) : matrix(other.matrix) {}
MatrixInt::MatrixInt(MatrixInt&& other) : matrix(move(other.matrix)) {}
MatrixInt::MatrixInt() : matrix(0, vector<int>(0)) {}

void MatrixInt::add(const MatrixInt& other) {
    if (matrix.size() != other.matrix.size() || matrix[0].size() != other.matrix[0].size()) {
        throw "Matrix sizes do not match";
    }
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[i][j] += other.matrix[i][j];
        }
    }
}

void MatrixInt::input() {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cin >> matrix[i][j];
        }
    }
}

void MatrixInt::print() {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
}


#endif // __MATRIX_CPP__
#endif
#include <iostream>
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    MatrixInt mat(n, m), mat2(n, m);
    mat.input();
    mat2.input();
    mat.add(mat2);
    mat.print();
}