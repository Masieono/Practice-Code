#include "card.hpp"

PlayingCard::PlayingCard(Rank rank, Suit suit)
: m_rank(rank)
, m_suit(suit)
{
}

Rank PlayingCard::get_rank() const
{
    return m_rank;
}

Suit PlayingCard::get_suit() const
{
    return m_suit;
}

std::string PlayingCard::convert_to_string() const
{

    if (m_rank == Joker)
    {
        return "Joker";
    }

    std::string rank_string;
    std::string suit_string;

    switch (m_rank)
    {
        case Ace: rank_string = "Ace"; break;
        case Two: rank_string = "Two"; break;
        case Three: rank_string = "Three"; break;
        case Four: rank_string = "Four"; break;
        case Five: rank_string = "Five"; break;
        case Six: rank_string = "Six"; break;
        case Seven: rank_string = "Seven"; break;
        case Eight: rank_string = "Eight"; break;
        case Nine: rank_string = "Nine"; break;
        case Ten: rank_string = "Ten"; break;
        case Jack: rank_string = "Jack"; break;
        case Queen: rank_string = "Queen"; break;
        case King: rank_string = "King"; break;    
    }

    switch (m_suit)
    {
        case Hearts: suit_string = "Hearts"; break;
        case Spades: suit_string = "Spades"; break;
        case Clubs: suit_string = "Clubs"; break;
        case Diamonds: suit_string = "Diamonds"; break;
        case None: suit_string = ""; break;
    }

    return rank_string + (suit_string.empty() ? "" : " of ") + suit_string;
}

std::ostream& operator<<(std::ostream& os, const PlayingCard& card)
{    
    // Send the string representation of the card to the output stream    
    os << card.convert_to_string();    
    return os;  
    // Return the stream so it can be used for further chained operations
}

bool operator==(const PlayingCard& lhs, const PlayingCard& rhs)
{
    return lhs.get_rank() == rhs.get_rank() && lhs.get_suit() == rhs.get_suit();
}

bool operator!=(const PlayingCard& lhs, const PlayingCard& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const PlayingCard& lhs, const PlayingCard& rhs)
{
    // Compare by rank first
    if (lhs.get_rank() != rhs.get_rank())
    {
        return lhs.get_rank() < rhs.get_rank();
    }
    // If ranks are equal, compare by suit
    return lhs.get_suit() < rhs.get_suit();
}

bool operator>(const PlayingCard& lhs, const PlayingCard& rhs)
{
    return rhs < lhs;
}

bool operator<=(const PlayingCard& lhs, const PlayingCard& rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const PlayingCard& lhs, const PlayingCard& rhs)
{
    return !(lhs < rhs);
}
