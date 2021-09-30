#ifndef TEC_BREAKOUT_READWRITE_H
#define TEC_BREAKOUT_READWRITE_H

#include <bits/stdc++.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * The ReadWrite class will read, write and clear an specific file to save it as a way to 
 *  communicate between two threads that can't otherwise communicate.
 */
class ReadWrite {
public:
    /**
     * This method clears all contents in the temporal file that is used to communicate
     * between the two working threads. It rewrites the contents of the tmp.txt to an empty
     * thus clearing the file.
     */
    void clearFile();

    /**
     * This method will read all of the contents of the temp.txt file that was created to
     * communicate the two thread and will return a string with its contents.
     * @return a string contaning the data in the tmp.txt
     */
    string readFile();

    /**
     * This methtod will write the contents of the string result variable into the tmp.txt
     * file, this is used when the socket receives information.
     * @param result the string that contains the data that is going to be written.
     */
    void writeFile(string result);
};


#endif
