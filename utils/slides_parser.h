#ifndef CPLUSPOINT_CONFIG_PARSER_H
#define CPLUSPOINT_CONFIG_PARSER_H
#include "vector"
#include "../Slide.h"
bool exists (const std::string& name);
std::vector<Slide> parse_slides();
#endif //CPLUSPOINT_CONFIG_PARSER_H
