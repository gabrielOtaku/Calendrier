#include "MesFonctions.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;


// Peremet a l'utilisateur de saisir une date selon les conditions. 
Date enterDate()
{

	int myYear;
	int numberDay;

	do
	{
		cout << "Entrer l'ann\x82""e desir\x82""e (allant de 1900 a aujourd'hui) :\n\n";
		while (!(cin >> myYear))
		{
			cout << " Desol\x82, la machine temporelle ne comprend pas cette valeur!\n\n"
				"veuillez saisir une date correspondant ! : \n\n";
			cin.ignore(256, '\n');

			if (myYear < 1900)
			{
				cout << " Date non disponible, veuillez reessayer: \n\n";
			}
		}
	} while (myYear < 1900);

	int myMonth;

	do
	{
		cout << "\n\n Entrer le mois desir\x82 (allant de 1 a 12 ) : " << "\n\n";
		while (!(cin >> myMonth))
		{
			cout << " Desole, la machine temporelle ne comprend pas cette valeur!\n\n"
				"veuillez saisir un mois correspondant ! : \n";
			cin.ignore(256, '\n');

			if (myMonth < 1 && myMonth > 12)
			{
				cout << " Mois non disponible, veuillez reessayer: ";
			}
		}
	} while (myMonth < 1 || myMonth > 12);

	numberDay = numberDayByMonth(myMonth, isBisextile(myYear)); // Gere le nombre de jour en fonction de l'annee bossextile

	int myDay;
	do
	{
		cout << " \n\nEntrez le jour desir\x82 :\n\n";

		while (!(cin >> myDay))
		{
			cout << " Desol\x82, la machine temporelle ne comprend pas cette valeur!\n\n"
				"veuillez saisir un jour correspondant ! : \n";
			cin.ignore(256, '\n');

			if (myDay > numberDay && myDay < 1)
			{
				cout << " Jour non disponible, veuillez reessayer: ";
			}
		}

	} while (myDay > numberDay || myDay < 1);

	Date myDate = { myYear, myMonth, myDay }; // Envoie les donnee dans la structure Date

	return myDate; // retour la valeur de l'annee, du mois et du jour 
}

// Declare si une annee est bissextile ou non
bool isBisextile(int myYear)
{
	return (myYear % 4 == 0 && myYear % 100 != 0) || (myYear % 400 == 0);
}

//Affiche si l'anneee choisi est bissextile ou non
void displayIfBisextile(bool Bissextile)
{
	string yearBissextile;

	(Bissextile) ? yearBissextile = " est " : yearBissextile = " n'est pas "; 

	cout << " Cette annee" << yearBissextile << " bissextile ";
}

// Format de la date afficher
void displayDate(Date date)
{
	cout << date.Jour << " " << nameMonth(date.Mois) << " " << date.Year;
}

// Affiche le calendrier
void displayCalendar(Calendar calendar)
{
	int checkEndl = 0;
	int firstDay = firstDayInYear(calendar.monAnnee);
	for (int i = 0; i < 12; i++)
	{
		cout << "\n\n" << " [" << calendar.month[i].leMois << "] " << "\n";
		for (int j = 0; j < 7; j++) { // Affiche le nombre de jours correspondant au mois 
			cout << twoLettersDay(j);
		}
		cout << "\n";
		for (checkEndl = 0; checkEndl < firstDay; checkEndl++) { 
			cout << "   "; 
		}
		for (int l = 1; l <= calendar.month[i].lesJours; l++) {// fait en sorte que le premier de chaque mois demarre au bon jour 
			cout << setw(2) << l << " ";
			if (++checkEndl > 6) {
				checkEndl = 0;
				cout << "\n";
			}
		}
		cout << "\n" << "---------------------" << "\n";
		firstDay = checkEndl;
	}
}

string twoLettersDay(int noJour)
{
	string nomJour;
	switch (noJour) {
	case 0:
		nomJour = "Lu ";
		break;
	case 1:
		nomJour = "Ma ";
		break;
	case 2:
		nomJour = "Me ";
		break;
	case 3:
		nomJour = "Je ";
		break;
	case 4:
		nomJour = "Ve ";
		break;
	case 5:
		nomJour = "Sa ";
		break;
	case 6:
		nomJour = "Di";
		break;
	}
	return nomJour;
}

// Pour le premier jour de l'annee
int firstDayInYear(int myYear)
{
	int decalage = 0;
	for (int i = 1900; i < myYear; i++) {
		if (isBisextile(i)) {
			decalage += 2;
		}
		else {
			decalage += 1;
		}
	}
	decalage %= 7;
	return decalage;
}

// Retourne le nombre de jours exacte en fonction de chaque mois
int numberDayByMonth(int myMonth, bool Bissextile)
{
	switch (myMonth)
	{
	case 2:
		return isBisextile(Bissextile) ? 29 : 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	default:
		return 31;
		break;
	}
}

//Construction du calendrier sur une annee
void buildCalendar(Calendar& myCalendar)
{
	for (int i = 0; i < 12; i++) {
		myCalendar.month[i].leMois = nameMonth(i + 1);
		myCalendar.month[i].lesJours = numberDayByMonth(i + 1, myCalendar.isBissextile);
	}
}

// Affiche le nom des mois 
string nameMonth(int noMonths)
{
	string nomMois;
	switch (noMonths) {
	case 1:
		nomMois = "Janvier";
		break;
	case 2:
		nomMois = "Fevrier";
		break;
	case 3:
		nomMois = "Mars";
		break;
	case 4:
		nomMois = "Avril";
		break;
	case 5:
		nomMois = "Mai";
		break;
	case 6:
		nomMois = "Juin";
		break;
	case 7:
		nomMois = "Juillet";
		break;
	case 8:
		nomMois = "Ao\x81t";
		break;
	case 9:
		nomMois = "Septembre";
		break;
	case 10:
		nomMois = "Octobre";
		break;
	case 11:
		nomMois = "Novembre";
		break;
	case 12:
		nomMois = "Decembre";
		break;
	}
	return nomMois;
}

// verifie que la premiere date est plus ancienne que la deuxieme
void orderDate(Date& firstDate, Date& secondDate)
{
	if (firstDate.Year > secondDate.Year)
	{
		reverseDate(firstDate, secondDate);

		cout << "Premier";
	}
	else if (firstDate.Mois > secondDate.Mois)
	{
		reverseDate(firstDate, secondDate);
		cout << "Deuxi\x8Ame";
	}
	else if (firstDate.Jour > secondDate.Jour)
	{
		reverseDate(firstDate, secondDate);
		cout << "Troisi\x8Ame";
	}
}

// La premiere date devient la deuxieme et vice versa
void reverseDate(Date& firstDate, Date& secondDate)
{
	Date time;
	time = secondDate;
	secondDate = firstDate;
	firstDate = time;
}