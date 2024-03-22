#include <iostream>
#include "Playlist.h"
#include "Song.h"

int main() {
	
	Playlist p;

	p.add("song A", 0, 1, 55, "rp", "song1.txt");
	p.add("song Z", 2, 3, 45, "p", "song1.txt");
	p.add("song C", 3, 1, 5, "p", "song1.txt");
	p.add("song B", 0, 1, 35, "p", "song1.txt");

	//p.sortByName();
	p.sortByDuration();
	
	p.print();

	//p.find("song 2");

	//p.findGenre('r');

	//p.save("song 1", "save1.dat");

	//Song s;
	//s.readFromBinaryFile("save1.dat");
	//s.print();
}
