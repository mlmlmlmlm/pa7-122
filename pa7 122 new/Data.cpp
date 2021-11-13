#include "Data.h"


Data::Data()
{
	recordNum = 0;
	idNum = 0;
	name = "";
	email = "";
	unit = "";
	program = "";
	level = "";

}

Data::Data(int nrec = 0, int nid = 0, string nname = "", string nemail = "", string nunit = "", string nprogram = "", string nlevel = "")
{
	recordNum = nrec;
	idNum = nid;
	name = nname;
	email = nemail;
	unit = nunit;
	program = nprogram;
	level = nlevel;

}

Data::Data(Data& copy)
{
	recordNum = copy.getRecordNum();
	idNum = copy.getIDNum();
	name = copy.getName();
	email = copy.getEmail();
	unit = copy.getUnit();
	program = copy.getProgram();
	level = copy.getLevel();
}



int Data::getRecordNum()
{
	return this->recordNum;
}
int Data::getIDNum()
{
	return this->idNum;
}
string Data::getName()
{
	return this->name;
}
string Data::getEmail()
{
	return this->email;
}
string Data::getUnit()
{
	return this->unit;
}
string Data::getProgram()
{
	return this->program;
}
string Data::getLevel()
{
	return this->level;
}


int Data::getAbsences()
{
	return this->absences;
}

string Data::peekRecentAbsence()
{
	string recent;
	this->dates.peek(recent);
	return recent;
}
void Data::pushAbsence(string newDate)
{
	this->dates.push(newDate);
}


Stack<string>* Data::getDates()
{
	return &dates;
}


void Data::iterAbs()
{
	absences++;
}


string Data::popAbsence()
{
	string tem;
	dates.pop(tem);
	return tem;
}

Data& Data::operator= (Data& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	recordNum = rhs.getRecordNum();
	idNum = rhs.getIDNum();
	name = rhs.getName();
	email = rhs.getEmail();
	unit = rhs.getUnit();
	program = rhs.getProgram();
	level = rhs.getLevel();

	return *this;


}

