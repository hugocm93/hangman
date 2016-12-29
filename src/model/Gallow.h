#ifndef GALLOW_H
#define GALLOW_H

#include <string>
#include <vector>

#include "WordDB.h"

class Gallow
{

public:

    Gallow();
    
    ~Gallow() = default;

    void pushLetter( char letter );
    
    bool didWin();

    bool didLose();

    std::vector< char > getWrongLetters();

    std::string getWord();

    std::string getStringBuffer();

    int wordSize();

private:

    int _numberOfRights;
    std::string _word;
    std::vector< char > _typedLetters;
    std::vector< char > _wrongLetters;
    std::string _buffer;
};

#endif
