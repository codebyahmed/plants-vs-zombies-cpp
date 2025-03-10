#include "Scoreboard.h"

void Scoreboard::readFromFile(string filename) {
    ifstream file;
    file.open(filename);
    string line;
    int lineCount = 0;
    while (getline(file, line)) {
        string delimiter = ":";
        size_t pos = 0;
        string token;
        int tokenCount = 0;
        while ((pos = line.find(delimiter)) != string::npos) {
            token = line.substr(0, pos);
            if (tokenCount == 0) {
                hscore[lineCount] = stoi(token);
            }
            else if (tokenCount == 1) {
                hname[lineCount] = token;
            }
            line.erase(0, pos + delimiter.length());
            tokenCount += 1;
        }
        lineCount += 1;
    }

}