#ifndef WORDDB_H
#define WORDDB_H

#include <vector>
#include <string>

class wordDB
{

public:

wordDB();

~wordDB();

std::string getRandomWord();

private:

std::vector< std::string > _listOfWords;

};

#endif
