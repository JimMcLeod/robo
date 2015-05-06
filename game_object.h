#ifndef _GAMEOBJECT_INCLUDED__
#define _GAMEOBJECT_INCLUDED__

struct GameObject
{
    bool active;
    int id;
    int type;

    float x;
    float y;
    float direction;
    float turnRate;
    float noOfDirections;
    float speed;
    float width;
    float height;
    float animFrame;
    float animUpdate;
    float animNoOfFrames;
};
#endif

