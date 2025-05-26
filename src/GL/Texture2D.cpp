#include "stb_image.h"

#include "GL/Texture2D.h"

#include <iostream>
#include <filesystem>
#include <utility>

Texture2D::Texture2D(const std::string& fileName)
{
    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_2D, this->id);

    // FIXME: 나중에 한번만 호출되도록 옮기면 좋을듯?
    stbi_set_flip_vertically_on_load(true);

    auto texturePath = std::filesystem::path(__FILE__).parent_path() / ".." / ".." / "resources" / "textures"; // TODO: 글로벌 변수로 빼도 좋을지도?
    const std::string path = (texturePath / fileName).string();

    int width, height, nChannels;
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &nChannels, 0);

    GLint format; GLenum fileFormat;
    if (nChannels == 4) format = fileFormat = GL_RGBA;
    else if (nChannels == 3) format = fileFormat = GL_RGB;
    
    if (data)
    {
        this->width = width;
        this->height = height;
        glTexImage2D(GL_TEXTURE_2D, 0, format, this->width, this->height, 0, fileFormat, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        std::cout << "Successfully loaded texture from: " << path << std::endl;
        std::cout << "Texture created at address: " << this << " with ID: " << this->id << std::endl;
    }
    else
    {
        std::cerr << "Failed to load texture: " << path << std::endl;
        std::cerr << "STB Error: " << stbi_failure_reason() << std::endl;
    }

    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture2D::~Texture2D()
{
    if (this->id != 0)
    {
        glDeleteTextures(1, &this->id);
        std::cout << "Texture destroyed at address: " << this << " with ID: " << this->id << std::endl;
    }
}

void Texture2D::Bind(GLenum unit)
{
    glActiveTexture(unit);
    glBindTexture(GL_TEXTURE_2D, this->id);
}

Texture2D::Texture2D(Texture2D&& other) noexcept {
    std::cout << "Texture moved from: " << &other << " to: " << this << std::endl;

    id = std::exchange(other.id, 0);
    width = std::exchange(other.width, 0);
    height = std::exchange(other.height, 0);
}

Texture2D& Texture2D::operator=(Texture2D&& other) noexcept {
    if (this != &other) {
        id = std::exchange(other.id, 0);
        width = std::exchange(other.width, 0);
        height = std::exchange(other.height, 0);
    }

    return *this;
}
