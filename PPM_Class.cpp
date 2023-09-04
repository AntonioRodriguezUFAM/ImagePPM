#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Pixel {
    int r, g, b;
};

class Image {
public:
    int width, height, max_color;
    vector<Pixel> pixels;

    Image() {}

    Image(int w, int h, int m) {
        width = w;
        height = h;
        max_color = m;
        pixels.resize(width * height);
    }

    void loadPPM(string filename) {
        ifstream infile(filename, ios::binary);
        string magic_number;
        infile >> magic_number >> width >> height >> max_color;
        pixels.resize(width * height);

        for (int i = 0; i < width * height; i++) {
            Pixel pixel;
            infile >> pixel.r >> pixel.g >> pixel.b;
            pixels[i] = pixel;
        }

        infile.close();
    }

    void savePPM(string filename) {
        ofstream outfile(filename, ios::binary);
        outfile << "P6" << endl << width << " " << height << endl << max_color << endl;

        for (int i = 0; i < width * height; i++) {
            Pixel pixel = pixels[i];
            outfile << (unsigned char)pixel.r << (unsigned char)pixel.g << (unsigned char)pixel.b;
        }

        outfile.close();
    }

    void invertColors() {
        for (int i = 0; i < width * height; i++) {
            Pixel pixel = pixels[i];
            pixel.r = max_color - pixel.r;
            pixel.g = max_color - pixel.g;
            pixel.b = max_color - pixel.b;
            pixels[i] = pixel;
        }
    }
};

int main() {
    Image image;
    image.loadPPM("input.ppm");

    image.invertColors();

    image.savePPM("output.ppm");

    return 0;
}
