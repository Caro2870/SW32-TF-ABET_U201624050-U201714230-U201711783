#pragma once
#include <string>
using namespace std;

class File {
	string name;
	string extension;
	int size;
	string date;
public:
	File(string name, string extension, int size, string date)
		:name(name), extension(extension), size(size), date(date) {}
	string getName() { return this->name; }
	string getExtension() { return this->extension; }
	int getSize() { return this->size; }
	string getDate() { return this->date; }
};