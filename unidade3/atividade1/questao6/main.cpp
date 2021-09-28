#include <iostream>
using std::cout;
using std::endl;


#include <iomanip>
using std::setw;

#include <fstream>

int main() {
  std::ofstream file;
  file.open("dados.dat");
  file << "char            " << sizeof(char) << "\n";
  file << "int             " << sizeof(int) << "\n";
  file << "unsigned int    " << sizeof(unsigned int) << "\n";
  file << "signed int      " << sizeof(signed int) << "\n";
  file << "short int       " << sizeof(short int) << "\n";
  file << "long int        " << sizeof(long int) << "\n";
  file << "long long int   " << sizeof(long long int) << "\n";
  file << "float           " << sizeof(float) << "\n";
  file << "double          " << sizeof(double) << "\n";
  file << "long double     " << sizeof(long double) << "\n";
  file << "bool            " << sizeof(bool) << "\n";

  file.close();

  std::ifstream fileToRead("dados.dat");

  std::string line;
  while(getline(fileToRead, line)) {
    cout << line << endl;
  }

  fileToRead.close();

  return 0;
}