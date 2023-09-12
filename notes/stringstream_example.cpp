#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int args, char * argv[])
{
	ifstream infile;
	ofstream outfile;
	string line, partOfLine;


	infile.open(argv[1]);
	outfile.open("intermediate");

	while (getline(infile, line))
	{
		stringstream ss(line);

		while (ss >> partOfLine && partOfLine[0] != ';')
			outfile << partOfLine << '\t';

		outfile << "\n";
	}

	infile.close();
	outfile.close();

	return 0;
}