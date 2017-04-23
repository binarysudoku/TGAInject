#pragma once

#include "ChunkInfo.h"
#include <vector>

using namespace std;

/*
1  bytes IDLength - number of chars in ImgID
1  bytes CMapType - color map type, ignore for now
1  bytes ImgType - PseudoColor, TrueColor or DirectColor
0  = no imgdata
1  = uncompressed cmapped image
2  = uncompresssed truecolor image
3  = uncompressed b&w image
9  = runlength encoded cmapped image
10 = runlength encoded truecolor image
11 = runlength encoded b&w image
5  bytes CMapSpec - contains data on the location, length and entry size of the image
0-1 = first entry index - index of first cmap entry
2-3 = cmap length - total number of cmap entries
4   = entry size - number of bits per entry
10 bytes ImgSpec - contains data on size and pixel info of the image
0-1 = x origin
2-3 = y origin
4-5 = image width
6-7 = image height
8   = pixel depth
9   = image descriptor
bit 0-3 = attribute bits per pixel
bit 4-5 = order in which pixel data is transferred from file to screen (bit4 l/r order, bit5 t/b order)
IDLength bytes ImgID - (optional) identifying information about the image - max 255 bytes
?? bytes CMapData -
?? bytes ImgData -
rest is DevData -
*/

class Image
{
	public:
		Image(vector<char> buffer);
		
		void TransferChannel(Image img, int channelID);
		void ReadChunkInfo(vector<char> buffer); //read chunk info from buffer to chunkinfo
		void WriteImageData(vector<char> buffer, ChunkInfo chunks); //write image information from buffer using chunks
		void WriteImageChannel(vector<char> buffer, ChunkInfo chunks, Channel channels[]); //write channel data from buffer using chunks

		//Data locations in file
		ChunkInfo ImgChunks;

		//Image metrics
		int width;
		int height;
		int pixeldepth;

		//Image Data
		vector<char> buffer;
		Channel channels[4];
};

class Channel
{
	public:
		char GetPixel(int i);
		void SetPixel(int i);

	vector<char> pixels;
};