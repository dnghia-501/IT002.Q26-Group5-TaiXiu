#pragma once

#include "RoundRecord.h"
#include <string>
#include <vector>

/* QA: why do NOT use `using namespace std`*/
class CSVExporter {
    std::string sFilename;

  public:
    CSVExporter(const std::string &);
    void exportToCSV(const std::vector<RoundRecord> &);
};
