#include "ReadWrite.h"

string ReadWrite::readFile() {
    string text;

    char tmp[256];
    getcwd(tmp, 256);
    string temporal=tmp;
    temporal=temporal.erase(temporal.size()-17,temporal.size())+"src/temp/tmp.txt";

    ifstream path(temporal);

    if(path.fail()){
        cout << "Unable to locate file to read " << endl;
        return text;
    }

    getline(path,text);

    path.close();
    return text;
}

void ReadWrite::writeFile(string result) {

    char tmp[256];
    getcwd(tmp, 256);
    string temporal=tmp;
    temporal=temporal.erase(temporal.size()-17,temporal.size())+"src/temp/tmp.txt";

    ofstream path(temporal);

    if(path.fail()){
        cout << "Unable to locate file to write " << endl;
    }

    path<<result;
    path.close();
}

void ReadWrite::clearFile() {
    writeFile("");
}

