class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x_nearest=max(x1,min(x2,xCenter));
        int y_nearest=max(y1,min(y2,yCenter));

        int dist_x=x_nearest - xCenter;
        int dist_y=y_nearest - yCenter;

        return radius*radius >= (dist_x*dist_x) + (dist_y*dist_y);
    }
};
