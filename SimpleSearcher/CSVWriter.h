#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <fstream>
#include <string>
#include "Serial.h"

class CSVWriter
{
private:
    std::fstream file;

public:
    CSVWriter(const std::string& filePath);
    bool isOpen() const;
    void Add(const Serial& serial);
};

#endif // CSVWRITER_H
