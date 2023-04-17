#include "data.h"
#include "plog/Init.h"
#include "plog/Appenders/ColorConsoleAppender.h"
#include "plog/Formatters/TxtFormatter.h"
#include "plog/Log.h"
#include <vector>

void logSingle()
{
    Space::data data;
    data.i = 42;
    data.s = "Hellow World!";
    PLOGN << data;
}

void logContainer()
{
    std::vector<Space::data> vdata;
    Space::data data1;
    data1.i = 42;
    data1.s = "Hellow World!";
    Space::data data2;
    data2.i = 12;
    data2.s = "Good bye!";
    vdata.push_back(data1);
    vdata.push_back(data2);

    PLOGN << vdata;
}

int main()
{
    static plog::ColorConsoleAppender<plog::TxtFormatter> console;
    plog::init(plog::debug, &console);
    logSingle();
    logContainer();
    return 0;
}