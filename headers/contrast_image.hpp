#include <vector>

using namespace std;

void contrast_image(vector<vector<double>> &image)
{
    double smallest = image[0][0];

    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[0].size(); j++)
        {
            if (image[i][j] < smallest)
            {
                smallest = image[i][j];
            }
        }
    }

    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[0].size(); j++)
        {
            image[i][j] = image[i][j] - smallest;
        }
    }
}