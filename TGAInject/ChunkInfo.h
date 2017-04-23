#pragma once

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

class ChunkInfo
{
	public:
		ChunkInfo();
		void SetCMapData(int i);
		void SetImgData(int i);
		void SetDevData(int i);

	public:
		const int IDLength = 0;
		const int CMapType = 1;
		const int ImgType = 2;
		const int CMapSpec = 3;
		const int CMapOrigin = 3;
		const int CMapLength = 5;
		const int CMapEntrySize = 7;
		const int ImgSpec = 8;
		const int ImgXOrigin = 8;  //2 BYTES BECAUSE LARGE?
		const int ImgYOrigin = 10; //2 BYTES BECAUSE LARGE?
		const int ImgWidth = 12;   //2 BYTES BECAUSE LARGE?
		const int ImgHeight = 14;  //2 BYTES BECAUSE LARGE?
		const int ImgPixelDepth = 16;
		const int ImgDescriptor = 17;

		//variable length chunks
		const int ImgID = 18;
		int CMapData; //variable location
		int ImgData;  //variable location
		int DevData;  //variable location
};