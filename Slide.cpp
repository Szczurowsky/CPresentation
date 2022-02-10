#include "Slide.h"

#include "iostream"
#include <utility>
#include "string"
#include <vector>
#include <sstream>
#include "utils/config_parser.h"

const int FULL_SIZE_LENGTH = std::stoi(parse().at("line_length"));

using namespace std;

Slide::Slide(string title, string content) {
    this->title = move(title);
    // If number is not even correct this to ensure it's centered correctly
    if (this->title.length()%2!=0)
        this->title += " ";
    this->content = move(content);
}

void Slide::showSlide() const {
    // Print header
    for (int i = 0; i < FULL_SIZE_LENGTH; i++)
        cout << "#";
    // Print spacer
    cout << endl << "#";
    for (int i = 0; i < FULL_SIZE_LENGTH - 2; i++)
        cout << " ";
    cout << "#" << endl;
    // Print beginning of line
    cout << "#";
    // Calculate center position
    int to_center = Slide::calculate_center(title);
    // Print first half
    for (int i = 0; i < to_center; i++)
        cout << " ";
    // Print text
    cout << title;
    // Print second half
    for (int i = 0; i < to_center; i++)
        cout << " ";
    cout << "#" << endl;
    // Print spacer
    cout << "#";
    for (int i = 0; i < FULL_SIZE_LENGTH - 2; i++)
        cout << " ";
    cout << "#" << endl;
    vector<string> words;
    Slide::split_sentence(content, words);
    string final_content = "# ";
    int line_size = 0;
    int l = 1;
    for (auto & word : words) {
        line_size += word.length() + 1;
        if (line_size > FULL_SIZE_LENGTH - 4) {
            for (int s = 0; s < (FULL_SIZE_LENGTH - (line_size - word.length()) - 2); s++)
                final_content += " ";
            final_content += "#\n# ";
            line_size = 1 + word.length();
        }
        if (l == words.size()) {
            final_content += word;
            int left = (FULL_SIZE_LENGTH - 2) - line_size;
            for (int s = 0; s < left; s++)
                final_content += " ";
            final_content += "#";
        }
        else {
            final_content += word + " ";
        }
        l++;
    }
    cout << final_content << endl;
    // Print spacer
    cout << "#";
    for (int i = 0; i < FULL_SIZE_LENGTH - 2; i++)
        cout << " ";
    cout << "#" << endl;
    // Print footer
    for (int i = 0; i < FULL_SIZE_LENGTH; i++)
        cout << "#";
}

int Slide::calculate_center(const string& text) {
    int len = text.length();
    return (FULL_SIZE_LENGTH - len - 2) / 2;
}

void Slide::split_sentence(const string& str, vector<string>& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));

    for(auto & i : cont){
        string word = i;
        for(int j = 0, len = word.length(); j < len; j++){
            if(ispunct(word[j])){
                i = word.substr(0, word.length() - 1);
            }
        }
    }
}
