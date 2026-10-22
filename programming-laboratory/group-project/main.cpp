//  Campus Tech Event & Competition Finder
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

// ---------- Global constants ----------
const int MAX_EVENTS = 100;          // maximum capacity of the array
const int NUM_CATEGORIES = 5;
const string CATEGORIES[NUM_CATEGORIES] = {
    "Hackathon", "Workshop", "Seminar", "Competition", "Other"
};
const int MAX_ID = 99999;            // assumption: IDs are 1..99999
const int MAX_DAYS = 3650;           // assumption: at most 10 years ahead

// ---------- Data structure ----------
struct Event {
    int eventID;             // unique whole number
    string eventName;        // may contain spaces
    string category;         // one of CATEGORIES
    double registrationFee;  // in Rupiah, never negative
    int daysUntilEvent;      // whole days, never negative
};

// ============================================================
//  INPUT HELPER FUNCTIONS (Member 2)
// ============================================================

// Reads a whole number between minValue and maxValue.
// Keeps asking until the input is valid, so letters or
// out-of-range numbers never crash the program.
int readIntInRange(string prompt, int minValue, int maxValue) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();                                          // reset the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // throw away the bad input
            cout << "  Invalid input. Please enter a whole number.\n";
        } else if (value < minValue || value > maxValue) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Please enter a number between " << minValue
                 << " and " << maxValue << ".\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // remove the leftover '\n'
            return value;
        }
    }
}

// Reads a number (decimals allowed) that is 0 or greater.
double readNonNegativeDouble(string prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Invalid input. Please enter a number.\n";
        } else if (value < 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  The value cannot be negative.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Reads a full line of text (spaces allowed) that is not empty.
string readNonEmptyLine(string prompt) {
    string text;
    while (true) {
        cout << prompt;
        getline(cin, text);

        // check that the text has at least one character that is not a space
        bool hasContent = false;
        for (int i = 0; i < (int)text.length(); i++) {
            if (text[i] != ' ') {
                hasContent = true;
            }
        }
        if (hasContent) {
            return text;
        }
        cout << "  This field cannot be empty.\n";
    }
}

// Shows the 5 allowed categories and returns the one the user picks.
// Choosing by number guarantees the category is always valid.
string chooseCategory() {
    cout << "  Categories:\n";
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        cout << "    " << i + 1 << ". " << CATEGORIES[i] << "\n";
    }
    int choice = readIntInRange("  Choose category (1-5): ", 1, NUM_CATEGORIES);
    return CATEGORIES[choice - 1];
}

// ============================================================
//  CORE LOGIC
// ============================================================

// Urgency classification using IF / ELSE IF (Member 2)
string classifyUrgency(int days) {
    if (days <= 3) {
        return "Urgent";      // 0-3 days
    } else if (days <= 14) {
        return "Soon";        // 4-14 days
    } else {
        return "Later";       // 15 days or more
    }
}

// Linear search by Event ID. Returns the array index, or -1 if not found.
// Used by: Add (duplicate check), Search by ID, Recursion feature. (Member 4)
int findIndexByID(Event events[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (events[i].eventID == id) {
            return i;
        }
    }
    return -1;
}

// ---------- Display helpers (Member 2) ----------
void printTableHeader() {
    cout << left << setw(7) << "ID"
         << setw(30) << "Event Name"
         << setw(13) << "Category"
         << right << setw(14) << "Fee (Rp)"
         << setw(7) << "Days"
         << "  " << left << "Urgency" << "\n";
    cout << string(81, '-') << "\n";
}

void printEventRow(Event e) {
    cout << left << setw(7) << e.eventID
         << setw(30) << e.eventName
         << setw(13) << e.category
         << right << setw(14) << fixed << setprecision(2) << e.registrationFee
         << setw(7) << e.daysUntilEvent
         << "  " << left << classifyUrgency(e.daysUntilEvent) << "\n";
}

// ---------- Feature A: Add Event (Member 2) ----------
void addEvent(Event events[], int &count) {
    if (count >= MAX_EVENTS) {
        cout << "\nThe event list is full (" << MAX_EVENTS
             << " events). No more events can be added.\n";
        return;
    }

    Event newEvent;
    cout << "\n--- Add New Event ---\n";

    // Event ID must be unique
    while (true) {
        newEvent.eventID = readIntInRange("Event ID (1-99999): ", 1, MAX_ID);
        if (findIndexByID(events, count, newEvent.eventID) == -1) {
            break;   // ID not used yet -> accept it
        }
        cout << "  Event ID " << newEvent.eventID
             << " already exists. Please use a different ID.\n";
    }

    newEvent.eventName = readNonEmptyLine("Event Name: ");
    newEvent.category = chooseCategory();
    newEvent.registrationFee = readNonNegativeDouble("Registration Fee (Rp): ");
    newEvent.daysUntilEvent = readIntInRange("Days Until Event (0-3650): ", 0, MAX_DAYS);

    events[count] = newEvent;   // store in the next empty slot
    count++;                    // one more event is stored

    cout << "Event added successfully. Total events: " << count << "\n";
}

// ---------- Feature B + D: Display Events with urgency (Member 2) ----------
void displayAllEvents(Event events[], int count) {
    if (count == 0) {
        cout << "\nNo events have been stored yet.\n";
        return;
    }
    cout << "\n--- All Events (" << count << ") ---\n";
    printTableHeader();
    for (int i = 0; i < count; i++) {
        printEventRow(events[i]);
    }
}

// ---------- Feature C: Fee Statistics (Member 1) ----------
void showFeeStatistics(Event events[], int count) {
    if (count == 0) {
        cout << "\nNo events stored. Statistics cannot be calculated.\n";
        return;
    }

    double total = 0;
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 0; i < count; i++) {
        total = total + events[i].registrationFee;
        if (events[i].registrationFee < events[minIndex].registrationFee) {
            minIndex = i;
        }
        if (events[i].registrationFee > events[maxIndex].registrationFee) {
            maxIndex = i;
        }
    }
    double average = total / count;   // safe: count is at least 1 here

    cout << fixed << setprecision(2);
    cout << "\n--- Registration Fee Statistics ---\n";
    cout << "Number of events : " << count << "\n";
    cout << "Average fee      : Rp " << average << "\n";
    cout << "Minimum fee      : Rp " << events[minIndex].registrationFee
         << " (" << events[minIndex].eventName << ")\n";
    cout << "Maximum fee      : Rp " << events[maxIndex].registrationFee
         << " (" << events[maxIndex].eventName << ")\n";
}

// ---------- Feature E: Count by Category (Member 1) ----------
void countByCategory(Event events[], int count) {
    int counts[NUM_CATEGORIES] = {0, 0, 0, 0, 0};

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < NUM_CATEGORIES; j++) {
            if (events[i].category == CATEGORIES[j]) {
                counts[j]++;
            }
        }
    }

    cout << "\n--- Number of Events per Category ---\n";
    for (int j = 0; j < NUM_CATEGORIES; j++) {
        cout << left << setw(13) << CATEGORIES[j] << ": " << counts[j] << "\n";
    }
    cout << "Total        : " << count << "\n";
}

// ---------- Feature F: Manual Bubble Sort (Member 4) ----------
void bubbleSortByFee(Event events[], int count) {
    for (int pass = 0; pass < count - 1; pass++) {
        bool swapped = false;
        for (int j = 0; j < count - 1 - pass; j++) {
            if (events[j].registrationFee > events[j + 1].registrationFee) {
                Event temp = events[j];
                events[j] = events[j + 1];
                events[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;   // no swaps in this pass -> already sorted
        }
    }
}

void bubbleSortByDays(Event events[], int count) {
    for (int pass = 0; pass < count - 1; pass++) {
        bool swapped = false;
        for (int j = 0; j < count - 1 - pass; j++) {
            if (events[j].daysUntilEvent > events[j + 1].daysUntilEvent) {
                Event temp = events[j];
                events[j] = events[j + 1];
                events[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void sortEventsMenu(Event events[], int count) {
    if (count == 0) {
        cout << "\nNo events to sort.\n";
        return;
    }
    cout << "\n--- Sort Events ---\n";
    cout << "1. By registration fee (lowest to highest)\n";
    cout << "2. By days until event (soonest to latest)\n";
    int choice = readIntInRange("Choose (1-2): ", 1, 2);

    if (choice == 1) {
        bubbleSortByFee(events, count);
        cout << "\nEvents sorted by registration fee.\n";
    } else {
        bubbleSortByDays(events, count);
        cout << "\nEvents sorted by days until event.\n";
    }
    displayAllEvents(events, count);
}

// ---------- Feature G: Manual Linear Search (Member 4) ----------
void searchEventsMenu(Event events[], int count) {
    if (count == 0) {
        cout << "\nNo events to search.\n";
        return;
    }
    cout << "\n--- Search Events ---\n";
    cout << "1. By Event ID\n";
    cout << "2. By Event Name (exact match)\n";
    cout << "3. By Category\n";
    int choice = readIntInRange("Choose (1-3): ", 1, 3);

    if (choice == 1) {
        int id = readIntInRange("Enter Event ID: ", 1, MAX_ID);
        int index = findIndexByID(events, count, id);
        if (index == -1) {
            cout << "No event found with ID " << id << ".\n";
        } else {
            printTableHeader();
            printEventRow(events[index]);
        }
    } else if (choice == 2) {
        string name = readNonEmptyLine("Enter Event Name: ");
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (events[i].eventName == name) {
                if (found == 0) {
                    printTableHeader();
                }
                printEventRow(events[i]);
                found++;
            }
        }
        if (found == 0) {
            cout << "No event found with the name \"" << name << "\".\n";
        }
    } else {
        string category = chooseCategory();
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (events[i].category == category) {
                if (found == 0) {
                    printTableHeader();
                }
                printEventRow(events[i]);
                found++;
            }
        }
        if (found == 0) {
            cout << "No events found in category " << category << ".\n";
        } else {
            cout << found << " event(s) found.\n";
        }
    }
}

// ---------- Feature H: Recursive Total Fee (Member 3) ----------
// selected[] holds array indices of the chosen events.
// n = how many of those indices still need to be added.
double totalFeeRecursive(Event events[], int selected[], int n) {
    if (n == 0) {
        return 0;   // BASE CASE: no events left -> total is 0
    }
    // RECURSIVE CASE: fee of the last selected event + total of the first (n-1)
    return events[selected[n - 1]].registrationFee
           + totalFeeRecursive(events, selected, n - 1);
}

void calculateSelectedTotal(Event events[], int count) {
    if (count == 0) {
        cout << "\nNo events stored. Nothing to select.\n";
        return;
    }
    cout << "\n--- Total Fee of Selected Events (Recursion) ---\n";
    int n = readIntInRange("How many events do you want to select (0-"
                           + to_string(count) + ")? ", 0, count);

    int selected[MAX_EVENTS];
    for (int i = 0; i < n; i++) {
        while (true) {
            int id = readIntInRange("  Enter Event ID #" + to_string(i + 1) + ": ", 1, MAX_ID);
            int index = findIndexByID(events, count, id);
            if (index == -1) {
                cout << "  Event ID not found. Try again.\n";
                continue;
            }
            bool alreadySelected = false;
            for (int k = 0; k < i; k++) {
                if (selected[k] == index) {
                    alreadySelected = true;
                }
            }
            if (alreadySelected) {
                cout << "  This event is already selected. Choose another one.\n";
                continue;
            }
            selected[i] = index;
            break;
        }
    }

    double total = totalFeeRecursive(events, selected, n);

    if (n > 0) {
        cout << "\nSelected events:\n";
        printTableHeader();
        for (int i = 0; i < n; i++) {
            printEventRow(events[selected[i]]);
        }
    }
    cout << fixed << setprecision(2);
    cout << "Total registration fee of " << n << " selected event(s): Rp " << total << "\n";
}

// ---------- Feature I (Challenge): Suitable Events (Member 1) ----------
void findSuitableEvents(Event events[], int count) {
    if (count == 0) {
        cout << "\nNo events stored.\n";
        return;
    }
    cout << "\n--- Find Suitable Events ---\n";
    double budget = readNonNegativeDouble("Maximum budget (Rp): ");
    string category = chooseCategory();

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (events[i].registrationFee <= budget && events[i].category == category) {
            if (found == 0) {
                cout << "\nSuitable events:\n";
                printTableHeader();
            }
            printEventRow(events[i]);
            found++;
        }
    }
    if (found == 0) {
        cout << fixed << setprecision(2);
        cout << "No " << category << " events found with a fee of Rp "
             << budget << " or less.\n";
    } else {
        cout << found << " suitable event(s) found.\n";
    }
}

// ============================================================
//  MENU AND MAIN (Member 1)
// ============================================================
void showMenu() {
    cout << "\n=========================================\n";
    cout << "   CAMPUS TECH EVENT & COMPETITION FINDER\n";
    cout << "=========================================\n";
    cout << "1. Add Event\n";
    cout << "2. Display All Events\n";
    cout << "3. Registration Fee Statistics\n";
    cout << "4. Count Events by Category\n";
    cout << "5. Sort Events\n";
    cout << "6. Search Events\n";
    cout << "7. Calculate Total Fee of Selected Events (Recursion)\n";
    cout << "8. Find Suitable Events by Budget and Category\n";
    cout << "9. Exit\n";
}

int main() {
    Event events[MAX_EVENTS];   // array of structs
    int count = 0;              // how many events are currently stored
    int choice;

    do {
        showMenu();
        choice = readIntInRange("Enter your choice (1-9): ", 1, 9);

        switch (choice) {
            case 1: addEvent(events, count);               break;
            case 2: displayAllEvents(events, count);       break;
            case 3: showFeeStatistics(events, count);      break;
            case 4: countByCategory(events, count);        break;
            case 5: sortEventsMenu(events, count);         break;
            case 6: searchEventsMenu(events, count);       break;
            case 7: calculateSelectedTotal(events, count); break;
            case 8: findSuitableEvents(events, count);     break;
            case 9: cout << "\nThank you for using the program. Goodbye!\n"; break;
        }
    } while (choice != 9);

    return 0;
}