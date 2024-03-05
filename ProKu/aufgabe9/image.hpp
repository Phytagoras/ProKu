#ifndef PROKU_IMAGE_HPP
#define PROKU_IMAGE_HPP

// Ein typedef fuer 'unsigned int'
typedef unsigned int uint;

// Die 'Image' Klasse
class Image {
    // TODO
   private:
    uint my_width, my_height;
    float* my_pixels;

   public:
    Image();
    Image(uint width, uint height);
    Image(uint width, uint height, const char* name);
    Image(const Image& oldImage);
    Image& operator=(const Image& other);
    ~Image();
    uint height() const;
    uint width() const;

    float& Image::at(int i, int j);
    bool write(const char* name) const;
};  // class Image

#endif  // PROKU_IMAGE_HPP
