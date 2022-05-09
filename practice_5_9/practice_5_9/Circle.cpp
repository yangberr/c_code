#define _CRT_SECURE_NO_WARNINGS
#include"Circle.h"
using namespace std;

	void Circle::set_m_R(int r)
	{
		m_R = r;
	}
	int Circle::get_m_R()
	{
		return m_R;
	}
	void Circle::set_m_Center(Point c)
	{
		m_Center = c;

	}
	Point Circle::get_Center()
	{
		return m_Center;
	}
	//判断点和圆心之间的距离
