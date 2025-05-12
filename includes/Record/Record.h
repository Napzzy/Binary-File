#ifndef Record_H
#define Record_H

#include "File_Functions.h"

using namespace std;

class Record
{
public:
    // when you construct a Record, it's either empty or it
    //   contains a word
    Record();

    // Converting array to a 2d array.
    Record(char str[]);

    Record(char str[][100]);
    // String into 2d;
    Record(string s);
    // Array of Strings
    Record(string s[]);

    // Writes into the file the data, takes care of 2d
    long write(fstream &outs);

    // Read the file content, can fetch data.
    long read(fstream &ins, long recno);

    friend ostream &operator<<(ostream &outs,
                               const Record &r);

private:
    static const int MAX = 100;
    int recno;
    char _record[MAX + 1][MAX + 1];
};

#include "Record.hpp"

#endif