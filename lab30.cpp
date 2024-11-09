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
int numMade(); //random number increasingly less likely to be higher
void timeCycle(map<string, array<list<string>, 3>>&, string[], string[]); //one time cycle function

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
		cout << endl;
	}
	cout << "\n\n";

	timeCycle(cafe, drinks, names);

	for (auto pair : cafe) {
			cout << "Drink: " << pair.first
				 << "; Ordered: ";
			for (string n : pair.second[0])
				cout << n << " ";
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

//random made number functon
int numMade() {

}

//time simulation function
void timeCycle(map<string, array<list<string>, 3>> &cafe, string drinks[], string names[]) {
	//test moving name from ordered to made
	/********************************************************************/

	for (auto it = cafe.begin(); it != cafe.end(); it++) {
		it->second[1].push_back(*it->second[0].begin());
		it->second[0].erase(it->second[0].begin());
	}

	/********************************************************************/
	//end test

	//beginning of interval flag
	static int counter = 1;
	cout << "Time interval " << counter << ":\n\n";

	//choose random number of drinks to be ordered
	int ordered = (rand() % MAX_OR) + 1;
	//loop for each drink
	for (int i = 0; i < ordered; i++) {
		//temp random name
		string temp = getName(names);
		//random index from drink array
		auto it = cafe.find(drinks[rand() % DRINKS]);
		if (it == cafe.end()) {
			cout << "Range error.\n";
			return;
		}
		//add random name to map item with key from drink array
		it->second[0].push_back(temp);

		//display names and drinks ordered
		cout << temp << " ordered " << it->first << endl;
	}

	//loop for each map element
	for (auto it = cafe.begin(); it != cafe.end(); it++) {
		//random number drinks to be made
		//move that many names from the front of ordered to the back of made
		//display drinks made for each drink on one line
			//"Mocha was made for: Cassie, Lena, Joe"
	}

	//loop for each map element
	for (auto it = cafe.begin(); it != cafe.end(); it++) {
		//if made.length >= max drinks served
			//serve that many drinks
		//else
			//serve all the drinks
		//display drinks served for each drink on one line
			//"Mocha was served to: Cassie, Lena, Joe, Tim"
	}

	counter++;
}
