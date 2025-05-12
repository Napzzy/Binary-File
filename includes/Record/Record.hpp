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
        strncpy(_record[i], str[i].c_str(), MAX-1);
        _record[i][MAX] = '\0'; 
    }

}

Record::Record(char str[])
{
    // Get the size of str;
    strncpy(_record[0], str, MAX-1);
    _record[0][MAX] = '\0'; 
}

Record::Record(char str[][100])
{
    unsigned int Size = sizeof(str) / sizeof(str[0]);

    for (int i = 0; i < Size && i < MAX; i++)
    {
        strncpy(_record[i], str[i], MAX-1);
        _record[i][MAX] = '\0';
    }
}

Record::Record(string s)
{
    // Copy the string until you find the spaces
    // If you find a space, go to the next line but before add a null character
    string_copy(s, MAX, _record);
}

long Record::write(fstream &outs)
{

    // Move the file ptr, to to end
    // 0 Offset, Start at the end. 
    outs.seekp(0, outs.end);

    // Return the current position in the file ptr. In Bytes.
    long pos = outs.tellp();

    // Loop thru and write into the file. 
    for (int i = 0; i < MAX; i++)
        outs.write(_record[i], sizeof(_record[i])); // Write para: Start, Until

        //  Returns the current position appended item. 
    return pos / sizeof(_record); 
}

long Record::read(fstream &ins, long recno){

    // Get the position of the index
    long pos = recno * size(_record);
    // Place the ptr from the beginning to pos. 
    ins.seekg(pos, ios_base::beg);

    ins.read(_record, sizeof(_record)); 
}