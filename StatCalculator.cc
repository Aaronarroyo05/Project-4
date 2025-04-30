#include <StatCalculator.h>
#include <fstream>
#include <sstream>
#include <stdexcept>

StatCalculator::StatCalculator(const string &filename) {
    ifstream textFile(filename.c_str());
    if (!textFile.is_open()) {
        throw runtime_error("ERROR: Could not open file '" + filename + "'");
    }

    string line;
    while (getline(textFile, line)) {
        istringstream iss(line);
        double value;
        while (iss >> value) {
            numberList_.push_back(value);
        }

        // Check if there was bad input
        if (!iss.eof()) {
            cerr << "WARNING: Skipping non-numeric content in line: " << line << endl;
        }
    }

    textFile.close();

    if (numberList_.empty()) {
        throw runtime_error("ERROR: No valid numeric data found in file.");
    }
}
