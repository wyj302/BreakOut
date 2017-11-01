#ifndef _TEXTURE2D_H_
#define _TEXTURE2D_H_
#include <GL/glew.h>
#include <memory>
class Texture2D
{
public:
	GLuint ID;
	GLuint Width, Height;
	GLuint Internal_Format;
	GLuint Image_Format;

	GLuint Wrap_S;
	GLuint Wrap_T;
	GLuint Filter_Min;
	GLuint Filter_Max;

	Texture2D();
	void Generate(GLuint width, GLuint height, unsigned char* data);

	void Bind() const;
};

typedef std::shared_ptr<Texture2D>  TexturePtr;

#endif