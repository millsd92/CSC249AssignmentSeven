// Necessary includes.
#include <iostream>
#include <vector>
#include <iomanip>
#include "Car.h"

// Defining constants.
#define SIZE 9
#define SET_WIDTH std::setw(12) <<

// Defining prototypes.
void setUpAllCars(Car *ptrAllCars);
void printAllCars(Car *ptrAllCars);
void printACar(Car *ptrAllCars);
int getVinToFind();
void linearSearch(Car *ptrAllCars, int vin);
void binarySearch(Car *ptrAllCars, int vin, int startIndex, int endIndex);
void selectionSort(Car *ptrAllCars, int startIndex);
void swap(Car *ptrAllCars, int positionOne, int positionTwo);
void quickSort(Car *ptrAllCars, int startIndex, int endIndex);
int partition(Car *ptrAllCars, int startIndex, int endIndex);

//*************************************************************************************************
// Defining main():																				  *
//																								  *
// The entry point for the program. I essentially copied and pasted my AssignmentThreePartTwo	  *
// code and just modified it to make it usable with a class instead of a structure.				  *
//																								  *
// Now I edited AssignmentFourPartTwo's code and made it usable for the requirements of this	  *
// program instead. Because it already had the car class set up and got user input of type int,   *
// the editing was minimal.																		  *
//*************************************************************************************************
int main()
{
	// Setting up the vector of all the cars and other necessary variables.
	std::vector<Car> allCars(SIZE);
	Car *ptrAllCars = &allCars[0];
	int vin = 2873644;

	// Set up all the car objects and print them out.
	std::cout << "Welcome to the Search & Sort Testing Program!" << std::endl;
	std::cout << "First, let's start by showing the original vector.\n" << std::endl;
	setUpAllCars(ptrAllCars);
	std::cout << "\t\tPRE-SORTED VECTOR\n" << std::endl;
	printAllCars(ptrAllCars);

	// Print a message and attempt a linear search for the program specified VIN.
	std::cout << "Let's do a linear search for a car with the VIN " << vin << "!\n" << std::endl;
	std::cout << "Press enter to continue..." << std::endl;
	std::cin.get();
	linearSearch(ptrAllCars, vin);

	// Get the user's input for what VIN they are looking for in the next linear search.
	vin = getVinToFind();
	std::cout << "Alright. Let's do a linear search for a car with the VIN " << vin << "!\n" 
		<< std::endl;
	linearSearch(ptrAllCars, vin);

	// Display all the cars in the vector.
	std::cout << "\t\tPRE-SORTED VECTOR\n" << std::endl;
	printAllCars(ptrAllCars);
	std::cout << std::endl << "Press enter to do a selection sort!\n";
	std::cin.get();

	// Sort the cars using a selection sort and then re-print the new sorted vector.
	selectionSort(ptrAllCars, 0);
	std::cout << "\t\tPOST-SORTED VECTOR (BY MILEAGE)\n" << std::endl;
	printAllCars(ptrAllCars);
	std::cout << std::endl << "Press enter to do a quick sort (AKA partition pivot sort)!\n";
	std::cin.get();

	// Sort the cars using the quick sort and then re-print the new sorted vector.
	quickSort(ptrAllCars, 0, SIZE - 1);
	std::cout << "\t\tPOST-SORTED VECTOR (BY VIN)\n" << std::endl;
	printAllCars(ptrAllCars);
	std::cout << std::endl << "Press enter to perform a binary search to find the car with VIN "
		<< "7337372!\n";
	std::cin.get();

	// Set the VIN to the number we are searching for and print the results.
	vin = 7337372;
	binarySearch(ptrAllCars, vin, 0, SIZE - 1);

	// Prompt the user to press enter to exit and keeping the console open.
	std::cout << "Press Enter to Exit...";
	std::cin.get();
	return 0;
}

//*************************************************************************************************
// Defining setUpAllCars(Car *ptrAllCars):														  *
//																								  *
// SetUpAllCars simply sets the values for all Car structures in the vector to the predefined     *
// values.																						  *
//*************************************************************************************************
void setUpAllCars(Car *ptrAllCars)
{
	std::string makes[SIZE] = { "Porsche", "Ford", "Chevrolet", "Ford", "Voltzwagon",
		"Rolls Royce", "Mazda", "Toyota", "Honda" };
	std::string models[SIZE] = { "911", "Mustang", "Beretta", "Focus", "Jetta", "Ghost",
		"626", "Camry", "S2000" };
	std::string colors[SIZE] = { "Silver", "Red", "Black", "White", "Black", "Silver", "Blue",
		"Red", "Teal" };
	int years[SIZE] = { 2005, 2007, 1989, 2008, 2006, 2005, 2002, 2004, 2007 };
	int mileages[SIZE] = { 18990, 49842, 90332, 150, 28002, 10000, 84754, 50332, 14766 };
	int vins[SIZE] = { 1237362, 7337372, 2873644, 9236498, 4673992, 9292983, 7364646, 2133737,
		7489199 };

	for (int i = 0; i < SIZE; i++)
	{
		(*ptrAllCars).setMake(makes[i]);
		(*ptrAllCars).setModel(models[i]);
		(*ptrAllCars).setColor(colors[i]);
		(*ptrAllCars).setYear(years[i]);
		(*ptrAllCars).setMileage(mileages[i]);
		(*ptrAllCars).setVin(vins[i]);
		ptrAllCars++;
	}
}

//*************************************************************************************************
// Defining printAllCars(Car *ptrAllCars):														  *
//																								  *
// PrintAllCars simply loops through the vector storing all the Car objects and prints out the	  *
// values associated with each Car.																  *
//*************************************************************************************************
void printAllCars(Car *ptrAllCars)
{
	std::string number;

	std::cout << std::left << "   " << SET_WIDTH "Make" << SET_WIDTH "Model"
		<< SET_WIDTH "Color" << SET_WIDTH "Year" << SET_WIDTH "Mileage" << SET_WIDTH "VIN"
		<< "\n" << std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		number = std::to_string(i + 1);
		number += ". ";
		std::cout << number << SET_WIDTH(*ptrAllCars).getMake()
			<< SET_WIDTH(*ptrAllCars).getModel() << SET_WIDTH(*ptrAllCars).getColor()
			<< SET_WIDTH(*ptrAllCars).getYear() << SET_WIDTH(*ptrAllCars).getMileage()
			<< SET_WIDTH(*ptrAllCars).getVin() << std::endl;
		ptrAllCars++;
	}
}

//*************************************************************************************************
// Defining printACar(Car *ptrAllCars):															  *
//																								  *
// PrintACar simply prints a specified Car object.												  *
//*************************************************************************************************
void printACar(Car *ptrAllCars)
{
	std::cout << SET_WIDTH(*ptrAllCars).getMake()
		<< SET_WIDTH(*ptrAllCars).getModel() << SET_WIDTH(*ptrAllCars).getColor()
		<< SET_WIDTH(*ptrAllCars).getYear() << SET_WIDTH(*ptrAllCars).getMileage()
		<< SET_WIDTH(*ptrAllCars).getVin() << std::endl;
}

//*************************************************************************************************
// Defining getVinToFind():																		  *
//																								  *
// Prompts the user for an integer and returns the validated input.								  *
//*************************************************************************************************
int getVinToFind()
{
	int returnValue;
	bool validInput = false;

	std::cout << "It's your turn to find a vehicle!\n" << std::endl;
	while (!validInput)
	{
		std::cout << "Enter the VIN of a vehicle you are trying to find: ";
		std::cin >> returnValue;
		if (std::cin.fail() || std::cin.get() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Input must be a valid integer. Try again." << std::endl;
		}
		else
			validInput = true;
	}

	return returnValue;
}

//*************************************************************************************************
// Defining linearSearch(Car *ptrAllCars, int vin):												  *
//																								  *
// Simply performs a linear search on the Car object vector and prints out the results.			  *
//*************************************************************************************************
void linearSearch(Car *ptrAllCars, int vin)
{
	for (int i = 0; i < SIZE; i++)
		if ((ptrAllCars + i)->getVin() == vin)
		{
			std::cout << "The car with VIN " << vin << " was found! The results are below:"
				<< std::endl;
			printACar(ptrAllCars + i);
			std::cout << std::endl;
			return;
		}

	std::cout << "The car with VIN " << vin << " was not found.\n" << std::endl;
}

//*************************************************************************************************
// Defining binarySearch(Car *ptrAllCars, int vin, int startIndex, int endIndex):				  *
//																								  *
// Simply performs a binary search on the Car object vector's VIN and prints out the results.	  *
//*************************************************************************************************
void binarySearch(Car *ptrAllCars, int vin, int startIndex, int endIndex)
{
	if (endIndex >= startIndex)
	{
		int middleIndex = ((endIndex - startIndex) / 2) + startIndex;
		if ((ptrAllCars + middleIndex)->getVin() == vin)
		{
			std::cout << "The car with VIN " << vin << " was found! The results are below:" << std::endl;
			printACar(ptrAllCars + middleIndex);
			std::cout << std::endl;
		}
		else if ((ptrAllCars + middleIndex)->getVin() > vin)
			binarySearch(ptrAllCars, vin, startIndex, middleIndex - 1);
		else
			binarySearch(ptrAllCars, vin, middleIndex + 1, endIndex);
	}
	else
	{
		std::cout << "The car with VIN " << vin << " was not found.\n" << std::endl;
	}
}

//*************************************************************************************************
// Defining selectionSort(Car *ptrAllCars, int startIndex):										  *
//																								  *
// Does a selection sort on the allCars vector using a pointer for comparisons and Car references.*
//*************************************************************************************************
void selectionSort(Car *ptrAllCars, int startIndex)
{
	if (startIndex != SIZE - 1)
	{
		int minMileageIndex = startIndex, minMileage = (ptrAllCars + startIndex)->getMileage();
		for (int i = startIndex + 1; i < SIZE; i++)
		{
			if ((ptrAllCars + i)->getMileage() < minMileage)
			{
				minMileage = (ptrAllCars + i)->getMileage();
				minMileageIndex = i;
			}
		}
		swap(ptrAllCars, startIndex, minMileageIndex);
		selectionSort(ptrAllCars, startIndex + 1);
	}
}

//*************************************************************************************************
// Defining swap(Car *ptrAllCars, int positionOne, int positionTwo):							  *
//																								  *
// Helper function for the sort functions. Swaps two Car objects using their pointers.			  *
//*************************************************************************************************
void swap(Car *ptrAllCars, int positionOne, int positionTwo)
{
	Car temp = *(ptrAllCars + positionOne);
	*(ptrAllCars + positionOne) = *(ptrAllCars + positionTwo);
	*(ptrAllCars + positionTwo) = temp;
}

//*************************************************************************************************
// Defining quickSort(Car *ptrAllCars, int startIndex, int endIndex):							  *
//																								  *
// The recursive portion of the quick sort algorithm. Also known as partition pivot sorting. It   *
// calls the helper function partition and then, following the pivot being placed in the correct  *
// spot, recursively does the same for the remainder of the vector.
//*************************************************************************************************
void quickSort(Car *ptrAllCars, int startIndex, int endIndex)
{
	// If you can break apart the vector, partition the vector and pivot values around it, then
	// do the same for the rest of the vector.
	if (startIndex < endIndex)
	{
		// This places the pivot (or partitionIndex) in the right spot in the vector by moving
		// every value that is less than the pivot point to the left of the pivot. At this point
		// we need to sort the rest of the positions in the vector and place them in the correct
		// spots as well.
		int partitionIndex = partition(ptrAllCars, startIndex, endIndex);
		quickSort(ptrAllCars, startIndex, partitionIndex - 1);
		quickSort(ptrAllCars, partitionIndex + 1, endIndex);
	}
}

//*************************************************************************************************
// Defining partition(Car *ptrAllCars, int startIndex, int endIndex):							  *
//																								  *
// This goes through a partition of the vector and places every Car that has a VIN less than the  *
// end position's VIN to the left part of the vector. After the vector has been traversed through *
// completely, it finally places the endIndex in its correct position in the vector.			  *
//*************************************************************************************************
int partition(Car *ptrAllCars, int startIndex, int endIndex)
{
	// This is the index we are going to place the element in the vector who's VIN is lower than
	// the ending index's VIN.
	int pivotToIndex = startIndex;

	// Go through the subvector.
	for (int i = startIndex; i < endIndex; i++)
	{
		// If this position's VIN is less than the ending index's VIN, swap where this Car is to
		// the left and increment the pivotToIndex's position in the process. This ensures that
		// we are not swapping an already proven-to-be-lower VIN back.
		if ((ptrAllCars + i)->getVin() < (ptrAllCars + endIndex)->getVin())
			swap(ptrAllCars, i, pivotToIndex++);
	}

	// Finally, now that we have traversed the vector, put the ending index's Car in the spot where
	// all the Cars before it have a VIN lower than it.
	swap(ptrAllCars, endIndex, pivotToIndex);

	// Return the index that we placed the ending index's Car because we know that it is in the
	// correct spot.
	return pivotToIndex;
}