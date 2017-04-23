#pragma once

#include <vector>

using namespace std;

class ImageProcessor
{
	vector<char> readFileToBuffer(char * fname, bool verbose);
};