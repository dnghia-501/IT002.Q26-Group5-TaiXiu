#include "../include/Dice.h"
#include <cstdlib>


/* Dùng rand() thay vì mt19937 để đảm bảo cùng seed → cùng chuỗi xúc xắc cho mọi
 * strategy */
int Dice::roll() { return (rand() % 6) + 1; }
