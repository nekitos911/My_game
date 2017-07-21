#include "game.h"

Game::Game() : m_window("New",Vector2u(800,600))
{
    RestartClock();
    srand(time(NULL));

    m_playerTexture.loadFromFile("Media/Images/Mushroom.png");
    m_player.setTexture(m_playerTexture);
    //m_player.setOrigin();
    m_increment = Vector2i(400,400);
}
Game::~Game() {}

Time Game::GetElapsed() { return m_elapsed; }
void Game::RestartClock() { m_elapsed = m_clock.restart(); }
MyWindow *Game::GetWindow() { return &m_window; }

void Game::HandleInput() {}

void Game::Update() {
    m_window.Update(); // update window
    MovePlayer();
}

void Game::MovePlayer() {

    float elapsed = m_elapsed.asSeconds();

    Vector2u l_windowSize = m_window.GetWindowSize();
    Vector2u l_textureSize = m_playerTexture.getSize();

    if ((m_player.getPosition().x > l_windowSize.x - l_textureSize.x && m_increment.x > 0) ||
           ( m_player.getPosition().x < 0 && m_increment.x < 0))
        m_increment.x = -m_increment.x;

    if ((m_player.getPosition().y > l_windowSize.y - l_textureSize.y && m_increment.y > 0) ||
           ( m_player.getPosition().y < 0 && m_increment.y < 0))
        m_increment.y = -m_increment.y;

    m_player.setPosition(m_player.getPosition().x + m_increment.x * elapsed,
                         m_player.getPosition().y + m_increment.y * elapsed);
}


void Game::Render() {
    m_window.BeginDraw(); // Clear
    m_window.Draw(m_player);
    m_window.EndDraw(); // Display
}


