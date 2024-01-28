#ifndef JSONWRITER_H
#define JSONWRITER_H

#include <fstream>
#include <string>
#include "Serial.h"

class JSONWriter
{
private:
    std::fstream file;

public:
    JSONWriter(const std::string& filePath);
    bool isOpen() const;
    void Add(const Serial& serial);
};

#endif // JSONWRITER_H
