#include <iostream>
#include "Playlist.h"

int main() {
	
	Playlist p;

	p.add("song 1", 0, 1, 55, "rp", "song1.txt");
	p.add("song 2", 0, 1, 5, "p", "song1.txt");
	
	p.print();

}
