#pragma once
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>

using namespace std;

class MyClass
{
public:
	
	float atk_trump(int m)
	{
		srand(time(NULL));
		switch (m)
		{
		case 1:
			return 15;
			break;
		case 2:
			return 40;
			break;
		case 3:
			return 0;
			break;
		}
	}
	//////
	float atk_soleimani(int m)
	{
		srand(time(NULL));
		switch (m)
		{
		case 1:
			return 15;
			break;
		case 2:
			return 25;
			break;
		case 3:
			return 1;
			break;
		}
	}
	//////
	float atk_salvini(int m)
	{
		srand(time(NULL));
		switch (m)
		{
		case 1:
			return 15;
			break;
		case 2:
			return 30;
			break;
		case 3:
			return 0.25;
			break;
		}
	}
	//////
	int energy_trump(int m)
	{
		switch (m)
		{
		case 1:
			return 30;
			break;
		case 2:
			return 90;
			break;
		case 3:
			return 10;
			break;
		}
	}
	//////
	int energy_soleimani(int m)
	{
		switch (m)
		{
		case 1:
			return 30;
			break;
		case 2:
			return 60;
			break;
		case 3:
			return 60;
			break;
		}
	}
	//////
	int energy_salvini(int m)
	{
		switch (m)
		{
		case 1:
			return 30;
			break;
		case 2:
			return 50;
			break;
		case 3:
			return 45;
			break;
		}
	}

private:

};

