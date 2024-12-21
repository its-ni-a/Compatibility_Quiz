#include <iostream>
#include <string>
#include <vector>

class CompatibilityQuiz {
private:
    std::string name;
    int age;
    int score;
    int totalPossible;

public:
    CompatibilityQuiz() : score(0), totalPossible(150) {}
    void startQuiz();
    void getUserDetails();
    void askQuestion(const std::string& question, const std::vector<std::string>& options, const std::vector<int>& scores, bool terminate = false);
    void askQuestions();
    void displayScore();
};

void CompatibilityQuiz::startQuiz() {
    std::cout << "\n\n\t\t\t\tNia's Compatibility Quiz" << std::endl;
    std::cout << "\nPress Enter to start the quiz... " << std::endl;
    std::cin.get();

    getUserDetails();
    if (age < 21) {
        std::cout << "Absolutely not.\nThank you for being open to take the quiz, " << name 
                  << ". Have a nice life buddy!" << std::endl;
        return;
    }

    askQuestions();
    displayScore();
}

void CompatibilityQuiz::getUserDetails() {
    std::cout << "What is your name?" << std::endl;
    std::getline(std::cin, name);
    std::cout << "\nHello " << name << ", how old are you?" << std::endl;
    std::cin >> age;
    std::cin.ignore(); // Clear newline from input buffer
}

void CompatibilityQuiz::askQuestion(const std::string& question, const std::vector<std::string>& options, const std::vector<int>& scores, bool terminate) {
    std::cout << question << std::endl;
    char option = 'a';
    for (size_t i = 0; i < options.size(); ++i) {
        std::cout << option << ". " << options[i] << std::endl;
        option++;
    }

    char answer;
    bool valid = false;

    do {
        std::cin >> answer;
        std::cin.ignore(); // Clear newline from input buffer

        if (answer >= 'a' && answer < 'a' + options.size()) {
            valid = true;
            int index = answer - 'a';
            score += scores[index];

            // End quiz early if the terminate condition is met
            if (terminate && answer == 'b') {
                std::cout << "I don't even know why you bothered. Goodbye." << std::endl;
                exit(0);
            }
        } else {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    } while (!valid);
}

void CompatibilityQuiz::askQuestions() {
    askQuestion("\nDo you love Jehovah?", {"Absolutely", "Sure", "Kind of", "No"}, {10, 0, 0, 0}, true);
    askQuestion("\nAre you baptized?", {"Yes", "No"}, {10, 0}, true);
    askQuestion("\nHow many years have you been baptized?", {"10+ years", "5-10 years", "2-5 years", "Less than 2 years"}, {10, 7, 5, 3});
    askQuestion("\nDo you know a trade? (i.e. electrical, HVAC, plumbing, welding, carpentry)", {"Yes", "No"}, {10, 5});
    askQuestion("\nDo you have a salary job?", {"Yes", "No"}, {10, 0});
    askQuestion("\nIf you don't have a salary job are you in Bethel?", {"Yes", "No"}, {10, 0});
    askQuestion("\nWhen at a party are you: ", {"The life of the party", "I'm on the dance floor", "I'm at the snack table", "I'm not even at the party"}, {6, 8, 10, 4});
    askQuestion("\nAre you an introvert or extrovert?", {"introvert", "a good mix of both", "extrovert"}, {5, 10, 5});
    askQuestion("\nDo you like to travel?", {"Absolutely", "Sometimes", "Not really", "No"}, {10, 7, 3, 0});
    askQuestion("\nDo you like to try new things?", {"Absolutely", "Sometimes", "Not really", "No"}, {10, 7, 3, 0});
    askQuestion("\nIf you don't live in New York, would you be willing to move to here?", {"Absolutely", "It depends", "Not really", "No"}, {10, 7, 3, 0});
    askQuestion("\nDo you have a car?", {"Yes", "No"}, {10, 0});
    askQuestion("\nIf you have a car, do you know how to change a tire?", {"Yes", "No"}, {10, 0});
    askQuestion("\nDo you watch red pill podcasts?", {"Yes", "Sometimes", "Not really", "No"}, {0, 0, 0, 10});
    askQuestion("\nHave you been married before?", {"Yes", "No"}, {0, 0, 5, 10});
    askQuestion("\nDo you have a girl best friend?", {"Yes", "Kind of", "No"}, {0, 0, 10});
    askQuestion("\nDoes anyone think you are in a relationship with them?", {"Yes", "Maybe", "Not really", "No"}, {0, 0, 5, 10});
}

void CompatibilityQuiz::displayScore() {
    int finalScore = (score * 100 / totalPossible);
    std::cout << "Your total score is: " << finalScore << "%" << std::endl;
    if (finalScore >= 70) {
        std::cout << "Yay, we are compatible :)";
    }
    else {
        std::cout << "Oops, we are not compatible :(";
    }
}

int main() {
    CompatibilityQuiz quiz;
    quiz.startQuiz();
    return 0;
}
