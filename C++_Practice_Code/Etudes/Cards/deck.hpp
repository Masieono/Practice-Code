#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include "card.hpp"

// standard deck of 54 playing cards (52 cards and 2 jokers)
class Deck
{
    public:
        Deck(bool include_jokers = false, int num_decks = 1);     
        // initialize a standard 52 card deck IN ORDER

        PlayingCard* draw_card();
        // draws one card from the unplayed stack and moves it to the played stack

        void shuffle_deck();
        // shuffles a full deck or unplayed stack

        void reset_deck();
        // gathers all played cards, puts them at the bottom of the unplayed deck

        int cards_left() const;
        // number of cards in the unplayed stack

        int cards_played() const;
        // number of cards that have been played so far

    private:

    std::vector<PlayingCard> played_cards; 
    std::vector<PlayingCard> unplayed_cards;

};

#endif // DECK_HPP