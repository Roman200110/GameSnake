#pragma once
#include<iostream>
#include<conio.h>
#include<opencv2/opencv.hpp>

#include"Fruit.h"
#include"Snake.h"
using namespace std;
using namespace cv;
class Game
{
public:
	Game(cv::Mat img = cv::Mat(1000, 1000, CV_8UC3), int scale = 40, float Gameover = false, int lengthSnake = 1);
	float getGameover();
	int getlengthSnake();
	void coordinatesfruit();
	void input(int msecs);
	void logic();
	cv::Mat DrawGame();
private:
	cv::Mat m_img;
	int m_scale;
	bool m_GameOver;
	int m_lengthSnake;
	Snake* m_snake;
	Fruit* m_fruit;
};
