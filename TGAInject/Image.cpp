#include "Image.h"

#ifndef IMAGE_H
#define IMAGE_H

//Image Constructor
Image::Image(vector<char> buffer)
{
	
}

void Image::ReadChunkInfo(vector<char> buffer) //read chunk info from buffer to chunkinfo
{
	//set CMapData offset to offset of ImgID + the files IDLength
	ImgChunks.SetCMapData(ImgChunks.ImgID + (int)buffer[ImgChunks.IDLength]);

	//convert cmaplength and cmaplength+1 to int (lo-hi)
	unsigned short Length = (buffer[ImgChunks.CMapLength] << 8) | buffer[ImgChunks.CMapLength + 1];
	//convert cmapentrysize and cmapentrysize+1 to int (lo-hi)
	unsigned short EntrySize = (buffer[ImgChunks.CMapEntrySize] << 8) | buffer[ImgChunks.CMapEntrySize + 1];

	//set ImgData offset to CMapData offset + (CMap Length * CMap Entry Size)
	ImgChunks.SetImgData((int)(Length*EntrySize));
}

void Image::WriteImageData(vector<char> buffer, ChunkInfo chunks)
{
	
}

/*
void Image::TransferChannel(Image img, int channelID)
{
}
*/

char Channel::GetPixel(int i)
{
	return 0;
}

void Channel::SetPixel(int i)
{

}

#endif