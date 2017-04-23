// TGAInject_PROTO.cpp : Defines the entry point for the console application.
//

#include "TGAInject.h"

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;



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
