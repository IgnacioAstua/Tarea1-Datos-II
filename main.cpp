#include <iostream>
#include <fstream>
using namespace std;

int l = 20000000;

void generator () {
    int list[l];
    cout << sizeof(list);
    ofstream file;
    ofstream *pfile = &file;
    file.open("/home/nacho/Escritorio/Archivos/hola.bin");

    for (int i = 0; i < l; ++i) {
        *pfile << list[i];
    }
    file.close();
    /*
    ifstream ifile;
    file.open("/home/nacho/Escritorio/Archivos/hola.txt");
    int s[5000];
    for (int i = 0; i < 5000; ++i) {
        ifile >> s[i];
    }
    for (int i = 0; i < 5000; ++i) {
        cout << s[i] << " ";
    }
    */
}

int main() {
    generator();
    return 0;
}
