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

/// Controller class for the BaseballCardCollectionWindow view
class BaseballCardCollectionWindowController
{
    BaseballCardBraidedList* braidedList;

    ListTraversalFormatter traversalFormatter;

    BaseballCardBraidedListCSVReader csvReader;

public:

    /// Instantiates a new BaseballCardCollectionWindowController.
    ///
    /// @pre none
    /// @post none
    BaseballCardCollectionWindowController();

    /// Default virtual destructor for BaseballCardCollectionWindowController.
    virtual ~BaseballCardCollectionWindowController();

    /// Loads baseball card data from the given file name.
    ///
    /// @param fileName the file name to load data from
    ///
    /// @pre none
    /// @post none
    void loadDataFromFile(const string& fileName);

    /// Adds the given baseball card to the currently loaded cards.
    ///
    /// @param card the card to add to the loaded cards.
    ///
    /// @pre none
    /// @post none
    void addCard(BaseballCard& card);

    /// Gives the cards sorted by name ascending, formatted for display.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the cards sorted by name ascending
    string displayCardsAscendingByName() const;

    /// Gives the cards sorted by name descending, formatted for display.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the cards sorted by name descending
    string displayCardsDescendingByName() const;

    /// Gives the cards sorted by year ascending, formatted for display.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the cards sorted by year ascending
    string displayCardsAscendingByYear() const;

    /// Gives the cards sorted by year descending, formatted for display.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the cards sorted by year descending
    string displayCardsDescendingByYear() const;
};

}

#endif // BASEBALLCARDCOLLECTIONWINDOWCONTROLLER_H
