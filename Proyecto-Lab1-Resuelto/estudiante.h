#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "persona.h"
#include <iostream>
using namespace std;

class Estudiante : public Persona
{
public:
    Estudiante(string name, string solapin, char sexo, string carnet_identidad,
               int grupo, bool alumno_ayudante, float indice, string centro);

    // Pregunta 1
    float salario();

    inline int grupo() const {  return m_grupo;   }
    inline bool alumnoAyudante() const {  return m_alumno_ayudante;       }
    inline float indice_academico() const {  return m_indice_academico;   }
    inline string centro() const {  return m_centro;   }
    string mostrarInfo();

protected:
    int m_grupo;
    bool m_alumno_ayudante;
    float m_indice_academico;
    string m_centro;
};

#endif // ESTUDIANTE_H
