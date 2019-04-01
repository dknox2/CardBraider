#ifndef BASEBALLCARDBRAIDEDlISTCSVREADER_H
#define BASEBALLCARDBRAIDEDlISTCSVREADER_H

#include <string>

#include "BaseballCard.h"
#include "BaseballCardBraidedList.h"

using namespace std;

using namespace model;

namespace io
{

class BaseballCardBraidedListCSVReader
{
    BaseballCardCondition stringToBaseballCardCondition(const string&  condition) const;
    BaseballCard buildBaseballCardFromLine(const string& line) const;

public:
    BaseballCardBraidedListCSVReader();
    virtual ~BaseballCardBraidedListCSVReader();

    BaseballCardBraidedList* buildBraidedListFromFile(const string& fileName) const ;
};
}


#endif // BASEBALLCARDBRAIDEDlISTCSVREADER_H
