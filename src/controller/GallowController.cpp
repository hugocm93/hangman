#include "GallowController.h"

GallowController::GallowController() :
    _view( _gallow.wordSize() , this )
{
    _view.loop();
}

GallowController::~GallowController()
{
}

int GallowController::getNumberOfMistakes()
{
    return _gallow.getWrongLetters().size();
}

std::vector< char > GallowController::getWrongLetters()
{
    return _gallow.getWrongLetters();
}

void GallowController::incomingLetter( char letter )
{
    _view.update( letter,  _gallow.hasLetter( letter ) );

    if( _gallow.didWin() )
    {
        _view.gameover( true );
    }

    if( _gallow.didLose() )
    {
        _view.gameover();
    }
}

std::string GallowController::getWord()
{
    return _gallow.getWord();
}
