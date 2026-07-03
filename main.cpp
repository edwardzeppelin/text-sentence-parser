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
    char ch;

    string sentence;
    while (getline(in, line)) {
        istringstream iss(line);
        char ch;

        while (iss.get(ch)) {
            sentence += ch;

            if (ch == '?' || ch == '!' || ch == '.') {
                if (ch == '?') {
                    quest += sentence + '\n';
                }
                else if (ch == '!') {
                    amplify += sentence + '\n';
                }
                sentence.clear();
            }
        }
        if (!sentence.empty() && sentence.back() != '?' && sentence.back() != '!' && sentence.back() != '.') {
            sentence += ' ';
        }
    }


    in.close();

    cout << "'?' sentences: " << endl;
    cout << quest << endl;

    cout << "'!' sentences:" << endl;
    cout << amplify << endl;

    return 0;
}
