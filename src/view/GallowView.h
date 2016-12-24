#ifndef GALLOW_VIEW_H
#define GALLOW_VIEW_H

#include <vector>
#include <string>

class GallowController;

class GallowView
{

public:
    GallowView( int wordSize , GallowController* controller );

    ~GallowView();

    void loop();

    void update( char letter = '_', std::vector< int > indexes = std::vector< int >() );
    
    void gameover( bool won = false );

private:
    void drawGallow();

    void drawFooter( char newLetter, std::vector< int > indexes );

    int _wordSize;
    std::string _word;
    GallowController* _controller;

};

#endif
