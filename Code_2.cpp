#include <cstdlib>
#include <string>       // C++ text strings
#include <iostream>     // stream input/output from console
#include <fstream>      // file streams

using namespace std;

struct Flat      // definition of the Flat structure  
{
	int rooms;
	int total;
	int living;
	int balconies;
	int floor;
	int storeys;
	string district;
};

// function read_info implements reading information 
// about some flat from the file stream. Reference to the 
// file stream is passed as a parameter. 
// The information read from 
// information is written to the new structure. 
// structure is returned to the calling program.

Flat read_info(ifstream &file)
{
	Flat aflat;                     // create a new structure
	file >> aflat.rooms;            // read the data from the file
	file >> aflat.total;
	file >> aflat.living;
	file >> aflat.balconies;
	file >> aflat.floor;
	file >> aflat.storeys;
	getline(file, aflat.district);
	file.get();
	return aflat;                    //return the result
}

// The print_flat function prints the information 
// the flat information given to it as a parameter. 
// It does not return any result.

// use stream cout
// to display the
// contents of all fields
// aflat structure

void print_flat(Flat aflat, int i)
{
	cout << "Enter data for apartments of multi-storey building #" << i + 1 << endl;
	cout << " Number of rooms - ";
	cout << aflat.rooms << endl;
	cout << " Total area - ";
	cout << aflat.total << endl;
	cout << " Living area - ";
	cout << aflat.living << endl;
	cout << " Number of balconies - ";
	cout << aflat.balconies << endl;
	cout << " Floor - ";
	cout << aflat.floor << endl;
	cout << " Floor of the house - ";
	cout << aflat.storeys << endl;
	cout << " District - ";
	cout << aflat.district << endl;
	cout << "\n";
}

void program_1(Flat aflat[], string find_by_district, int N)
{
	int k = 0;
	bool found = false;
	for (int i = 0; i < N; i++)
	{
		if (aflat[i].district == find_by_district)
		{
			found = true;
			k = aflat[i].total + k;
		}
	}
	cout << "The total area of apartments in the given area: \n" << k << endl;
	if (!found)
		cout << "There are no apartments in the given area!\n" << endl;
	system("pause");
}

void program_2(Flat aflat[], int N)
{
	bool found = false;
	for (int i = 0; i < N; i++)
	{
		if ((aflat[i].floor == aflat[i].storeys) && (aflat[i].floor >= 5))
		{
			found = true;
			cout << "\nNumber of rooms: " << aflat[i].rooms << endl;
			cout << "Total area: " << aflat[i].total << endl;
			cout << "Living area: " << aflat[i].living << endl;
			cout << "Number of balconies/loggia: " << aflat[i].balconies << endl;
			cout << "Floor: " << aflat[i].floor << endl;
			cout << "Floor of the house: " << aflat[i].storeys << endl;
			cout << "Area: " << aflat[i].district << endl;
			cout << "-----------------------------------------------------------------------\n" << endl;
		}
	}
	if (!found)
		cout << "The apartment, located on the top floor of a multi-storey building was NOT found!\n" << endl;
	system("pause");
}

void menu()
{
	cout << "\n-----------------------------------------------------------------------" << endl;
	cout << "\nTasks: \n" << endl;
	cout << "\n1 - Calculate the total area of apartments, located in the specified" << endl;
	cout << "\n   district (the name of the district is entered from the keyboard).\n" << endl;
	cout << "\n2 - Display data about all apartments, located on the last floor" << endl;
	cout << "\n   of multi-storey building (5 and more floors).\n" << endl;
	cout << "\nTo finish the program enter: -1" << endl;
	cout << "\nTo repeat the menu call, enter: 0" << endl;
	cout << "\n-----------------------------------------------------------------------" << endl;
}

int N;
Flat* flat;                     // pointer to place the array

int main()
{
	int  n;
    string str;
	ifstream infile;            // file stream for data input
	infile.open("file.txt");    // open a stream, connect it with a file
	infile >> N;                // read data into the N variable
	infile.get();               // clear buffer for reading
	flat = new Flat[N];         // allocate memory

	for (int i = 0; i < N; i++)
		flat[i] = read_info(infile);

	infile.close();              // close the file stream

	for (int i = 0; i < N; i++)  // in the loop read from the file
		print_flat(flat[i], i);  // data on each flat

	menu();
	do
	{
		cout << "\n-----------------------------------------------------------------------" << endl;
		cout << "\nEnter task number: \n" << endl;
		cout << "-----------------------------------------------------------------------\n" << endl;
		cin >> n;
		cout << "-----------------------------------------------------------------------" << endl;
		switch (n)
		{
		case 0: menu();
			break;
		case 1:
			cout << "\nEnter district - ";
			cin.get();      // this is another call to a function that reads data from the input data stream and waits for the ENTER key to be pressed
			getline(cin, str);  // read the name of the flat you are looking for
			program_1(flat, str, N);
			break;
		case 2: program_2(flat, N);
			break;
		default:
			cout << "\nThere are no tasks under the given number!\n" << endl;
		}
	} while (n != -1);
	cout << "\nThe end.\n" << endl;

	delete[] flat;    // free the memory
	system("pause");  // programme termination delay
	return 0;
}
