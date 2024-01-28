#include <fstream>
#include "CSVWriter.h"

CSVWriter::CSVWriter(const std::string& filePath)
{
    file.open(filePath, std::ios_base::app);
}

bool CSVWriter::isOpen() const
{
    return file.is_open();
}

void CSVWriter::Add(const Serial &serial)
{
    file << std::endl << serial.id << "," << serial.name << "," << serial.year << "," << serial.seasons;
}
