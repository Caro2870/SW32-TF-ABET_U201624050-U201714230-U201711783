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
public:
	CFileExp() {
		auto l1 = [](CArchivo* a) {return a->getNombre(); };
		auto l2 = [](CArchivo* a) {return a->getExtension(); };
		auto l3 = [](CArchivo* a) {return a->getTama�o(); };
		auto l4 = [](CArchivo* a) {return a->getFecha(); };
		this->TreeName = new CAVLtree<CArchivo*, string, nullptr>(l1);
		this->TreeExten = new CAVLtree<CArchivo*, string, nullptr>(l2);
		this->TreeSize = new CAVLtree<CArchivo*, long long, nullptr>(l3);
		this->TreeDate = new CAVLtree<CArchivo*, string, nullptr>(l4);
	}
	void scanear(string ruta) {
		for (const auto& entry : recursive_directory_iterator(ruta)) {
			string ruta = entry.path().string();
			string nombre = entry.path().filename().string();
			string extension = entry.path().extension().string();
			long long tama�o = -1;
			if (is_directory(status(entry.path())))  tama�o = 0;
			else tama�o = file_size(entry.path());
			auto ftime = last_write_time(entry.path());
			time_t cftime = decltype(ftime)::clock::to_time_t(ftime);
			string fecha = asctime(localtime(&cftime));

			CArchivo* archivo = new CArchivo(nombre, extension, tama�o, fecha, ruta);
			this->TreeName->add(archivo);
			this->TreeExten->add(archivo); // Sun Nov 3 19:04:26 2019 "Sun Nov  3 19:04:26 2019\n"
			this->TreeSize->add(archivo);
			this->TreeDate->add(archivo);
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
	vector<CArchivo*> buscar_archivo_tama�o(long long tama�o) {
		vector<CArchivo*> v;
		this->TreeSize->find(tama�o, v);
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
	vector<string> filtrardo_columnas_nombres_final(char fin) {
		vector<CArchivo*> nombre;
		vector<string> nombres_filtrados;
		auto l = [&](CArchivo* x) {
			nombre.push_back(x);
		};
		this->TreeName->inorder(l);
		for (auto e : nombre) {
			if (e->getNombre()[e->getNombre().size() - 1] == fin) {
				nombres_filtrados.push_back(e->getRuta());
			}
		}
		return nombres_filtrados;
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
	vector<string> filtrardo_columnas_tama�o_mayor(long long tam) {
		vector<CArchivo*> tama�o;
		vector<string> tama�os_filtrados;
		auto l = [&](CArchivo* x) {
			tama�o.push_back(x);
		};
		this->TreeName->inorder(l);
		for (auto e : tama�o) {
			if (e->getTama�o() > tam) {
				tama�os_filtrados.push_back(e->getRuta());
			}
		}
		return tama�os_filtrados;
	}
	/*vector<long long> filtrardo_columnas_tama�o_mayor1(long long tam) {
	//vector<CArchivo*> tama�o;
	vector<long long> tama�os_filtrados;
	auto l = [&](CArchivo* x) {
	tama�os_filtrados.push_back(x->getTama�o());
	};
	this->TreeName->inorder(l);
	for (int i = tama�os_filtrados.size() - 1; i >= 0; --i) {
	long long siz = tama�os_filtrados[i];
	if (siz < tam) {
	tama�os_filtrados.erase(tama�os_filtrados.begin() + i);
	}
	}
	return tama�os_filtrados;
	}*/
	vector<string> filtrardo_columnas_tama�o_menor(long long tam) {
		vector<CArchivo*> tama�o;
		vector<string> tama�os_filtrados;
		auto l = [&](CArchivo* x) {
			tama�o.push_back(x);
		};
		this->TreeName->inorder(l);
		for (auto e : tama�o) {
			if (e->getTama�o() < tam) {
				tama�os_filtrados.push_back(e->getRuta());
			}
		}
		return tama�os_filtrados;
	}
	vector<string> filtrardo_columnas_tama�o_igual(long long tam) {
		vector<CArchivo*> tama�o;
		vector<string> tama�os_filtrados;
		auto l = [&](CArchivo* x) {
			tama�o.push_back(x);
		};
		this->TreeName->inorder(l);
		for (auto e : tama�o) {
			if (e->getTama�o() == tam) {
				tama�os_filtrados.push_back(e->getRuta());
			}
		}
		return tama�os_filtrados;
	}


};