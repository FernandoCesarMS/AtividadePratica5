#include <iostream>

class Ponto2D{
    
    int x,y;
    
    public:
        Ponto2D(int xx=0, int yy=0):x(xx),y(yy){ };
        Ponto2D& operator-- ();
        Ponto2D operator+ (const Ponto2D& ) const;
        ~Ponto2D(){}; 
};

Ponto2D Ponto2D::operator+ (const Ponto2D& aux1) const{
    Ponto2D aux2;
    aux2.x = x + aux1.x;
    aux2.y = y + aux1.y;
    return aux2;
}

Ponto2D &Ponto2D::operator-- (){
    x -= 1;
    y -=1;
    return *this;
}

int main() {
    Ponto2D a(1,4), b(3,2), c;
    c = a + b;               // soma as coordenadas dos pontos a e b 
    --c;                    // decrementa em uma unidade as coordenadas de c
    //std::cout << c.x << c.y;
}