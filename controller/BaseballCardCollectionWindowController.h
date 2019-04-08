#ifndef BASEBALLCARDCOLLECTIONWINDOWCONTROLLER_H
#define BASEBALLCARDCOLLECTIONWINDOWCONTROLLER_H

#include "BaseballCardBraidedList.h"
#include "BaseballCardBraidedListCSVReader.h"
#include "BaseballCardBraidedListCSVWriter.h"
#include "ListTraversalFormatter.h"
#include "SortOrder.h"

using namespace model;
using namespace io;
using namespace view;

namespace controller
{

/// Controller class for the BaseballCardCollectionWindow view
class BaseballCardCollectionWindowController
{
    BaseballCardBraidedList braidedList;

    ListTraversalFormatter traversalFormatter;

    BaseballCardBraidedListCSVReader csvReader;
    BaseballCardBraidedListCSVWriter csvWriter;

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

    /// Saves baseball card data to the given file name.
    ///
    /// @param fileName the file name to save data to
    ///
    /// @pre none
    /// @post none
    void saveDataToFile(const string& fileName);

    /// Adds the given baseball card to the currently loaded cards.
    ///
    /// @param card the card to add to the loaded cards.
    ///
    /// @pre none
    /// @post none
    void addCard(BaseballCard& card);

    /// Removes all cards with the given last name, case insensitive.
    ///
    /// @param lastName the last name on the cards to remove
    ///
    /// @pre none
    /// @post containsLastName(lastName) == false
    void removeByLastName(const string& lastName);

    /// Returns true if a card with the given last name is held in the collection. False otherwise.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return true if a card with the given last name is held in the collection, false otherwise
    bool containsLastName(const string& lastName) const;

    /// Returns the cards sorted by the given sort order, formatted for display.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the cards sorted by name ascending
    string displayCards(SortOrder order) const;
};

}

#endif // BASEBALLCARDCOLLECTIONWINDOWCONTROLLER_H
