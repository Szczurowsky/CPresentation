#ifdef _WIN32
#include <conio.h>
#endif
#ifdef linux
#include <curses.h>
#endif
#include "Slide.h"
#include <vector>
#include "utils/console.h"
#include "utils/slides_parser.h"

using namespace std;


void run(std::vector<Slide> slides)
{
    int c = 0;
    int i = 0;
    slides.at(i).showSlide();
    while(c != 3)
    {
        #ifdef linux
        initscr();
        #endif
        switch((c=getch())) {
            case 75:
                if (i == 0)
                    break;
                else
                    i--;
                clear_console();
                slides.at(i).showSlide();
                break;
            case 77:
                if (i == slides.size() - 1)
                    break;
                i++;
                clear_console();
                slides.at(i).showSlide();
                break;
            default:
                break;
        }

    }
}

int main()
{
    run(parse_slides());
    return 0;
}