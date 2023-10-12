#ifndef ALGO_ASS_1_SORTER_HXX
#define ALGO_ASS_1_SORTER_HXX

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "Passenger.hxx"

class Sorter
{
private:
    std::vector<Passenger> passengers;

public:
    Sorter(const std::vector<Passenger> &passengerVector) : passengers(passengerVector) {}

    std::vector<Passenger> quicksort(std::vector<Passenger> &passengers);
    std::vector<Passenger> selectionsort(std::vector<Passenger> &passengers);
    std::vector<Passenger> insertionsort(std::vector<Passenger> &passengers);
    std::vector<Passenger> mergesort(std::vector<Passenger> &passengers);

    
    std::vector<Passenger> sortAndMeasureTime(const std::string &sortingAlgorithm, int n)
    {
        std::vector<Passenger> sortedPassengers;

        if (n <= 0)
        {
            std::cout << "Invalid number of elements specified." << std::endl;
            return sortedPassengers; // Return an empty vector
        }

        auto start = std::chrono::high_resolution_clock::now();

        std::vector<Passenger> passengersCopy = {};
        for (int i = 0; i < n; i++)
        {
            passengersCopy.push_back(passengers[i]);
        }

        if (sortingAlgorithm == "quicksort")
        {
            sortedPassengers = quicksort(passengersCopy);
        }
        else if (sortingAlgorithm == "selectionsort")
        {
            sortedPassengers = selectionsort(passengersCopy);
        }
        else if (sortingAlgorithm == "insertionsort")
        {
            sortedPassengers = insertionsort(passengersCopy);
        }
        else if (sortingAlgorithm == "mergesort")
        {
            sortedPassengers = mergesort(passengersCopy);
        }
        else
        {
            std::cout << "Invalid sorting algorithm specified." << std::endl;
            return sortedPassengers; // Return an empty vector
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        int elementsSorted = std::min(n, static_cast<int>(sortedPassengers.size()));

        std::cout << "Sorted " << elementsSorted << " elements using " << sortingAlgorithm
                  << " in " << duration.count() << " microseconds." << std::endl;

        return sortedPassengers;
    }
};

#endif