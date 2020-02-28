#include "persona.h"

Persona::Persona(string name, string solapin, char sexo, string carnet_identidad)
{
    m_name = name;
    m_solapin = solapin;
    m_sexo = sexo;
    m_carnet_identidad = carnet_identidad;
}

string Persona::mostrarInfo()
{
    return m_name + " " + m_solapin + " " + m_sexo;
}
