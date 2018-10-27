//17.20 random seekg() seekp() ios_base::binary
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>

const int LIM = 20;

struct planet{
	char name[LIM];
	double population;
	double g;
};

const char * file = "planets.dat";

inline void eatline(){while(std::cin.get() != '\n')continue;}
void test();

int main()
{
	using namespace std;

	planet pl;
	cout << fixed;

	//show initial contents
	fstream finout;
	finout.open(file,ios_base::in | ios_base::out | ios_base::binary);

	int ct = 0;
	if(finout.is_open())
	{
		finout.seekg(0);
		cout << "Here are the current contents of "
			<< file << "file:\n";
		while(finout.read((char *)&pl,sizeof(pl)))
		{
			cout << ct++ << setw(LIM) << pl.name
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}
		if(finout.eof())
			finout.clear();
		else
		{
			cerr << "Error in reading " << file << ".\n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << file << "Could not be opened -- bye.\n";
		exit(EXIT_FAILURE);
	}

	//change a record
	cout << "Enter the record number you wish to change:";
	long rec;
	cin >> rec;
	eatline();
	if(rec < 0 || rec >= ct)
	{
		cerr << "Invalid record number -- bye.\n";
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof(pl);//conver to streampos
	finout.seekg(place);
	if(finout.fail())
	{
		cerr << "Error on attempted seek\n";
		exit(EXIT_FAILURE);
	}
	finout.read((char *)&pl,sizeof(pl));
	cout << "Your selection:\n";
	cout << rec << ":" << setw(LIM) << pl.name << ":"
		<< setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl;
	if(finout.eof())
		finout.clear();

	cout << "Enter a planet name:";
	cin.get(pl.name,LIM);
	eatline();
	cout << "Enter planetary population:";
	cin >> pl.population;
	cout << "Enter planet's acceleration of gravity:";
	cin >> pl.g;
	finout.seekp(place);//go back
	finout.write((char *)&pl,sizeof(pl));
	if(finout.fail())
	{
		cerr << "Error on attempted write\n";
		exit(EXIT_FAILURE);
	}

	//show revised file
	ct = 0;
	finout.seekg(0);
	cout << "Here are the current contents of " << file << " file:\n";
	while(finout.read((char *)&pl,sizeof(pl)))
	{
		cout << ct++ << setw(LIM) << pl.name
			<< setprecision(0) << setw(12) << pl.population
			<< setprecision(2) << setw(6) << pl.g << endl;
	}
	finout.close();
	cout << "Done.\n";
	test();

	return 0;
}



void test()
{
	using namespace std;

	cout << "This system can generate up to " << TMP_MAX
		<< " temporary names of up to " << L_tmpnam
		<< " characters.\n";
	char pszName[L_tmpnam] = {'\0'};
	cout << "Here are ten names:\n";
	for(int i = 0;i < 10;i++)
	{
		tmpnam(pszName);
		cout << pszName << endl;
	}

}