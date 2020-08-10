#include"Game.h"

int main()
{
	Game a(cv::Mat(1000, 1000, CV_8UC3), 20, false, 1);
	cv::Mat img(1000, 1000, CV_8UC3);
	img.setTo(0);
	a.coordinatesfruit();
	int s = 300;
	int tmplengthSnake = 4;
	while (!a.getGameover())
	{
		system("cls");
		cout << "m_lengthSnake: " << a.getlengthSnake() << endl;
		if (a.getlengthSnake() == tmplengthSnake)
		{
			tmplengthSnake += 4;
			s -= 30;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(s));
		a.input();
		a.logic();
		img = a.DrawGame();
		imshow("Game", img);
		waitKey(10);
	}
	img.setTo(0);
	putText(img, "GAME OVER", cv::Point(200, 500), 5, 5, cv::Vec3b(0, 255, 0), 4);
	imshow("Game", img);
	waitKey(0);
	return 0;

}