#include "Sorter.hxx"
#include "Passenger.hxx"
#include <vector>

// This function partitions the vector of Passengers by selecting a pivot element
// and rearranging the elements in such a way that elements smaller than the pivot
// are on the left, and elements greater than or equal to the pivot are on the right.
int partition(std::vector<Passenger> &passengers, int left, int right) {
    // Select the pivot element. In this case, it's the ID of the passenger at 'right'.
    std::string pivot = passengers[right].getId();
    // Initialize the index 'i' to the left of the subarray.
    int i = left - 1;

    // Iterate through the subarray from 'left' to 'right - 1'.
    for (int j = left; j < right; j++) {
        // Compare the ID of the passenger at index 'j' with the pivot.
        if (passengers[j].getId() < pivot) {
            // If the ID is smaller than the pivot, increment 'i'.
            i++;
            // Swap the passenger at 'i' with the passenger at 'j'.
            std::swap(passengers[i], passengers[j]);
        }
    }

    // Finally, swap the pivot element with the element at index 'i + 1'.
    std::swap(passengers[i + 1], passengers[right]);
    // Return the index of the pivot element after partitioning.
    return i + 1;
}

// This is the main Quick Sort function that sorts the vector of Passengers.
void quick_sort(std::vector<Passenger> &passengers, int left, int right) {
    // If the 'left' index is less than the 'right' index, there are elements to sort.
    if (left < right) {
        // Partition the array and get the index of the pivot element.
        int pivotIndex = partition(passengers, left, right);
        // Recursively sort the subarray to the left of the pivot.
        quick_sort(passengers, left, pivotIndex - 1);
        // Recursively sort the subarray to the right of the pivot.
        quick_sort(passengers, pivotIndex + 1, right);
    }
}

// The quick_sort function is typically called with 'left' as 0 and 'right' as the
// last index of the vector to sort the entire vector. It uses the partition function
// to divide and conquer the elements in the vector, ultimately sorting them.


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
