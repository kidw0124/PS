#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <vector>
#include <iostream>
using namespace std;

class MatrixInt{
private:
    vector<vector<int>> matrix;
public:
    // Constructors
    MatrixInt(int rows, int columns);
    MatrixInt(const MatrixInt& other);
    MatrixInt(MatrixInt&& other);
    MatrixInt(vector<vector<int>>&& other);
    MatrixInt(vector<vector<int>>& other);
    MatrixInt();

    // Assignment operator
    MatrixInt& operator=(const MatrixInt& other);
    MatrixInt& operator=(MatrixInt&& other);
    MatrixInt& operator=(vector<vector<int>>&& other);
    MatrixInt& operator=(vector<vector<int>>& other);
    
    // IO methods
    void input(istream& is);
    void print(ostream& os) const ;

    // Matrix operations
    void add(const MatrixInt& other);
    void subtract(const MatrixInt& other);
    MatrixInt multiply(const MatrixInt& other);


    // Operators
    MatrixInt operator+(const MatrixInt& other);
    MatrixInt& operator+=(const MatrixInt& other);
    MatrixInt operator-(const MatrixInt& other);
    MatrixInt& operator-=(const MatrixInt& other);
    MatrixInt operator*(const MatrixInt& other);
    MatrixInt& operator*=(const MatrixInt& other);


};

#ifndef __MATRIX_CPP__
#define __MATRIX_CPP__


#include <iostream>


MatrixInt::MatrixInt(int rows, int columns) : matrix(rows, vector<int>(columns)) {}
MatrixInt::MatrixInt(const MatrixInt& other) : matrix(other.matrix) {}
MatrixInt::MatrixInt(MatrixInt&& other) : matrix(move(other.matrix)) {}
MatrixInt::MatrixInt(vector<vector<int>>&& other) : matrix(move(other)) {}
MatrixInt::MatrixInt(vector<vector<int>>& other) : matrix(other) {}
MatrixInt::MatrixInt() : matrix(0, vector<int>(0)) {}

MatrixInt& MatrixInt::operator=(const MatrixInt& other){
    matrix = other.matrix;
    return *this;
}
MatrixInt& MatrixInt::operator=(MatrixInt&& other){
    matrix = move(other.matrix);
    return *this;
}
MatrixInt& MatrixInt::operator=(vector<vector<int>>&& other){
    matrix = move(other);
    return *this;
}
MatrixInt& MatrixInt::operator=(vector<vector<int>>& other){
    matrix = other;
    return *this;
}

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

void MatrixInt::subtract(const MatrixInt& other) {
    if (matrix.size() != other.matrix.size() || matrix[0].size() != other.matrix[0].size()) {
        throw "Matrix sizes do not match";
    }
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[i][j] -= other.matrix[i][j];
        }
    }
}

MatrixInt MatrixInt::multiply(const MatrixInt& other) {
    // Matrix multiplication size check
    if (matrix[0].size() != other.matrix.size()) {
        throw "Matrix sizes do not match";
    }
    // Matrix multiplication
    MatrixInt result(matrix.size(), other.matrix[0].size());
    for (int i = 0; i < matrix.size(); i++) {
            for (int k = 0; k < matrix[0].size(); k++) {
        for (int j = 0; j < other.matrix[0].size(); j++) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return result;
}

void MatrixInt::input(istream& is = cin) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            is >> matrix[i][j];
        }
    }
}

void MatrixInt::print(ostream& os = cout) const {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            os << matrix[i][j] << " ";
        }
        os << '\n';
    }
}

MatrixInt MatrixInt::operator+(const MatrixInt& other) {
    MatrixInt result(*this);
    result.add(other);
    return result;
}

MatrixInt& MatrixInt::operator+=(const MatrixInt& other) {
    *this = *this + other;
    return *this;
}

MatrixInt MatrixInt::operator-(const MatrixInt& other) {
    MatrixInt result(*this);
    result.subtract(other);
    return result;
}

MatrixInt& MatrixInt::operator-=(const MatrixInt& other) {
    *this = *this - other;
    return *this;
}

MatrixInt MatrixInt::operator*(const MatrixInt& other) {
    return MatrixInt(this->multiply(other));
}

MatrixInt& MatrixInt::operator*=(const MatrixInt& other) {
    *this = *this * other;
    return *this;
}


#endif // __MATRIX_CPP__
#endif
#include <iostream>
typedef long long int ll;

istream& operator>>(istream& is, MatrixInt& m) {
    m.input(is);
    return is;
}

ostream& operator<<(ostream& os, const MatrixInt& m) {
    m.print(os);
    return os;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m,k;
    cin >> n >> m;
    MatrixInt mat(n, m);
    cin>>mat;
    cin>>m>>k;
    MatrixInt mat2(m, k);
    cin>>mat2;
    cout<<mat*mat2<<endl;
}