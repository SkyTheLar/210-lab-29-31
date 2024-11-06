/*********************************************************

COMSC 210 | Lab 29 | Skylar Robinson | IDE Used: Eclipse

*********************************************************/

//headers

//define constants
	//time intervals, max drinks ordered, min drinks ordered,
	//max drinks served, number of names, number of drinks

//function prototypes
//random name function
	//parameters: array of size names; returns: string
//one time cycle function
	//parameters: map of drinks by reference, array of keys; returns: nothing

//define main function
	//initialize map with string keys and array of 3 lists value
	//initialize array for names
	//initialize array for drink names

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

	//begin simulation
		//loop through simulation function for 48 intervals

	//end simulation
		//display final map data

//end main function

//random name function
	//select random index from 0 to names - 1
	//return that name in passed array

//time simulation function
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

