/*
    ASSIGNMENT 6.1:
    Create a pseudocode and program to determine the zodiac by birth_date and birth_month using struct data type.
    The table below is the rules to determine the zodiac.

    Zodiac          | Data Range
    ----------------|----------------------------
    Aries           | 21 March s/d 19 April
    Taurus          | 20 April s/d 20 May
    Gemini          | 21 May s/d 20 June
    Cancer          | 21 June s/d 22 July
    Leo             | 23 July s/d 22 August
    Virgo           | 23 August s/d 22 September
    Libra           | 23 September s/d 22 October
    Scorpio         | 23 October s/d 21 November
    Sagittarius     | 22 November s/d 21 December
    Capricorn       | 22 December s/d 19 January
    Aquarius        | 20 January s/d 18 February
    Pisces          | 19 February s/d 20 March
*/

#include <iostream>
#include <string>
using namespace std;
struct Birth {
    int birth_date;
    int birth_month;
    string zodiac;
};

int main (){
    Birth person;
    cout << "Enter your birth date (1-31): ";
    cin >> person.birth_date;
    cout << "Enter your birth month (1-12): ";
    cin >> person.birth_month;

     if (person.birth_date < 1 || person.birth_date > 31 ||
        person.birth_month < 1 || person.birth_month > 12) {
        cout << "Invalid date or month!" << endl;
    } else {
        if (person.birth_month == 1) {
            if (person.birth_date <= 19) person.zodiac = "Capricorn";
            else person.zodiac = "Aquarius";
        } else if (person.birth_month == 2) {
            if (person.birth_date <= 18) person.zodiac = "Aquarius";
            else person.zodiac = "Pisces";
        } else if (person.birth_month == 3) {
            if (person.birth_date <= 20) person.zodiac = "Pisces";
            else person.zodiac = "Aries";
        } else if (person.birth_month == 4) {
            if (person.birth_date <= 19) person.zodiac = "Aries";
            else person.zodiac = "Taurus";
        } else if (person.birth_month == 5) {
            if (person.birth_date <= 20) person.zodiac = "Taurus";
            else person.zodiac = "Gemini";
        } else if (person.birth_month == 6) {
            if (person.birth_date <= 20) person.zodiac = "Gemini";
            else person.zodiac = "Cancer";
        } else if (person.birth_month == 7) {
            if (person.birth_date <= 22) person.zodiac = "Cancer";
            else person.zodiac = "Leo";
        } else if (person.birth_month == 8) {
            if (person.birth_date <= 22) person.zodiac = "Leo";
            else person.zodiac = "Virgo";
        } else if (person.birth_month == 9) {
            if (person.birth_date <= 22) person.zodiac = "Virgo";
            else person.zodiac = "Libra";
        } else if (person.birth_month == 10) {
            if (person.birth_date <= 22) person.zodiac = "Libra";
            else person.zodiac = "Scorpio";
        } else if (person.birth_month == 11) {
            if (person.birth_date <= 21) person.zodiac = "Scorpio";
            else person.zodiac = "Sagittarius";
        } else {
            if (person.birth_date <= 21) person.zodiac = "Sagittarius";
            else person.zodiac = "Capricorn";
        }

        cout << "\n--- RESULT ---" << endl;
        cout << "Birth Date: " << person.birth_date << "/" << person.birth_month << endl;
        cout << "Zodiac Sign: " << person.zodiac << endl;
        return 0;
    }
}

/*
PSEUDOCODE:

DECLARATION
    STRUCT Birth
        birth_date  : integer
        birth_month : integer
        zodiac      : string
    END STRUCT
    person : Birth

ALGORITHM
    OUTPUT "Enter your birth date (1-31): "
    INPUT person.birth_date
    OUTPUT "Enter your birth month (1-12): "
    INPUT person.birth_month

    IF person.birth_date < 1 OR person.birth_date > 31
       OR person.birth_month < 1 OR person.birth_month > 12 THEN
        OUTPUT "Invalid date or month!"
    ELSE
        IF person.birth_month = 1 THEN
            IF person.birth_date <= 19 THEN person.zodiac <- "Capricorn"
            ELSE person.zodiac <- "Aquarius"
        ELSE IF person.birth_month = 2 THEN
            IF person.birth_date <= 18 THEN person.zodiac <- "Aquarius"
            ELSE person.zodiac <- "Pisces"
        ELSE IF person.birth_month = 3 THEN
            IF person.birth_date <= 20 THEN person.zodiac <- "Pisces"
            ELSE person.zodiac <- "Aries"
        ELSE IF person.birth_month = 4 THEN
            IF person.birth_date <= 19 THEN person.zodiac <- "Aries"
            ELSE person.zodiac <- "Taurus"
        ELSE IF person.birth_month = 5 THEN
            IF person.birth_date <= 20 THEN person.zodiac <- "Taurus"
            ELSE person.zodiac <- "Gemini"
        ELSE IF person.birth_month = 6 THEN
            IF person.birth_date <= 20 THEN person.zodiac <- "Gemini"
            ELSE person.zodiac <- "Cancer"
        ELSE IF person.birth_month = 7 THEN
            IF person.birth_date <= 22 THEN person.zodiac <- "Cancer"
            ELSE person.zodiac <- "Leo"
        ELSE IF person.birth_month = 8 THEN
            IF person.birth_date <= 22 THEN person.zodiac <- "Leo"
            ELSE person.zodiac <- "Virgo"
        ELSE IF person.birth_month = 9 THEN
            IF person.birth_date <= 22 THEN person.zodiac <- "Virgo"
            ELSE person.zodiac <- "Libra"
        ELSE IF person.birth_month = 10 THEN
            IF person.birth_date <= 22 THEN person.zodiac <- "Libra"
            ELSE person.zodiac <- "Scorpio"
        ELSE IF person.birth_month = 11 THEN
            IF person.birth_date <= 21 THEN person.zodiac <- "Scorpio"
            ELSE person.zodiac <- "Sagittarius"
        ELSE
            IF person.birth_date <= 21 THEN person.zodiac <- "Sagittarius"
            ELSE person.zodiac <- "Capricorn"
        END IF

        OUTPUT "Your zodiac is: ", person.zodiac
    END IF
END
*/