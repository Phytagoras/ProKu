#include "image.hpp"

#include <cassert>

#include "jpeg_io.hpp"

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

Image::~Image() { delete[] my_pixels; }