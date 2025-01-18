#pragma once

class Rectangle
{
public:
    // static inline float _default_size;
    Rectangle();
    Rectangle(float length, float width);
    /*
    Rectangle(float length, float width)
        : _length { length }
        , _width { width }
    {}
    */
    Rectangle(float size);

    float get_length() const { return _length; }
    float get_width() const { return _width; }

    void scale(float ratio);
    /*
    void scale(float ratio)
    {
        _length *= ratio;
        _width *= ratio;
    }
    */
    static void set_default_size(float size);

private:
    static inline float _default_size;
    float               _length;
    float               _width;
};
