#include "Utils.h"

const Color Color::COLOR_BLACK = { 0,0,0,255 };
const Color Color::COLOR_WHITE = { 255,255,255,255 };

Color::Color(Uint8 ra, Uint8 ga, Uint8 ba, Uint8 aa)
	:r(ra),g(ga),b(ba),a(aa)
{
}
