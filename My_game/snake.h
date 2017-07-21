#ifndef SNAKE_H
#define SNAKE_H
#include "SFML/Graphics.hpp"

using namespace sf;

struct SnakeSegment {
    SnakeSegment(int x,int y) : position(x,y){}
    Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction { None,Up,Down,Left,Right};

class Snake
{
public:
    Snake(int l_blockSize);
    ~Snake();

    void SetDirection(Direction l_dir);
    Direction GetDirection();
    int GetSpeed();
    Vector2i GetPosition();
    Direction GetPhysicalDirection();
    int GetLives();
    int GetScore();
    void IncreaseScore();
    bool HasLost();

    void Lose(); // Handle losing
    void ToggleLost();

    void Extend(); //Grow the snake
    void Reset();//Reset to starting point

    void Move(); // Movement method
    void Tick(); // Update method
    void Cut(int l_segments); // Cutting snake
    void Render(RenderWindow &l_window);
private:
    void CheckCollision(); // Checking for collision

    SnakeContainer m_snakeBody; // Snake's body vector
    int m_size; //size of tiles
    Direction m_dir; // Current direction
    int m_speed; // Snake's speed
    int m_lives; //Snake's lives
    int m_score; // Player's score
    bool m_lost; // Losing state
    RectangleShape m_bodyRect; // Snake's body rects
};

#endif // SNAKE_H
