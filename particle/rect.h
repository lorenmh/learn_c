#ifndef MV_RECT_H
#define MV_RECT_H

class MvRect {
  private:
    float[] velocity;
    unsigned char r;
    unsigned char g;
    unsigned char b;
  public:
    MvRect();
    MvRect( float[], char, char, char )
