#ifndef GALLOW_CONTROLLER_H
#define GALLOW_CONTROLLER_H

#include <vector>

#include "../model/Gallow.h"
#include "../view/GallowView.h"

class GallowController
{

public:
    GallowController();
    
    ~GallowController();
    
    int getNumberOfMistakes();

    std::vector< char > getWrongLetters();

    void incomingLetter( char letter );

    std::string getWord();

private:
    Gallow _gallow;
    
    GallowView _view;
};

#endif
