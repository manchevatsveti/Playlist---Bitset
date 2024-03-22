#include <iostream>
#pragma once
#include "Song.h"

namespace {
	const int MAX_PLAYLIST_LEN = 30;
}
class Playlist
{
private:
	Song playlist[MAX_PLAYLIST_LEN];
	int size = 0;


public:
	void add(const char* name, int hour, int min, int sec, const char* genre, const char* filename);
	void print()const;
};

