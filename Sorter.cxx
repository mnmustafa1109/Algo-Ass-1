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

//! MERGE SORT

void merge(std::vector<Passenger> &passengers, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<Passenger> leftSubarray;

    std::vector<Passenger> rightSubarray;


    for (int i = 0; i < n1; i++) {
        leftSubarray.push_back(passengers[left + i]);
    }
    for (int j = 0; j < n2; j++) {
        rightSubarray.push_back(passengers[middle + 1 + j]);
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftSubarray[i].getId() <= rightSubarray[j].getId()) {
            passengers[k] = leftSubarray[i];
            i++;
        } else {
            passengers[k] = rightSubarray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        passengers[k] = leftSubarray[i];
        i++;
        k++;
    }

    while (j < n2) {
        passengers[k] = rightSubarray[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<Passenger> &passengers, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        merge_sort(passengers, left, middle);
        merge_sort(passengers, middle + 1, right);
        merge(passengers, left, middle, right);
    }
}



std::vector<Passenger> Sorter::quicksort(std::vector<Passenger> &passengers) {
    quick_sort(passengers, 0, passengers.size() - 1);
    return passengers;
}

std::vector<Passenger> Sorter::selectionsort(std::vector<Passenger> &passengers) {
    //implementing selection sort
    int n = passengers.size();

     for (int i = 0; i < n - 1; i++)
    {
	         int minIndex = i;
           for (int j = i + 1; j < n; j++) 
           {
                  if (passengers[j].getId() < passengers[minIndex].getId())
                 {
    			        minIndex = j;
                 }
	       }
         if (minIndex != i)
        {
            std::swap(passengers[minIndex], passengers[i]);
        }
   }
    return passengers;
}

std::vector<Passenger> Sorter::insertionsort(std::vector<Passenger> &passengers) {
    int n = passengers.size();
    for (int i = 1; i < n; ++i) {
        Passenger key = passengers[i];
        int j = i - 1;

        while (j >= 0 && passengers[j].getId() > key.getId()) {
            passengers[j + 1] = passengers[j];
            j = j - 1;
        }
        passengers[j + 1] = key;
    }
    return passengers;
}

std::vector<Passenger> Sorter::mergesort(std::vector<Passenger> &passengers) {
    merge_sort(passengers, 0, passengers.size() - 1);
    return passengers;
}
