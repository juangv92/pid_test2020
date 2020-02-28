#include "facultad4.h"
#include <QStringList>
#include <ctime>

Facultad4::Facultad4()
{
    srand(25042019);

    m_inicio_estudiantes = rand() % 12;
    m_inicio_trabajadores = rand() % 10;
}

void Facultad4::generarDatos()
{
    int trabajadores = 15;
    int estudiantes = 10;
    bool flag = true;
    Persona *persona;
    while (trabajadores + estudiantes)
    {
        if (flag)
        {   // generar estudiante
            if (estudiantes)
            {
                estudiantes--;
                persona = generarEstudiante(m_inicio_estudiantes);
                m_miembrosFacultad[persona->carnetIdentidad()] = persona;
                m_inicio_estudiantes = (m_inicio_estudiantes + 1) % 12;
            }
        }
        else
        {   // generar profesor
            if (trabajadores)
            {
                trabajadores--;
                persona = generarTrabajador(m_inicio_trabajadores);
                m_miembrosFacultad[persona->carnetIdentidad()] = persona;
                m_inicio_trabajadores = (m_inicio_trabajadores + 1) % 15;
            }
        }

        flag = rand() % 2;
    }
}

Estudiante *Facultad4::generarEstudiante(int pos)
{
    // Actualizar los nombres de los estudiantes
    QStringList estudiantes;
    estudiantes << "Naila Rodriguez Torres" << "Wilber Cue Laria";
    estudiantes << "Javier Lopez Requejo" << "Jose Rodriguez Loriga";
    estudiantes << "Hellen Maria Ramos Concepcion" << "Amanda Rodriguez Navarro";
    estudiantes << "Angel Luis Fumero Sanchez" << "Deniss Aida De La Osa Ramos";
    estudiantes << "Elianys Mendoza Amador"    << "Yasmany Malagon Gutierrez";
    estudiantes << "Yahima Perez Rodriguez"    << "Liliana Rodriguez Rosa";

    QStringList solapines;
    solapines << "E157902" << "E155434" << "E155528" << "E157915";
    solapines << "E155104" << "E158233" << "E156406" << "E156066";
    solapines << "E159522" << "E151401" << "E155243" << "E150633";

    QStringList sexo;
    sexo << "F" << "M" << "M" << "M" << "M" << "M" << "M" << "F";
    sexo << "F" << "M" << "F" << "F";

    QStringList carnet_idad;
    carnet_idad << "96070714015" << "95121029708" << "95082233220" << "95072405029";
    carnet_idad << "94030828321" << "95022833086" << "94090829905" << "96062208652";
    carnet_idad << "96053105538" << "94101705026" << "96021309457" << "96071408031";

    QList<int> grupos;
    grupos << 4401 << 4402 << 4403;

    char s = 'F';
    if (sexo[pos] == "F")
        s = 'F';
    else if (sexo[pos] == "M")
        s = 'M';

    float indice = (300 + (rand() % 200)) / 100.0;
    return new Estudiante(estudiantes[pos].toStdString(), solapines[pos % solapines.size()].toStdString(),
            s, carnet_idad[pos % carnet_idad.size()].toStdString(), grupos[pos % grupos.size()],
            pos % 2 == 1, indice, string("Vertex"));
}

Trabajador *Facultad4::generarTrabajador(int pos)
{
    QStringList profesores;
    profesores << "Ailyn Perez Aguila" << "Neysa Baldoquin Alonso";
    profesores << "Arlenys Palmero Ortega" << "Daciel Alberto Olivera Cortina";
    profesores << "Leduan Barbaro Rosell Acosta" << "Lisset Salazar Gomez";
    profesores << "Luis Eduardo Benitez Oliva" << "Mailin Carballosa Infante";
    profesores << "Luis Manuel Valera Perez" << "Roberto Millet Luaces";
    profesores << "Tomas Orlando Junco Vazquez" << "Yadira Ramirez Rodriguez";
    profesores << "Yonny Mondelo Hernandez" << "Yorgelys Gonzalez Lopez";
    profesores << "Yosleidy Arteaga Gomez";

    QStringList solapines;
    solapines << "T146047" << "T114729" << "T112002" << "T118163";
    solapines << "T110848" << "T111250" << "T112057" << "T109802";
    solapines << "T146036" << "T114756" << "T112084" << "T118173";
    solapines << "T151061" << "T109763" << "T548654";

    QStringList sexo;
    sexo << "F" << "F" << "F" << "M" << "M";
    sexo << "F" << "M" << "F" << "M" << "M";
    sexo << "M" << "F" << "M" << "F" << "F";

    QStringList carnet_idad;
    carnet_idad << "96070711234" << "95121095723" << "95082239621" << "95072406073";
    carnet_idad << "94030822183" << "95022838630" << "94090825099" << "96062206528";
    carnet_idad << "96053103855" << "94101702650" << "96021309457" << "96071403180";
    carnet_idad << "96053103855" << "94101702650" << "96021309841";

    QStringList plaza;
    plaza << "Profesor" << "Especialista";

    QStringList categoria;
    categoria << "Master" << "Doctor" << "Ninguna";

    char s = 'F';
    if (sexo[pos] == "F")
        s = 'F';
    else if (sexo[pos] == "M")
        s = 'M';

    return new Trabajador(profesores[pos].toStdString(), solapines[pos % solapines.size()].toStdString(),
            s, carnet_idad[pos % carnet_idad.size()].toStdString(), 500 + float(rand() % 1000),
            plaza[pos % plaza.size()].toStdString(), rand() % 5,
            categoria[pos % categoria.size()].toStdString());
}

vector<Estudiante *> Facultad4::getEstudiantes()
{
    vector<Estudiante *> estudiantes;

    map<string, Persona*>::iterator i;
    for (i = m_miembrosFacultad.begin(); i != m_miembrosFacultad.end(); i++)
        if (i->second->esEstudiante())
            estudiantes.push_back((Estudiante *)i->second);

    return estudiantes;
}

vector<Trabajador *> Facultad4::getTrabajadores()
{
    vector<Trabajador *> trabajadores;

    map<string, Persona*>::iterator i;
    for (i = m_miembrosFacultad.begin(); i != m_miembrosFacultad.end(); i++)
        if (i->second->esEstudiante() == false)
            trabajadores.push_back((Trabajador *)i->second);

    return trabajadores;
}

Persona *Facultad4::buscarPorCI(string ci)
{
    if (m_miembrosFacultad.find(ci) != m_miembrosFacultad.end())
        return m_miembrosFacultad[ci];

    return 0;
}

bool compare(Persona * a, Persona *b)
{
    return a->salario() > b->salario();
}

vector<Persona *> Facultad4::reporteSalarios()
{
    vector<Persona *> facultad4;

    for (auto x : m_miembrosFacultad)
        facultad4.push_back(x.second);

    sort(facultad4.begin(), facultad4.end(), compare);
    return facultad4;
}

bool compare2(Trabajador *a, Trabajador *b)
{
    // Doctor > Master > Ninguna
    if (a->categoria() != b->categoria())
    {
        if (a->categoria() == "Doctor")
            return true;

        if (a->categoria() == "Master" && b->categoria() == "Ninguna")
            return true;
    }

    return false;
}

vector<Trabajador *> Facultad4::reporteCategoriaCientifica()
{
    vector<Trabajador *> trabajadores = getTrabajadores();

    sort(trabajadores.begin(), trabajadores.end(), compare2);
    return trabajadores;
}

bool compare3(Estudiante *a, Estudiante *b)
{
    return a->indice_academico() > b->indice_academico();
}

vector<Estudiante *> Facultad4::reporteIndiceAcademico()
{
    vector<Estudiante *> estudiantes = getEstudiantes();

    sort(estudiantes.begin(), estudiantes.end(), compare3);
    return estudiantes;
}

pair<float, float> Facultad4::reportePorcientoSexo()
{
    int total = 0;
    float mujeres = 0.0, hombres = 0.0;

    for (auto x : m_miembrosFacultad)
    {
        if (x.second->sexo() == 'F')
            mujeres += 1.0f;
        else if (x.second->sexo() == 'M')
            hombres += 1.0f;

        total++;
    }

    return make_pair(mujeres / total * 100.0f,
                     hombres / total * 100.0f);
}

vector<Equipo *> Facultad4::reporteEquiposACM()
{
    vector<Equipo *> equipos;

    vector<Estudiante *> estudiantes = getEstudiantes();
    for (size_t i = 0; i < estudiantes.size() - 2; i++)
        for (size_t j = i + 1; j < estudiantes.size() - 1; j++)
            for (size_t k = j + 1; k < estudiantes.size(); k++)
                equipos.push_back(new Equipo(estudiantes[i]->name(),
                                             estudiantes[j]->name(),
                                             estudiantes[k]->name()));

    return equipos;
}
