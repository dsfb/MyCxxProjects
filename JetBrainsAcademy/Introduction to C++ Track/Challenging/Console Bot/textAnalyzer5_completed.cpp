
#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::mt19937;
using std::random_device;
using std::regex;
using std::set;
using std::sort;
using std::sregex_iterator;
using std::string;
using std::stringstream;
using std::to_string;
using std::transform;
using std::vector;


void printMenu(){
    cout << "Hello, the following top-level commands are available to you:" << endl;
    cout << "- Text analysis: -a" << endl;
    cout << "- String Processing: -s" << endl;
    cout << "- Password generator: -p" << endl;
    cout << "- Text processing: -t" << endl;
    cout << "Please enter your query" << endl << endl;
}

bool startsWith(string full, string partial) {
    return full.rfind(partial, 0) == 0;
}

string getLowerString(string originalStr) {
    string lowerStr(originalStr);
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
        [](unsigned char c){ return tolower(c); });
    return lowerStr;
}

string getReverseString(string originalStr) {
    string result(originalStr);
    reverse(result.begin(), result.end());
    return result;
}

class TextAnalysis {
private:
    string command;
    string text;
    string wordDelimiter = " ';";
    string sentenceDelimiter = ".?!";
    map<char, unsigned int> frequencies;

    void printHelp(string help) {
        cout << help << endl;
    }

    vector<string> getVectorFromText(string delimiter) {
        vector<string> wordVector;
        stringstream stringStream(text);
        string line;
        while(getline(stringStream, line)) {
            size_t prev = 0, pos;
            while ((pos = line.find_first_of(delimiter, prev)) != string::npos) {
                if (pos > prev) {
                    wordVector.push_back(line.substr(prev, pos-prev));
                }

                prev = pos+1;
            }

            if (prev < line.length()) {
                wordVector.push_back(line.substr(prev, string::npos));
            }
        }

        return wordVector;
    }

    int calculateTotalSyllables() {
        int result = 0;
        stringstream stringStream(text);
        string line;
        while (getline(stringStream, line)) {
            for (char c : line) {
                char low = tolower(c);
                if (low == 'a' || low == 'e' || low == 'i' ||
                    low == 'o' || low == 'u') {
                    result += 1;
                }
            }
        }

        return result;
    }

    void extractTextFromCommand(string subQuery) {
        text = command.substr(string(subQuery).size());
    }

    void processFk() {
        string fkQuery = "-a -fk";
        if (command == fkQuery) {
            printHelp("This function defines the Flesch-Kincaid Readability Index.\nIt is necessary to add the analyzed text after the parameters.");
        } else {
            extractTextFromCommand(fkQuery + " ");

            int totalWords = getVectorFromText(wordDelimiter).size();
            int totalSentences = getVectorFromText(sentenceDelimiter).size();
            int totalSyllables = calculateTotalSyllables();
            double result = (0.39 * totalWords) / totalSentences;
            result += (11.8 * totalSyllables) / totalWords;
            result -= 15.59;
            cout << "Readability Level (FKGL): " << result << endl;
        }
    }

    void processKey() {
        string keyQuery = "-a -key";
        if (command == keyQuery) {
            printHelp("Identifying the most frequent words in the text.\nIt is necessary to add the analyzed text after the parameters.");
        } else {
            extractTextFromCommand(keyQuery + " ");

            string theWords[3] = {"and", "the", "to"};
            string allWords = "";
            for (string word : theWords) {
                allWords += word + "-";
            }
            vector<string> wordVector = getVectorFromText(wordDelimiter);

            map<string, unsigned int> wordMap;
            for (string word : theWords) {
                wordMap[word] = 0;
            }

            for (string word : wordVector) {
                string lowerWord = getLowerString(word);
                if (allWords.find(lowerWord) != string::npos) {
                    wordMap[lowerWord] += 1;
                }
            }

            for (string str : theWords) {
                cout << str << ": " << wordMap[str] << " times" << endl;
            }
        }
    }

    void processPalindromes() {
        string palindromesQuery = "-a -p";
        if (command == palindromesQuery) {
            printHelp("Analyzing text for palindrome words.\nIt is necessary to add the analyzed text after the parameters.");
        } else {
            extractTextFromCommand(palindromesQuery + " ");

            vector<string> wordVector = getVectorFromText(wordDelimiter);
            vector<string> palindromes;
            for (string word : wordVector) {
                if (getLowerString(word) == getReverseString(getLowerString(word))) {
                    palindromes.push_back(word);
                }
            }

            if (palindromes.size() > 0) {
                cout << "Found palindromes: ";
                for (size_t i = 0; i < palindromes.size() - 1; i++) {
                    cout << palindromes[i] << ", ";
                }

                cout << palindromes[palindromes.size() - 1]  << "\n";
            }
        }
    }

    void processTheSum() {
        string sumQuery = "-a -sum";
        if (command == sumQuery) {
            printHelp("Number of characters, number of vowels/consonants, total letter frequency, number of punctuation marks.\nIt is necessary to add the analyzed text after the parameters.");
        } else {
            extractTextFromCommand(sumQuery + " ");

            string punctuationMarks = ".,;!?-";
            string vowels = "aeiouAEIOU";
            string theCases[4] = {"Characters", "Vowels", "Consonants", "Punctuation marks"};

            map<string, unsigned int> sum;
            sum["Characters"] = 0;
            sum["Vowels"] = 0;
            sum["Consonants"] = 0;
            sum["Punctuation marks"] = 0;

            for (char c : text) {
                if (vowels.find(c) != string::npos) {
                    sum["Vowels"] += 1;
                    sum["Characters"] += 1;
                } else if (punctuationMarks.find(c) != string::npos) {
                    sum["Punctuation marks"] += 1;
                } else if (c != ' ') {
                    sum["Consonants"] += 1;
                    sum["Characters"] += 1;
                }
            }

            cout << "Characters: " << sum["Characters"] << "\n";
            cout << "Vowels: " << sum["Vowels"] << "\n";
            cout << "Consonants: " << sum["Consonants"] << "\n";
            cout << "Punctuation marks: " << sum["Punctuation marks"] << "\n";
        }
    }

    void processFrequencies() {
        string frequenciesQuery = "-a -f";
        if (command == frequenciesQuery) {
            printHelp("Counting how many times each letter of the alphabet and each punctuation mark occurs in the text.\nIt is necessary to add the analyzed text after the parameters.");
        } else {
            extractTextFromCommand(frequenciesQuery + " ");

            // Calculate frequencies
            for (char letter = 'A'; letter <= 'Z'; letter++) {
                frequencies[letter] = 0;
            }

            string punctuationMarks = ".,;!?-";

            for (char pm : punctuationMarks) {
                frequencies[pm] = 0;
            }

            for (char c : text) {
                if (c >= 'A' && c <= 'Z') {
                    frequencies[c] += 1;
                } else if (c >= 'a' && c <= 'z') {
                    frequencies[c + 'A' - 'a'] += 1;
                } else if (punctuationMarks.find(c) != string::npos) {
                    frequencies[c] += 1;
                }
            }

            // Show (calculated) frequencies
            for (char c = 'A'; c <= 'Z'; c++) {
                cout << c << ": " << frequencies[c] << endl;
            }

            cout << endl;

            for (char c : string(".,;!?-")) {
                cout << c << ": " << frequencies[c] << endl;
            }
        }
    }
public:
    TextAnalysis(string command) {
        this->command = command;
    }

    void process() {
        if (command == "-a") {
            string help = "Text Analysis (-a): This command offers comprehensive text analysis tools.\nIt includes functions:\n";
            help += "- Readability level: -fk\n- Keywords and phrases: -key\n- Palindrome search: -p\n";
            help += "- Brief summary information: -sum\n- Letter and punctuation mark frequency: -f\n";
            cout << help << endl;
        } else if (startsWith(command, "-a -fk")) {
            processFk();
        } else if (startsWith(command, "-a -key")) {
            processKey();
        } else if (startsWith(command, "-a -p")) {
            processPalindromes();
        } else if (startsWith(command, "-a -sum")) {
            processTheSum();
        } else if (startsWith(command, "-a -f")) {
            processFrequencies();
        }
    }
};

class StringProcessing {
private:
    string command;
    string text;
    string number;

    void extractTextFromCommand(string subQuery) {
        text = command.substr(string(subQuery).size());
    }

    int extractNumberFromCommand(string subQuery) {
        string result;

        for (char &c : subQuery) {
            if ((c >= '0' && c <= '9') || c == '-' || c == '+') {
                result += c;
            } else if (c == ' ') {
                continue;
            } else {
                break;
            }
        }

        return std::stoi(result);
    }

    void processEncryptionDecryption(int placesToGoDown) {
        string result;

        for (char c : text) {
            if (c != ' ') {
                result += char(int(c) + placesToGoDown);
            } else {
                result += c;
            }
        }

        cout << result << endl;
    }

    void processFlipping() {
        cout << getReverseString(text) << endl;
    }
public:
    StringProcessing(string command) {
        this->command = command;
    }

    void process() {
        string encryptionQuery = "-s -e";
        string flippingQuery = "-s -f";
        if (command == "-s") {
            cout << "String Processing (-s): This feature is designed for manipulating and transforming strings.\n"
                << "It includes functions:\n"
                << "- Encrypt the string (Use Caesar's cipher): -e\n"
                << "- Flip the string: -f\n";
        } else if (command == encryptionQuery) {
            cout << "This is a function to encrypt/decrypt a string of text.\n"
                << "Here is the format of the command:\n"
                << "-s -e -en 3 this is secret message\n"
                << "Where -en is the encryption parameter (for decryption use -de).\n"
                << "3 is the offset parameter\n";
        } else if (command == flippingQuery) {
            cout << "This is a function for flipping a string. Specify the text to be flipped.\n";
        } else if (startsWith(command, encryptionQuery + " -en")) {
            int number = extractNumberFromCommand(command.substr(string(encryptionQuery + " -en").size()));
            extractTextFromCommand(encryptionQuery + " -en " + to_string(number) + " ");

            processEncryptionDecryption(number);
        } else if (startsWith(command, encryptionQuery + " -de")) {
            int number = extractNumberFromCommand(command.substr(string(encryptionQuery + " -de").size()));
            extractTextFromCommand(encryptionQuery + " -de " + to_string(number) + " ");

            processEncryptionDecryption(-number);
        } else if (startsWith(command, flippingQuery)) {
            extractTextFromCommand(flippingQuery + " ");
            processFlipping();
        }
    }
};

class PasswordGenerator {
private:
    string command;
    string password;

    int extractNumberFromCommand(string subQuery) {
        string result;

        for (char &c : subQuery) {
            if ((c >= '0' && c <= '9') || c == '-' || c == '+') {
                result += c;
            } else if (c == ' ') {
                continue;
            } else {
                break;
            }
        }

        return std::stoi(result);
    }

    char getCharFromString(std::mt19937 gen, string refStr) {
        return refStr[gen() % (refStr.size() - 1)];
    }

    void generatePassword(int len) {
        random_device rd;   // Seed with a real random value, if available
        mt19937 gen(rd());  // Standard mersenne_twister_engine seeded with rd()

        string upperAlpha = "ABCDEFGHJKLMNPQRSTUVWXYZ";
        string lowerAlpha = "abcdefghjklmnpqrstuvwxyz";
        string digits = "23456789";
        string specialChars = "!@#$%^&";
        string alphaNum = digits + upperAlpha + lowerAlpha + specialChars;

        password = "";
        password += upperAlpha[gen() % (upperAlpha.size() - 1)];
        password += lowerAlpha[gen() % (lowerAlpha.size() - 1)];
        password += digits[gen() % (digits.size() - 1)];
        password += specialChars[gen() % (specialChars.size() - 1)];

        for (int i = 4; i < len; ++i) {
            password += alphaNum[gen() % (alphaNum.size() - 1)];
        }
    }

    bool strIsNum(string item) {
        for (char &c : item) {
            if ((c > '9' || c < '0') && c != '-' && c != '+' && c != ' ') {
                return false;
            }
        }

        return true;
    }

    vector<string> getWordForSeedPhrase(string cmd) {
        vector<string> vec;

        stringstream ss (cmd);
        string item;
        char delim = ' ';

        while (getline (ss, item, delim)) {
            if (item != "-p" && item != "-seed" && !strIsNum(item))
            vec.push_back (item);
        }

        return vec;
    }

    void generateSeedPhrase(int quantity, vector<string> words) {
        random_device rd;   // Seed with a real random value, if available
        mt19937 gen(rd());  // Standard mersenne_twister_engine seeded with rd()

        password = "";
        for (int i = 0; i < quantity; ++i) {
            int result = gen() % words.size();
            password += words[result];
            if (i < quantity - 1) {
                password += " ";
            }
        }
    }
public:
    PasswordGenerator(string command) {
        this->command = command;
    }

    void process() {
        string randQuery = "-p -rand";
        string seedQuery = "-p -seed";
        if (command == "-p") {
            string help_text = "Password Generator (-p): This command generates secure, random passwords.\nIt includes functions:";
            help_text += "\n- Random character set passwords: -rand\n- Seed phrase passwords: -seed\n";
            cout << help_text << endl;
        } else if (command == randQuery) {
            cout << "This is a function to generate a random character password.\n"
                << "It is necessary to specify the desired password length.\n";
        } else if (command == seedQuery) {
            cout << "This is a function for generating a seed phrase password.\n"
                    << "It is necessary to specify number of words and text.\n"
                    << "The default delimiter is space.\n";
        } else if (startsWith(command, randQuery)) {
            int number = extractNumberFromCommand(command.substr(randQuery.size()));
            generatePassword(number);
            cout << password << endl;
        } else if (startsWith(command, seedQuery)) {
            int number = extractNumberFromCommand(command.substr(seedQuery.size()));
            vector<string> words = getWordForSeedPhrase(command);
            if (words.size() == 0) {
                cout << "You forgot to enter the text" << endl;
                return;
            }
            generateSeedPhrase(number, words);
            cout << password << endl;
        }
    }
};

class TextProcessing {
private:
    string command;
    string text;

    int numMailAddresses;
    int numPhoneNumbers;
    int numDates;

public:
    TextProcessing(string command) {
        this->command = command;
        numMailAddresses = 0;
        numPhoneNumbers = 0;
        numDates = 0;
    }

    void extractTextFromCommand(string subQuery) {
        text = command.substr(string(subQuery).size() + 1);
    }

    void tokenizeText() {
        set<string> tokens;
        string curToken;

        for (const char &c : text) {
            if (c == ' ' && curToken.size() > 0) {
                tokens.insert(curToken);
                curToken = "";
            } else {
                curToken += c;
            }
        }

        tokens.insert(curToken);

         for (const string &t: tokens) {
            cout << t << "\n";
        }
    }

    int getNumResultsForRegex(const regex &expression, const string &str) {
        auto str_begin = sregex_iterator(str.begin(), str.end(), expression);
        auto str_end = sregex_iterator();
        return static_cast<int>(distance(str_begin, str_end));
    }

    void processRegularExpressions() {
        regex mailAdrRegex("[\\w.-]+@[\\w.-]+\\.\\w+");
        regex phoneNumRegex("\\+?[0-9]{1,4}[\\s-]?\\(?[0-9]{1,3}\\)?[\\s-]?[0-9]{3,4}[\\s-]?[0-9]{3,4}");
        regex dateRegex("\\d{4}-\\d{2}-\\d{2}");

        numMailAddresses = getNumResultsForRegex(mailAdrRegex, text);
        numPhoneNumbers = getNumResultsForRegex(phoneNumRegex, text);
        numDates = getNumResultsForRegex(dateRegex, text);

        cout << "email addresses: " << numMailAddresses << "\n";
        cout << "phone numbers: " << numPhoneNumbers << "\n";
        cout << "dates: " << numDates << "\n";
    }

    void lowerTextsCase() {
        cout << getLowerString(text) << "\n";
    }

    void process() {
        string tokenizingQuery = "-t -token";
        string regexQuery = "-t -reg";
        string loweringQuery = "-t -low";
        if (command == "-t") {
            string help_text = "Text Processing (-t): This option focuses on editing and formatting text.\n";
            help_text += "It includes functions:\n";
            help_text += "- Tokenization: -token\n- Pattern extraction: -reg\n";
            help_text += "- Convert to lower case: -low";
            cout << help_text << endl;
        } else if (command == tokenizingQuery) {
            cout << "Breaking text into separate elements, words.\n";
        } else if (command == regexQuery) {
            cout << "Searching for and extracting specific text patterns.\n";
        } else if (command == loweringQuery) {
            cout << "Convert all text to lower case.\n";
        } else if (startsWith(command, tokenizingQuery)) {
            extractTextFromCommand(tokenizingQuery);
            tokenizeText();
        } else if (startsWith(command, regexQuery)) {
            extractTextFromCommand(regexQuery);
            processRegularExpressions();
        } else if (startsWith(command, loweringQuery)) {
            extractTextFromCommand(loweringQuery);
            lowerTextsCase();
        }
    }
};

/*

Expected Sample Input / Output cases:


Sample Input 1:

-s

Sample Output 1:

Hello, the following top-level commands are available to you:
- Text analysis: -a
- String Processing: -s
- Password generator: -p
- Text processing: -t
Please enter your query

> -s
String Processing (-s): This feature is designed for manipulating and transforming strings.
It includes functions:
- Encrypt the string (Use Caesar's cipher): -e
- Flip the string: -f

Sample Input 2:

-s -e -en 3 This is a secret message

Sample Output 2:

Hello, the following top-level commands are available to you:
- Text analysis: -a
- String Processing: -s
- Password generator: -p
- Text processing: -t
Please enter your query

> -s -e -en 3 This is a secret message
Wklv lv d vhfuhw phvvdjh

Sample Input 3:

-s -f This is a secret message

Sample Output 3:

Hello, the following top-level commands are available to you:
- Text analysis: -a
- String Processing: -s
- Password generator: -p
- Text processing: -t
Please enter your query

> -s -f This is a secret message
egassem terces a si sihT


*/

int main() {

    printMenu();

    string command;
    std::getline(cin, command);
    std::istringstream iss(command);
    cout << "> " << command << endl;

    char optionChar = command[1];
    switch (optionChar) {
    case 'a':
        {
            TextAnalysis ta(command);
            ta.process();
        }
        break;
    case 's':
        {
            StringProcessing sp(command);
            sp.process();
        }
        break;
    case 'p':
        {
            PasswordGenerator pg(command);
            pg.process();
        }
        break;
    case 't':
        {
            TextProcessing tp(command);
            tp.process();
        }
        break;
    default:
        cout << "Invalid parameter" << endl;
        break;
    }

    return 0;
}
