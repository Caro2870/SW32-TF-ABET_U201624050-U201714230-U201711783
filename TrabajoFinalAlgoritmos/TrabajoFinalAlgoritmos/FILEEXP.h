#pragma once
#include <iostream>
#include <filesystem>
#include "FILE.h"
#include "AVLtree.h"
using namespace std;
using namespace std::experimental::filesystem;
class FILEEXP {
	AVLtree<File*, string>* TreeName;
	AVLtree<File*, string>* TreeExtension;
	AVLtree<File*, int>* TreeSize;
	AVLtree<File*, string>* TreeDate;
	string name;
	string extension;
	int size;
	string date;
public:
	FILEEXP() {
		this->TreeName = new AVLtree<File*, string>([](File* f) { return f->getName(); });
		this->TreeExtension = new AVLtree<File*, string>([](File* f) { return f->getExtension(); });
		this->TreeSize = new AVLtree<File*, int>([](File* f) { return f->getSize(); });
		this->TreeDate = new AVLtree<File*, string>([](File* f) { return f->getDate(); });
	}
	void serialize() {
	}
	void index() {}
	void file_search() {}
	void filter_by_columns() {}
	void final_order() {}
	void setName(string name) { this->name = name; }
	void setExten(string extension) { this->extension = extension; }
	void setSize(int size) { this->size = size; }
	void setDate(string date) { this->date = date; }
};