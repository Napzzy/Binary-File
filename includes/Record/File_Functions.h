#ifndef FileFunction_H
#define FileFunction_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
bool file_exists(const char filename[])
{
    const bool debug = false;
    fstream ff;
    ff.open(filename,
            std::fstream::in | std::fstream::binary);
    if (ff.fail())
    {
        if (debug)
            cout << "file_exists(): File does NOT exist: " << filename << endl;
        return false;
    }
    if (debug)
        cout << "file_exists(): File DOES exist: " << filename << endl;
    ff.close();
    return true;
}

void ReadStringArray(string str[], char _record[])
{
}

void open_fileRW(fstream &f, const char filename[]) throw(char *)
{
    const bool debug = false;
    // opening a nonexistent file for in|out|app causes a fail()
    //   so, if the file does not exist, create it by openning it for
    //   output:
    if (!file_exists(filename))
    {
        // create the file
        f.open(filename, std::fstream::out | std::fstream::binary);
        if (f.fail())
        {
            cout << "file open (RW) failed: with out|" << filename << "]" << endl;
            throw("file RW failed  ");
        }
        else
        {
            if (debug)
                cout << "open_fileRW: file created successfully: " << filename << endl;
        }
    }
    else
    {
        f.open(filename,
               std::fstream::in | std::fstream::out | std::fstream::binary);
        if (f.fail())
        {
            cout << "file open (RW) failed. [" << filename << "]" << endl;
            throw("file failed to open.");
        }
    }
}


void string_copy(const string &s, const int &SIZE, char _record[][101])
{
    int row = 0;
    int column = 0;
    for (int i = 0; i <= SIZE && s[i] != '\0'; i++)
    {
        if (s[i] != ' ')
        {
            _record[row][column] = s[i];
            column++;
        }
        else
        {
            _record[row][column] = '\0';
            column = 0;
            row++;
        }
    }

    _record[row][column] = '\0';
}

void Array_copy(const char str[], const int &SIZE, char _record[][101])
{
    unsigned int Size = sizeof(str) / sizeof(str[0]);
    int row = 0;
    int column = 0;
    for (int i = 0; i < Size && i <= SIZE && str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            _record[row][column] = str[i];
        }
        else
        {
            _record[row][column] = '\0';
            column = 0;
            row++;
        }
    }
    _record[row][column] = '\0';
}

#endif