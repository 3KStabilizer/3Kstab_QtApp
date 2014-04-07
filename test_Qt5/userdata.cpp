#include "userdata.h"

UserData::UserData()
{
    x = 0;
    y = 0;
    z = 0;
}

int UserData::getX()
{
    return x;
}

int UserData::getY()
{
    return y;
}

int UserData::getZ()
{
    return z;
}

void UserData::setX(int val)
{
    if(val>=-90 && val<=90)
        x = val;
    else
        return;
}

void UserData::setY(int val)
{
    if(val>=-90 && val<=90)
        y = val;
    else
        return;
}

void UserData::setZ(int val)
{
    if(val>=-90 && val<=90)
        z = val;
    else
        return;
}
