#ifndef PLAYING_CARD_HPP
#define PLAYING_CARD_HPP

#include <string>
#include <iostream>

enum Rank
{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Joker
};

enum Suit
{
    Hearts,
    Spades,
    Clubs,
    Diamonds,
    None // Jokers have no suit
};

class PlayingCard
{
    public:
        PlayingCard(Rank rank, Suit suit);

        Suit get_suit() const;

        Rank get_rank() const;

        std::string convert_to_string() const;
        // converts rank/suit pairing to a string e.g. "Ace of Clubs"

    private:
        Rank m_rank;
        Suit m_suit;

        // overloaded output operator for easy printing
        friend std::ostream& operator<<(std::ostream& os, const PlayingCard& card);

        // comparison operators
        friend bool operator==(const PlayingCard& lhs, const PlayingCard& rhs);
        friend bool operator!=(const PlayingCard& lhs, const PlayingCard& rhs);
        friend bool operator<(const PlayingCard& lhs, const PlayingCard& rhs);
        friend bool operator>(const PlayingCard& lhs, const PlayingCard& rhs);
        friend bool operator<=(const PlayingCard& lhs, const PlayingCard& rhs);
        friend bool operator>=(const PlayingCard& lhs, const PlayingCard& rhs);
};

#endif // PLAYING_CARD_HPP