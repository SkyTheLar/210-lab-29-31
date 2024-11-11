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
int const INTERVALS = 48, MAX_OR = 40, MAX_SV = 2, NAMES = 99, DRINKS = 41;

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
	in.open("names.txt");
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
	in.open("drinks.txt");
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

	//begin simulation
	//loop through simulation function for 48 intervals
	for (int i = 0; i < INTERVALS; i++)
		timeCycle(cafe, drinks, names);

	//end simulation

	//display final map data
	for (auto pair : cafe) {
			cout << "Drink: " << pair.first
				 << "\n\tOrdered: ";
			for (string n : pair.second[0])
				cout << n << " ";
			cout << "\n\tMade: ";
			for (string n : pair.second[1])
				cout << n << " ";
			cout << "\n\tServed: ";
			for (string n : pair.second[2])
				cout << n << " ";
			cout << endl;
		}
		cout << "\n\n";

	return 0;
}

//random name function
string getName(string names[]) {
	//select random index from 0 to names - 1
	int ind = rand() % NAMES;
	//return that name in passed array
	return names[ind];
}

//random made number function
int numMade() {
	int n = 0;
	bool again = true;
	while(again) {
		n++;
		if ((rand() % 100) <= 25)
			again = false;
	}
	return n;
}

//time simulation function
void timeCycle(map<string, array<list<string>, 3>> &cafe, string drinks[], string names[]) {
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
	cout << endl;

	//loop for each map element
	for (auto it = cafe.begin(); it != cafe.end(); it++) {
		//random number drinks to be made
		//move that many names from the front of ordered to the back of made
		if (it->second[0].begin() != it->second[0].end()) {
			cout << it->first << " was made for: ";
			for (int i = 0; i < numMade(); i++) {
				if (it->second[0].begin() != it->second[0].end()){ //if the list isn't empty
					it->second[1].push_back(*it->second[0].begin());
					//display drinks made for each drink on one line
					cout << *it->second[0].begin() << " ";
					it->second[0].erase(it->second[0].begin());
				}
			}
			cout << endl;
		}
	}
	cout << endl;

	//loop for each map element
	for (auto it = cafe.begin(); it != cafe.end(); it++) {
		int toServe;
		//if made.length >= max drinks served
		if (it->second[1].size() >= MAX_SV)
			//serve that many drinks
			toServe = MAX_SV;
		else
			//serve all the drinks
			toServe = it->second[1].size();

		if (it->second[1].begin() != it->second[1].end()) {
			cout << it->first << " served to: ";
			for (int i = 0; i < toServe; i++) {
				it->second[2].push_back(*it->second[1].begin());
				//display drinks served for each drink on one line
				cout << *it->second[1].begin() << " ";
				it->second[1].erase(it->second[1].begin());
			}
			cout << endl;
		}
	}
	cout << endl;

	counter++;
}
