/*********************************************************

COMSC 210 | Lab 29 | Skylar Robinson | IDE Used: Eclipse

*********************************************************/

//headers
#include <iostream>
#include <array>
#include <list>
#include <map>
#include <ctime>
using namespace std;

//define constants
	//time intervals, max drinks ordered,
	//max drinks served, number of names, number of drinks
int const INTERVALS = 48, MAX_OR = 10, MAX_SV = 10, NAMES = 3, DRINKS = 3;

//function prototypes
//random name function
	//parameters: array of size names; returns: string
string getName(string[]);
//one time cycle function
void timeCycle(map<string, array<list<string>, 3>>&, string[]);
	//parameters: map of drinks by reference, array of keys; returns: nothing

//define main function
int main() {
	srand(time(0));
	//initialize map with string keys and array of 3 lists value
	map<string, array<list<string>, 3>> cafe;
	//initialize array for names
	string names[NAMES] = {"name1", "name2", "name3"};
	//initialize array for drink names
	string drinks[DRINKS] = {"drink1", "drink2", "drink3"};

	//test of random name function
	/**********************************************************/

	for (int i = 0; i < 10; i++)
		cout << getName(names) << " ";
	cout << "\n\n";

	/**********************************************************/
	//end random name test

	//open people names file
		//check for file open error

	//read names into names array

	//close file

	//open file of drink names
		//check for file open error

	//populate map keys with drink names
	//populate drink names array with same data
	//add an initial 1 name to each ordered list

	//close file

	//test of cafe map
	/****************************************************/

	array<list<string>, 3> temp;
	temp[0].push_back("Lucy");
	cafe.insert({"Coffee", temp});

	for (auto pair : cafe) {
		cout << "Drink: " << pair.first
			 << "; Ordered: ";
		for (string n : pair.second[0])
			cout << n << " ";
	}
	cout << "\n\n";

	/****************************************************/
	//end map test

	//test time interval function
	/****************************************************/

	timeCycle(cafe, drinks);

	for (auto pair : cafe) {
		cout << "Drink: " << pair.first
		     << "; Ordered:";
		for (string n : pair.second[0])
			cout << " " << n;
		cout << "; Made:";
		for (string n : pair.second[1])
			cout << " " << n;
		}
	cout << "\n\n";

	/****************************************************/
	//end function test

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

	//confirm drinks array
	/********************************************************************/

	for (int i = 0; i < 3; i++)
		cout << drinks[i] << " ";
	cout << "\n\n";

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
