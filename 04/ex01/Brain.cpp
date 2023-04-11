#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << PINK "Brain" RES " default constructor called" << std::endl;

    std::string const ideas[] = {
        "Without a sound.",
        "No technique is forbidden.",
        "Brave the shadows, find the truth.",
        "Do not fear the shrouded path.",
        "Balance is a fool's master.",
        "Secrets kept are weapons wasted.",
        "The shadows have enlightened me.",
        "Balance is weakness.",
        "The truth lies in darkness.",
        "Tradition is the corpse of wisdom.",
        "What I have done... cannot be undone.",
        "Embrace the shadow... or die in darkness!",
        "Only the worthy will survive.",
        "Time to do what's gotta be done.",
        "The rules hold you back! Leave 'em for someone who needs 'em.",
        "They can't stop me. I mean, they can try.",
        "Forget balance. This is a reckoning.",
        "I got a pack full of trouble, and nothing but time.",
        "If you look dangerous, you better be dangerous.",
        "Hold on! I'm about to say something really cool!",
        "I'm crazy! Got a doctor's note.",
        "Who needs a map?",
        "You belong in a museum!",
        "The gauntlet's for show… the talent's all me.",
        "I rarely know what I'm looking for, but I always find it.",
        "If I don't know the rules, then how can I be breaking them?",
    };
    int const numOfQuotes = sizeof(ideas) / sizeof(ideas[0]);

    for (int i = 0; i < NUM_IDEAS; ++i) {
        this->ideas[i] = ideas[std::rand() % numOfQuotes];
    }
}

Brain::Brain(Brain const &brainObj) {
    std::cout << PINK "Brain" RES " copy constructor called" << std::endl;

    for (int i = 0; i < NUM_IDEAS; ++i) {
        this->ideas[i] = brainObj.getIdea(i);
    }
}

Brain::~Brain(void) {
    std::cout << PINK "Brain" RES " destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &rhs) {
    std::cout << PINK "Brain" RES " assignment operator called" << std::endl;

    for (int i = 0; i < NUM_IDEAS; ++i) {
        this->ideas[i] = rhs.getIdea(i);
    }

    return *this;
}

std::string Brain::getIdea(int const i) const {
    return this->ideas[i];
}
