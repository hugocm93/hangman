#ifndef WORDDB_H
#define WORDDB_H

#include <vector>
#include <string>

class WordDB
{

public:

virtual ~WordDB() = default;

static std::string getRandomWord();

private:

WordDB();

static WordDB _instance;

static std::vector< std::string > _listOfWords;

};

#endif
