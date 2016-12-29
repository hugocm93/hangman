#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "WordDB.h"

std::vector< std::string > WordDB::_listOfWords = std::vector< std::string >();
WordDB WordDB::_instance = WordDB();

WordDB::WordDB()
{
    std::ifstream file;
    file.open( "resources/words.txt", std::ios::in );
    if( !file.is_open() )
    {
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
        exit( 1 );
    }

    std::string temp;
    while( std::getline( file, temp ) )
    {
        _listOfWords.push_back( temp );
    }

    file.close();
}


std::string WordDB::getRandomWord()
{
    std::srand( std::time( 0 ) );
    int randomIndex = std::rand() % _listOfWords.size();

    return _listOfWords[ randomIndex ];
}


