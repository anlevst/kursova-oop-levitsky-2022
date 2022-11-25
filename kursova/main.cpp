#include <iostream>
#include <fstream>
#include <string> // std::string, std::stoi
#include <vector> 
#include <iomanip> // std::left, std::setw()
#include "Paroplav.h"

int main()
{
    // Відкриття вхідного файлу для зчитування
    std::string fipath = "in.txt";
    std::ifstream finput(fipath);

    std::string tmp; // Тимчасовий рядок для операції getline

    int sizeArr = 0; // Кількість рядків у файлі, та, водночас, розмір масиву об'єктів Paroplav
    while (std::getline(finput, tmp)) // Доки можемо зчитувати з файлу рядки
    {
        sizeArr++;
    }
    // Встановлюємо курсор у файлі на початок файлу
    finput.clear();
    finput.seekg(0);

    // Масив об'єктів Paroplav
    Paroplav* paroplavArr = new Paroplav[sizeArr];

    std::cout << "Current tours:\nDestination\tPassengers\tCompany \tTonnage\n";
    std::string token; // Поточне слово/число, яке було зчитано з файлу
    for (int i = 0; i < sizeArr; i++)
    {
        std::getline(finput, token, ' ');
        paroplavArr[i].setDestination(token);

        std::getline(finput, token, ' ');
        paroplavArr[i].setPassengerCount(std::stoi(token)); // stoi - функція, яка перетворює string на int

        std::getline(finput, token, ' ');
        paroplavArr[i].setCompany(token);

        std::getline(finput, token, '\n');
        paroplavArr[i].setTonnage(std::stof(token));

        // Стилізована таблиця для виводу у консоль
        std::cout << std::left << std::setw(16) << paroplavArr[i].getDestination() <<
            std::left << std::setw(16) << paroplavArr[i].getPassengerCount() <<
            std::left << std::setw(16) << paroplavArr[i].getCompany() <<
            std::left << std::setw(16) << paroplavArr[i].getTonnage() << "\n";

    }

    finput.close();

    // Відкриття вихідного файлу для запису
    std::string fopath = "out.txt";
    std::ofstream foutput(fopath);

    // Вектор (покращенна версія динамічного масиву) об'єктів Paroplav для перевантажених пароплавів
    std::vector<Paroplav> deniedTours;

    for (int i = 0; i < sizeArr; i++)
    {
        if (paroplavArr[i].isOverloaded()) // Якщо пароплав перевантажений
        {
            deniedTours.push_back(paroplavArr[i]);
        }
    }

    // Bubble Sort для сортування за алфавітом
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

    // Вивід у консоль всіх перевезень які скасовані через перевантаження
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
