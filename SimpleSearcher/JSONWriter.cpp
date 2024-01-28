#include <fstream>
#include "JSONWriter.h"

JSONWriter::JSONWriter(const std::string& filePath)
{
    file.open(filePath, std::ios_base::app);
}

bool JSONWriter::isOpen() const
{
    return file.is_open();
}

void JSONWriter::Add(const Serial &serial)
{
    file << std::endl << serial.id << "," << serial.name << "," << serial.year << "," << serial.seasons;
}
