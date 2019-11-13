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
		auto l3 = [](CArchivo* a) {return a->getTamaño(); };
		auto l4 = [](CArchivo* a) {return a->getFecha(); };
		this->TreeName = new CAVLtree<CArchivo*, string, nullptr> (l1);
		this->TreeExten = new CAVLtree<CArchivo*, string, nullptr>(l2);
		this->TreeSize = new CAVLtree<CArchivo*, long long, nullptr>    (l3);
		this->TreeDate = new CAVLtree<CArchivo*, string, nullptr> (l4);
	}
	void scanear(string ruta) {
		for (const auto& entry : recursive_directory_iterator(ruta)) {
			string ruta = entry.path().string();
			string nombre = entry.path().filename().string();
			string extension = entry.path().extension().string();
			long long tamaño = -1;
			if (is_directory(status(entry.path())))  tamaño = 0;
			else tamaño = file_size(entry.path());
			auto ftime = last_write_time(entry.path());
			time_t cftime = decltype(ftime)::clock::to_time_t(ftime);
			string fecha = asctime(localtime(&cftime));

			CArchivo* archivo = new CArchivo(nombre, extension, tamaño, fecha, ruta);
			this->TreeName->add(archivo);
			this->TreeExten->add(archivo); // Sun Nov 3 19:04:26 2019 "Sun Nov  3 19:04:26 2019\n"
			this->TreeSize->add(archivo);
			this->TreeDate->add(archivo);
			//HOLASA
		}
	}
	string buscar_archivo_nombre(string nombre) {	
		return this->TreeName->find(nombre) == nullptr ? "nada" : this->TreeName->find(nombre)->getRuta();
	}
	string buscar_archivo_exten(string extension) {
		return this->TreeExten->find(extension) == nullptr ? "nada" : this->TreeExten->find(extension)->getRuta();
	}
	string buscar_archivo_tamaño(long long tamaño) {
		return this->TreeSize->find(tamaño) == nullptr ? "nada" : this->TreeSize->find(tamaño)->getRuta();
	}
	string buscar_archivos_fecha(string fecha) {
		return this->TreeDate->find(fecha) == nullptr ? "nada" : this->TreeDate->find(fecha)->getRuta();
	}
	//list<string> filtrado_columnas_nombres_inicial(char ini) {
	//	list<string> nombre;
	//	auto l = [&](CArchivo* x) {
	//		nombre.push_back(x->getNombre());
	//	};
	//	this->TreeName->inorder(l);
	//	//for (auto e : nombre) {
	//		for (list<string>::iterator it = nombre.begin(); it != nombre.end(); ++it) {
	//			if ((*it)[0] != ini) {
	//				nombre.remove(*it);
	//			}
	//		}
	//	//}
	//	return nombre;
	//}
	
	vector<string> filtrado_columnas_nombres_inicial(char ini) {
		vector<CArchivo*> nombre;
		vector<string> nombres_filtrados;
		auto l = [&](CArchivo* x) {
			nombre.push_back(x);
		};
		this->TreeName->inorder(l);
		for (auto e : nombre) {
			if (e->getNombre()[0] == ini) {
				nombres_filtrados.push_back(e->getRuta());
			}
		}
		return nombres_filtrados;
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
	vector<string> filtrardo_columnas_tamaño_mayor(long long tam) {
		vector<CArchivo*> tamaño;
		vector<string> tamaños_filtrados;
		auto l = [&](CArchivo* x) {
			tamaño.push_back(x);
		};
		this->TreeName->inorder(l);
		for (auto e : tamaño) {
			if (e->getTamaño() > tam) {
				tamaños_filtrados.push_back(e->getRuta());
			}
		}
		return tamaños_filtrados;
	}
	/*vector<long long> filtrardo_columnas_tamaño_mayor1(long long tam) {
		//vector<CArchivo*> tamaño;
		vector<long long> tamaños_filtrados;
		auto l = [&](CArchivo* x) {
			tamaños_filtrados.push_back(x->getTamaño());
		};
		this->TreeName->inorder(l);
		for (int i = tamaños_filtrados.size() - 1; i >= 0; --i) {
			long long siz = tamaños_filtrados[i];
			if (siz < tam) {
				tamaños_filtrados.erase(tamaños_filtrados.begin() + i);
			}
		}
		return tamaños_filtrados;
	}*/
	vector<string> filtrardo_columnas_tamaño_menor(long long tam) {
		vector<CArchivo*> tamaño;
		vector<string> tamaños_filtrados;
		auto l = [&](CArchivo* x) {
			tamaño.push_back(x);
		};
		this->TreeName->inorder(l);
		for (auto e : tamaño) {
			if (e->getTamaño() < tam) {
				tamaños_filtrados.push_back(e->getRuta());
			}
		}
		return tamaños_filtrados;
	}
	vector<string> filtrardo_columnas_tamaño_igual(long long tam) {
		vector<CArchivo*> tamaño;
		vector<string> tamaños_filtrados;
		auto l = [&](CArchivo* x) {
			tamaño.push_back(x);
		};
		this->TreeName->inorder(l);
		for (auto e : tamaño) {
			if (e->getTamaño() == tam) {
				tamaños_filtrados.push_back(e->getRuta());
			}
		}
		return tamaños_filtrados;
	}
	

};