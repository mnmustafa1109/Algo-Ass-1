#include "Sorter.hxx"
#include "Passenger.hxx"
#include <vector>

int partition(std::vector<Passenger> &passengers, int left, int right) {
    std::string pivot = passengers[right].getId();
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (passengers[j].getId() < pivot) {
            i++;
            std::swap(passengers[i], passengers[j]);
        }
    }

    std::swap(passengers[i + 1], passengers[right]);
    return i + 1;
}

void quick_sort(std::vector<Passenger> &passengers, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(passengers, left, right);
        quick_sort(passengers, left, pivotIndex - 1);
        quick_sort(passengers, pivotIndex + 1, right);
    }
}

std::vector<Passenger> Sorter::quicksort(std::vector<Passenger> &passengers) {
    quick_sort(passengers, 0, passengers.size() - 1);
    return passengers;
}

std::vector<Passenger> Sorter::selectionsort(std::vector<Passenger> &passengers) {
    
    return passengers;
}

std::vector<Passenger> Sorter::insertionsort(std::vector<Passenger> &passengers) {
    
    return passengers;
}

std::vector<Passenger> Sorter::mergesort(std::vector<Passenger> &passengers) {
    
    return passengers;
}
