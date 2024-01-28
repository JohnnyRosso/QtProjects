#include "JSONReader.h"
#include "Serial.h"
#include "json.hpp"
#include <fstream>

nlohmann::json json;

JSONReader::JSONReader(const std::string& filePath)
{
    fin.open(filePath);
}

bool JSONReader::is_Open()
{
    return fin.is_open();
}

std::vector<Serial> JSONReader::Read()
{
    std::vector<Serial> result;
    fin>>json;

    for (const auto & j: json)
    {
        Serial serial;

        serial.id = j["id"];
        serial.name = j["name"];
        serial.seasons = j["seasons"];
        serial.year = j["year"];

        result.push_back(serial);
    }

    return result;
}
