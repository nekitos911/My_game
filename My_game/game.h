#ifndef GAME_H
#define GAME_H

#include "mywindow.h"

using namespace sf;

class Game
{
public:
    Game();
    ~Game();

    void HandleInput();
    void Update();
    void Render();

    MyWindow *GetWindow();

    Time GetElapsed();
    void RestartClock();
private:
    MyWindow m_window;
    Texture m_playerTexture;
    Sprite m_player;
    Vector2i m_increment;

    Clock m_clock;
    Time m_elapsed;

    void MovePlayer();
};

#endif // GAME_H
