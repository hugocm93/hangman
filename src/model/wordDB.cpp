#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "wordDB.h"

wordDB::wordDB()
{
    std::ifstream file;
    file.open( "../resources/words.txt", std::ios::in );
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

wordDB::~wordDB()
{
}

std::string wordDB::getRandomWord()
{
    std::srand(std::time(0));
    int randomIndex = std::rand()%_listOfWords.size();

    return _listOfWords[ randomIndex ] ;
}
