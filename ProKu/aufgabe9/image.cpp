#include "image.hpp"

#include <cassert>

#include "jpeg_io.hpp"
typedef unsigned int uint;
Image::Image() {
    my_height = 0;
    my_width = 0;
    my_pixels = new float[0];
}
Image::Image(uint width, uint height) {
    my_height = height;
    my_width = width;
    my_pixels = new float[0];
}
Image::Image(uint width, uint height, const char* name) {
    my_height = height;
    my_width = width;
    my_pixels = read_jpeg(width, height, name);
}
Image::Image(const Image& oldImage) {
    my_height = oldImage.my_height;
    my_width = oldImage.my_width;
    my_pixels = new float[my_height * my_width];
    for (int i = 0; i < my_height * my_width; i++) {
        my_pixels[i] = oldImage.my_pixels[i];
    }
}

Image::~Image() { delete[] my_pixels; }

Image& Image::operator=(const Image& other) {
    if (this == &other) return *this;

    if (my_pixels != nullptr) delete[] my_pixels;
    int length = other.my_height * other.my_width;
    my_height = other.my_height;
    my_width = other.my_width;
    my_pixels = nullptr;
    if (length > 0) {
        assert(other.my_pixels != nullptr);
        my_pixels = new float[length];
        for (int i(0); i < length; ++i) {
            my_pixels[i] = other.my_pixels[i];
        }
    } else
        my_pixels = new float[0];
    return *this;
}
uint Image::height() const { return my_height; }
uint Image::width() const { return my_width; }

float& Image::at(int i, int j) { 
    assert(0 <= i && my_height >= i);
    assert(0 <= j && my_width >= j);
    return my_pixels[my_width * i + j];
}

bool Image::write(const char* name) const{
    return write_jpeg(my_width, my_height, my_pixels, name);
}
