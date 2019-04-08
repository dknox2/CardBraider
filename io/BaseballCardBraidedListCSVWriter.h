#ifndef BASEBALLCARDBRAIDEDLISTCSVWRITER_H
#define BASEBALLCARDBRAIDEDLISTCSVWRITER_H

#include <string>

#include "BaseballCardBraidedList.h"

using namespace std;

using namespace model;

namespace io
{

/// Responsible for writing BaseballCardBraidedLists to CSV files.
///
/// The CSV format this class writes is as follows:
/// lastname,firstname,year,condition,price
///
/// where price is a whole number amount.
class BaseballCardBraidedListCSVWriter
{
    string formatBaseballCard(const BaseballCard& card) const;

public:

    /// Instantiates a new BaseballCardBraidedListCSVWriter.
    ///
    /// @pre none
    /// @post none
    BaseballCardBraidedListCSVWriter();

    /// Default virtual destructor for BaseballCardBraidedListCSVWriter.
    virtual ~BaseballCardBraidedListCSVWriter();

    /// Writes the given BaseballCardBraidedList to the given file name in the CSV format given above.
    ///
    /// @param braidedList the BaseballCardBraidedList to write
    /// @param fileName the file name to write the CSV data to
    void writeBraidedListToFile(const BaseballCardBraidedList& braidedList, const string& fileName) const;
};
}


#endif // BASEBALLCARDBRAIDEDLISTCSVWRITER_H
