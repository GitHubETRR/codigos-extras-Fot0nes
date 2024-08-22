#include <iostream>
#include <stdlib.h>
using namespace std;

class Rectangulo{
    private:
        float largo, ancho;
    public:
    Rectangulo (float, float);
        void perimetro();
        void area();
};
Rectangulo::Rectangulo(float _largo, float _ancho){
 largo= _largo;
 ancho=_ancho;   
}
void Rectangulo :: perimetro(){
    float _perimetro;
    _perimetro = (2*largo)+ (2*ancho);
    cout <<"El perimetro es:"<<_perimetro<<endl;
}
void Rectangulo ::area(){
    float _area;
    _area = largo*ancho;
    cout<<"El area es:"<<_area<<endl;

}
int main (){
    int o;
    float l1, a1;
    cout<<"El ancho es"<<endl;
    cin>>l1;
    cout<<"El largo es"<<endl;
    cin>>a1;
    Rectangulo r1(l1, a1);
    cout<<"¿Que desea ver5?\n1. Perimetro \n2.Area"<<endl;
    cin>>o;
    if (o==1){
        r1.perimetro();
    }
     else if (o == 2) {
        r1.area(); 
    }
     else {
        cout << "Opción no válida." << endl;
    }

    return 0;
}
