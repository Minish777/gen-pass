#include <iostream>
#include <string_view>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]) {

        srand(time(nullptr));

    if (argc < 2 || argc > 3) {
        cout << "how to use: genpass [length] or genpass --help\n";
        return 1;
    }

    string_view arg = argv[1];

    if (arg == "-h" || arg == "--help") {
        cout << "To generate a password, use 'genpass [number of characters]' a minimum of 8 characters is recommended.";
        return 0;
    }
        int lenght = 0;
        try {
            lenght = stoi(string(arg));
        } catch (...) {
            cout << "Error: Lenght must be a valid number. \n";
            return 1;
        }

     if (lenght <= 0 || lenght > 128) {
         cout << "Error: Password length must be between 8 and 128 characters.\n";
        return 1;
     }
     bool use_special = true;

     if (argc == 3) {
         string_view flag = argv[2];

         if (flag == "-n" || flag == "--no-spec") {
             use_special = false;
         }
     }
        string_view alphabet_full = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
        string_view alphabet_no_spec = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

            string_view alphabet;

            if (use_special) {
                alphabet = alphabet_full;
            } else {
                alphabet = alphabet_no_spec;
            }

            cout << "your password: ";
            for (int i = 0; i < lenght; i++) {
                int idx = rand() % alphabet.length();
                cout << alphabet[idx];
            }

            cout << "\n";

    return 0;
}
