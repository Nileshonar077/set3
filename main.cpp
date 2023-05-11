#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> getBestCoordinate(vector<vector<int>>& towers, int radius) {
    int maxQuality = 0;
    vector<int> bestCoord(2, 0);

    for (int x = 0; x <= 50; x++) {  // coordinates range from 0 to 50
        for (int y = 0; y <= 50; y++) {
            int quality = 0;

            for (auto& tower : towers) {
                int dx = tower[0] - x;
                int dy = tower[1] - y;
                double dist = sqrt(dx*dx + dy*dy);

                if (dist <= radius) {
                    quality += tower[2] / (1 + dist);
                }
            }

            if (quality > maxQuality) {
                maxQuality = quality;
                bestCoord[0] = x;
                bestCoord[1] = y;
            }
        }
    }

    return bestCoord;
}

int main() {
    vector<vector<int>> towers = {{1, 2, 5}, {2, 1, 7}, {3, 1, 9}};
    int radius = 2;

    vector<int> bestCoord = getBestCoordinate(towers, radius);
    cout << "[" << bestCoord[0] << ", " << bestCoord[1] << "]" << endl;

    return 0;
}
