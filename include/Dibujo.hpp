#include <ftxui/dom/elements.hpp>
#include <string>
#include <fstream>

using namespace std;
using namespace ftxui;

class Dibujo
{
private:
    ifstream archivo;
    Element contenido;

public:
    Dibujo(string path)
    {
        archivo.open(path);
        Elements elementos;
        string linea;
        while (getline(archivo, linea))
        {
            elementos.emplace_back(text(linea));
        }
        contenido = vbox(elementos);
        archivo.close();

        archivo.open(path);
        Elements objetos;
        string serie;
        while (getline(archivo, serie))
        {
            objetos.emplace_back(text(serie));
        }
        Element bloque = vbox(objetos);
        archivo.close();
    }
    Element GetElement()
    {
        return this->contenido;
    }
    ~Dibujo()
}