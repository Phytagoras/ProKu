#ifndef PROKU_IMAGE_HPP
#define PROKU_IMAGE_HPP

// Ein typedef fuer 'unsigned int'
typedef unsigned int uint;

// Die 'Image' Klasse
class Image {
    // TODO
   private:
    uint my_width, my_height;
    float *my_pixels;

   public:
    Image();
    Image(uint width, uint height);
    Image(uint width, uint height, const char* name);
    ~Image();

};  // class Image

#endif  // PROKU_IMAGE_HPP
