#include <iostream>
#include "Playlist.h"
#include "Song.h"

int main() {
	
	Playlist p;

	p.add("song 1", 0, 1, 55, "rp", "song1.txt");
	p.add("song 2", 0, 1, 5, "p", "song1.txt");
	
	p.print();

	//p.find("song 2");

	//p.findGenre('r');

	p.save("song 1", "save1.dat");

	Song s;
	s.readFromBinaryFile("save1.dat");
	s.print();
}
