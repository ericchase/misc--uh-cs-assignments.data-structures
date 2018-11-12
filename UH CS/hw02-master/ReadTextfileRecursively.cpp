#include <iostream>

#include <string>
#include <fstream>

using namespace std;

int readFileRecursively_aux(ifstream & aStream) {
	string str;
	if(getline(aStream, str)) {
		cout << str << endl;
		int remaining = readFileRecursively_aux( aStream );
		return 1 + remaining;
	}
	return 0;
}

// returns number of lines read
int readFileRecursively(string filename) {
	ifstream olaf( filename );
	int n = readFileRecursively_aux( olaf );
	olaf.close();
	return n;
}

int main( int argc, char** argv )
{
	int lines = readFileRecursively( "easy-test-case.1.txt" );
	cout << "Read " << lines << " lines"<< endl;
}

