#include <iostream>

#include <string>
#include <fstream>

using namespace std;

int main( int argc, char** argv )
{
	// verify that there was 1 parameter passed.
	if( argc != 2 ) {
		cout << "Error, please specify parameter correctly. This program needs a parameter to work." << endl;
		return 0;
	}
	// initialize the variable 'parameter' with the argument 1
	string parameter(argv[1]);

	// get only the filename via substring,
	// assuming program had parameter such as "icecreamFlavor=vanilla.cougar.txt"
	string filename = parameter.substr(15);
	cout << filename << endl;

	// find the position of the .cougar.txt
	string::size_type position = filename.find(".cougar.txt");
	cout << "position: " << position << endl;
	string base = filename.substr(0, position);
	cout << "base: " << base << endl;
}
