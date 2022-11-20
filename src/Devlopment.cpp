#include "Devlopment.h"
void savePath(vector<Point> &path) {
    ofstream fo;
    if (DEBUG_TOWER)
        fo.open("GamePathBorder.txt");
    else
        fo.open("GamePath.txt");
    fo << path.size() << endl;
    for (Point &p : path) {
        fo << p.x << ' ' << p.y << endl;
    }
    fo.close();
}
void readPath(vector<Point> &path, string file_path) {
    ifstream fi(file_path);
    int _size;
    fi >> _size;
    path.resize(_size);
    for (Point &p : path) {
        fi >> p.x >> p.y;
    }
    fi.close();
}
void Devlopment(bool DEBUG_PATH, bool DEBUG_TOWER) {
    if (DEBUG_PATH) {
        if (DEBUG_TOWER) {
            if (MainScreen.g_event.type == SDL_MOUSEBUTTONDOWN) {
                int xMouse, yMouse;
                SDL_GetMouseState(&xMouse, &yMouse);
                cout << xMouse << " " << yMouse << endl;
                path.push_back(Point(xMouse, yMouse));
            }
        } else {
            if (MainScreen.g_event.type == SDL_MOUSEMOTION) {
                int xMouse, yMouse;
                SDL_GetMouseState(&xMouse, &yMouse);
                cout << xMouse << " " << yMouse << endl;
                path.push_back(Point(xMouse, yMouse));
            }
        }
    }
}