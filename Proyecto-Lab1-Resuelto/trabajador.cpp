#include "trabajador.h"

Trabajador::Trabajador(string name, string solapin, char sexo, string carnet_identidad,
                       float salarioBasico, string plaza, int annos, string categoria)
    : Persona(name, solapin, sexo, carnet_identidad)
{
    m_salario_basico = salarioBasico;
    m_plaza = plaza;
    m_annos_trabajo = annos;
    m_categoria = categoria;

    m_estudiante = false;
}

float Trabajador::salario()
{
    return m_salario_basico + 25 * m_annos_trabajo;
}

string Trabajador::mostrarInfo()
{
    return "Trabajador " + m_name + " Solapin " + m_solapin + " Sexo " + m_sexo;
}
