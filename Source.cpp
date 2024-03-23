#include <iostream>
#include <fstream>
#include "Playlist.h"
#include "Song.h"

int main() {

	/*std::ofstream ofs("Song4.dat", std::ios::out | std::ios::binary);
	char ch[2] = "";
	ch[0] = 'A';
	ch[1] = '\n';

	ofs.write((const char*)ch, sizeof(char) * 2);*/

	/*Song s;
	s.createSong("song A", 0, 1, 55, "rp", "Song.dat");
	std::cout << s.content;*/
	
	Playlist p;

	p.add("song A", 0, 1, 55, "rp", "Song1.dat");
	p.add("song Z", 2, 3, 45, "p", "Song2.dat");
	p.add("song C", 3, 1, 5, "p", "Song3.dat");
	p.add("song B", 0, 1, 35, "p", "Song4.dat");

	p.modify("song C", "song B");
	p.save("song C", "song_res.dat");

	//p.sortByName();
	//p.sortByDuration();
	
	p.print();

	//p.find("song 2");

	//p.findGenre('r');

	//p.save("song 1", "save1.dat");

	//Song s;
	//s.readFromBinaryFile("save1.dat");
	//s.print();
}
