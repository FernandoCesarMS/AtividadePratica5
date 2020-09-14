#include <iostream>
#include <fstream>
#include <vector>
#include "Matrix.cpp"

int main()
{
    // Iniciando objetos Matrix
    ifstream in("myMatrix.txt");
    Matrix Y;
    Matrix X(3, 1), A(3, 3), C(3, 3);
    Matrix Z(3, 2, 7.0);
    Matrix W(in);

    // operadores a serem implementados em sua classe:

    // Não conseguimos entender a função que altera o valor de uma posição de A
    C = A + A;  // Soma
    C -= A;     // Subtração
    A = C - A;  // Subtração
    A += A;     // Soma
    A = ~C;     // A é igual a transposta de C
    X *= 2;     // multiplicação por uma constante
    C = A * X;  // multiplicação de matrizes
    C *= X;     // multiplicação de matrizes
    if (A == C) // verifica a igualdade entre A e C
        cout << endl << "A eh igual a C" << endl;
    else
        cout << endl << "A não eh igual a C" << endl;
    if (X != Y) // verifica a desigualdade entre A e C
        cout << endl << "X eh diferente de Y" << endl;
    else
        cout << endl << "X não eh diferente de Y" << endl;

    cout << Z << endl; // impressão de matrizes
    cin >> W;          // leitura de dados para dentro da matriz Y
    return 0;
}
