#include "Record.h"

Record::Record()
{
    _record[0][0] = '\0';
    recno = -1;
}

Record::Record(string str[])
{
    unsigned int Size = sizeof(str) / sizeof(str[0]);
    for (int i = 0; i < Size; i++)
    {
        strncpy(_record[i], str[i].c_str(), MAX);
    }
}

Record::Record(char str[])
{
    // Get the size of str;
    Array_copy(str, MAX, _record);
}

Record::Record(char str[][100])
{
    unsigned int Size = sizeof(str) / sizeof(str[0]);

    for (int i = 0; i < Size && i < MAX; i++)
    {
        strncpy(_record[i], str[i], MAX);
        _record[i][MAX] = '\0';
    }
}

Record::Record(string s)
{
    // Copy the string untifil you find the spaces
    // If you find a space, go to the next line but before add a null character
    string_copy(s, MAX, _record);
}

long Record::write(fstream &outs)
{
}