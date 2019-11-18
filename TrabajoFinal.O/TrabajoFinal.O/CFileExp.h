#pragma once
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <list>
#include "CAVLTree.h"
#include "CArchivo.h"

using namespace std::experimental::filesystem;
using namespace std::chrono_literals;

class CFileExp {
	CAVLtree<CArchivo*, string, nullptr>* TreeName;
	CAVLtree<CArchivo*, string, nullptr>* TreeExten;
	CAVLtree<CArchivo*, long long, nullptr>* TreeSize;
	CAVLtree<CArchivo*, string, nullptr>* TreeDate;
	CAVLtree<CArchivo*, string, nullptr>* TreeReversName;
public:
	CFileExp() {
		auto l1 = [](CArchivo* a) {return a->getNombre(); };
		auto l2 = [](CArchivo* a) {return a->getExtension(); };
		auto l3 = [](CArchivo* a) {return a->getTamaño(); };
		auto l4 = [](CArchivo* a) {return a->getFecha(); };
		auto l5 = [](CArchivo* b) {return b->getRname(); };
		this->TreeName = new CAVLtree<CArchivo*, string, nullptr>(l1);
		this->TreeExten = new CAVLtree<CArchivo*, string, nullptr>(l2);
		this->TreeSize = new CAVLtree<CArchivo*, long long, nullptr>(l3);
		this->TreeDate = new CAVLtree<CArchivo*, string, nullptr>(l4);
		this->TreeReversName = new CAVLtree<CArchivo*, string, nullptr>(l5);
	}
	void scanear(string ruta) {
		for (const auto& entry : recursive_directory_iterator(ruta)) {
			string ruta = entry.path().string();
			string nombre = entry.path().filename().string();
			string RName = entry.path().filename().string();
			reverse(RName.begin(), RName.end());
			string extension = entry.path().extension().string();
			long long tamaño = -1;
			if (is_directory(status(entry.path())))  tamaño = 0;
			else tamaño = file_size(entry.path());
			auto ftime = last_write_time(entry.path());
			time_t cftime = decltype(ftime)::clock::to_time_t(ftime);
			string fecha = asctime(localtime(&cftime));
			CArchivo* archivo = new CArchivo(nombre, extension, tamaño, fecha, ruta, RName);
			this->TreeName->add(archivo);
			this->TreeExten->add(archivo); // Sun Nov 3 19:04:26 2019 "Sun Nov  3 19:04:26 2019\n"
			this->TreeSize->add(archivo);
			this->TreeDate->add(archivo);
			this->TreeReversName->add(archivo);
		}
	}
	vector<CArchivo*> buscar_archivo_nombre(string nombre) {
		vector<CArchivo*> v;
		this->TreeName->find(nombre, v);
		return v;
	}
	vector<CArchivo*> buscar_archivo_exten(string extension) {
		vector<CArchivo*> v;
		this->TreeExten->find(extension, v);
		return v;
	}
	vector<CArchivo*> buscar_archivo_tamaño(long long tamaño) {
		vector<CArchivo*> v;
		this->TreeSize->find(tamaño, v);
		return v;
	}
	vector<CArchivo*> buscar_archivos_fecha(string fecha) {
		vector<CArchivo*> v;
		this->TreeDate->find(fecha, v);
		return v;
	}

	vector<CArchivo*> filtrado_columnas_nombres_inicial(string ini) {
		vector<CArchivo*> v;
		this->TreeName->findX(ini, v);
		return v;
	}
	vector<CArchivo*> filtrardo_columnas_nombres_final(string fin) {
		vector<CArchivo*> v;
		this->TreeReversName->findX(fin, v);
		return v;
	}
	vector<string> filtrardo_columnas_nombres_contiene(char x) {
		vector<CArchivo*> nombre;
		vector<string> nombres_filtrados;
		auto l = [&](CArchivo* x) {
			nombre.push_back(x);
		};
		this->TreeName->inorder(l);
		for (auto e : nombre) {
			for (int i = 0; i < e->getNombre().size(); ++i) {
				if (e->getNombre()[i] == x) {
					nombres_filtrados.push_back(e->getRuta());
					break;
				}
			}
		}
		return nombres_filtrados;
	}
	vector<CArchivo*> filtrardo_columnas_tamaño_mayor(long long tam) {
		vector<CArchivo*> tamaño;
		this->TreeSize->findMa(tam, tamaño);
		return tamaño;
	}
	vector<CArchivo*> filtrardo_columnas_tamaño_menor(long long tam) {
		vector<CArchivo*> tamaño;
		this->TreeSize->findMi(tam, tamaño);
		return tamaño;
	}
	vector<CArchivo*> filtrardo_columnas_tamaño_igual(long long tam) {
		vector<CArchivo*> v;
		this->TreeSize->find(tam, v);
		return v;
	}


};