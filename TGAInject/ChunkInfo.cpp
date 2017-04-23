#include "ChunkInfo.h"
#include <iostream>

using namespace std;

#ifndef CHUNKINFO_H
#define CHUNKINFO_H

ChunkInfo::ChunkInfo()
{

}

void ChunkInfo::SetCMapData(int i)
{
	CMapData = i;
}

void ChunkInfo::SetImgData(int i)
{
	ImgData = i;
}

void ChunkInfo::SetDevData(int i)
{
	DevData = i;
}

//TEST

void ChunkInfo::TEST_DumpChunkInfo()
{
	cout << "IDLength: " << IDLength << "\n";
	cout << "CMapType: " << CMapType << "\n";
	cout << "ImgType: " << ImgType << "\n";
	cout << "CMapSpec: " << CMapSpec << "\n";
	cout << "CMapOrigin: " << CMapOrigin << "\n";
	cout << "CMapLength: " << CMapLength << "\n";
	cout << "CMapEntrySize: " << CMapEntrySize << "\n";
	cout << "ImgSpec: " << ImgSpec << "\n";
	cout << "ImgXOrigin: " << ImgXOrigin << "\n";  //2 BYTES BECAUSE LARGE?
	cout << "ImgYOrigin: " << ImgYOrigin << "\n"; //2 BYTES BECAUSE LARGE?
	cout << "ImgWidth: " << ImgWidth << "\n";   //2 BYTES BECAUSE LARGE?
	cout << "ImgHeight: " << ImgHeight << "\n";  //2 BYTES BECAUSE LARGE?
	cout << "ImgPixelDepth: " << ImgPixelDepth << "\n";
	cout << "ImgDescriptor: " << ImgDescriptor << "\n";

	//variable length chunks
	cout << "ImgID: " << ImgID << "\n";
	cout << "CMapData: " << CMapData << "\n"; //variable location
	cout << "ImgData: " << ImgData << "\n";  //variable location
	cout << "DevData: " << DevData << "\n";  //variable location
}

#endif