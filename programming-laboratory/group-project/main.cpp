// === CAMPUS TECH EVENT AND COMPETITION FINDER ===
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

// ---------- Global constants ----------
const int MAX_EVENTS = 100;          // maximum capacity of the array
const int NUM_CATEGORIES = 5;
const string CATEGORIES[NUM_CATEGORIES] ={
    "Hackathon", "Workshop", "Seminar", "Competition", "Other"
};
const int MAX_ID = 99999;            // assumption: IDs are 1..99999
const int MAX_DAYS = 3650;           // assumption: at most 10 years ahead

// ---------- Data structure ----------
struct event{
    int event_id;             // unique whole number
    string event_name;        // may contain spaces
    string category;          // one of CATEGORIES
    double registration_fee;  // in Rupiah, never negative
    int days_until_event;     // whole days, never negative
};

// ============================================================
//  INPUT HELPER FUNCTIONS (Member 2)
// ============================================================

// Reads a whole number between min_value and max_value.
// Keeps asking until the input is valid, so letters or
// out-of-range numbers never crash the program.
int read_int_in_range(string prompt, int min_value, int max_value){
    int value;
    while (true){
        cout << prompt;
        cin >> value;
        if (cin.fail()){
            cin.clear();                                          // reset the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // throw away the bad input
            cout << "  Invalid input. Please enter a whole number.\n";
        } else if (value < min_value || value > max_value){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Please enter a number between " << min_value
                 << " and " << max_value << ".\n";
        } else{
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // remove the leftover '\n'
            return value;
        }
    }
}

// Reads a number (decimals allowed) that is 0 or greater.
double read_non_negative_double(string prompt){
    double value;
    while (true){
        cout << prompt;
        cin >> value;
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Invalid input. Please enter a number.\n";
        } else if (value < 0){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  The value cannot be negative.\n";
        } else{
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Reads a full line of text (spaces allowed) that is not empty.
string read_non_empty_line(string prompt){
    string text;
    while (true){
        cout << prompt;
        getline(cin, text);

        // check that the text has at least one character that is not a space
        bool has_content = false;
        for (int i = 0; i < (int)text.length(); i++){
            if (text[i] != ' '){
                has_content = true;
            }
        }
        if (has_content){
            return text;
        }
        cout << "  This field cannot be empty.\n";
    }
}

// Shows the 5 allowed categories and returns the one the user picks.
// Choosing by number guarantees the category is always valid.
string choose_category(){
    cout << "  Categories:\n";
    for (int i = 0; i < NUM_CATEGORIES; i++){
        cout << "    " << i + 1 << ". " << CATEGORIES[i] << "\n";
    }
    int choice = read_int_in_range("  Choose category (1-5): ", 1, NUM_CATEGORIES);
    return CATEGORIES[choice - 1];
}

// ============================================================
//  CORE LOGIC
// ============================================================

// Urgency classification using IF / ELSE IF (Member 2)
string classify_urgency(int days){
    if (days <= 3){
        return "Urgent";      // 0-3 days
    } else if (days <= 14){
        return "Soon";        // 4-14 days
    } else{
        return "Later";       // 15 days or more
    }
}

// Linear search by Event ID. Returns the array index, or -1 if not found.
// Used by: Add (duplicate check), Search by ID, Recursion feature. (Member 4)
int find_index_by_id(event events[], int count, int id){
    for (int i = 0; i < count; i++){
        if (events[i].event_id == id){
            return i;
        }
    }
    return -1;
}

// ---------- Display helpers (Member 2) ----------
void print_table_header(){
    cout << left << setw(7) << "ID"
         << setw(30) << "Event Name"
         << setw(13) << "Category"
         << right << setw(14) << "Fee (Rp)"
         << setw(7) << "Days"
         << "  " << left << "Urgency" << "\n";
    cout << string(81, '-') << "\n";
}

void print_event_row(event e){
    cout << left << setw(7) << e.event_id
         << setw(30) << e.event_name
         << setw(13) << e.category
         << right << setw(14) << fixed << setprecision(2) << e.registration_fee
         << setw(7) << e.days_until_event
         << "  " << left << classify_urgency(e.days_until_event) << "\n";
}

// ---------- Feature A: Add Event (Member 2) ----------
void add_event(event events[], int &count){
    if (count >= MAX_EVENTS){
        cout << "\nThe event list is full (" << MAX_EVENTS
             << " events). No more events can be added.\n";
        return;
    }

    event new_event;
    cout << "\n--- Add New Event ---\n";

    // Event ID must be unique
    while (true){
        new_event.event_id = read_int_in_range("Event ID (1-99999): ", 1, MAX_ID);
        if (find_index_by_id(events, count, new_event.event_id) == -1) {
            break;   // ID not used yet -> accept it
        }
        cout << "  Event ID " << new_event.event_id
             << " already exists. Please use a different ID.\n";
    }

    new_event.event_name = read_non_empty_line("Event Name: ");
    new_event.category = choose_category();
    new_event.registration_fee = read_non_negative_double("Registration Fee (Rp): ");
    new_event.days_until_event = read_int_in_range("Days Until Event (0-3650): ", 0, MAX_DAYS);

    events[count] = new_event;   // store in the next empty slot
    count++;                     // one more event is stored

    cout << "Event added successfully. Total events: " << count << "\n";
}

// ---------- Feature B + D: Display Events with urgency (Member 2) ----------
void display_all_events(event events[], int count){
    if (count == 0){
        cout << "\nNo events have been stored yet.\n";
        return;
    }
    cout << "\n--- All Events (" << count << ") ---\n";
    print_table_header();
    for (int i = 0; i < count; i++){
        print_event_row(events[i]);
    }
}

// ---------- Feature C: Fee Statistics (Member 1) ----------
void show_fee_statistics(event events[], int count){
    if (count == 0){
        cout << "\nNo events stored. Statistics cannot be calculated.\n";
        return;
    }

    double total = 0;
    int min_index = 0;
    int max_index = 0;

    for (int i = 0; i < count; i++){
        total = total + events[i].registration_fee;
        if (events[i].registration_fee < events[min_index].registration_fee){
            min_index = i;
        }
        if (events[i].registration_fee > events[max_index].registration_fee){
            max_index = i;
        }
    }
    double average = total / count;   // safe: count is at least 1 here

    cout << fixed << setprecision(2);
    cout << "\n--- Registration Fee Statistics ---\n";
    cout << "Number of events : " << count << "\n";
    cout << "Average fee      : Rp " << average << "\n";
    cout << "Minimum fee      : Rp " << events[min_index].registration_fee
         << " (" << events[min_index].event_name << ")\n";
    cout << "Maximum fee      : Rp " << events[max_index].registration_fee
         << " (" << events[max_index].event_name << ")\n";
}

// ---------- Feature E: Count by Category (Member 1) ----------
void count_by_category(event events[], int count){
    int counts[NUM_CATEGORIES] = {0, 0, 0, 0, 0};

    for (int i = 0; i < count; i++){
        for (int j = 0; j < NUM_CATEGORIES; j++){
            if (events[i].category == CATEGORIES[j]){
                counts[j]++;
            }
        }
    }

    cout << "\n--- Number of Events per Category ---\n";
    for (int j = 0; j < NUM_CATEGORIES; j++){
        cout << left << setw(13) << CATEGORIES[j] << ": " << counts[j] << "\n";
    }
    cout << "Total        : " << count << "\n";
}

// ---------- Feature F: Manual Bubble Sort (Member 4) ----------
void bubble_sort_by_fee(event events[], int count){
    for (int pass = 0; pass < count - 1; pass++){
        bool swapped = false;
        for (int j = 0; j < count - 1 - pass; j++){
            if (events[j].registration_fee > events[j + 1].registration_fee){
                event temp = events[j];
                events[j] = events[j + 1];
                events[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped){
            break;   // no swaps in this pass -> already sorted
        }
    }
}

void bubble_sort_by_days(event events[], int count){
    for (int pass = 0; pass < count - 1; pass++){
        bool swapped = false;
        for (int j = 0; j < count - 1 - pass; j++){
            if (events[j].days_until_event > events[j + 1].days_until_event){
                event temp = events[j];
                events[j] = events[j + 1];
                events[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped){
            break;
        }
    }
}

void sort_events_menu(event events[], int count){
    if (count == 0){
        cout << "\nNo events to sort.\n";
        return;
    }
    cout << "\n--- Sort Events ---\n";
    cout << "1. By registration fee (lowest to highest)\n";
    cout << "2. By days until event (soonest to latest)\n";
    int choice = read_int_in_range("Choose (1-2): ", 1, 2);

    if (choice == 1){
        bubble_sort_by_fee(events, count);
        cout << "\nEvents sorted by registration fee.\n";
    } else{
        bubble_sort_by_days(events, count);
        cout << "\nEvents sorted by days until event.\n";
    }
    display_all_events(events, count);
}

// ---------- Feature G: Manual Linear Search (Member 4) ----------
void search_events_menu(event events[], int count){
    if (count == 0){
        cout << "\nNo events to search.\n";
        return;
    }
    cout << "\n--- Search Events ---\n";
    cout << "1. By Event ID\n";
    cout << "2. By Event Name (exact match)\n";
    cout << "3. By Category\n";
    int choice = read_int_in_range("Choose (1-3): ", 1, 3);

    if (choice == 1){
        int id = read_int_in_range("Enter Event ID: ", 1, MAX_ID);
        int index = find_index_by_id(events, count, id);
        if (index == -1){
            cout << "No event found with ID " << id << ".\n";
        } else{
            print_table_header();
            print_event_row(events[index]);
        }
    } else if (choice == 2){
        string name = read_non_empty_line("Enter Event Name: ");
        int found = 0;
        for (int i = 0; i < count; i++){
            if (events[i].event_name == name){
                if (found == 0){
                    print_table_header();
                }
                print_event_row(events[i]);
                found++;
            }
        }
        if (found == 0){
            cout << "No event found with the name \"" << name << "\".\n";
        }
    } else {
        string category = choose_category();
        int found = 0;
        for (int i = 0; i < count; i++){
            if (events[i].category == category){
                if (found == 0){
                    print_table_header();
                }
                print_event_row(events[i]);
                found++;
            }
        }
        if (found == 0){
            cout << "No events found in category " << category << ".\n";
        } else{
            cout << found << " event(s) found.\n";
        }
    }
}

// ---------- Feature H: Recursive Total Fee (Member 3) ----------
// selected[] holds array indices of the chosen events.
// n = how many of those indices still need to be added.
double total_fee_recursive(event events[], int selected[], int n){
    if (n == 0){
        return 0;   // BASE CASE: no events left -> total is 0
    }
    // RECURSIVE CASE: fee of the last selected event + total of the first (n-1)
    return events[selected[n - 1]].registration_fee
           + total_fee_recursive(events, selected, n - 1);
}

void calculate_selected_total(event events[], int count){
    if (count == 0){
        cout << "\nNo events stored. Nothing to select.\n";
        return;
    }
    cout << "\n--- Total Fee of Selected Events (Recursion) ---\n";
    int n = read_int_in_range("How many events do you want to select (0-" + to_string(count) + ")? ", 0, count);

    int selected[MAX_EVENTS];
    for (int i = 0; i < n; i++){
        while (true){
            int id = read_int_in_range("  Enter Event ID #" + to_string(i + 1) + ": ", 1, MAX_ID);
            int index = find_index_by_id(events, count, id);
            if (index == -1){
                cout << "  Event ID not found. Try again.\n";
                continue;
            }
            bool already_selected = false;
            for (int k = 0; k < i; k++){
                if (selected[k] == index){
                    already_selected = true;
                }
            }
            if (already_selected){
                cout << "  This event is already selected. Choose another one.\n";
                continue;
            }
            selected[i] = index;
            break;
        }
    }

    double total = total_fee_recursive(events, selected, n);

    if (n > 0){
        cout << "\nSelected events:\n";
        print_table_header();
        for (int i = 0; i < n; i++){
            print_event_row(events[selected[i]]);
        }
    }
    cout << fixed << setprecision(2);
    cout << "Total registration fee of " << n << " selected event(s): Rp " << total << "\n";
}

// ---------- Feature I (Challenge): Suitable Events (Member 1) ----------
void find_suitable_events(event events[], int count){
    if (count == 0){
        cout << "\nNo events stored.\n";
        return;
    }
    cout << "\n--- Find Suitable Events ---\n";
    double budget = read_non_negative_double("Maximum budget (Rp): ");
    string category = choose_category();

    int found = 0;
    for (int i = 0; i < count; i++){
        if (events[i].registration_fee <= budget && events[i].category == category){
            if (found == 0){
                cout << "\nSuitable events:\n";
                print_table_header();
            }
            print_event_row(events[i]);
            found++;
        }
    }
    if (found == 0){
        cout << fixed << setprecision(2);
        cout << "No " << category << " events found with a fee of Rp "
             << budget << " or less.\n";
    } else{
        cout << found << " suitable event(s) found.\n";
    }
}

// ============================================================
//  MENU AND MAIN (Member 1)
// ============================================================
void show_menu(){
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

int main(){
    event events[MAX_EVENTS];   // array of structs
    int count = 0;              // how many events are currently stored
    int choice;

    do{
        show_menu();
        choice = read_int_in_range("Enter your choice (1-9): ", 1, 9);

        switch (choice){
            case 1: add_event(events, count);                break;
            case 2: display_all_events(events, count);       break;
            case 3: show_fee_statistics(events, count);      break;
            case 4: count_by_category(events, count);        break;
            case 5: sort_events_menu(events, count);         break;
            case 6: search_events_menu(events, count);       break;
            case 7: calculate_selected_total(events, count); break;
            case 8: find_suitable_events(events, count);     break;
            case 9: cout << "\nThank you for using the program. Goodbye!\n"; break;
        }
    } while (choice != 9);

    return 0;
}