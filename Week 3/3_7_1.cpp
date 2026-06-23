#include <iostream>

int main () 
{
    unsigned hour, minutes;
    std::cout << "Please enter what the time currently is: " << std::endl;
    std::cin >> hour >> minutes;

    if (minutes < 45) minutes +=15;
    else if (minutes >= 45) {
        hour ++;
        minutes = minutes - 45;
    }
    std::cout << "The new time is: " << hour << ":" << minutes << std::endl;
    return 0;
}