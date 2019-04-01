#ifndef BASEBALLCARDBRAIDEDLIST_H
#define BASEBALLCARDBRAIDEDLIST_H

#include <sstream>
#include <string>

#include "BaseballCard.h"
#include "BaseballCardNode.h"

using namespace std;

namespace model
{

typedef BaseballCardNode* (*BaseballCardNodeGetter)(BaseballCardNode*);
typedef void (*BaseballCardNodeSetter)(BaseballCardNode*, BaseballCardNode*);
typedef bool (*BaseballCardCompare)(const BaseballCard&, const BaseballCard&);

class BaseballCardBraidedList
{
    BaseballCardNode* headName;

    static BaseballCardNode* getNextName(BaseballCardNode* node);
    static void setNextName(BaseballCardNode* node, BaseballCardNode* toSet);

    static bool compareLastThenFirst(const BaseballCard& card0, const BaseballCard& card1);

    BaseballCardNode* insertCard(BaseballCardNode* node, BaseballCard& card, BaseballCardNodeGetter getNext, BaseballCardNodeSetter setNext, BaseballCardCompare comp);

    void appendCardToOutputAscending(BaseballCardNode* node, stringstream& stream) const;
    void appendCardToOutputDescending(BaseballCardNode* node, stringstream& stream) const;

public:
    BaseballCardBraidedList();
    virtual ~BaseballCardBraidedList();

    void insertCardByName(BaseballCard card);

    string displayCardsAscending() const;
    string displayCardsDescending() const;
};
}


#endif // BASEBALLCARDBRAIDEDLIST_H
