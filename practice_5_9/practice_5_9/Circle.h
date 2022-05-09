#pragma once

#include<iostream>
#include<string>
#include"Point.h"
using namespace std;

class Circle
{
public:
	void set_m_R(int r);
	int get_m_R();
	void set_m_Center(Point c);
	Point get_Center();
	//判断点和圆心之间的距离

private:
	int m_R;//半径
	//在类中可以让另一个类作为本类成员
	Point m_Center;//圆心

};