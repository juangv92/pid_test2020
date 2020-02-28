#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
using namespace std;

class Persona
{
public:
    Persona(string name, string solapin, char sexo, string carnet_identidad);
    virtual float salario() = 0;

    inline string name() const {  return m_name;  }
    inline string solapin() const {  return m_solapin;  }
    inline char sexo() const {  return m_sexo;  }
    inline string carnetIdentidad() const {  return m_carnet_identidad;  }
    inline bool esEstudiante() const {   return m_estudiante;    }
    virtual string mostrarInfo();

protected:
    string m_name;
    string m_solapin;
    string m_carnet_identidad;
    char m_sexo;
    bool m_estudiante;
};

#endif // PERSONA_H

