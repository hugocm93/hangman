#include "GallowController.h"

GallowController::GallowController() :
    _view( this )
{
    _view.loop();
}

void GallowController::newGame()
{
    _gallow = Gallow();
    _view.update();
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
    _gallow.pushLetter( letter );
    _view.update();

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

std::string GallowController::getStringBuffer()
{
    return _gallow.getStringBuffer();
}
