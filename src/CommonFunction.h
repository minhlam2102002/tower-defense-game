#pragma once
#include "BaseObject.h"
#include "App.h"

void savePath(vector<Point> &path);
void readPath(vector<Point> &path, string file_path);
void getPath(vector<Point> &path, vector<Point> &pathBorder, vector<SDL_Rect> &pathRect);
void setPath(vector<Point> &path, App &MainScreen);