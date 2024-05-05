#include <iostream>
#include <string>

using namespace std;

// Estructura para almacenar la información de un estudiante
struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    double notas[4]; // Arreglo para almacenar las 4 notas
    double promedio;
};

int main() {
    int N;

    // Solicitar al usuario la cantidad de estudiantes
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> N;

    // Crear un arreglo de estudiantes de tamaño N
    Estudiante estudiantes[N];

    // Ciclo para ingresar los datos de cada estudiante
    for (int i = 0; i < N; i++) {
        cout << "\nIngrese datos del estudiante " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> estudiantes[i].id;
        cin.ignore(); // Limpiar el buffer de entrada
        cout << "Nombres: ";
        getline(cin, estudiantes[i].nombres);
        cout << "Apellidos: ";
        getline(cin, estudiantes[i].apellidos);

        // Solicitar las 4 notas del estudiante
        cout << "Nota 1: ";
        cin >> estudiantes[i].notas[0];
        cout << "Nota 2: ";
        cin >> estudiantes[i].notas[1];
        cout << "Nota 3: ";
        cin >> estudiantes[i].notas[2];
        cout << "Nota 4: ";
        cin >> estudiantes[i].notas[3];

        // Calcular el promedio del estudiante
        estudiantes[i].promedio = (estudiantes[i].notas[0] + estudiantes[i].notas[1] +
                                    estudiantes[i].notas[2] + estudiantes[i].notas[3]) / 4.0;
    }

    // Mostrar resultados para cada estudiante
    cout << "\nResultados de los estudiantes:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "\nEstudiante " << i + 1 << ": " << estudiantes[i].nombres << " "
             << estudiantes[i].apellidos << endl;
        cout << "ID: " << estudiantes[i].id << endl;
        cout << "Promedio: " << estudiantes[i].promedio << endl;

        // Verificar si el estudiante aprobó o reprobó
        if (estudiantes[i].promedio >= 60.0) {
            cout << "Estado: Aprobado" << endl;
        } else {
            cout << "Estado: Reprobado" << endl;
        }
    }

    return 0;
}

