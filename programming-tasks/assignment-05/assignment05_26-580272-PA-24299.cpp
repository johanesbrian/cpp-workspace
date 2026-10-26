// === DATA TYPE RATIONALE ===
// Tracking number : string, because the number may start with zeros that need to be kept,
//                   and we don't calculate anything using the tracking number.
// Destination     : string, because a city name is text (Sleman, Bantul), not a number.
// Weight          : double, because a parcel's weight can have decimal values such as 7.25 or 0.75 kg.
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
void print_parcel(Paket parcel) {
    cout << parcel.tracking_number << " " << parcel.destination << " "
         << parcel.weight << " kg" << endl;
}

// Prints every parcel that weighs > 5 kg (exactly 5 kg is not included)
void display_heavy_parcels(Paket daftar[], int n) {
    for (int i = 0; i < n; i++) {
        if (daftar[i].weight > 5) {
            print_parcel(daftar[i]);
        }
    }
}

// Calculates and prints: total parcels, total weight, average weight,
// and the number of heavy parcels
void calculate_statistics(Paket daftar[], int n) {
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
void find_heaviest_parcel(Paket daftar[], int n) {
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
            print_parcel(daftar[i]);
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
    display_heavy_parcels(daftar, n);

    cout << endl << "=== GENERAL STATISTICS ===" << endl;
    calculate_statistics(daftar, n);

    cout << endl << "=== HEAVIEST PARCEL(S) ===" << endl;
    find_heaviest_parcel(daftar, n);

    return 0;
}

/*
=== DISCUSSION ANSWERS ===
1. A tracking number is used to identify a parcel, so it doesn't need to be used for calculations.
   I use string because some tracking numbers start with zeros, and those zeros must not disappear.
   If I used int, a number like 008625241 could become 8625241 and also a large tracking number may be too big to fit in an int.

2. I use double for the parcel weight because the value can have decimal numbers, such as 7.25 kg or 0.75 kg.
   If I used int, the decimal part would be lost and the calculation could be incorrect. For example, a parcel weighing 5.01 kg might be treated as 5 kg,
   even though it should be included in the heavy parcel list. Double also helps the program calculate the average weight more accurately.

3. The time complexity is O(N) because the program goes through the array to find the highest weight, then goes through it again to
   display all parcels with that weight. This means the array is checked twice but both loops depend on the number of parcels.
   In Big-O notation, the constant factor is ignored so the complexity is O(N).

4. The program needs to find the maximum weight before displaying the heaviest parcels. If it displays a parcel before checking all the
   others, there may be another parcel that weighs more. For example, a parcel weighing 12 kg is not the heaviest if another parcel weighs 15 kg.
   By finding the maximum first, the program can display every parcel with that weight, including parcels that have the same maximum weight.
*/