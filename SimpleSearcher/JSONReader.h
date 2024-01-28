#ifndef JSONREADER_H
#define JSONREADER_H

#include <fstream>
#include <vector>
#include "AbstractReader.h"
#include "Serial.h"

class JSONReader : public AbstractReader
{
private:
    std::fstream fin;

public:
    JSONReader(const std::string& filePath);
    bool is_Open() override;
    std::vector<Serial> Read() override;
};

#endif // JSONREADER_H
