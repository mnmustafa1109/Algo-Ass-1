#include <iostream>
#include <string>
#include "Parser.hxx"
#include "Passenger.hxx"
#include "Sorter.hxx"
#include "MaxHeap.hxx"

int main()
{

    //     // selectionsort, insertionsort, mergesort, quicksort
    //     std::string sortType = "quicksort";

    //     // max size = 98620
    //     // 10,25,50,100,250,500,1000,2500,5000,10000,25000,50000,98620
    //     // int size = 98620; (old implementation)
    //     // array of sizes to test code with
    //     int sizes[] = { 10,25,50,100,250,500,1000,2500,5000,10000,25000,50000 };

    // Create an instance of the CSVParser and provide the path to the CSV data file.
    CSVParser parser("./data/dataset.csv");

    // Parse the CSV data into a vector of Passenger objects.
    std::vector<Passenger> passengers = parser.parseCSV();

    //     // Loop through the different dataset sizes to test the sorting algorithm.
    //     for (int size : sizes)
    //     {
    //         // Create an instance of the Sorter and pass the vector of passengers.
    //         Sorter sorter(passengers);

    //         // Sort the dataset using the specified sorting algorithm and measure the execution time.
    //         std::vector<Passenger> sortedPassengers = sorter.sortAndMeasureTime(sortType, size);

    //         // Define the output file name for the sorted dataset.
    //         std::string fileName = "../output/" + sortType + "-" + std::to_string(size) + ".csv";

    //         // Write the sorted dataset to a CSV file with the specified file name.
    //         parser.writeCSV(fileName, sortedPassengers);
    //     }

    // Initialize the MaxPriorityQueue with the vector of passengers
    MaxPriorityQueue passengerQueue(passengers);

    // std::string newPriority = "zzzzzzzzzzzz"; // Define the new priority key
    // passengerQueue.increaseKey(0, newPriority);

    std::cout << "Max priority queue:" << std::endl;
    std::cout << "------------------" << std::endl;
    std::cout << "Passenger with the highest ID: " << passengerQueue.heapExtractMax().getId() << std::endl;
    std::cout << "Passenger with the second highest ID: " << passengerQueue.heapExtractMax().getId() << std::endl;

    // save to file for testing
    std::string fileName = "../output/heapsize-" + std::to_string(passengerQueue.getSize()) + ".csv";
    parser.writeCSV(fileName, passengerQueue.getHeap());

    return 0;
}
