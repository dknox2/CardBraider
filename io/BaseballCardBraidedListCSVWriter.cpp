#include <fstream>
#include <sstream>
#include <vector>

#include "BaseballCardBraidedListCSVWriter.h"
#include "CSVConstants.h"

using namespace std;

namespace io
{

BaseballCardBraidedListCSVWriter::BaseballCardBraidedListCSVWriter()
{
}

BaseballCardBraidedListCSVWriter::~BaseballCardBraidedListCSVWriter()
{
}

string BaseballCardBraidedListCSVWriter::formatBaseballCard(const BaseballCard& card) const
{
    stringstream stream;

    stream << card.getLastName() << CSVConstants::SPLIT << card.getFirstName() << CSVConstants::SPLIT
           << card.getYear() << CSVConstants::SPLIT << card.getCondition() << CSVConstants::SPLIT
           << card.getPrice() << endl;

    return stream.str();
}

void BaseballCardBraidedListCSVWriter::writeBraidedListToFile(const BaseballCardBraidedList& braidedList, const string& fileName) const
{
    ofstream file(fileName);

    vector<BaseballCard> cards = braidedList.traverseAscendingByName();

    for (auto& card : cards)
    {
        file << this->formatBaseballCard(card);
    }

    file.close();
}

}
