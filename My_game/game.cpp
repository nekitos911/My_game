#include "game.h"

Game::Game() : m_window("New",Vector2u(800,600)),m_snake(m_world.GetBlockSize()),m_world(Vector2u(800,600))
{
    RestartClock();
    srand(time(nullptr));

    m_playerTexture.loadFromFile("Media/Images/Mushroom.png");
    m_player.setTexture(m_playerTexture);
    //m_player.setOrigin();
    m_increment = Vector2i(400,400);
}
Game::~Game() {}

Time Game::GetElapsed() { return m_clock.getElapsedTime(); }
void Game::RestartClock() { m_elapsed += m_clock.restart().asSeconds(); }
MyWindow *Game::GetWindow() { return &m_window; }

void Game::HandleInput() {
    if (Keyboard::isKeyPressed(Keyboard::Up) && m_snake.GetPhysicalDirection() != Direction::Down)
        m_snake.SetDirection(Direction::Up);
    else if (Keyboard::isKeyPressed(Keyboard::Down) && m_snake.GetPhysicalDirection() != Direction::Up)
        m_snake.SetDirection(Direction::Down);
    else if (Keyboard::isKeyPressed(Keyboard::Left) && m_snake.GetPhysicalDirection() != Direction::Right)
        m_snake.SetDirection(Direction::Left);
    else if (Keyboard::isKeyPressed(Keyboard::Right) && m_snake.GetPhysicalDirection() != Direction::Left)
        m_snake.SetDirection(Direction::Right);
}

void Game::Update() {
    m_window.Update(); // update window
    //MovePlayer();

    float timestep = 1.0f / m_snake.GetSpeed();

    if (m_elapsed >= timestep) {
        m_snake.Tick();
        m_world.Update(m_snake);
        m_elapsed -= timestep;
        if (m_snake.HasLost())
            m_snake.Reset();
    }
}

void Game::Render() {
    m_window.BeginDraw(); // Clear
    m_world.Render(*m_window.GetRenderWindow());
    m_snake.Render(*m_window.GetRenderWindow());
    m_window.EndDraw(); // Display
}


