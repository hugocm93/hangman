#include <iostream>

#include "Gallow.h"

#define ATTEMPTS 6

Gallow::Gallow()
{
    wordDB db;
    _word = db.getRandomWord();
    _numberOfRights = 0;
}

Gallow::~Gallow()
{
}

std::vector< int > Gallow::hasLetter( char letter )
{
    std::vector< int > indexes;
    int pos = 0;

    while( true )
    {
        int firstOc = _word.find( letter, pos );

        if( firstOc == std::string::npos )
        {
            if( indexes.empty() )
            {
                _wrongLetters.push_back( letter );
            }

            return indexes;
        }

        pos = firstOc + 1;
        indexes.push_back( firstOc );
        _numberOfRights++;
    }
}

bool Gallow::didWin()
{
    if( _numberOfRights == _word.size() )
    {
        return true;
    }

    return false;
}

bool Gallow::didLose()
{
    if( _wrongLetters.size() == ATTEMPTS )
    {
        return true;
    }
    
    return false;
}

std::vector< char > Gallow::getWrongLetters()
{
    return _wrongLetters;
}

std::string Gallow::getWord()
{
    return _word;
}

int Gallow::wordSize()
{
    return _word.size();
}
