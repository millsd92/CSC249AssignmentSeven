#include "Car.h"

// Empty constructor.
Car::Car()
	{ }

// Full constructor.
Car::Car(std::string incomingMake, std::string incomingModel, std::string incomingColor,
	int incomingYear, int incomingMileage, int incomingVin)
{
	setMake(incomingMake);
	setModel(incomingModel);
	setColor(incomingColor);
	setYear(incomingYear);
	setMileage(incomingMileage);
	setVin(incomingVin);
}

// Setter methods.
void Car::setMake(std::string incomingMake)
{
	if (incomingMake.length() < 3)
		throw std::invalid_argument("Make must be at least three characters long!");
	else
		make = incomingMake;
}

void Car::setModel(std::string incomingModel)
	{ model = incomingModel; }

void Car::setColor(std::string incomingColor)
	{ color = incomingColor; }

void Car::setYear(int incomingYear)
{
	if (incomingYear < FIRST_YEAR)
		throw std::invalid_argument("Year must be greater than " + std::to_string(FIRST_YEAR) 
			+ "!");
	else if (incomingYear > CURRENT_YEAR)
		throw std::invalid_argument("Year must be less than " + std::to_string(CURRENT_YEAR) + 
			"!");
	else
		year = incomingYear;
}

void Car::setMileage(int incomingMileage)
{
	if (incomingMileage < 0)
		throw std::invalid_argument("Mileage must be a non-negative integer!");
	else
		mileage = incomingMileage;
}

void Car::setVin(int incomingVin)
{
	if (incomingVin < 1000000 || incomingVin > 9999999)
		throw std::invalid_argument("VIN must be at seven digits!");
	else
		vin = incomingVin;
}

// Getter methods.
std::string Car::getMake() const
	{ return make; }

std::string Car::getModel() const
	{ return model; }

std::string Car::getColor() const
	{ return color; }

int Car::getYear() const
	{ return year; }

int Car::getMileage() const
	{ return mileage; }

int Car::getVin() const
	{ return vin; }
