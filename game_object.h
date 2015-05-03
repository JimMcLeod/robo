#ifndef _GAMEOBJECT_INCLUDED__
#define _GAMEOBJECT_INCLUDED__

struct GameObject
{
    bool active;
    int id;
    int type;

    float x;
    float y;
    int direction;
    float speed;
    float width;
    float height;
    int animFrame;

    void (* update)();
    void (* render)();
};
#endif

