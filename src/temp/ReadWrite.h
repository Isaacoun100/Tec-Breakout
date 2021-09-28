#ifndef TEC_BREAKOUT_READWRITE_H
#define TEC_BREAKOUT_READWRITE_H

#include <bits/stdc++.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class ReadWrite {
public:
    void clearFile();
    string readFile();
    void writeFile(string result);
};


#endif //TEC_BREAKOUT_READWRITE_H
