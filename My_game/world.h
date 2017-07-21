#ifndef WORLD_H
#define WORLD_H

#include "snake.h"

class World
{
public:
    World(Vector2u l_windowSize);
    ~World();

    int GetBlockSize();

    void RespawnAple();

    void Update(Snake &l_player);
    void Render(RenderWindow &l_window);
private:
    Vector2u m_windowSize;
    Vector2i m_item;
    int m_blockSize;

    CircleShape m_apple;
    RectangleShape m_bounds[4];

};

#endif // WORLD_H
