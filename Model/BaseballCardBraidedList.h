#ifndef BASEBALLCARDBRAIDEDLIST_H
#define BASEBALLCARDBRAIDEDLIST_H

#include <sstream>
#include <vector>

#include "BaseballCard.h"
#include "BaseballCardNode.h"
#include "BaseballCardNodeFunctionalArgs.h"

using namespace std;

/// Linked list of BaseballCardNodes. The braided list is a sorted list, linking by name, year, and condition, hence the name.
namespace model
{

class BaseballCardBraidedList
{
    BaseballCardNode* headName;
    BaseballCardNode* headYear;
    BaseballCardNode* headCondition;

    void deleteAllNodes(BaseballCardNode* node);

    BaseballCardNode* insertNode(BaseballCardNode* node, BaseballCardNode* toInsert, BaseballCardNodeGetter getNext, BaseballCardNodeSetter setNext, BaseballCardCompare comp);

    BaseballCardNode* insertNodeByName(BaseballCardNode* node);
    BaseballCardNode* insertNodeByYear(BaseballCardNode* node);

    const vector<BaseballCardNode*> findNodesByLastName(const string& lastName) const;
    void findNodesByLastName(BaseballCardNode* node, const string& lastName, vector<BaseballCardNode*>& foundNodes) const;

    void rebraidAllByLastName(const string& lastName);
    void rebraidNameByLastName(const string& lastName);
    void rebraidYearByLastName(const string& lastName);

    void deleteNodes(const vector<BaseballCardNode*>& nodes);

    BaseballCardNode* rebraidByLastName(BaseballCardNode* node, const string& lastName, BaseballCardNodeGetter getNext, BaseballCardNodeSetter setNext);

    void traverseAscending(BaseballCardNode* node, BaseballCardNodeGetter getNext, vector<BaseballCard>& traversal) const;
    void traverseDescending(BaseballCardNode* node, BaseballCardNodeGetter getNext, vector<BaseballCard>& traversal) const;

public:

    /// Instantiates a new empty BaseballCardBraidedList.
    ///
    /// @pre none
    /// @post traverseAscendingByName().size() == 0 && traverseDescendingByName().size() == 0
    ///       && traverseAscendingByYear().size() == 0 && traverseDescendingByYear().size() == 0
    ///       && traverseAscendingByCondition().size() == 0 && traverseDescendingByCondition.size() == 0
    BaseballCardBraidedList();

    /// Virtual destructor for BaseballCardBraidedList which deletes all stored nodes.
    virtual ~BaseballCardBraidedList();

    /// Inserts the BaseballCard to the braided list, sorted by each braid.
    ///
    /// @param card the BaseballCard to insert
    ///
    /// @pre none
    /// @post traverseAscendingByName().size() == size()@prev + 1 && traverseDescendingByName().size() == size()@prev + 1
    ///       && traverseAscendingByYear().size() == size()@prev + 1 && traverseDescendingByYear().size() == size()@prev + 1
    ///       && traverseAscendingByCondition().size() == size()@prev + 1 && traverseDescendingByCondition.size() == size()@prev + 1
    void insertCard(const BaseballCard& card);

    /// Removes all cards from the braided list with the given last name, case insensitive.
    ///
    /// @param lastName the last name on the cards to remove
    ///
    /// @pre none
    /// @post containsLastName(lastName) == false
    void removeByLastName(const string& lastName);

    /// Returns true if a card with the given last name is in the braided list. False otherwise.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return true if a card with the given last name is in the braided list, false otherwise
    bool containsLastName(const string& lastName) const;

    /// Performs a traversal of the list on the name braid, returning the cards in the list sorted by last name, then first name, ascending.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the cards in the list sorted by last name, then first name ascending
    const vector<BaseballCard> traverseAscendingByName() const;

    /// Performs a traversal of the list on the name braid, returning the cards in the list sorted by last name, then first name, descending.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the cards in the list sorted by last name, then first name descending
    const vector<BaseballCard> traverseDescendingByName() const;

    /// Performs a traversal of the list on the year braid, returning the cards in the list sorted by year ascending.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the cards in the list sorted by year ascending
    const vector<BaseballCard> traverseAscendingByYear() const;

    /// Performs a traversal of the list on the year braid, returning the cards in the list sorted by year descending.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the cards in the list sorted by year descending
    const vector<BaseballCard> traverseDescendingByYear() const;
};
}


#endif // BASEBALLCARDBRAIDEDLIST_H
