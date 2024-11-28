#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {

    ifstream in;
    in.open("text.txt");
    if (!in) {
        cerr << "Cant open file" << endl;
        return -1;
    }

    string line;
    string quest;
    string amplify;

    while (getline(in, line)) {
            istringstream iss(line);
            string sentence;
            char sign;

            while (iss) {
                sentence.clear();
                iss >> noskipws;
                while (iss.get(sign)) {
                    sentence += sign;
                    if (sign == '?' || sign == '!' || sign == '.') {
                        break;
                    }
                }

                if (sign == '?') {
                    quest += sentence + '\n';
                }
                else if (sign == '!') {
                    amplify += sentence + '\n';
                }
            }
    }

    in.close();

    cout << "'?' sentences: " << endl;
    cout << quest << endl;

    cout << "'!' sentences:" << endl;
    cout << amplify << endl;

    return 0;
}