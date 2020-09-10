#include "matrix.hpp"

// construtor default - cria uma matriz vazia com nRows = nCols = 0
Matrix::Matrix(){
    m = NULL;
    nRows = 0;
    nCols = 0;
}

// construtor parametrico 1 - cria uma matriz com nRows  = rows, nCols = cols e
// com todos os elementos iguais a 0.0 (double)
Matrix::Matrix(int rows, int cols, const double &value){
    nRows = rows;
    nCols = cols;
    m = new double *[nRows];
    for (int i = 0; i < nRows; i++){
        m[i] = new double[nCols];
        for (int j = 0; j < nCols; j++){
            m[i][j] = 0.0;
        }
    }
}

// construtor parametrico 2 - cria uma matriz com os dados fornecidos pelo arquivo texto myFile.
Matrix::Matrix(fstream &myFile){
    vector<string> texto;
    myFile.open("teste.txt", ios::in);
    for (int i = 0; !myFile.fail(); i++){ // Guardando as informações do arquivo num vector de string
        string str;
        getline(myFile, str);
        texto.push_back(str);
    }
    this->nRows = texto.size()-1;
    m = new double *[this->nRows];
    for (int i = 0; i < texto.size() - 1; i++){
        vector<double> matriz;
        for (int j = 0; j < texto[i].size(); j++){ // transformando os caracteres em int
            int num;
            if (((int)texto[i][j] >= 48) && ((int)texto[i][j] <= 57)){
                num = texto[i][j] - '0';
                matriz.push_back(num);
            }
        }
        m[i] = new double[matriz.size()];
        for (int j = 0; j < matriz.size(); j++){ // atribuindo os numeros a matrix
            this->m[i][j] = matriz[j];
        }
        this-> nCols = matriz.size();
    }
    myFile.close();
}

// construtor de copia
Matrix::Matrix(const Matrix &that){
    this->nRows = that.nRows;
    this->nCols = that.nCols;
    for (int i = 0; i < nRows; i++){
        for (int j = 0; j < nCols; j++){
            this->m[i][j] = that.m[i][j];
        }
    }
}

// destrutor
Matrix::~Matrix(){
    for (int i; i < nRows; i++){
        delete[] m[nCols];
        delete[] m;
    }
}
// obtem o numero de linhas
int Matrix::getRows() const{
    return nRows;
}
// obtem o numero de colunas
int Matrix::getCols() const{
    return nCols;
}

// obtem um elemento específico na posição (row,col). Obs: deve checar consistencia
double Matrix::get(int row, int col) const{
    if (row <= (this->nRows - 1) && col <= (this->nCols - 1)){
        return this->m[row][col];
    }
    else{
        cout << "Não foi encontrado esse elemento!" << endl;
        return 0.0;
    }
}
// imprime o conteudo da matriz
void Matrix::print() const{
    for (int i = 0; i < nRows; i++){
        for (int j = 0; j < nCols; j++){
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
}
// faz com que a matriz torne-se uma matriz identidade
void Matrix::unit(){
    if (nCols == nRows){
        for (int i = 0; i <= nRows; i++){
            for (int j = 0; j <= nCols; j++){
                if (j == i){
                    m[i][j] = 1;
                }
                else{
                    m[i][j] = 0;
                }
            }
        }
    }
    else{
        std::cout << "Essa matriz nao pode ser transformada em identidade";
    }
}
// faz com que a matriz torne-se uma matriz nula
void Matrix::zeros(){
    for (int i = 0; i <= nRows; i++){
        for (int j = 0; j <= nCols; j++){
            m[i][j] = 0;
        }
    }
}

// faz com que a matriz torne-se uma matriz cujos elementos sao iguais a 1
void Matrix::ones()
{
    for (int i = 0; i <= nRows; i++){
        for (int j = 0; j <= nCols; j++){
            m[i][j] = 1.1;
        }
    }
}

//---------------------------------------------------------
//metodos de sobrecarga de operadores

bool Matrix::operator == (const Matrix& that){

}; //verifica igualdade entre as matrizes
bool Matrix::operator != (const Matrix& that){

}; //verifica desigualdade
Matrix Matrix::operator + (const Matrix& that){

}; //soma
Matrix Matrix::operator += (const Matrix& that){

}; //soma
Matrix Matrix::operator - (const Matrix& that){

}; //subtrai
Matrix Matrix::operator -= (const Matrix& that){

}; //subtrai 
Matrix Matrix::operator * (int C){

}; //multiplicação por C
Matrix Matrix::operator *= (int C){

}; //multiplicação por C
Matrix Matrix::operator * (const Matrix& that){

}; //multiplicação por matrix
Matrix Matrix::operator *= (const Matrix& that){

}; //multiplicação por matrix
void Matrix::operator << (const Matrix) const{

}; //impressao da matrix
Matrix& Matrix::operator ~ (){
    
}; //transposta