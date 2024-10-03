#include <iostream>
#include "deck.hpp"

/*
    Shows off the playing card functionality within deck.cpp and card.cpp
*/

using std::cout;
using std::endl;

int main()
{

    cout << "Initializing a deck of cards..." << endl;

    Deck standard_deck;

    while (standard_deck.cards_left() > 0)
    {
        PlayingCard* drawn_card = standard_deck.draw_card();
        cout << *drawn_card << endl;
    }

    cout << "That's all the cards! Shuffling..." << endl;

    standard_deck.shuffle_deck();

    // Draw 5 cards
    cout << "Drawing 5 cards from the deck: " << endl;
    for (int i = 0; i < 5; i++)
    {
        PlayingCard* drawn_card = standard_deck.draw_card();
        if(drawn_card)
        {
            cout << "Card " << i + 1 << ": " << *drawn_card << endl;
        }
    }

    // show number of cards left in the deck
    cout << "Cards left in the deck: " << standard_deck.cards_left() << endl;

    // show number of cards played so far
    cout << "Cards played: " << standard_deck.cards_played() << endl;

    // reset the deck
    cout << "Resetting the deck..." << endl;
    standard_deck.reset_deck();

    // Shuffle again after reset
    // cout << "Shuffling again..." << endl;
    // deck.shuffle_deck();

    // Draw another 5 cards
    cout << "Drawing another 5 cards: " << endl;
    for (int i = 0; i < 5; i++)
    {
        PlayingCard* drawn_card = standard_deck.draw_card();
        if (drawn_card)
        {
            cout << "Card " << i + 1 << ": " << *drawn_card << endl;
        }
    }

    // Show final state of the deck
    cout << "Cards left in the deck: " << standard_deck.cards_left() << endl;
    cout << "Cards played: " << standard_deck.cards_played() << endl;

    Deck multi_deck(true, 2);

    while (multi_deck.cards_left() > 0)
    {
        PlayingCard* drawn_card = multi_deck.draw_card();
        cout << *drawn_card << endl;
    }

    cout << "That's all the cards! Shuffling..." << endl;
    multi_deck.shuffle_deck();

    cout << "Drawing 15 cards..." << endl;

    for (int i = 0; i < 15; i++)
    {
        PlayingCard* drawn_card = multi_deck.draw_card();
        cout << *drawn_card << endl;
    }

    cout << "Resetting deck..." << endl;
    multi_deck.reset_deck();

    cout << "Drawing another 15 cards..." << endl;

    for (int i = 0; i < 15; i++)
    {
        PlayingCard* drawn_card = multi_deck.draw_card();
        cout << *drawn_card << endl;
    }

    cout << "Program finished. Powering down..." << endl;

    return EXIT_SUCCESS;
}