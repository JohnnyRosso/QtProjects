#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include <vector>
#include "Serial.h"

class AbstractReader
{
public:
    virtual bool is_Open() = 0;
    virtual std::vector<Serial> Read() = 0;
};

#endif // ABSTRACTREADER_H
