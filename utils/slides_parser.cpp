#include "slides_parser.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "vector"
#include "map"

using namespace std;

inline bool exists (const std::string& name) {
    struct stat buffer{};
    return (stat (name.c_str(), &buffer) == 0);
}

std::vector<Slide> parse_slides() {
    map<string,string> values;
    string config = "slides_quantity=2\n"
                    "slide1_title=First Slide\n"
                    "slide1_content=Example slide\n"
                    "slide2_title=Second Slide\n"
                    "slide2_content=Example slide\n";
    if (exists("slides.cfg")) {
        fstream config_file;
        config_file.open("slides.cfg");
        stringstream ss;
        ss << config_file.rdbuf();
        config = ss.str();
        config_file.close();
    }
    else {
        ofstream config_file;
        config_file.open("slides.cfg");
        config_file << config << endl;
        config_file.close();
    }
    std::vector<Slide> slides;
    std::istringstream is_file(config);

    std::string line;
    while( std::getline(is_file, line) )
    {
        std::istringstream is_line(line);
        std::string key;
        if( std::getline(is_line, key, '=') )
        {
            std::string value;
            if( std::getline(is_line, value) )
                values.insert(pair<string ,string>(key,value));
        }
    }
    int sq = std::stoi(values.at("slides_quantity"));
    for (int i = 1; i <= sq; i++) {
        Slide _slide = Slide(values.at("slide" + std::to_string(i) + "_title"), values.at("slide" + std::to_string(i) + "_content"));
        slides.push_back(_slide);
    }
    return slides;
}