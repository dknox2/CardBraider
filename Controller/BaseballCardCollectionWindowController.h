#ifndef BASEBALLCARDCOLLECTIONWINDOWCONTROLLER_H
#define BASEBALLCARDCOLLECTIONWINDOWCONTROLLER_H

#include "BaseballCardBraidedList.h"
#include "BaseballCardBraidedListCSVReader.h"
#include "ListTraversalFormatter.h"

using namespace model;
using namespace io;
using namespace view;

namespace controller
{

class BaseballCardCollectionWindowController
{
    BaseballCardBraidedList* braidedList;

    ListTraversalFormatter traversalFormatter;

    BaseballCardBraidedListCSVReader csvReader;

public:
    BaseballCardCollectionWindowController();
    virtual ~BaseballCardCollectionWindowController();

    void loadDataFromFile(const string& fileName);

    void addCard(BaseballCard& card);

    string displayCardsAscendingByName() const;
    string displayCardsDescendingByName() const;

    string displayCardsAscendingByYear() const;
    string displayCardsDescendingByYear() const;
};

}

#endif // BASEBALLCARDCOLLECTIONWINDOWCONTROLLER_H
