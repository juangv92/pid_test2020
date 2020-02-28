#ifndef FACULTAD4_H
#define FACULTAD4_H

#include <vector>
#include <map>

#include "persona.h"
#include "estudiante.h"
#include "trabajador.h"
using namespace std;

class Equipo
{
public:
    Equipo(string m1, string m2, string m3)
    {
        m_miembro1 = m1;
        m_miembro2 = m2;
        m_miembro3 = m3;
    }

    inline string miembro1() const {  return m_miembro1;  }
    inline string miembro2() const {  return m_miembro2;  }
    inline string miembro3() const {  return m_miembro3;  }

private:
    string m_miembro1;
    string m_miembro2;
    string m_miembro3;
};

class Facultad4
{
public:
    Facultad4();

    void generarDatos();
    Estudiante *generarEstudiante(int pos);
    Trabajador *generarTrabajador(int pos);

    vector<Estudiante *> getEstudiantes();
    vector<Trabajador *> getTrabajadores();

    inline int size() const {  return m_miembrosFacultad.size();   }

    // Pregunta 2
    Persona * buscarPorCI(string ci);

    // Pregunta 3
    vector<Persona *> reporteSalarios();

    // Pregunta 4
    vector<Trabajador *> reporteCategoriaCientifica();

    // Pregunta 5
    vector<Estudiante *> reporteIndiceAcademico();

    // Pregunta 6
    pair<float, float> reportePorcientoSexo();

    // Pregunta 7
    vector<Equipo *> reporteEquiposACM();

private:
    map<string, Persona *> m_miembrosFacultad;

    int m_inicio_estudiantes;
    int m_inicio_trabajadores;
};

#endif // FACULTAD4_H
