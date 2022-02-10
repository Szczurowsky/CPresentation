#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "map"
#include "config_parser.h"
using namespace std;

bool config_exists (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}


std::map<string, string> parse() {
    map<string,string> values;
    string config = "line_length=72\n";
    if (config_exists("config.cfg")) {
        fstream config_file;
        config_file.open("config.cfg");
        stringstream ss;
        ss << config_file.rdbuf();
        config = ss.str();
        config_file.close();
    }
    else {
        ofstream config_file;
        config_file.open("config.cfg");
        config_file << config << endl;
        config_file.close();
    }

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
    return values;
}