#include "Point.h"

bool Point::operator==(const Point& rhs) const {
    return x == rhs.x && y == rhs.y;
}

bool Point::operator!=(const Point& rhs) const {
    return !(*this == rhs);
}
