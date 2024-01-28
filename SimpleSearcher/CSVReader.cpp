#include <fstream>
#include "CSVReader.h"
#include <iostream>

std::vector<std::string> split(const std::string& str, char delim)
{
    std::vector<std::string> tokens;

    if (!str.empty())
    {
        size_t start = 0, end;
        do {
            end = str.find(delim, start);
            tokens.push_back(str.substr(start, (end - start)));
            start = end + 1;
        } while (end != std::string::npos);
    }

    return tokens;
}

CSVReader::CSVReader(const std::string& filePath)
{
    fin.open(filePath);
}

bool CSVReader::is_Open()
{
    return fin.is_open();
}

std::vector<Serial> CSVReader::Read()
{
    std::vector<Serial> Serials;

    while(!fin.eof())
    {
        try
        {
            std::string str;
            std::getline(fin,str);

            auto tokens = split(str, ',');
            Serial serial;
            serial.id = std::stoi(tokens[0]);
            serial.name = tokens[1];
            serial.seasons = std::stoi(tokens[2]);
            serial.year = std::stoi(tokens[3]);
            Serials.push_back(serial);
        }
        catch (const std::exception& e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;

        }
    }

    return Serials;
}
