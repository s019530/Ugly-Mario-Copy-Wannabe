#include "util.hpp"
#include "LevelLoader.hpp"

HBRUSH skyBlue = CreateSolidBrush(RGB(68,243, 255));
HBRUSH white = CreateSolidBrush(RGB(250,250,250));
HBRUSH black = CreateSolidBrush(RGB(0,0,0));
HBRUSH green = CreateSolidBrush(RGB(0, 250, 0));
HBRUSH brown = CreateSolidBrush(RGB(150,75,0));
HBRUSH gray = CreateSolidBrush(RGB(128,128,128));
HBRUSH yellow = CreateSolidBrush(RGB(255,255,0));
std::vector<HBRUSH> all_colors = {skyBlue, white, green, brown, gray, yellow, black};

HFONT menuFontNormal = CreateFont(50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Times New Roman");
HFONT menuFontBig = CreateFont(60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Times New Roman");

HFONT escmenuFontBig = CreateFont(35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Times New Roman");
HFONT escmenuFontNormal = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Times New Roman");

int state_of_game = MAINMENU;
int previous_state_of_game = MAINMENU;

bool escMenu = false;


bool isKeyDown(CUSTOM_KEY key){
    if(GetKeyState(key) & 0x8000)
    {
        return true;
    }
    return false;
}


int generateNumber(int offset, int max){
    return offset + (rand() % max);
}

std::vector<std::string> split(std::string input, char delim)
{
    std::vector<std::string> output;
    std::string temp;
    for(char c : input)
    {
        if(c == delim)
        {
            output.push_back(temp);
            temp.clear();
        }
        else{
            temp.push_back(c);
        }
    }

    output.push_back(temp);
    
    return output;
}



RECT createRectUsingCords(RECT rect, int size_width, int size_height){
    int width = rect.right - rect.left;
    int height = rect.bottom - rect.top;

    rect.left = rect.left + (width/2) - (size_width/2);
    rect.right = rect.right - (width/2) + (size_width/2);
    rect.top = rect.top + (height/2) - (size_height/2);
    rect.bottom = rect.bottom - (height/2) + (size_height/2);

    return rect;
}

bool mouseInBox(RECT rect, POINT pt){
    if((pt.x <= rect.right) && (pt.x >= rect.left) && (pt.y >= rect.top) && (pt.y <= rect.bottom)){
        return true;
    }
    return false;
}

RECT pointsToRect(POINT one, POINT two){
    RECT rect;

    rect.left = (one.x < two.x) ? one.x : two.x;
    rect.right = (one.x > two.x) ? one.x : two.x;
    rect.top = (one.y < two.y) ? one.y : two.y;
    rect.bottom = (one.y > two.y) ? one.y : two.y;

    return rect;
}

void printRectCords(RECT rect){
    std::cout << "top: " + std::to_string(rect.top) + " bottom: " + std::to_string(rect.bottom)  + " left: " + std::to_string(rect.left) + " right: " + std::to_string(rect.right) << std::endl;
}