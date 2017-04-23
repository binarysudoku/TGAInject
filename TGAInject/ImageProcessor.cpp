#include "ImageProcessor.h"

//Load file from filename to buffer
vector<char> ImageProcessor::readFileToBuffer(char* fname, bool verbose)
{
	ifstream input(fname, ios::in | ifstream::binary);

	input.seekg(0, ios::end);
	size_t size = input.tellg();
	input.seekg(0, ios::beg);
	vector<char> output(size, 0);
	cout << output.size();

	char c = ' ';
	for (int i = 0; i<output.size(); i++)
	{
		input.get(c);
		output[i] = c;
		if (verbose) { cout << i << ":  " << c << "\n"; }
	}

	return output;
}