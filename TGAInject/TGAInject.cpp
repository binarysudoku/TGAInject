// TGAInject_PROTO.cpp : Defines the entry point for the console application.
//

#include "TGAInject.h"

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Load file from filename to buffer
vector<char> readFileToBuffer(char* fname,bool verbose)
{	
	ifstream input(fname, ios::in | ifstream::binary);

	input.seekg(0, ios::end);
	size_t size = input.tellg();
	input.seekg(0, ios::beg);
	vector<char> output(size, 0);
	cout << output.size();

	char c = ' ';
	for (int i = 0;i<output.size();i++)
	{
		input.get(c);
		output[i] = c;
		if (verbose) { cout << i << ":  " << c << "\n"; }
	}

	return output;
 }

int main()
{
	//Image InputMask = BitMask();
	//Image InputImage = Image();
	//Image OutputImage = Image();

	vector<char> buffer = readFileToBuffer("testdefault.tga", true);
	
	cout << "WRITE SOME FUCKING TEST CODE\n";
	int i;
	cin >> i;
    return 0;
}
