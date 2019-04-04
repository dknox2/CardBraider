#ifndef BASEBALLCARDBRAIDEDLIST_H
#define BASEBALLCARDBRAIDEDLIST_H

#include <sstream>
#include <vector>

#include "BaseballCard.h"
#include "BaseballCardNode.h"
#include "BaseballCardNodeFunctionalArgs.h"

using namespace std;

namespace model
{

class BaseballCardBraidedList
{
    BaseballCardNode* headName;
    BaseballCardNode* headYear;

    void deleteNodes(BaseballCardNode* node);

    BaseballCardNode* insertNode(BaseballCardNode* node, BaseballCardNode* toInsert, BaseballCardNodeGetter getNext, BaseballCardNodeSetter setNext, BaseballCardCompare comp);

    BaseballCardNode* insertNodeByName(BaseballCardNode* node);
    BaseballCardNode* insertNodeByYear(BaseballCardNode* node);

    /*
    void appendCardToOutputAscending(BaseballCardNode* node, stringstream& stream) const;
    void appendCardToOutputDescending(BaseballCardNode* node, stringstream& stream) const;
    */

    void traverseAscending(BaseballCardNode* node, BaseballCardNodeGetter getNext, vector<BaseballCard>& traversal) const;
    void traverseDescending(BaseballCardNode* node, BaseballCardNodeGetter getNext, vector<BaseballCard>& traversal) const;

public:
    BaseballCardBraidedList();
    virtual ~BaseballCardBraidedList();

    void insertCard(const BaseballCard& card);

    const vector<BaseballCard> traverseAscendingByName() const;
    const vector<BaseballCard> traverseDescendingByName() const;

    const vector<BaseballCard> traverseAscendingByYear() const;
    const vector<BaseballCard> traverseDescendingByYear() const;

};
}


#endif // BASEBALLCARDBRAIDEDLIST_H
