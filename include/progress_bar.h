#ifndef __PROGRESS_BAR_H__
#define __PROGRESS_BAR_H__

#include <iostream>
#include<thread>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/ioctl.h>
#endif
#include <iomanip>

using namespace std;
namespace my_color
{
#define COLOR_NONE		"\033[0m"

#define COLOR_RED		"\033[31m"
#define COLOR_RED_H		"\033[1;31m"

#define COLOR_GREEN		"\033[32m"
#define COLOR_GREEN_H	"\033[1;32m"

#define COLOR_YELLOW	"\033[33m"
#define COLOR_YELLOW_H	"\033[1;33m"
}

class ProgressBar
{
public:
	ProgressBar(const int& total, const int& is_color = 0, const char& icon = '=');
	~ProgressBar();

	void run(const int& curr_index);

private:
	void do_ani();

private:
	//终端宽度
	int m_window_width;

	//进度
	int m_rate;
	int m_total;

	//动画
	bool m_stop;
	std::thread m_ani_thrd;

	//颜色
	int m_is_color;

	//图案
	char m_progress_icon;
	std::string m_animated_icon;
	std::string m_progress_str;

};

#endif
