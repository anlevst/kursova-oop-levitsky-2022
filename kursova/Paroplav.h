#pragma once

#include <string>

class Paroplav
{
private:
	std::string destination; // H���� ������ �����������
	int passengerCount; // K������� ��������
	std::string company; // H���� ������
	float tonnage; // T���������
public:
	// CONSTRUCTORS
	Paroplav();
	Paroplav(std::string destination, int passengerCount, std::string company, float tonnage);

	// SETTERS
	void setDestination(std::string destination); // ���������� ����� ������ �����������
	void setPassengerCount(int passengerCount); // ���������� ������� ��������
	void setCompany(std::string company); // ���������� ����� ������
	void setTonnage(float tonnage); // ���������� ����������

	// GETTERS
	std::string getDestination(); // ������� ����� ������ �����������
	int getPassengerCount(); // ������� ������� ��������
	std::string getCompany(); // ������� ����� ������
	float getTonnage(); // ������� ����������

	// OTHER
	int isOverloaded(); // ������� 1, ���� �������� ��������������, 0 � ����� ��������
};

