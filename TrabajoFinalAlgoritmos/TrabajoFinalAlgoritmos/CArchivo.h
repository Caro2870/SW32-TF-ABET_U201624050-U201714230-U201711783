
////HOLAA CAMBIO
#pragma once
#include <string>
using namespace std;
class CArchivo {
	string nombre;
	string extension;
	long long tama�o;
	string fecha;
	string ruta;
public:
	CArchivo(string nombre, string extension, long long tama�o, string fecha, string ruta)
		:nombre(nombre), extension(extension), tama�o(tama�o), fecha(fecha), ruta(ruta) {}
	
	string getNombre() { return this->nombre; }
	string getExtension() { return this->extension; }
	long long getTama�o() { return this->tama�o; }
	string getFecha() { return this->fecha; }
	string getRuta() { return this->ruta; }


	void setNombre(string nombre) { this->nombre = nombre; }
	void setExtension(string extension) { this->extension = extension; }
	void setTama�o(long long tama�o) { this->tama�o = tama�o; }
	void setFecha(string fecha) { this->fecha = fecha; }
};