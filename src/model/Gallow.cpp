#include <algorithm>

#include "Gallow.h"

#define ATTEMPTS 6

Gallow::Gallow() :
    _numberOfRights( 0 ),
    _word( WordDB::getRandomWord() )
{
    for( int i = 0; i < _word.size(); i++ )
    {
        _buffer.insert( i, "_" );
    }
}

void Gallow::pushLetter( char letter )
{
    if( !isalpha( letter ) && letter != '-' || 
        std::find( _typedLetters.begin(), _typedLetters.end(), letter ) != _typedLetters.end() )
    {
        return;
    }

    _typedLetters.push_back( letter );

    int pos = 0;
    while( true )
    {
        int firstOc = _word.find( letter, pos );

        if( firstOc == std::string::npos )
        {
            if( pos == 0 )
            {
                _wrongLetters.push_back( letter );
            }

            return;
        }

        pos = firstOc + 1;
        _buffer.replace( firstOc, 1, 1, letter );
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
    if( _wrongLetters.size() >= ATTEMPTS )
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

std::string Gallow::getStringBuffer()
{
    return _buffer;
}

int Gallow::wordSize()
{
    return _word.size();
}
