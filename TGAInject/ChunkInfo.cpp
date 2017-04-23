#include "ChunkInfo.h"

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

#endif