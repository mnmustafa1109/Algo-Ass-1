#include <iostream>
#include <string>
#include "Parser.hxx"
#include "Passenger.hxx"
#include "Sorter.hxx"

int main()
{

    // selectionsort, insertionsort, mergesort, quicksort
    std::string sortType = "insertionsort";

    // max size = 98620
    // 10,25,50,100,250,500,1000,2500,5000,10000,25000,50000,98620
    //int size = 98620; (old implementation)
    // array of sizes to test code with
    int sizes[] = {10, 25, 50, 100, 250, 500, 1000, 2500, 5000, 10000, 25000, 50000, 98620};

    CSVParser parser("./data/dataset.csv");
    std::vector<Passenger> passengers = parser.parseCSV();
    
    for (int size : sizes) {
    Sorter sorter(passengers);
    std::vector<Passenger> sortedPassengers = sorter.sortAndMeasureTime(sortType, size);
    
    std::string fileName = "./output/" +sortType + "-" + std::to_string(size) + ".csv";
    parser.writeCSV(fileName, sortedPassengers);
}

    return 0;
}
