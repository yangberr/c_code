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
	//�жϵ��Բ��֮��ľ���

private:
	int m_R;//�뾶
	//�����п�������һ������Ϊ�����Ա
	Point m_Center;//Բ��

};