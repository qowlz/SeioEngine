#pragma once

#include "glad/glad.h"

#include <string>

class Texture2D
{
public:
    // 기본 생성자 삭제
    Texture2D() = delete;

    Texture2D(const std::string& fileName);

    ~Texture2D();

    // 복사 생성자 및 복사 대입 연산자 삭제
    Texture2D(const Texture2D& other) = delete;
    Texture2D& operator=(const Texture2D& other) = delete;

    // 이동 생성자 및 이동 대입 연산자 정의
    Texture2D(Texture2D&& other) noexcept;
    Texture2D& operator=(Texture2D&& other) noexcept;

    void Bind(GLenum unit);

    int GetWidth() const { return width; }
    int GetHeight() const { return height; }
    GLuint GetID() const { return id; }

private:

    GLuint id;
    int width = 0, height = 0;
};