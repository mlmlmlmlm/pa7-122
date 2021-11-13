#include "menu.h"

void Menu::run()
{
	display();
	int sel = -1;

	while (sel < 0 || sel > 7 || sel == 5)
	{
		cin >> sel;
	}

	if (sel == 1)
	{
		ap.impo();
	}
	if (sel == 2)
	{

	}
	if (sel == 3)
	{
		ap.storemaster();
	}
	if (sel == 4)
	{
		ap.mark();
	}
	if (sel == 6)
	{

	}
	if (sel == 7)
	{
		exit(0);
	}


	run();


}


void Menu::display()
{
	system("cls");
	cout << "1. import course list" << endl;
	cout << "2. load master list (not working)" << endl;
	cout << "3. store master list (kinda works)" << endl;
	cout << "4. Mark absences." << endl;
	cout << "5. edit (notworking)" << endl;
	cout << "6. generate report (not working)" << endl;
	cout << "7. exit" << endl;

}