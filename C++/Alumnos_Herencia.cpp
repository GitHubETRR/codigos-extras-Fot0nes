//Clase abstracta, profe solo quería aprender a usar herencias.
#include <iostream>
#include <vector>  
using namespace std;

class Persona {
private:
    string nombre;
    int edad;
public:
    Persona(string _nombre, int _edad) : nombre(_nombre), edad(_edad) {}
    void mostrarPersona() const {
        cout << "\n\nNombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
};

class Alumno : public Persona {
private:
    string codigoAlumno;
    float notaFinal;
public:
    Alumno(string _nombre, int _edad, string _codigoAlumno, float _notaFinal)
        : Persona(_nombre, _edad), codigoAlumno(_codigoAlumno), notaFinal(_notaFinal) {}
    
    void mostrarAlumno() const {
        mostrarPersona();
        cout << "Codigo de alumno: " << codigoAlumno << endl;
        cout << "Nota final: " << notaFinal << endl;
    }
};

int main() {
    int cantidad;
    cout << "Ingrese cuantos alumnos va a ingresar: ";
    cin >> cantidad;

    vector<Alumno*> alumnos; 

    for (int i = 0; i < cantidad; i++) {
        string nombre, codigoAlumno;
        int edad;
        float notaFinal;

        cout << "Ingrese el nombre del alumno " << i + 1 << ": ";
        cin >> nombre;

        cout << "Ingrese la edad del alumno " << i + 1 << ": ";
        cin >> edad;

        cout << "Ingrese el codigo del alumno " << i + 1 << ": ";
        cin >> codigoAlumno;

        cout << "Ingrese la nota final del alumno " << i + 1 << ": ";
        cin >> notaFinal;
       Alumno* nuevoAlumno = new Alumno (nombre, edad,codigoAlumno, notaFinal);
        alumnos.push_back(nuevoAlumno);
    
    }
    for (size_t i = 0; i < alumnos.size(); ++i)  {
        alumnos[i]-> mostrarAlumno();
        cout << "--------------------" << endl;
    }
    for (size_t i=0; i<alumnos.size();++i){
        delete alumnos[i];
            }

    return 0;
}

