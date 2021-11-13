#include "App.h"



class Menu
{
public:
	Menu() = default;
	~Menu() = default;

	void run();

private:
	// need app object
	App ap;
	void display();
};

