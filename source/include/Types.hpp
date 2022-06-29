#pragma once

#include <bitset>

struct Vector2 {

    double x;
    double y;

    Vector2(double _x, double _y){
        x = _x;
        y = _y;
    }

    Vector2(){
        x = 0;
        y = 0;
    }

    Vector2 operator+(const Vector2 &other){
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator-(const Vector2 &other){
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 operator*(const Vector2 &other){
        return Vector2(x * other.x, y * other.y);
    }
    Vector2& operator+=(const Vector2 &other){
      this->x += other.x;
      this->y += other.y;

      return *this;
    }
};

struct Transform {

    Transform(){
        position = Vector2();
        rotation = 0;
        scale = Vector2();
    };

    Vector2 position;
    double rotation;
    Vector2 scale;
};