// PROGRAMMING CLASS ASSIGNMENT 05 - PARCEL WAREHOUSE

// === DATA TYPE RATIONALE ===
// Tracking number : string, because it is an identifier, not a quantity we
//                   do math with, and it can start with zeros (0087123456).
//                   An int would drop those zeros and could also overflow
//                   for a 10-digit number such as 9999999999.
// Destination     : string, because a city name is text (Sleman, Bantul),
//                   not a number.
// Weight          : double, because weights can be fractional like 7.25 kg
//                   or 0.75 kg, and so can the total and the average.
//
// Name            : Johanes Baptista Timur Indra Febbriano
// Student ID      : 26/580272/PA/24299
// Class           : Programming IUP2

#include <iostream>
using namespace std;

struct Paket{
    string tracking_number;
    string destination;
    double weight;
};

// Prints one parcel in the form: <tracking> <city> <weight> kg
void printParcel(Paket parcel) {
    cout << parcel.tracking_number << " " << parcel.destination << " "
         << parcel.weight << " kg" << endl;
}

// Prints every parcel that weighs MORE than 5 kg (exactly 5 kg is not included)
void displayHeavyParcels(Paket daftar[], int n) {
    for (int i = 0; i < n; i++) {
        if (daftar[i].weight > 5) {
            printParcel(daftar[i]);
        }
    }
}

// Calculates and prints: total parcels, total weight, average weight,
// and the number of heavy parcels
void calculateStatistics(Paket daftar[], int n) {
    double totalWeight = 0;
    int heavyCount = 0;

    for (int i = 0; i < n; i++) {
        totalWeight = totalWeight + daftar[i].weight;
        if (daftar[i].weight > 5) {
            heavyCount++;
        }
    }

    double averageWeight = totalWeight / n;

    cout << "Total parcels: " << n << endl;
    cout << "Total weight: " << totalWeight << " kg" << endl;
    cout << "Average weight: " << averageWeight << " kg" << endl;
    cout << "Heavy parcels: " << heavyCount << endl;
}

// Finds the maximum weight, then prints every parcel with that weight
void findHeaviestParcel(Paket daftar[], int n) {
    // Pass 1: find the maximum weight
    double maxWeight = daftar[0].weight;
    for (int i = 1; i < n; i++) {
        if (daftar[i].weight > maxWeight) {
            maxWeight = daftar[i].weight;
        }
    }

    // Pass 2: print all parcels that have the maximum weight (handles ties)
    for (int i = 0; i < n; i++) {
        if (daftar[i].weight == maxWeight) {
            printParcel(daftar[i]);
        }
    }
}

int main() {
    Paket daftar[100];
    int n;
    cin >> n;

    // Read n parcels into daftar
    for (int i = 0; i < n; i++) {
        cin >> daftar[i].tracking_number >> daftar[i].destination >> daftar[i].weight;
    }

    cout << "=== HEAVY PARCELS (> 5 KG) ===" << endl;
    displayHeavyParcels(daftar, n);

    cout << endl << "=== GENERAL STATISTICS ===" << endl;
    calculateStatistics(daftar, n);

    cout << endl << "=== HEAVIEST PARCEL(S) ===" << endl;
    findHeaviestParcel(daftar, n);

    return 0;
}

/*
=== DISCUSSION ANSWERS ===

1. A tracking number is a label that identifies a parcel, not a quantity we
   add or average, so it should be stored as text. If it were read into an
   int, the input 0087123456 would be printed as 87123456 because leading
   zeros are lost. A 10-digit number like 9999999999 is also too large for
   an int. A string keeps every character exactly as it was typed.

2. Parcel weights can have decimal parts, such as 7.25 kg or 0.75 kg. An int
   would cut these to 7 and 0, which makes the heavy-parcel list, the total
   and the average wrong. For example, with int a 5.01 kg parcel would become
   5 and would no longer count as heavier than 5 kg. A double keeps the
   fractional part, and the average (6.8643 for the sample) is fractional too.

3. The time complexity is O(N). The function loops over the N parcels once
   to find the maximum weight, and then once more to print the parcels with
   that weight. That is about 2N steps, and constant factors are dropped in
   Big-O notation, so the work grows linearly with N.

4. We cannot know which weight is the heaviest until every parcel has been
   checked. If the program printed parcels while it was still searching, it
   could print a parcel that later turns out not to be the heaviest; in the
   sample input, 12 kg would be printed before 15 kg is found. Finding the
   maximum first and then scanning again lets the program print exactly the
   parcels equal to the maximum, including all ties such as the two 9.5 kg
   parcels in test case 2.
*/