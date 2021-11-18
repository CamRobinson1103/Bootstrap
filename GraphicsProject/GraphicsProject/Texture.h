#pragma once
#include "Quad.h"
class Texture : public Quad
{
public:
	Texture(const char* fileName);

	void onDraw() override;

private:
	aie::Texture m_texture;
};

