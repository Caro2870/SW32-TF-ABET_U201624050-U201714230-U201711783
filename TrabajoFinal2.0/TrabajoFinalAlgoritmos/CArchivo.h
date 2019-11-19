#pragma once
#include <string>
using namespace std;
class CArchivo {
	string nombre;
	string extension;
	long long tama�o;
	string fecha;
	string ruta;
	string reverseName;
public:
	CArchivo(string nombre, string extension, long long tama�o, string fecha, string ruta, string reverseName)
		:nombre(nombre), extension(extension), tama�o(tama�o), fecha(fecha), ruta(ruta), reverseName(reverseName) {}
	
	string getNombre() { return this->nombre; }
	string getExtension() { return this->extension; }
	long long getTama�o() { return this->tama�o; }
	string getFecha() { return this->fecha; }
	string getRuta() { return this->ruta; }
	string getRname() { return this->reverseName; }

	void setNombre(string nombre) { this->nombre = nombre; }
	void setExtension(string extension) { this->extension = extension; }
	void setTama�o(long long tama�o) { this->tama�o = tama�o; }
	void setFecha(string fecha) { this->fecha = fecha; }
};