#include "world.h"

World::World(Vector2u l_windowSize) : m_windowSize(l_windowSize) {
    m_blockSize = 16;

    RespawnAple();
    m_apple.setFillColor(Color::Red);
    m_apple.setRadius(m_blockSize / 2);

    for (unsigned i = 0;i < 4;i ++) {
        m_bounds[i].setFillColor(Color::Red);
        if (!((i + 1) % 2))
            m_bounds[i].setSize(Vector2f(m_windowSize.x,m_blockSize));
        else
            m_bounds[i].setSize(Vector2f(m_blockSize,m_windowSize.y));
        if (i < 2)
            m_bounds[i].setPosition(0,0);
        else {
            m_bounds[i].setOrigin(m_bounds[i].getSize());
            m_bounds[i].setPosition(Vector2f(m_windowSize));
        }
    }
}
World::~World() {}

void World::RespawnAple() {
    unsigned maxX = m_windowSize.x / m_blockSize - 2;
    unsigned maxY = m_windowSize.y / m_blockSize - 2;

    m_item = Vector2i (rand() % maxX + 1,rand() % maxY + 1);
    m_apple.setPosition(m_item.x * m_blockSize,m_item.y * m_blockSize);
}

void World::Update(Snake &l_player) {
    if (l_player.GetPosition() == m_item) {
        l_player.Extend();
        l_player.IncreaseScore();
        RespawnAple();
    }

    unsigned gridSize_x = m_windowSize.x / m_blockSize;
    unsigned gridSize_y = m_windowSize.y / m_blockSize;

    if (l_player.GetPosition().x <= 0 ||
            l_player.GetPosition().y <= 0 ||
            l_player.GetPosition().x >= gridSize_x - 1 ||
            l_player.GetPosition().y >= gridSize_y - 1)
        l_player.Lose();
}

void World::Render(RenderWindow &l_window) {
    for (unsigned i = 0;i < 4;i ++)
        l_window.draw(m_bounds[i]);
    l_window.draw(m_apple);
}

int World::GetBlockSize() { return m_blockSize; }
