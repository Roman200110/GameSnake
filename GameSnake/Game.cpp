#include "Game.h"
enum edirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
edirection dir;
edirection dir1;
Game::Game(cv::Mat img, int scale, float Gameover, int lengthSnake):
	m_img(img),
	m_scale(scale),
	m_GameOver(Gameover),
	m_lengthSnake(lengthSnake),
	m_snake(new Snake[100]),
	m_fruit(new Fruit[5])
{
	m_img.setTo(0);
	m_snake[0].x = 520;
	m_snake[0].y = 520;
}

float Game::getGameover()
{
	return m_GameOver;
}

int Game::getlengthSnake()
{
	return m_lengthSnake;
}

void Game::coordinatesfruit()
{
	for (int i = 0; i < 5; i++)
	{
		m_fruit[i].NewFruit();
	}
}

void Game::input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			if (dir1 == RIGHT)
			{
				break;
			}
			dir = LEFT;
			break;
		case 'd':
			if (dir1 == LEFT)
			{
				break;
			}
			dir = RIGHT;
			break;
		case 's':
			if (dir1 == UP)
			{
				break;
			}
			dir = DOWN;
			break;
		case 'w':
			if (dir1 == DOWN)
			{
				break;
			}
			dir = UP;
			break;
		}
		dir1 = dir;
	}
}

void Game::logic()
{
	for (int i = m_lengthSnake; i > 0; i--)
	{
		m_snake[i].x = m_snake[i - 1].x;
		m_snake[i].y = m_snake[i - 1].y;
	}
	for (int i = 0; i < 5; i++)
	{
		if (sqrt(pow(m_snake[0].x - m_fruit[i].x * m_scale, 2) + pow(m_snake[0].y - m_fruit[i].y * m_scale, 2)) <= 30)
		{
			m_fruit[i].NewFruit();
			m_lengthSnake++;
		}
	}
	switch (dir)
	{
	case LEFT:
		m_snake[0].x -= m_scale;
		break;
	case RIGHT:
		m_snake[0].x += m_scale;
		break;
	case DOWN:
		m_snake[0].y += m_scale;
		break;
	case UP:
		m_snake[0].y -= m_scale;
		break;
	}
	for (int i = 1; i < m_lengthSnake; i++)
	{
		if (m_snake[0].x == m_snake[i].x && m_snake[0].y == m_snake[i].y)
		{
			m_GameOver = true;
		}
	}
	if (m_snake[0].x >= m_img.cols)
	{
		m_snake[0].x = 0;
	}
	else if (m_snake[0].x <= -(m_scale - 2))
	{
		m_snake[0].x = m_img.cols - (m_scale - 2);
	}
	else if (m_snake[0].y >= m_img.rows)
	{
		m_snake[0].y = 0;
	}
	else if (m_snake[0].y <= -(m_scale - 2))
	{
		m_snake[0].y = m_img.rows - (m_scale - 2);
	}

}

cv::Mat Game::DrawGame()
{
	cv::Mat res = m_img.clone();
	for (int i = 0; i < 5; i++)
	{
		cv::rectangle(res, cv::Point(m_fruit[i].x * m_scale + 1, m_fruit[i].y * m_scale + 1), cv::Point(m_fruit[i].x * m_scale + m_scale - 2, m_fruit[i].y * m_scale + m_scale - 2), cv::Vec3b(0, 255, 0), -1);
	}
	for (int i = 0; i < m_lengthSnake; i++)
	{
		rectangle(res, cv::Point(m_snake[i].x + 1, m_snake[i].y + 1), cv::Point(m_snake[i].x + m_scale - 2, m_snake[i].y + m_scale - 2), cv::Vec3b(255, 0, 0), -1);
	}
	return res;
}
