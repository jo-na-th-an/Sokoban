#include <fstream>
#include <iostream>

using namespace std;


void saveLevel(string level) {

	fstream file;

	file.open(level, ios::out);

		if (!file) {
			cout << "Archivo no encontrado";
		}


}

void loadLevel() {
	
}