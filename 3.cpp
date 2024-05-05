#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Definición de la estructura Estudiante
struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    double notas[4];
    double promedio;
    string resultado;
};

// Función para ingresar un nuevo estudiante y almacenarlo en el archivo binario
void crearEstudiante(const char* filename) {
    Estudiante estudiante;

    cout << "\nIngrese datos del estudiante:" << endl;
    cout << "ID: ";
    cin >> estudiante.id;
    cin.ignore(); // Limpiar el buffer de entrada
    cout << "Nombres: ";
    getline(cin, estudiante.nombres);
    cout << "Apellidos: ";
    getline(cin, estudiante.apellidos);

    cout << "Nota 1: ";
    cin >> estudiante.notas[0];
    cout << "Nota 2: ";
    cin >> estudiante.notas[1];
    cout << "Nota 3: ";
    cin >> estudiante.notas[2];
    cout << "Nota 4: ";
    cin >> estudiante.notas[3];

    // Calcular promedio
    estudiante.promedio = (estudiante.notas[0] + estudiante.notas[1] +
                           estudiante.notas[2] + estudiante.notas[3]) / 4.0;

    // Determinar resultado
    estudiante.resultado = (estudiante.promedio >= 60.0) ? "Aprobado" : "Reprobado";

    // Abrir el archivo en modo binario para escritura (append)
    ofstream outFile(filename, ios::binary | ios::app);
    if (!outFile) {
        cerr << "Error al abrir el archivo " << filename << " para escritura." << endl;
        return;
    }

    // Escribir el estudiante en el archivo binario
    outFile.write(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante));

    // Cerrar el archivo
    outFile.close();

    cout << "Estudiante agregado correctamente." << endl;
}

void mostrarEstudiantes(const char* filename) {
    Estudiante estudiante;

    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error al abrir el archivo " << filename << " para lectura." << endl;
        return;
    }

    cout << "\nLista de estudiantes:" << endl;
    while (inFile.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
        cout << "ID: " << estudiante.id << endl;
        cout << "Nombres: " << estudiante.nombres << endl;
        cout << "Apellidos: " << estudiante.apellidos << endl;
        cout << "Promedio: " << estudiante.promedio << endl;
        cout << "Resultado: " << estudiante.resultado << endl;
        cout << "---------------------" << endl;
    }

    if (inFile.eof()) {
        cout << "Lectura completada." << endl;
    } else if (inFile.fail()) {
        cout << "Error de lectura: se encontró un error durante la lectura." << endl;
    } else if (inFile.bad()) {
        cout << "Error crítico: se encontró un error fatal durante la lectura." << endl;
    }

    inFile.close();
}


int main() {
    char filename[] = "notas.dat";
    int opcion;

    do {
        // Menú de opciones
        cout << "\nMenu:" << endl;
        cout << "1. Agregar estudiante" << endl;
        cout << "2. Mostrar estudiantes" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearEstudiante(filename);
                break;
            case 2:
                mostrarEstudiantes(filename);
                break;
            case 3:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);

    return 0;
}

