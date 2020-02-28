#ifndef TRABAJADOR_H
#define TRABAJADOR_H

#include "persona.h"

class Trabajador : public Persona
{
public:
    Trabajador(string name, string solapin, char sexo, string carnet_identidad,
               float salarioBasico, string plaza, int annos, string categoria);

    // Pregunta 1
    float salario();

    inline float salarioBasico() const {  return m_salario_basico;  }
    inline int annosTrabajo() const {  return m_annos_trabajo;  }
    inline string plaza() const {  return m_plaza;  }
    inline string categoria() const {  return m_categoria;  }
    string mostrarInfo();

protected:
    float m_salario_basico;
    string m_plaza;
    int m_annos_trabajo;
    string m_categoria;
};

#endif // TRABAJADOR_H
