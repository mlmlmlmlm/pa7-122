#include "List.h"


class App
{
public:
	App();
	~App();

	void impo();
	void mark();

	void loadmaster();
	void storemaster();
	
private:
	ifstream infile;
	fstream mfile;
	List<Data> master;
	
};
