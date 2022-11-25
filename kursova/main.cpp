#include <iostream>
#include <fstream>
#include <string> // std::string, std::stoi
#include <vector> 
#include <iomanip> // std::left, std::setw()
#include "Paroplav.h"

int main()
{
    // ³������� �������� ����� ��� ����������
    std::string fipath = "in.txt";
    std::ifstream finput(fipath);

    std::string tmp; // ���������� ����� ��� �������� getline

    int sizeArr = 0; // ʳ������ ����� � ����, ��, ��������, ����� ������ ��'���� Paroplav
    while (std::getline(finput, tmp)) // ���� ������ ��������� � ����� �����
    {
        sizeArr++;
    }
    // ������������ ������ � ���� �� ������� �����
    finput.clear();
    finput.seekg(0);

    // ����� ��'���� Paroplav
    Paroplav* paroplavArr = new Paroplav[sizeArr];

    std::cout << "Current tours:\nDestination\tPassengers\tCompany \tTonnage\n";
    std::string token; // ������� �����/�����, ��� ���� ������� � �����
    for (int i = 0; i < sizeArr; i++)
    {
        std::getline(finput, token, ' ');
        paroplavArr[i].setDestination(token);

        std::getline(finput, token, ' ');
        paroplavArr[i].setPassengerCount(std::stoi(token)); // stoi - �������, ��� ���������� string �� int

        std::getline(finput, token, ' ');
        paroplavArr[i].setCompany(token);

        std::getline(finput, token, '\n');
        paroplavArr[i].setTonnage(std::stof(token));

        // ���������� ������� ��� ������ � �������
        std::cout << std::left << std::setw(16) << paroplavArr[i].getDestination() <<
            std::left << std::setw(16) << paroplavArr[i].getPassengerCount() <<
            std::left << std::setw(16) << paroplavArr[i].getCompany() <<
            std::left << std::setw(16) << paroplavArr[i].getTonnage() << "\n";

    }

    finput.close();

    // ³������� ��������� ����� ��� ������
    std::string fopath = "out.txt";
    std::ofstream foutput(fopath);

    // ������ (���������� ����� ���������� ������) ��'���� Paroplav ��� �������������� ���������
    std::vector<Paroplav> deniedTours;

    for (int i = 0; i < sizeArr; i++)
    {
        if (paroplavArr[i].isOverloaded()) // ���� �������� ��������������
        {
            deniedTours.push_back(paroplavArr[i]);
        }
    }

    // Bubble Sort ��� ���������� �� ��������
    for (int i = 0; i < deniedTours.size(); i++)
    {
        for (int j = i; j < deniedTours.size(); j++)
        {
            if (deniedTours[i].getDestination() > deniedTours[j].getDestination())
            {
                Paroplav tmp;
                tmp = deniedTours[i];
                deniedTours[i] = deniedTours[j];
                deniedTours[j] = tmp;
            }
        }
    }

    // ���� � ������� ��� ���������� �� �������� ����� ��������������
    std::cout << "\nTours that are denied:\n";
    for (int i = 0; i < deniedTours.size(); i++)
    {
        std::cout << deniedTours[i].getDestination() << " " << deniedTours[i].getCompany() << '\n';
        foutput << deniedTours[i].getDestination() << " " << deniedTours[i].getCompany() << '\n';
    }

    foutput.close();

    std::cout << std::endl; // flush + \n
    delete[] paroplavArr;
    return 0;
}
