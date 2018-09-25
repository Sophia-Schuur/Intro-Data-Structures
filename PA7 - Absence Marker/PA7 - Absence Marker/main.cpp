//Sophia Schuur
//CptS 122
//3/30/2017
//PA 7 - Absence Marker


#include "List.h"
#include "ListNode.h"
#include "Stack.h"


int main(void)
{
	List list;
	//printMenu();
	int option = 0;
	ofstream Outfile;
	Outfile.open("master.txt");

	

	char goback = 'y';
	char submenu = '\0';

	while (goback == 'y')
	{

		printMenu();
		cin >> option;
		switch (option)
		{
		case IMPORT:
			list.LoadList();

			system("cls");
			cout << "Class list loaded!" << endl;
			cout << "Press y to go back to the main menu." << endl;
			cin >> goback;
			system("cls");
			break;

		case LOADMASTER:
			system("cls");
			list.PrintList();

			
			cout << "Press y to go back to the main menu." << endl;
			cin >> goback;
			system("cls");
			break;

		case STOREMASTER:

			system("cls");
			list.StoreList(Outfile);
			cout << "Class list stored to file!" << endl;


			cout << "Press y to go back to the main menu." << endl;
			cin >> goback;
			system("cls");
			break;


		case MARKABSENCES:
			system("cls");
			list.MarkAbsences();

			cout << "Press y to go back to the main menu." << endl;
			cin >> goback;
			system("cls");
			break;
		case GENERATEREPORT:
			system("cls");
			printSubMenu();
			cin >> submenu;
			if (submenu == 1)
			{
				list.GenerateRecent();

				cout << "Press y to go back to the main menu." << endl;
				cin >> goback;
				system("cls");
			}

			else
			{
				list.GenerateMatch();

				cout << "Press y to go back to the main menu." << endl;
				cin >> goback;
				system("cls");

				break;
			}
			
			break;
		case EXIT:
			goback = 'n';
			break;
		}
	}
	
	return 0;
}
