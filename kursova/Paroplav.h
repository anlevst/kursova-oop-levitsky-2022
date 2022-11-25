#pragma once

#include <string>

class Paroplav
{
private:
	std::string destination; // Hазва пункту призначення
	int passengerCount; // Kількість пасажирів
	std::string company; // Hазва компанії
	float tonnage; // Tоннажність
public:
	// CONSTRUCTORS
	Paroplav();
	Paroplav(std::string destination, int passengerCount, std::string company, float tonnage);

	// SETTERS
	void setDestination(std::string destination); // Встановлює назву пункту призначення
	void setPassengerCount(int passengerCount); // Встановлює кількість пасажирів
	void setCompany(std::string company); // Встановлює назву компанії
	void setTonnage(float tonnage); // Встановлює тоннажність

	// GETTERS
	std::string getDestination(); // Повертає назву пункту призначення
	int getPassengerCount(); // Повертає кількість пасажирів
	std::string getCompany(); // Повертає назву компанії
	float getTonnage(); // Повертає тоннажність

	// OTHER
	int isOverloaded(); // Повертає 1, якщо пароплав перевантажений, 0 в інших випадках
};

