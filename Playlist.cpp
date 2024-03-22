#include "Playlist.h"

void Playlist::add(const char* name, int hour, int min, int sec, const char* genre, const char* filename)
{
	playlist[size].createSong(name, hour, min, sec, genre, filename); //copy constr is preferable
	size++;
}

void Playlist::print() const
{
	for (int i = 0; i < size; i++) {
		playlist[i].print();
	}
}
