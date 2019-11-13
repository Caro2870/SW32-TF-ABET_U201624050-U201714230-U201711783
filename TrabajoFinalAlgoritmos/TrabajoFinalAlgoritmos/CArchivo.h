
////HOLAA CAMBIO
#pragma once
#include <string>
using namespace std;
class CArchivo {
	string nombre;
	string extension;
	long long tamaño;
	string fecha;
	string ruta;
public:
	CArchivo(string nombre, string extension, long long tamaño, string fecha, string ruta)
		:nombre(nombre), extension(extension), tamaño(tamaño), fecha(fecha), ruta(ruta) {}
	
	string getNombre() { return this->nombre; }
	string getExtension() { return this->extension; }
	long long getTamaño() { return this->tamaño; }
	string getFecha() { return this->fecha; }
	string getRuta() { return this->ruta; }


	void setNombre(string nombre) { this->nombre = nombre; }
	void setExtension(string extension) { this->extension = extension; }
	void setTamaño(long long tamaño) { this->tamaño = tamaño; }
	void setFecha(string fecha) { this->fecha = fecha; }
};