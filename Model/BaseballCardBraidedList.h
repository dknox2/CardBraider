#ifndef BASEBALLCARDBRAIDEDLIST_H
#define BASEBALLCARDBRAIDEDLIST_H

#include "BaseballCard.h"
#include "BaseballCardNode.h"

namespace model
{

class BaseballCardBraidedList
{
    BaseballCardNode* headName;

    void addCard(BaseballCardNode* node, BaseballCard& card);

public:
    BaseballCardBraidedList();
    virtual ~BaseballCardBraidedList();

    void addCard(BaseballCard card);
};
}


#endif // BASEBALLCARDBRAIDEDLIST_H
