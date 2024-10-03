#include "deck.hpp"
#include <algorithm>    // for shuffling
#include <random>       // random engine
#include <ctime>        // seeding randomness

// constructor initializes a deck with 52 cards in order
Deck::Deck(bool include_jokers, int num_decks)    
{
    for (int i = 0; i < num_decks; i++)
    {
        // initialize all rank-suit combinations
        for (int suit = Hearts; suit <= Diamonds; suit++)
        {
            for (int rank = Ace; rank <= King; rank++)
            {
                unplayed_cards.push_back(PlayingCard(static_cast<Rank>(rank), static_cast<Suit>(suit)));
            }
        }

        if (include_jokers)
        {
            unplayed_cards.push_back(PlayingCard(Joker, None)); // first joker
            unplayed_cards.push_back(PlayingCard(Joker, None)); // second joker
        }   
    }
}

// shuffle the deck (after joining all cards both played and unplayed)
void Deck::shuffle_deck()
{
    // Combine played cards back into unplayed cards if necessary
    reset_deck();

    // shuffle the unplayed cards
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(unplayed_cards.begin(), unplayed_cards.end(), g);
}

PlayingCard* Deck::draw_card()
{
    if (unplayed_cards.empty())
    {
        std::cerr << "No more cards to draw!" << std::endl;
        return nullptr;
    }

    // take the top card from the unplayed stack
    PlayingCard& drawn_card = unplayed_cards.back();
    unplayed_cards.pop_back();

    // move it to the played stack
    played_cards.push_back(drawn_card);

    return &drawn_card; // return the drawn card
}

// move all played cards back into the unplayed cards stack
void Deck::reset_deck()
{    
    if (!played_cards.empty())
    {
        // move played cards back to unplayed stack
        unplayed_cards.insert(unplayed_cards.begin(), played_cards.begin(), played_cards.end());
        played_cards.clear();
    }   
}

// return the number of cards left in the unplayed stack
int Deck::cards_left() const
{
    return unplayed_cards.size();
}

// return the number of cards played so far
int Deck::cards_played() const
{
    return played_cards.size();
}