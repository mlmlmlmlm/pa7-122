#include "Stack.h"

//class for data
class Data
{
public:
	Data();
	Data(int nrec, int nid, string nname, string nemail, string nunit, string nprogram, string nlevel);
	//record number, id number, name, email, units, major, level
	Data(Data& copy);
	Data& operator=(Data& rhs);



	//getters
	int getRecordNum();
	int getIDNum();
	string getName();
	string getEmail();
	string getUnit();
	string getProgram();
	string getLevel();

	int getAbsences();

	void iterAbs();
	
	Stack<string>* getDates();

	string peekRecentAbsence();
	void pushAbsence(string newDate);
	string popAbsence();

private:
	int recordNum;
	int idNum;
	string name; //last,first bound by quotes
	string email;
	string unit;
	string program;
	string level;

	int absences;
	Stack<string> dates; //every day they were absent

};
