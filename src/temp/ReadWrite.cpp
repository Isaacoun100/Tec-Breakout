#include "ReadWrite.h"

/**
 * This method will read all of the contents of the temp.txt file that was created to
 * communicate the two thread and will return a string with its contents.
 * @return a string contaning the data in the tmp.txt
 */
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

 /**
  * This methtod will write the contents of the string result variable into the tmp.txt
  * file, this is used when the socket receives information.
  * @param result the string that contains the data that is going to be written.
 */
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

 /**
  * This method clears all contents in the temporal file that is used to communicate
  * between the two working threads. It rewrites the contents of the tmp.txt to an empty
  * thus clearing the file.
  */
void ReadWrite::clearFile() {
    writeFile("");
}

