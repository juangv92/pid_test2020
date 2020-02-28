#include <cstdio>
#include <iostream>
#include <iomanip>

#include <QString>

#include "facultad4.h"
#include "estudiante.h"

int opcion;
string op;
Facultad4 *facultad;

void MenuPrincipal()
{
#ifdef __WIN32__
    system("cls");
#elif __linux__
    system("clear");
#endif
    cout << "1- Buscar por carne de identidad" << "\n";
    cout << "2- Reporte de salarios" << "\n";
    cout << "3- Ordenar trabajadores por categoria cientifica" << "\n";
    cout << "4- Indice academico de estudiantes" << "\n";
    cout << "5- Porciento de hombres y mujeres en la facultad" << "\n";
    cout << "6- Equipos para la ACM" << "\n";
    cout << "7- Salir" << "\n";

    cout << "Introduzca una opcion: ";
    cin >> op;
}

bool check()
{
    if (op.length() > 1)
        return false;

    if (op.at(0) <= '0' || op.at(0) > '9')
        return false;

    return true;
}

void buscarPorCI()
{
    // implementar metodo aqui
    string ci;
    cout << "Entre el CI de la persona: ";
    cin >> ci;

    Persona *p = facultad->buscarPorCI(ci);
    if (p)
        cout << p->mostrarInfo() << endl;
    else
        cout << "La persona con CI " << ci << " no esta en el sistema." << endl;

    // waiting for user to press Enter
    cin.ignore();
    cin.get();
}

void reporteSalarios()
{
    cout << "Trabajadores y estudiantes ordenados por el salario:" << "\n";
    vector<Persona *> p = facultad->reporteSalarios();

    for (auto x : p)
    {
        cout << x->name() << " $" << x->salario() << "\n";
    }

    // waiting for user to press Enter
    cin.ignore();
    cin.get();
}

void ordenarPorCategoriaCientifica()
{
    cout << "Trabajadores ordenados por categoria cientifica:" << "\n";
    vector<Trabajador *> p = facultad->reporteCategoriaCientifica();

    for (auto x : p)
    {
        cout << x->name() << " Categoria: " << x->categoria() << "\n";
    }

    // waiting for user to press Enter
    cin.ignore();
    cin.get();
}

void reporteIndiceAcademico()
{
    cout << "Estudiantes ordenados por indice academico:" << "\n";
    vector<Estudiante *> e = facultad->reporteIndiceAcademico();

    for (auto x : e)
    {
        cout << x->name() << " Indice: " << x->indice_academico() << "\n";
    }

    // waiting for user to press Enter
    cin.ignore();
    cin.get();
}

void reportePorSexo()
{
    pair<float, float> p = facultad->reportePorcientoSexo();
    cout << setprecision(2) << fixed;
    cout << "Mujeres: " << p.first  << "%\n";
    cout << "Hombres: " << p.second << "%\n";

    // waiting for user to press Enter
    cin.ignore();
    cin.get();
}

void reporteEquiposACM()
{
    vector<Equipo *> equipos = facultad->reporteEquiposACM();

    int numero = 1;
    for (auto x : equipos)
    {
        cout << "Equipo " << numero++ << "\n";
        cout << "  1- " << x->miembro1() << "\n";
        cout << "  2- " << x->miembro2() << "\n";
        cout << "  3- " << x->miembro3() << "\n";
    }

    // waiting for user to press Enter
    cin.ignore();
    cin.get();
}

int main(int /*argc*/, char **/*argv[]*/)
{
    facultad = new Facultad4();
    facultad->generarDatos();

    MenuPrincipal();
    while (check())
    {
        opcion = op.at(0) - '0';
        switch(opcion)
        {
        case 1 :  buscarPorCI();
            break;
        case 2 :  reporteSalarios();
            break;
        case 3 :  ordenarPorCategoriaCientifica();
            break;
        case 4 :  reporteIndiceAcademico();
            break;
        case 5 :  reportePorSexo();
            break;
        case 6 :  reporteEquiposACM();
            break;
        case 7 :  { cout << "Gracias por utilizar nuestro sistema." << "\n"; return 0; }
            break;
        }
        MenuPrincipal();
    }
    return 0;
}
