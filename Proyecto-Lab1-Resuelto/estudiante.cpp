#include "estudiante.h"

Estudiante::Estudiante(string name, string solapin, char sexo, string carnet_identidad,
                       int grupo, bool alumno_ayudante, float indice, string centro)
    : Persona(name, solapin, sexo, carnet_identidad)
{
    m_grupo = grupo;
    m_alumno_ayudante = alumno_ayudante;
    m_indice_academico = indice;
    m_centro = centro;

    m_estudiante = true;
}

float Estudiante::salario()
{
    return m_alumno_ayudante ? 100 : 75;
}

string Estudiante::mostrarInfo()
{
    return "Estudiante " + m_name + " Solapin " + m_solapin + " Sexo " + m_sexo;
}
