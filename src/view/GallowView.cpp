#include <iostream>
#include <cstdio>
#include <cstdlib> 

#include "GallowView.h"
#include "../controller/GallowController.h"

GallowView::GallowView( int wordSize, GallowController* controller ) :
    _wordSize( wordSize ),
    _controller( controller )
{
    for(int i = 0; i < _wordSize; i++ )
    {
        _word.insert( i, "_" );
    }
    update();
}

GallowView::~GallowView()
{
}

void GallowView::loop()
{
    char letter;

    while( std::cin >> letter )
    {
       _controller->incomingLetter( letter );
    }
}

void GallowView::update( char letter, std::vector< int > indexes )
{
    system( "clear" ); 
    drawGallow();
    drawFooter( letter, indexes );
}

void GallowView::drawGallow()
{
    switch( _controller->getNumberOfMistakes() )
    {
        case 0:
           std::cout << "  _________  " << std::endl;   
           std::cout << " |         | " << std::endl;
           std::cout << " |           " << std::endl;
           std::cout << " |           " << std::endl; 
           std::cout << " |           " << std::endl; 
           std::cout << " |           " << std::endl;  
           std::cout << " |           " << std::endl;  
        break;
        case 1:
           std::cout << "  _________  " << std::endl;   
           std::cout << " |         | " << std::endl;
           std::cout << " |         0 " << std::endl;
           std::cout << " |           " << std::endl; 
           std::cout << " |           " << std::endl; 
           std::cout << " |           " << std::endl;  
           std::cout << " |           " << std::endl;  
        break;
        case 2:
           std::cout << "  _________  " << std::endl;   
           std::cout << " |         | " << std::endl;
           std::cout << " |         0 " << std::endl;
           std::cout << " |          \\ " << std::endl; 
           std::cout << " |             " << std::endl; 
           std::cout << " |           " << std::endl;  
           std::cout << " |           " << std::endl;  
        break;
        case 3:
           std::cout << "  _________  " << std::endl;   
           std::cout << " |         | " << std::endl;
           std::cout << " |         0 " << std::endl;
           std::cout << " |        / \\ " << std::endl; 
           std::cout << " |             " << std::endl; 
           std::cout << " |           " << std::endl;  
           std::cout << " |           " << std::endl;  
        break;
        case 4:
           std::cout << "  _________  " << std::endl;   
           std::cout << " |         | " << std::endl;
           std::cout << " |         0 " << std::endl;
           std::cout << " |        /|\\ " << std::endl; 
           std::cout << " |             " << std::endl; 
           std::cout << " |           " << std::endl;  
           std::cout << " |           " << std::endl;  
        break;
        case 5:
           std::cout << "  _________  " << std::endl;   
           std::cout << " |         | " << std::endl;
           std::cout << " |         0 " << std::endl;
           std::cout << " |        /|\\ " << std::endl; 
           std::cout << " |          \\ " << std::endl; 
           std::cout << " |           " << std::endl;  
           std::cout << " |           " << std::endl;  
        break;
        case 6:
           std::cout << "  _________  " << std::endl;   
           std::cout << " |         | " << std::endl;
           std::cout << " |         0 " << std::endl;
           std::cout << " |        /|\\ " << std::endl; 
           std::cout << " |        / \\ " << std::endl; 
           std::cout << " |           " << std::endl;  
           std::cout << " |           " << std::endl;  
        break;
    }
}

void GallowView::drawFooter( char newLetter, std::vector< int > indexes )
{
    if( indexes.empty() )
    {
        newLetter = '_';
    }

    for(int i = 0; i < indexes.size(); i++ )
    {
        _word.replace( indexes[ i ], 1, 1, newLetter );
    }
    std::cout << " " << std::endl;    
    std::cout << _word << std::endl;    
    std::cout << " " << std::endl;    
    std::cout << "Erros: " << std::endl;
    
    auto wrongLetters = _controller->getWrongLetters();

    for( int i = 0; i < wrongLetters.size(); i++ )
    {
        printf("%c-", wrongLetters[ i ] );        
    }
    printf( "\n" );
}

void GallowView::gameover( bool won )
{
    update();

    if( won )
    {
        std::cout << "Ganhou!" << std::endl;
    }
    else
    {
        std::cout << _controller->getWord() << std::endl;
        std::cout << "Perdeu!" << std::endl;
    }
    exit( 2 );
}
