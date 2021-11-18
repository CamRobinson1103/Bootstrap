#include "Texture.h"
#include "gl_core_4_4.h"

Texture::Texture(const char* fileName)
{
	if (!m_texture.load(fileName))
		printf("No Texture");
}

void Texture::onDraw()
{
	// Get current shader
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);
	if (program == -1)
		printf("no shader bound.\n");

	// Get texture uniform
	int diffuseTextureUniform = glGetUniformLocation(program, "diffuseTexture");

	// Bind texture
	if (diffuseTextureUniform >= 0)
		glUniform1i(diffuseTextureUniform, 0);

	// Set active texture
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_texture.getHandle());

	// Call super
	Quad::onDraw();
}
