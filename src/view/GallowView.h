#ifndef GALLOW_VIEW_H
#define GALLOW_VIEW_H

#include <string>

class GallowController;

class GallowView
{
public:

    GallowView() = delete;

    GallowView( GallowController* controller );

    virtual ~GallowView() = default;

    void loop();

    void update();

    void gameover( bool won = false );

private:

    void drawGallow();

    void drawFooter();

    GallowController* _controller;
};

#endif
