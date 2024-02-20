#pragma once

class View
{
public:
    int Scale;
    int Width;
    int Height;
    struct Center
    {
        int X;
        int Y;
    };
    Center Center;
    View();
};