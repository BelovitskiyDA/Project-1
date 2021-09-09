#include <iostream>

using namespace std;

void printMenu()
{
	cout << "[1] Add pipe" << endl
		<< "[2] Add CS" << endl
		<< "[3] View all objects" << endl
		<< "[4] Edit pipe" << endl
		<< "[5] Edit CS" << endl
		<< "[6] Save" << endl
		<< "[7] Load" << endl
		<< "[0] Exit" << endl
		<< "Choose action: ";
}

struct Pipe
{
	int id;
	double length;
	double diameter;
	bool repair;
};

struct CS
{
	int id;
	string name;
	int numOfShops;
	int numOfShopsInWork;


};

int main()
{
	while (true)
	{
		printMenu();
		int i = 0;
		cin >> i;
		switch (i)
		{
		case 1:
		{
			//addPipe();
			break;
		}
		case 2:
		{
			//addCS();
			break;
		}
		case 3:
		{
			//viewAllObjects();
			break;
		}
		case 4:
		{
			//editPipe();
			break;
		}
		case 5:
		{
			//editCS();
			break;
		}
		case 6:
		{
			//Save();
			break;
		}
		case 7:
		{
			//Load();
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
			cout << "Wrong action" << endl;
		}
	}
	return 0;
}