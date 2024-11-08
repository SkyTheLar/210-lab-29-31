/*********************************************************

COMSC 210 | Lab 29 | Skylar Robinson | IDE Used: Eclipse

*********************************************************/

//headers
#include <iostream>
#include <array>
#include <list>
#include <map>
#include <ctime>
#include <fstream>
using namespace std;

//define constants
int const INTERVALS = 48, MAX_OR = 10, MAX_SV = 10, NAMES = 3, DRINKS = 5;

string getName(string[]); //random name function
void timeCycle(map<string, array<list<string>, 3>>&, string[]); //one time cycle function

int main() {
	srand(time(0));
	//initialize map with string keys and array of 3 lists value
	map<string, array<list<string>, 3>> cafe;
	//initialize array for names
	string names[NAMES];
	//initialize array for drink names
	string drinks[DRINKS];

	//open people names file
	ifstream in;
	in.open("alphanames.txt");
	//check for file open error
	if (!in) {
		cout << "File error.\n";
		return -1;
	}

	//read names into names array
	int i = 0;
	while (getline(in, names[i]))
		i++;

	//close file
	in.close();

	//open file of drink names
	in.open("alphadrinks.txt");
	//check for file open error
	if (!in) {
		cout << "File error.\n";
		return -1;
	}

	//populate map keys with drink names
	//populate drink names array with same data
	i = 0;
	while(getline(in, drinks[i])) {
		//add an initial 1 name to each ordered list
		array<list<string>, 3> temp;
		temp[0].push_back(getName(names));
		cafe.insert({drinks[i], temp});
		i++;
	}

	//close file
	in.close();

	//display starting list
	for (auto pair : cafe) {
		cout << "Drink: " << pair.first
			 << "; Ordered: ";
		for (string n : pair.second[0])
			cout << n << " ";
		cout << "; Made: "
		cout << endl;
	}
	cout << "\n\n";


	//begin simulation
		//loop through simulation function for 48 intervals

	//end simulation
		//display final map data

	return 0;
//end main function
}

//random name function
string getName(string names[]) {
	//select random index from 0 to names - 1
	int ind = rand() % NAMES;
	//return that name in passed array
	return names[ind];
}

//time simulation function
void timeCycle(map<string, array<list<string>, 3>> &cafe, string drinks[]) {
	//test moving name from ordered to made
	/********************************************************************/

	for (auto it = cafe.begin(); it != cafe.end(); it++) {
		it->second[1].push_back(*it->second[0].begin());
		it->second[0].erase(it->second[0].begin());
	}

	/********************************************************************/
	//end test

	//beginning of interval flag
		//"10 minutes pass"

	//choose random number of drinks to be ordered
	//loop for each drink
		//random index from drink array
		//temp random name
		//add random name to map of with key from drink array
		//display names and drinks ordered
			//"Hannah ordered Coffee"

	//loop for each map element
		//random number drinks to be made
		//move that many names from the front of ordered to the back of made
		//display drinks made for each drink on one line
			//"Mocha was made for: Cassie, Lena, Joe"

	//loop for each map element
		//if made.length >= max drinks served
			//serve that many drinks
		//else
			//serve all the drinks
		//display drinks served for each drink on one line
			//"Mocha was served to: Cassie, Lena, Joe, Tim"
}
