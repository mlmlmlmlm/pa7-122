#include "App.h"


App::App()
{	
}


App::~App()
{
}



void App::impo()
{
	infile.open("classList.csv", std::ios::in);

	int nrost;
	int nid;
	string nname;
	string nemail;
	string nunits;
	string nprogram;
	string nlevel;

	string line;


	getline(infile, line);

	while (!infile.eof())
	{
		std::getline(infile, line, ',');
		nrost = std::stoi(line);


		std::getline(infile, line, ',');
		nid = std::stoi(line);


		std::getline(infile, line, '"');


		std::getline(infile, line, '"');


		nname = "\"" + line + "\"";

		std::getline(infile, line, ',');
		std::getline(infile, line, ',');

		nemail = line;



		std::getline(infile, line, ',');
		nunits = line;




		std::getline(infile, line, ',');
		nprogram = line;



		std::getline(infile, line, '\n');
		nlevel = line;


		Data *nData = new Data(nrost, nid, nname, nemail, nunits, nprogram, nlevel);
	
		master.insertAtFront(*nData);

	}

	infile.close(); //close file after its loaded

	
}

void App::mark()
{
	//display to screen

	Node<Data>* point = master.getHeadPtr();
	
	while (point != nullptr)
	{
		cout << point->getData()->getRecordNum() << ", ";
		cout << point->getData()->getIDNum() << ", ";
		cout << point->getData()->getName() << ", ";
		cout << point->getData()->getEmail() << ", ";
		cout << point->getData()->getUnit() << ", ";
		cout << point->getData()->getProgram() << ", ";
		cout << point->getData()->getLevel() << "" << endl;
		//printed to screen
		point = point->getNextPtr();
	}

	cout << "enter student number to mark or enter 0 to quit" << endl;

	int temp;
	cin >> temp;

	if (temp == 0)
	{
		return;
	}

	else
	{
		//mark absences for selected value

		point = master.getHeadPtr();

		while (point != nullptr && point->getData()->getRecordNum() != temp)
		{

			point = point->getNextPtr();
		}
		if (point == nullptr)
		{
			cout << "invalid input";
			system("pause");
		}
		else
		{
			point->getData()->iterAbs();
			string timeTemp = "";
			time_t t = time(0);   // get time now

			struct tm* now = localtime(&t);

			timeTemp = std::to_string(now->tm_year + 1900) + '-'

				+ std::to_string(now->tm_mon + 1) + '-'

				+ std::to_string(now->tm_mday);

			// retrieved from stackoverflow - http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
			

			point->getData()->pushAbsence(timeTemp); //absense now pushed

		 //mark code here, need to push date onto stack
		}

		//cls and recursivly call

		system("cls");

		mark();
	}


}


void App::loadmaster()
{
	//doesnt realy work
	//must have imported to work


	mfile.open("master.txt", std::ios::in);

	string line;

	getline(mfile, line);

	while (!mfile.eof())
	{

		getline(mfile, line, ',');
		int num = stoi(line); //student number to search for 
		getline(mfile, line, '"');
		getline(mfile, line, '"');
		getline(mfile, line, ',');
		getline(mfile, line, ',');
		getline(infile, line, ',');
		getline(infile, line, ',');
		getline(infile, line, ',');
		//now at end

		getline(infile, line, '\n');
		//everything but new line
		string line2;


		while(line != "")
		{


			getline(infile, line, ',');
		}





	}








	infile.close(); //close file after its loaded


}

void App::mark()
{
	//display to screen

	Node<Data>* point = master.getHeadPtr();

	while (point != nullptr)
	{
		cout << point->getData()->getRecordNum() << ", ";
		cout << point->getData()->getIDNum() << ", ";
		cout << point->getData()->getName() << ", ";
		cout << point->getData()->getEmail() << ", ";
		cout << point->getData()->getUnit() << ", ";
		cout << point->getData()->getProgram() << ", ";
		cout << point->getData()->getLevel() << "" << endl;
		//printed to screen
		point = point->getNextPtr();
	}

	cout << "enter student number to mark or enter 0 to quit" << endl;

	int temp;
	cin >> temp;

	if (temp == 0)
	{
		return;
	}

	else
	{
		//mark absences for selected value

		point = master.getHeadPtr();

		while (point != nullptr && point->getData()->getRecordNum() != temp)
		{

			point = point->getNextPtr();
		}
		if (point == nullptr)
		{
			cout << "invalid input";
			system("pause");
		}
		else
		{
			point->getData()->iterAbs();
			string timeTemp = "";
			time_t t = time(0);   // get time now

			struct tm* now = localtime(&t);

			timeTemp = std::to_string(now->tm_year + 1900) + '-'

				+ std::to_string(now->tm_mon + 1) + '-'

				+ std::to_string(now->tm_mday);

			// retrieved from stackoverflow - http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c


			point->getData()->pushAbsence(timeTemp); //absense now pushed

		 //mark code here, need to push date onto stack
		}

		//cls and recursivly call

		system("cls");

		mark();
	}



	mfile.close();

}


void App::storemaster()
{

	//this pastes it in reverse order plus removes absesne from stack when pasting 
	//choosing not to care bc of time

	mfile.open("master.txt", std::ios::out);

	Node<Data>* point = master.getHeadPtr();

	while (point != nullptr)
	{
		mfile << point->getData()->getRecordNum() << ",";
		mfile << point->getData()->getIDNum() << ",";
		mfile << point->getData()->getName() << ",";
		mfile << point->getData()->getEmail() << ",";
		mfile << point->getData()->getUnit() << ",";
		mfile << point->getData()->getProgram() << ",";
		mfile << point->getData()->getLevel() << ",";
		//now print abbsessns
		for (int index = 0; index < point->getData()->getAbsences(); index++)
		{

			mfile << point->getData()->popAbsence() << ",";

		}
		mfile << endl;
		//printed to screen
		point = point->getNextPtr();
	}






	mfile.close();
}