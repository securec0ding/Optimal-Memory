#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

const int MAX_TRIES = 3;

int main(int argc, char const *argv[]) {
  for (int i = 0; i < MAX_TRIES; i++) {

    // Read password file into secret
    string secret;
    ifstream secret_file;
    secret_file.exceptions(ifstream::failbit);
    secret_file.open("secret.txt", ifstream::in);
    getline(secret_file, secret);
    secret_file.close();

    // Get user password input
    cout << "Enter the password: ";
    string input;
    getline(cin, input);

    // Compare and grant shell access if input matches secret
    if (input.compare(secret) == 0) {
      cout << "ACCESS GRANTED" << endl;
      return system("/bin/sh");
    } else {
      cout << "Incorrect! Attempt " << i+1 << " of " << MAX_TRIES << endl;
    }
  }

  return 0;
}