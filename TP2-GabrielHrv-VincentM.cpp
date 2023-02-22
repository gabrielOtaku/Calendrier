
#include <iostream>
#include <iomanip>
#include <string>
#include "MesFonctions.h"
#include "Structures.h"





int main()
{


	Date firstDate, secondDate;
	Calendar calendar;


	firstDate = enterDate();
	calendar.monAnnee = firstDate.Year;
	buildCalendar(calendar);
	displayCalendar(calendar);

	cout << "\n\n" << "Enter la premi\x8Are date ( \x85 partir de 1900 jusqu'\x85 cette ann\x82""e ) : \n\n";
	displayDate(firstDate);

	cout << "\n\n" << "Entrer la deuxi\x8Ame date (\x85 partir de 1900 jusqu'\x85 cette ann\x82""e ) : \n\n";
	secondDate = enterDate();

	orderDate(firstDate, secondDate);
	cout << "\n" << " the ";
	displayDate(firstDate);

	cout << " Coming before the ";
	displayDate(secondDate);

	cout << "\n";


	return 0;
}
