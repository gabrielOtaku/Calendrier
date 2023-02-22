
#pragma once
#include "Structures.h"

using namespace std;

Date enterDate();
bool isBisextile(int myYear);
void displayIfBisextile(bool Bissextile);
int firstDayInYear(int myYear);
int numberDayByMonth(int myMonth, bool Bissextile);
void displayDate(Date date);
void displayCalendar(Calendar calendar);
string nameMonth(int noMonths);
void buildCalendar(Calendar& myCalendar);
string twoLettersDay(int noJour);
void orderDate(Date& firstDate, Date& secondDate);
void reverseDate(Date& firstDate, Date& secondDate);