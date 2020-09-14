#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Matrix {
    private:

        double** m; // m é um array 2D a ser implementado como um pointer de pointers
        int nRows;  // numero de linhas
        int nCols;  //  numero de colunas

    public:

        // Construtores
        Matrix();                           
        Matrix(int rows, int cols, const double &value = 0.0);
        Matrix(ifstream &myFile);
        Matrix(const Matrix& that);
        // destrutor
        ~Matrix();
    
        // basic getters
        int getRows() const;
        int getCols() const;
        double get(int row, int col) const;   
        
        // other methods
        void print() const;
        void unit();
        void zeros();
        void ones();
        
        //new others methods
        bool operator == (const Matrix& that) const; //verifica igualdade entre as matrizes
        bool operator != (const Matrix& that) const; //verifica desigualdade
        Matrix operator + (const Matrix& that); //soma
        Matrix operator += (const Matrix& that); //soma
        Matrix operator - (const Matrix& that); //subtrai
        Matrix operator -= (const Matrix& that); //subtrai 
        Matrix operator * (int C); //multiplicação por C
        Matrix operator *= (int C); //multiplicação por C
        Matrix operator * (const Matrix& that); //multiplicação por matrix
        Matrix operator *= (const Matrix& that); //multiplicação por matrix
        void operator << (const Matrix) const; //impressao da matrix
        Matrix& operator ~ (); //transposta
        
};