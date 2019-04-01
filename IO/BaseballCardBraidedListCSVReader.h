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
    BaseballCardCondition stringToBaseballCardCondition(const string&  condition);
    BaseballCard buildBaseballCardFromLine(const string& line);

public:
    BaseballCardBraidedListCSVReader();
    virtual ~BaseballCardBraidedListCSVReader();

    BaseballCardBraidedList buildBraidedListFromFile(const string& fileName);
};
}


#endif // BASEBALLCARDBRAIDEDlISTCSVREADER_H
