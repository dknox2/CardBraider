#include "BaseballCardCollectionWindow.h"

#include "DeleteBaseballCardWindow.h"
#include "AddBaseballCardWindow.h"

#include <FL/fl_types.h>
#include <Fl/fl_draw.H>
#include <Fl/Fl_File_Chooser.H>

#define DIAGNOSTIC_OUTPUT

#ifdef DIAGNOSTIC_OUTPUT
#include <iostream>
#endif

using namespace model;

using namespace std;

namespace view
{

BaseballCardCollectionWindow::BaseballCardCollectionWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    this->controller = new BaseballCardCollectionWindowController();

    begin();

    this->sortingOutputLabel = new Fl_Output(100, 25, 0, 0, "Sort order:");
    createAndDisplaySortingRadioButtons();

    this->cardSummaryOutputLabel = new Fl_Output(270, 110, 0, 0, "Baseball card collection summary:");

    this->summaryOutputTextBuffer = new Fl_Text_Buffer();
    this->summaryOutputTextDisplay = new Fl_Text_Display(20, 120, 500, 200);
    this->summaryOutputTextDisplay->textfont(FL_COURIER);
    this->summaryOutputTextDisplay->buffer(summaryOutputTextBuffer);

    this->loadButton = new Fl_Button(120, 330, 70, 30, "Load");
    this->loadButton->callback(cbLoad, this);

    this->saveButton = new Fl_Button(200, 330, 70, 30, "Save");
    this->saveButton->callback(cbSave, this);

    this->addButton = new Fl_Button(280, 330, 70, 30, "Add");
    this->addButton->callback(cbAddCard, this);

    this->deleteButton = new Fl_Button(360, 330, 70, 30, "Delete");
    this->deleteButton->callback(cbDeleteCard, this);

    this->setSummaryText("Demo of how to set the summary text.");

    end();
}

void BaseballCardCollectionWindow::draw()
{
    Fl_Window::draw();
    fl_frame("AAAA", 20, 35, 500, 55);
}


void BaseballCardCollectionWindow::createAndDisplaySortingRadioButtons()
{
    const int X_RADIO_GROUP = 35;
    const int Y_RADIO_GROUP = 45;
    const int WIDTH_RADIO_GROUP = 400;
    const int HEIGHT_RADIO_GROUP = 100;

    this->sortingRadioGroup = new Fl_Group(X_RADIO_GROUP, Y_RADIO_GROUP, WIDTH_RADIO_GROUP, HEIGHT_RADIO_GROUP);

    this->sortingRadioGroup->begin();

    for (int i=0; i<SORTING_GROUPS; i++)
    {
        for (int j = 0; j<SORTING_TYPES_PER_GROUP; j++)
        {
            string label = this->sortingGroup[i] + " " + this->sortingTypes[j];
            int offset = (i*SORTING_TYPES_PER_GROUP) + j;
            this->radioSortingLabels[offset] = new string(label);
            this->sortingRadioGroupButton[offset] = new Fl_Round_Button(X_RADIO_GROUP + i*160, Y_RADIO_GROUP + j*25, 12, 12, radioSortingLabels[offset]->c_str());
            this->sortingRadioGroupButton[offset]->type(FL_RADIO_BUTTON);
            this->sortingRadioGroupButton[offset]->callback(cbSortingMethodChanged, this);
        }
    }

    this->sortingRadioGroup->end();

    this->sortingRadioGroupButton[0]->set();
    this->sortOrderSelection = NAME_ASCENDING;
}

void BaseballCardCollectionWindow::cbSortingMethodChanged(Fl_Widget* widget, void* data)
{
    BaseballCardCollectionWindow* window = (BaseballCardCollectionWindow*)data;
    window->sortingMethodChanged();

#ifdef DIAGNOSTIC_OUTPUT
    cout << "Sorting method: " << window->getSortOrder() << endl;
#endif
}

void BaseballCardCollectionWindow::sortingMethodChanged()
{
    this->setSortOrderBasedOnSelection();
    this->updateSummaryTextBySelectedSort();
}

void BaseballCardCollectionWindow::updateSummaryTextBySelectedSort()
{
    switch (this->sortOrderSelection)
    {
    case SortOrder::NAME_ASCENDING:
        this->setSummaryText(this->controller->displayCardsAscendingByName());
        break;
    case SortOrder::NAME_DESCENDING:
        this->setSummaryText(this->controller->displayCardsDescendingByName());
        break;
    case SortOrder::YEAR_ASCENDING:
        this->setSummaryText(this->controller->displayCardsAscendingByYear());
        break;
    case SortOrder::YEAR_DESCENDING:
        this->setSummaryText(this->controller->displayCardsDescendingByYear());
        break;
    case SortOrder::CONDITION_ASCENDING:
        this->setSummaryText(this->controller->displayCardsAscendingByCondition());
        break;
    case SortOrder::CONDITION_DESCENDING:
        this->setSummaryText(this->controller->displayCardsDescendingByCondition());
        break;
    default:
        this->setSummaryText(this->controller->displayCardsAscendingByName());
        break;
    }
}

void BaseballCardCollectionWindow::cbLoad(Fl_Widget* widget, void* data)
{
    BaseballCardCollectionWindow* window = (BaseballCardCollectionWindow*)data;
    window->promptUserForFilename(Fl_File_Chooser::SINGLE, "Card file to load");

    BaseballCardCollectionWindowController* controller = window->getController();
    string fileName = window->getFilename();

#ifdef DIAGNOSTIC_OUTPUT
    cout << "Filename selected: " << window->getFilename() << endl;
#endif

    controller->loadDataFromFile(fileName);
    window->updateSummaryTextBySelectedSort();
}

const string BaseballCardCollectionWindow::promptUserForFilename(int type, const string& title)
{
    Fl_File_Chooser chooser(".", "*", type, title.c_str());
    chooser.show();

    while(chooser.shown())
    {
        Fl::wait();
    }

    if (chooser.value() != 0)
    {
        this->selectedFilename = chooser.value();
    }
    else
    {
        this->selectedFilename = "";
    }

    return this->selectedFilename;
}

const string BaseballCardCollectionWindow::getFilename() const
{
    return this->selectedFilename;
}

void BaseballCardCollectionWindow::cbSave(Fl_Widget* widget, void* data)
{
    BaseballCardCollectionWindow* window = (BaseballCardCollectionWindow*)data;
    window->promptUserForFilename(Fl_File_Chooser::CREATE, "Card file to save to");

#ifdef DIAGNOSTIC_OUTPUT
    cout << "Filename selected: " << window->getFilename() << endl;
#endif

}

void BaseballCardCollectionWindow::cbAddCard(Fl_Widget* widget, void* data)
{
    BaseballCardCollectionWindow* window = (BaseballCardCollectionWindow*)data; // TODO Currently, not used by may need to be used when adapt code

    AddBaseballCardWindow addCard;
    addCard.set_modal();
    addCard.show();

    while (addCard.shown())
    {
        Fl::wait();
    }

    if (addCard.getWindowResult() == OKCancelWindow::WindowResult::OK)
    {
        BaseballCardCollectionWindowController* controller = window->getController();
        BaseballCard* card = addCard.getCard();
        controller->addCard(*card);
        window->updateSummaryTextBySelectedSort();
    }

#ifdef DIAGNOSTIC_OUTPUT
    // TODO Remove or adapt code below, currently in for demo purposes
    if (addCard.getWindowResult() == OKCancelWindow::WindowResult::OK)
    {
        BaseballCard* pCard = addCard.getCard();
        cout << "OK" << endl;
        cout << "First name: " << pCard->getFirstName() << endl;
        cout << "Last name: " << pCard->getLastName() << endl;
        cout << "Year: " << pCard->getYear() << endl;
        cout << "Condition: " << pCard->getCondition() << endl;
        cout << "Price: " << pCard->getPrice() << endl;
    }
    else
    {
        cout << "Cancel or closed window." << endl;
    }
#endif

}

void BaseballCardCollectionWindow::cbDeleteCard(Fl_Widget* widget, void* data)
{
    BaseballCardCollectionWindow* window = (BaseballCardCollectionWindow*)data;

    DeleteBaseballCardWindow deleteCard;
    deleteCard.set_modal();
    deleteCard.show();

    while (deleteCard.shown())
    {
        Fl::wait();
    }

    if (deleteCard.getWindowResult() == OKCancelWindow::WindowResult::OK)
    {
        BaseballCardCollectionWindowController* controller = window->getController();
        controller->removeByLastName(deleteCard.getLastName());
        window->updateSummaryTextBySelectedSort();
    }

#ifdef DIAGNOSTIC_OUTPUT
    if (deleteCard.getWindowResult() == OKCancelWindow::WindowResult::OK)
    {
        cout << "OK - Player name: " << deleteCard.getLastName() << endl;
    }
    else
    {
        cout << "Cancel or closed window." << endl;
    }
#endif

}

void BaseballCardCollectionWindow::setSortOrderBasedOnSelection()
{
    for (int i=0; i<TOTAL_SORTING_METHODS; i++)
    {
        if (this->sortingRadioGroupButton[i]->value())
        {
            this->sortOrderSelection = (SortOrder)i;
        }
    }
}

void BaseballCardCollectionWindow::setSummaryText(const string& outputText)
{
    this->summaryOutputTextBuffer->text(outputText.c_str());
}

BaseballCardCollectionWindow::SortOrder BaseballCardCollectionWindow::getSortOrder() const {
    return this->sortOrderSelection;
}

BaseballCardCollectionWindowController* BaseballCardCollectionWindow::getController() const
{
    return this->controller;
}

BaseballCardCollectionWindow::~BaseballCardCollectionWindow()
{
    for (int i=0; i<TOTAL_SORTING_METHODS; i++)
    {
        delete this->radioSortingLabels[i];
        delete this->sortingRadioGroupButton[i];
    }

    delete this->sortingOutputLabel;

    delete this->cardSummaryOutputLabel;
    this->summaryOutputTextDisplay->buffer(0);
    delete this->summaryOutputTextBuffer;
    delete this->summaryOutputTextDisplay;

    delete this->loadButton;
    delete this->saveButton;
    delete this->addButton;
    delete this->deleteButton;

    delete this->controller;
}

}
