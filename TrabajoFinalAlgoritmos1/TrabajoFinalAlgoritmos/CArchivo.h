#pragma once
#include <string>
using namespace std;
class CArchivo {
	string nombre;
	string extension;
	long long tamaño;
	string fecha;
	string ruta;
	string reverseName;
public:
	CArchivo(string nombre, string extension, long long tamaño, string fecha, string ruta, string reverseName)
		:nombre(nombre), extension(extension), tamaño(tamaño), fecha(fecha), ruta(ruta), reverseName(reverseName) {}
	
	string getNombre() { return this->nombre; }
	string getExtension() { return this->extension; }
	long long getTamaño() { return this->tamaño; }
	string getFecha() { return this->fecha; }
	string getRuta() { return this->ruta; }
	string getRname() { return this->reverseName; }

	void setNombre(string nombre) { this->nombre = nombre; }
	void setExtension(string extension) { this->extension = extension; }
	void setTamaño(long long tamaño) { this->tamaño = tamaño; }
	void setFecha(string fecha) { this->fecha = fecha; }
};