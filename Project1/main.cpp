#include <iostream>
#include <vector>
#include <fstream>
#include "Pipe.h"
#include "CS.h"

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

void SavePipe(ofstream& fout, Pipe& p)
{
	fout << p.id << endl
		<< p.length << endl
		<< p.diameter << endl
		<< p.repair << endl;
}

void SaveCS(ofstream& fout, CS& st)
{
	fout << st.id << endl
		<< st.name << endl
		<< st.numOfShops << endl
		<< st.numOfShopsInWork << endl
		<< st.efficiency << endl;
}

Pipe LoadPipe(ifstream& fin)
{
	Pipe p;
	fin >> p.id
		>> p.length
		>> p.diameter
		>> p.repair;

	return p;
}

CS LoadCS(ifstream& fin)
{
	CS st;
	fin >> st.id
		>> st.name
		>> st.numOfShops
		>> st.numOfShopsInWork
		>> st.efficiency;

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
		if (cin.fail())
		{
			cout << "Wrong action" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		switch (i)
		{
		case 1:
		{	
			baseOfPipes.push_back(addPipe());
			break;
		}
		case 2:
		{
			baseOfCS.push_back(addCS());
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

			ofstream fout;
			fout.open("Pipe.txt", ios::out);
			if (fout.is_open())
			{
				fout << baseOfPipes.size() << endl;
				for (Pipe& p : baseOfPipes)
					SavePipe(fout, p);
			}
			fout.close();

			fout.open("CS.txt", ios::out);
			if (fout.is_open())
			{
				fout << baseOfCS.size() << endl;
				for (CS& st : baseOfCS)
					SaveCS(fout, st);
			}
			fout.close();
			break;
		}
		case 7:
		{
			ifstream fin;
			fin.open("Pipe.txt", ios::in);
			if (fin.is_open())
			{
				int j = 0;
				fin >> j;
				while (j--)
					baseOfPipes.push_back(LoadPipe(fin));
			}
			fin.close();

			fin.open("CS.txt", ios::in);
			if (fin.is_open())
			{
				int k = 0;
				fin >> k;
				while (k--)
					baseOfCS.push_back(LoadCS(fin));
			}
			fin.close();
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