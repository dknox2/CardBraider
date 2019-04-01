#ifndef BASEBALLCARDBRAIDEDLIST_H
#define BASEBALLCARDBRAIDEDLIST_H

#include <sstream>
#include <string>

#include "BaseballCard.h"
#include "BaseballCardNode.h"

using namespace std;

namespace model
{

class BaseballCardBraidedList
{
    BaseballCardNode* headName;

    BaseballCardNode* addCard(BaseballCardNode* node, BaseballCard& card);
    void appendCardToOutput(BaseballCardNode* node, stringstream& stream) const;

public:
    BaseballCardBraidedList();
    virtual ~BaseballCardBraidedList();

    void addCard(BaseballCard card);

    string displayCardsAscending() const;
};
}


#endif // BASEBALLCARDBRAIDEDLIST_H
