#include <iostream>
#include <vector>

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
	double efficiency;
};

Pipe addPipe()
{
	Pipe p;
	cout << "id: ";
	cin >> p.id;
	cout << "length: ";
	cin >> p.length;
	cout << "diameter: ";
	cin >> p.diameter;
	cout << "repair: ";
	cin >> p.repair;
	return p;
}

CS addCS()
{
	CS st;
	cout << "id: ";
	cin >> st.id;
	cout << "name: ";
	cin >> st.name;
	cout << "numOfShops: ";
	cin >> st.numOfShops;
	cout << "numOfShopsInWork: ";
	cin >> st.numOfShopsInWork;
	cout << "efficiency: ";
	cin >> st.efficiency;
	return st;
}

int main()
{
	vector <Pipe> baseOfPipes;
	vector <CS> baseOfCS;

	while (true)
	{
		printMenu();
		int i = 0;
		cin >> i;
		switch (i)
		{
		case 1:
		{	
			baseOfPipes.resize(size(baseOfPipes) + 1);
			baseOfPipes[size(baseOfPipes) - 1] = addPipe();
			break;
		}
		case 2:
		{
			baseOfCS.resize(size(baseOfCS) + 1);
			baseOfCS[size(baseOfCS) - 1] = addCS();
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