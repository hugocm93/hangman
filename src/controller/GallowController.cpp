#include "GallowController.h"

GallowController::GallowController() :
    _view( _gallow.wordSize() , this )
{
    _view.loop();
}

GallowController::~GallowController()
{
}

void GallowController::newGame()
{
    _gallow = Gallow();
    _view.init( _gallow.wordSize() );
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
