#ifndef CPLUSPOINT_SLIDE_H
#define CPLUSPOINT_SLIDE_H
#include <vector>
#include "string"

class Slide
{
public:
    Slide(std::string title, std::string content);

    std::string title;
    std::string content;
    void showSlide() const;
private:
    static void split_sentence(const std::string& str, std::vector<std::string>& cont);
    static int calculate_center(const std::string& text) ;
};

#endif //CPLUSPOINT_SLIDE_H
