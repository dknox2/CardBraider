#ifndef BASEBALLCARDCOLLECTIONWINDOWCONTROLLER_H
#define BASEBALLCARDCOLLECTIONWINDOWCONTROLLER_H

#include "BaseballCardBraidedList.h"
#include "BaseballCardBraidedListCSVReader.h"

using namespace model;
using namespace io;

namespace controller
{

class BaseballCardCollectionWindowController
{
    BaseballCardBraidedList* braidedList;
    BaseballCardBraidedListCSVReader csvReader;

public:
    BaseballCardCollectionWindowController();
    virtual ~BaseballCardCollectionWindowController();

    void loadDataFromFile(const string& fileName);

    void addCard(BaseballCard& card);

    string displayCardsAscending() const;
    string displayCardsDescending() const;
};

}

#endif // BASEBALLCARDCOLLECTIONWINDOWCONTROLLER_H
