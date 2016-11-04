#pragma once

#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <Texture.h>
#include <GL/glew.h>

template<typename T, int TextureIndex = 0>
class ProgramVariable
{
public:
    ProgramVariable(const class ShaderProgram *program, const char *name) : ProgramVariable(glGetUniformLocation(program->getId(), name)) {

    }

    ProgramVariable(const int id) : id(id) {
        if (isOk()) {
            glUniform1i(this->id, TextureIndex);
        }
    }
    void setValue(const T *value) {
        this->setValueInternal(value);
    }
    void setValue(const T &value) {
        this->setValueInternal(value);
    }
    bool isOk() const {
        return this->id >= 0;
    }
private:
    inline void setValueInternal(const Texture *value)
    {
        glActiveTexture(GL_TEXTURE0 + TextureIndex);
        if (value == nullptr) {
            glBindTexture(GL_TEXTURE_2D, 0);
        } else {
            value->use();
        }
    }
    inline void setValueInternal(const glm::mat4 *mat)
    {
        glUniformMatrix4fv(this->id, 1, GL_FALSE, mat);
    }
    inline void setValueInternal(const glm::mat3 *mat)
    {
        glUniformMatrix3fv(this->id, 1, GL_FALSE, mat);
    }
    inline void setValueInternal(const glm::vec2 *vec)
    {
        glUniform2fv(this->id, 1, vec);
    }

    inline void setValueInternal(const glm::vec3 *vec)
    {
        glUniform3fv(this->id, 1, vec);
    }
    inline void setValueInternal(const glm::vec4 *vec)
    {
        glUniform4fv(this->id, 1, vec);
    }

    inline void setValueInternal(const int *value)
    {
        glUniform1i(this->id, *value);
    }
    inline void setValueInternal(const float *value)
    {
        glUniform1f(this->id, *value);
    }

    inline void setValueInternal(const Texture &value)
    {
        glActiveTexture(GL_TEXTURE0 + TextureIndex);
        value.use();
    }
    inline void setValueInternal(const glm::mat4 &mat)
    {
        glUniformMatrix4fv(this->id, 1, GL_FALSE, glm::value_ptr(mat));
    }
    inline void setValueInternal(const glm::mat3 &mat)
    {
        glUniformMatrix3fv(this->id, 1, GL_FALSE, glm::value_ptr(mat));
    }
    inline void setValueInternal(const glm::vec2 &vec)
    {
        glUniform2fv(this->id, 1, glm::value_ptr(vec));
    }
    inline void setValueInternal(const glm::vec3 &vec)
    {
        glUniform3fv(this->id, 1, glm::value_ptr(vec));
    }
    inline void setValueInternal(const glm::vec4 &vec)
    {
        glUniform4fv(this->id, 1, glm::value_ptr(vec));
    }
    inline void setValueInternal(const int &value)
    {
        glUniform1i(this->id, value);
    }
    inline void setValueInternal(const float &value)
    {
        glUniform1f(this->id, value);
    }

    int id;
};
