#include "Song.h"
#pragma warning(disable: 4996)

void Song::modify(int n)
{
	int i = 0;
	int lastPos = n - 1;

	while (true) {
		
		if ((lastPos + n) % BYTE_SIZE < lastPos) {
			i++;

			if (i == MAX_SONG_CONTENT_LEN)
				break;
		}
		lastPos = (lastPos + n) % BYTE_SIZE;

		content[i] |= (1 << lastPos);
	}
}

Song::Song(const char* name, int hour, int min, int sec, const char* genre, const char* filename)
{
	if (name) strcpy(this->name, name);

	this->duration.setTime(hour,min,sec);

	if(genre) readGenre(genre);

	if(filename) readContent(filename);
}

void Song::createSong(const char* name, int hour, int min, int sec, const char* genre, const char* filename)
{
	if (name) strcpy(this->name, name);

	this->duration.setTime(hour, min, sec);

	if (genre) readGenre(genre);

	if (filename) readContent(filename);
}

void Song::mix(const Song& other)
{
	int len = sizeContent <= other.sizeContent ? sizeContent : other.sizeContent;

	for (int i = 0; i < len; i++) {
		content[i] ^= other.content[i];
	}
}

void Song::print() const
{
	std::cout << name<<" ";
	duration.print();
	std::cout << " ";
	printGeneres();
	std::cout << std::endl;
}

void Song::readGenre(const char* genre)
{
	int len = strlen(genre);

	for (int i = 0; i < len; i++) {
		addGenre(genre[i]);
	}
}

void Song::addGenre(char g)
{
	genre |= (1 << findPosGenre(g));
}

void Song::readContent(const char* filename)
{
	std::ifstream ifs(filename, std::ios::in);

	if (!ifs.is_open()) {
		std::cerr << "Invalid filename.";
		return;
	}
	readContentFromFile(ifs);
}

void Song::readContentFromFile(std::ifstream& ifs)
{
	ifs.getline(content, MAX_SONG_CONTENT_LEN);

}

bool Song::isGenreIn(char g) const
{
	return genre & (1 << findPosGenre(g));
}

int Song::findPosGenre(char ch) const
{
	switch (ch) {
		case MusicGenre::POP: {
			return MusicGenre::POP_POS;
		}case MusicGenre::ROCK: {
			return MusicGenre::ROCK_POS;
		}case MusicGenre::HIPHOP: {
			return MusicGenre::HIPHOP_POS;
		}case MusicGenre::EDM: {
			return MusicGenre::EDM_POS;
		}case MusicGenre::JAZZ: {
			return MusicGenre::JAZZ_POS;
		}
	}
}

void Song::printGeneres() const
{
	bool atLeastOne = false;

	if (isGenreIn(MusicGenre::POP)) {
		std::cout << "Pop";
		atLeastOne = true;
	}

	if (isGenreIn(MusicGenre::ROCK)) {
		if (atLeastOne) std::cout << "&";
		std::cout << "Rock";
		atLeastOne = true;
	}

	if (isGenreIn(MusicGenre::HIPHOP)) {
		if (atLeastOne) std::cout << "&";
		std::cout << "Hi Hop";
		atLeastOne = true;
	}

	if (isGenreIn(MusicGenre::EDM)) {
		if (atLeastOne) std::cout << "&";
		std::cout << "EDM";
		atLeastOne = true;
	}

	if (isGenreIn(MusicGenre::JAZZ)) {
		if (atLeastOne) std::cout << "&";
		std::cout << "Jazz";
		atLeastOne = true;
	}
}

void Song::Time::setTime(int hour, int min, int sec) 
{
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}

void Song::Time::print() const
{
	std::cout << hour << ":" << min << ":" << sec;
}
