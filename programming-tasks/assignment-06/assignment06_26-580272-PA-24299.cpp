// === MY CIPHER DESIGN ===
// Shift formula : subtracting 'a' from a lowercase character gives its alphabet index (0-25).
//                 For uppercase letters, use 'A'. Add the key to this index, then add 'a' or 'A' back to get the shifted character.
//                 For example 'c' + 3 = 'f'.
// Wrap-around   : adding the key may produce a number greater than 25. Using % 26 brings the result back to the range 0-25.
//                 For example 'x' has index 23, so with key 3, (23 + 3) % 26 = 0, which represents 'a'.
// Decryption    : to reverse encryption, shift the character forward by 26 minus the key. This gives the same result as shifting backward by the original key,
//                 so decrypt() can reuse encrypt() with the adjusted key (26 - key) % 26.
//
// Name       : Johanes Baptista Timur Indra Febbriano
// Student ID : 26/580272/PA/24299
// Class      : Programming IUP2

#include <iostream>
#include <string>
using namespace std;

// Turn any key (larger than 25 or negative) into the range 0..25
int normalize_key(int key){
    return ((key % 26) + 26) % 26;
}

// Shift one letter forward by key (0..25); anything else stays the same
char shift_char(char c, int key){
    if (c >= 'a' && c <= 'z'){
        int position = c - 'a';
        return static_cast<char>('a' + (position + key) % 26);
    } else if (c >= 'A' && c <= 'Z'){
        int position = c - 'A';
        return static_cast<char>('A' + (position + key) % 26);
    }
    return c;
}

// Shift every character of text forward by key
string encrypt(string text, int key){
    string result = text;
    for (int i = 0; i < text.length(); i++){
        result[i] = shift_char(text[i], key);
    }
    return result;
}

// Undo encrypt: shifting forward by 26 - key is the same as shifting back by key
string decrypt(string text, int key){
    return encrypt(text, (26 - key) % 26);
}

int main(){
    char mode;
    int key;
    string message;

    cin >> mode;
    cin >> key;
    cin.ignore(1000, '\n');   // remove the '\n' left after cin >> key
    getline(cin, message);

    cout << "=== CAESAR CIPHER ===" << endl;
    if (mode != 'E' && mode != 'e' && mode != 'D' && mode != 'd'){
        cout << "Invalid mode: " << mode << endl;
        return 0;
    }

    key = normalize_key(key);
    
    string result;
    if (mode == 'E' || mode == 'e'){
        cout << "Mode: Encrypt" << endl;
        result = encrypt(message, key);
    } else{
        cout << "Mode: Decrypt" << endl;
        result = decrypt(message, key);
    }

    cout << "Key: " << key << endl;
    cout << "Input: " << message << endl;
    cout << "Output: " << result << endl;
    return 0;
}

/* === DISCUSSION ANSWERS ===
1. Without % 26, the letter 'z' (position 25) with key 3 gives 25 + 3 = 28, so the program calculates 'a' + 28 = 97 + 28 = 125 and prints '}'.
   Lowercase letters in ASCII only go up to 122 ('z'), so the result goes past the end of the alphabet instead of wrapping back to 'a'.
2. Shifting by key and then by 26 - key moves the letter a total of 26 steps, which is one full trip around the alphabet, so it lands on the same letter.
   For example, with key 3, 'd' becomes 'g', and shifting 'g' forward by 23 brings it back to 'd'.
3. Without cin.ignore(), getline() reads the newline that was left in the input buffer after cin >> key, instead of the actual message. The message becomes an empty string,
   so when I ran it the program printed "Input: " and "Output: " with nothing after it.
4. Someone could simply try all 25 possible keys and look for the one that gives a readable message. Since there are so few keys, this can be done quickly even by hand.
   That's why the Caesar cipher is not safe for protecting real secrets.
*/