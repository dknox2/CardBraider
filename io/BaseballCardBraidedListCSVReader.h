#ifndef BASEBALLCARDBRAIDEDlISTCSVREADER_H
#define BASEBALLCARDBRAIDEDlISTCSVREADER_H

#include <string>

#include "BaseballCardBraidedList.h"

using namespace std;

using namespace model;

namespace io
{

/// Responsible for loading BaseballCardBraidedLists from CSV files.
///
/// The CSV format this class reads is as follows:
/// lastname,firstname,year,condition,price
///
/// where price is a whole number amount.
class BaseballCardBraidedListCSVReader
{
    BaseballCardCondition stringToBaseballCardCondition(const string&  condition) const;

    BaseballCard buildBaseballCardFromLine(const string& line) const;

public:

    /// Instantiates a new BaseballCardBraidedListCSVReader.
    ///
    /// @pre none
    /// @post none
    BaseballCardBraidedListCSVReader();

    /// Default virtual destructor for BaseballCardBraidedListCSVReader.
    virtual ~BaseballCardBraidedListCSVReader();

    /// Returns a BaseballCardBraidedList, whose contents are taken from the given CSV file using the format described above.
    ///
    /// @param fileName the CSV file to load data from
    ///
    /// @pre none
    /// @post none
    ///
    /// @return a BaseballCardBraidedList whose contents are taken from the file
    BaseballCardBraidedList buildBraidedListFromFile(const string& fileName) const;
};
}


#endif // BASEBALLCARDBRAIDEDlISTCSVREADER_H
