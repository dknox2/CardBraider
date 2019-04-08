#ifndef BASEBALLCARDCOLLECTIONWINDOW_H
#define BASEBALLCARDCOLLECTIONWINDOW_H

#include <vector>
#include <string>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Button.H>

#include "BaseballCardCollectionWindowController.h"
#include "SortOrder.h"

using namespace std;

using namespace controller;

namespace view
{

/// Defines the window where a user can load, save, add, and delete cards from a baseball card collection
class BaseballCardCollectionWindow : public Fl_Window
{
private:
    static const int SORTING_GROUPS = 3;
    static const int SORTING_TYPES_PER_GROUP = 2;
    static const int TOTAL_SORTING_METHODS = SORTING_GROUPS * SORTING_TYPES_PER_GROUP;

    vector<string> sortingGroup = {"Name", "Year", "Cond."};
    vector<string> sortingTypes = {"Ascending", "Descending"};
    string* radioSortingLabels[TOTAL_SORTING_METHODS];

    Fl_Output *sortingOutputLabel;
    Fl_Group *sortingRadioGroup;
    Fl_Round_Button *sortingRadioGroupButton[TOTAL_SORTING_METHODS];
    SortOrder sortOrderSelection;

    Fl_Output *cardSummaryOutputLabel;

    Fl_Text_Buffer *summaryOutputTextBuffer;
    Fl_Text_Display *summaryOutputTextDisplay;

    Fl_Button* loadButton;
    Fl_Button* saveButton;
    Fl_Button* addButton;
    Fl_Button* deleteButton;

    BaseballCardCollectionWindowController* controller;

    string selectedFilename;

    void createAndDisplaySortingRadioButtons();

    void setSortOrderBasedOnSelection();

    void draw();

public:

    /// Constructs a card collection window creating and initializing all the widgets that will be displayed
    ///
    /// @param width The width of the window
    /// @param height The height of the window
    /// @param title The title to display for the window
    ///
    /// @pre width > 0 AND height > 0
    /// @post none
    BaseballCardCollectionWindow(int width, int height, const char* title);

    /// Destructor that cleans up all allocated resources for the window
    virtual ~BaseballCardCollectionWindow();

    /// Callback when a radio button for the way to sort the cards has changed
    ///
    /// @param widget The widget that initiatied the callback
    /// @param data Any data that was passed with the call back. In this instance, a pointer to the window.
    ///
    /// @pre widget != 0 AND data != 0
    /// @post CardCollectionWindow::getSortOrder() == value of new sort order selected
    static void cbSortingMethodChanged(Fl_Widget* widget, void* data);

    /// Callback that is an instance function of the window class to encapsulate function
    ///
    /// @pre none
    /// @post getSortOrder() == value of new sort order selected
    void sortingMethodChanged();

    /// Callback when the Load button is invoked
    ///
    /// @param widget The widget that initiated the callback
    /// @param data Any data that was passed with the call back. In this instance, a pointer to the window.
    ///
    /// @pre widget != 0 AND data != 0
    /// @post BaseballCardCollectionWindow::getFilename() == file selected by the user
    static void cbLoad(Fl_Widget* widget, void* data);

    /// Callback when the Save button is invoked
    ///
    /// @param widget The widget that initiatied the callback
    /// @param data Any data that was passed with the call back. In this instance, a pointer to the window.
    ///
    /// @pre widget != 0 AND data != 0
    /// @post CardCollectionWindow::getFilename() == file selected by the user
    static void cbSave(Fl_Widget* widget, void* data);

    /// Callback when the Load button is invoked
    ///
    /// @param type Fl_File_Chooser type of SINGLE, MULTI, CREATE, or DIRECTORY
    /// @param title Title to display for the file chooser
    ///
    /// @pre type == Fl_File_Chooser type of SINGLE, MULTI, CREATE, or DIRECTORY
    /// @post CardCollectionWindow::getFilename() == file selected by the user
    ///
    /// @return The filename the user selected
    const string promptUserForFilename(int type, const string& title);

    /// Gets the filename the user selected when the file chooser was invoked
    ///
    /// @pre none
    /// @post none
    ///
    /// @return The filename the user had selected when the file chooser was invoked
    const string getFilename() const;

    /// Callback when the Add button is invoked
    ///
    /// @param widget The widget that initiatied the callback
    /// @param data Any data that was passed with the call back. In this instance, a pointer to the window.
    ///
    /// @pre widget != 0 AND data != 0
    /// @post none
    static void cbAddCard(Fl_Widget* widget, void* data);

    /// Callback when the Delete button is invoked
    ///
    /// @param widget The widget that initiatied the callback
    /// @param data Any data that was passed with the call back. In this instance, a pointer to the window.
    ///
    /// @pre widget != 0 AND data != 0
    /// @post none
    static void cbDeleteCard(Fl_Widget* widget, void* data);

    /// Gets the sort order the user has selected
    ///
    /// @pre none
    /// @post none
    ///
    /// @return The sort order the user has selected
    SortOrder getSortOrder() const;

    /// Sets the summary test to display in the card collection summary output
    ///
    /// @param outputText The text to display
    ///
    /// @pre none
    /// @post none
    void setSummaryText(const string& outputText);

    /// Updates the summary text according to the current selected sort order.
    ///
    /// @pre none
    /// @post none
    void updateSummaryTextBySelectedSort();

    /// Returns the controller of this window.
    ///
    /// @pre none
    /// @post none
    ///
    /// @return the controller for the window
    BaseballCardCollectionWindowController* getController() const;
};

}

#endif // BASEBALLCARDCOLLECTIONWINDOW_H
