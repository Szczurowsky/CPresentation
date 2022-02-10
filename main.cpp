#include <conio.h>
#include "Slide.h"
#include <vector>
#include "utils/console.h"

using namespace std;

void run(std::vector<Slide> slides)
{
    int c = 0;
    int i = 0;
    slides.at(i).showSlide();
    while(c != 80)
    {
        switch((c=getch())) {
            case 75:
                if (i == 0)
                    break;
                else
                    i--;
                clear();
                slides.at(i).showSlide();
                break;
            case 77:
                if (i == slides.size() - 1)
                    break;
                i++;
                clear();
                slides.at(i).showSlide();
                break;
            default:
                break;
        }

    }
}

int main()
{
    std::vector<Slide> slides;
    Slide slide = Slide("Test Test test", "loirem ipsum dolore mepisum asdafasdfs");
    Slide slide1 = Slide("Test2 Test test", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum finibus nisi eu risuss fermentum dignissim. Praesent a auctor mauris. Duis eleifend libero ac lacus accumsan pulvinar. Suspendisse sapien metus, aliquet sed felis sed, luctus commodo erat. Pellentesque eget blandit risus.");
    slides.push_back(slide);
    slides.push_back(slide1);
    run(slides);
    return 0;
}