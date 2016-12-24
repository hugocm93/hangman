#ifndef GALLOW_H
#define GALLOW_H

#include <string>
#include <vector>

#include "wordDB.h"

class Gallow
{

public:

    Gallow();
    
    ~Gallow();

    std::vector< int > hasLetter( char letter );
    
    bool didWin();

    bool didLose();

    std::vector< char > getWrongLetters();

    std::string getWord();

    int wordSize();

private:

    std::string _word;
    int _numberOfRights;

    std::vector< char > _wrongLetters;
};

#endif
