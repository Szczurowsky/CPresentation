#ifndef CPLUSPOINT_CONFIG_PARSER_H
#define CPLUSPOINT_CONFIG_PARSER_H
#include "map"
bool config_exists (const std::string& name);
std::map<std::string, std::string> parse();
#endif //CPLUSPOINT_CONFIG_PARSER_H
