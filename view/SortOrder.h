#ifndef SORTORDER_H
#define SORTORDER_H

namespace view
{

/// Represents the possible sorting selections in the collection window.
enum class SortOrder
{
    /// Sort and display by name ascending
    NAME_ASCENDING,

    /// Sort and display by name descending
    NAME_DESCENDING,

    /// Sort and display by year ascending
    YEAR_ASCENDING,

    /// Sort and display by year descending
    YEAR_DESCENDING,

    /// Sort and display by condition ascending
    CONDITION_ASCENDING,

    /// Sort and display by condition descending
    CONDITION_DESCENDING
};
}

#endif // SORTORDER_H
