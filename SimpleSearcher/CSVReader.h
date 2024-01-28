#ifndef CSVREADER_H
#define CSVREADER_H

#include <fstream>
#include <vector>
#include "Serial.h"
#include "AbstractReader.h"

class CSVReader : public AbstractReader
{
private:
    std::fstream fin;

public:
    CSVReader(const std::string& filePath);
    bool is_Open() override;
    std::vector<Serial> Read() override;
};

#endif // CSVREADER_H
