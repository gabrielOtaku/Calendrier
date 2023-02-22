#pragma once
#include <string>
using namespace std;

struct Date
{
	int Year;
	int Mois;
	int Jour;

};


struct Month
{
	string leMois;
	int  lesJours;
	int lesFinsDeSemaine;

};



struct Calendar
{
	int monAnnee;
	bool isBissextile;
	Month month[12];
};
