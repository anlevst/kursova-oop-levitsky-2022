#include "Paroplav.h"

#define AVG_PASSENGER_WEIGHT_KG 70

// CONSTRUCTORS
Paroplav::Paroplav()
{
	this->destination = "";
	this->passengerCount = 0;
	this->company = "";
	this->tonnage = 0;
}

Paroplav::Paroplav(std::string destination, int passengerCount, std::string company, float tonnage)
{
	this->destination = destination;
	this->passengerCount = passengerCount;
	this->company = company;
	this->tonnage = tonnage;
}

// SETTERS
void Paroplav::setDestination(std::string destination)
{
	this->destination = destination;
};

void Paroplav::setPassengerCount(int passengerCount)
{
	this->passengerCount = passengerCount;
}

void Paroplav::setCompany(std::string company)
{
	this->company = company;
}

void Paroplav::setTonnage(float tonnage)
{
	this->tonnage = tonnage;
}

// GETTERS
std::string Paroplav::getDestination()
{
	return destination;
};

int Paroplav::getPassengerCount()
{
	return passengerCount;
};

std::string Paroplav::getCompany()
{
	return company;
};

float Paroplav::getTonnage()
{
	return tonnage;
};

// OTHER
int Paroplav::isOverloaded()
{
	if (tonnage * 1000 < passengerCount * AVG_PASSENGER_WEIGHT_KG) return 1; // Маса тонажу конвертована у кілограми

	return 0;
};

