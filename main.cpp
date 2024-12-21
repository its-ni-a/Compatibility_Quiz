#include <iostream>
#include <string>
#include <vector>

class SpiritualityQuiz {
private:
    std::string name;
    int score;
    int totalPossible;

public:
    SpiritualityQuiz() : score(0), totalPossible(110) {}
    void startQuiz();
    void getUserDetails();
    void askQuestion(const std::string& question, const std::vector<std::string>& options, const std::vector<int>& scores, bool terminate = false);
    void askQuestions();
    void displayScore();
};

void SpiritualityQuiz::startQuiz() {
    std::cout << "\n\n\t\t\t\tThink you know your Bible? We'll see about that ;)" << std::endl;
    std::cout << "\nPress Enter to start the quiz... " << std::endl;
    std::cin.get();

    askQuestions();
    displayScore();
}

void SpiritualityQuiz::getUserDetails() {
    std::cout << "What is your name?" << std::endl;
    std::getline(std::cin, name);
    std::cin.ignore(); // Clear newline from input buffer
}

void SpiritualityQuiz::askQuestion(const std::string& question, const std::vector<std::string>& options, const std::vector<int>& scores, bool terminate) {
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

void SpiritualityQuiz::askQuestions() {
    askQuestion("\nDo you love Jehovah?", {"Absolutely", "Sure", "Kind of", "No"}, {10, 0, 0, 0}, true);
    askQuestion("\nAfter what time did Adam and Eve eat the fruit? (Appendix B1)", {"4026 B.C.E", "4036 B.C.E", "4035 B.C.E", "4025 B.C.E"}, {10, 0, 0, 0});
    askQuestion("\nWhen did Jehovah tell Abraham about the promised 'offspring'? (Appendix B1)", {"1943 B.C.E", "1948 B.C.E", "1938 B.C.E", "1928 B.C.E"}, {0, 0, 10, 0});
    askQuestion("\nWhen did Jehovah assure David about his son being the promised 'offspring'? (Appendix B1)", {"Before 1060 B.C.E", "Before 1070 B.C.E", "After 1070 B.C.E", "After 1080 B.C.E"}, {0, 0, 10, 0});
    askQuestion("\nWhen was Jesus baptized? (Appendix B1)", {"26 C.E", "27 B.C.E", "28 C.E", "29 C.E"}, {0, 0, 0, 10});
    askQuestion("\nWhat is the correct order of World Powers as foretold by Daniel? (Appendix B9)", {"Greece, Babylon, Medo-Persia, Rome, Anglo-America", "Egypt, Babylon, Greece, Rome, Anglo-America", "Babylon, Medo-Persia, Greece, Rome, Anglo-America", "Egypt, Medo-Persia, Greece, Rome, Anglo-America"}, {0, 0, 10, 0});
    askQuestion("\nWhat island was Paul shipwrecked on? (Acts 28:1)", {"Cyprus", "Malta", "Crete", "Rhodes"}, {0, 10, 10, 0});
    askQuestion("\nDurich which missionary tour was Paul shipwrecked? (Appendix B13)", {"1st missionary tour", "2nd missionary tour", "3rd missionary tour", "Trip to Rome"}, {0, 0, 0, 10});
    askQuestion("\nWhich currency did Jesus say the poor widow put in the contribution box? (Luke 21:3)", {"Lepton", "Denarius", "Didrachma", "Drachma"}, {10, 0, 0, 0});
    askQuestion("\nWhat dimensions did Jehovah specifiy for Noah to use in the creation of the ark? (Genesis 6:15)", {"200 cubits long, 50 cubits wide, and 30 cubits high", "300 cubits long, 50 cubits wide, and 30 cubits high", "300 cubits long, 30 cubits wide, and 30 cubits high", "300 cubits long, 50 cubits wide, and 50 cubits high"}, {0, 10, 0, 0});
    askQuestion("\nWhat color cord did Rahab throw out her window? (Joshua 2:21)", {"Red", "Crimson", "Scarlet", "Marroon"}, {0, 0, 10, 0});
    askQuestion("\nWhat color cord did Rahab throw out her window? (Joshua 2:21)", {"Red", "Crimson", "Scarlet", "Marroon"}, {0, 0, 10, 0});

}   

void SpiritualityQuiz::displayScore() {
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
    SpiritualityQuiz quiz;
    quiz.startQuiz();
    return 0;
}
