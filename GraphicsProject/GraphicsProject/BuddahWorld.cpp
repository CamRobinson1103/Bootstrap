#include "BuddhaWorld.h"

void BuddhaWorld::onStart()
{
	//Camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

	
	Light* light = new Light(
		{ -1.0f, 0.0f, -1.0f },
		{ 0.5f, 0.0f, 0.0f, 1.0f },
		{ 1.0f, 0.0f, 0.0f, 1.0f },
		{ 1.0f, 0.0f, 0.0f, 1.0f }
	);
	light->setIndex(1);
	add(light);

	Light* light1 = new Light
	(
		{ 0.0f, 0.5f, 0.0f },
		{ 0.0f, 0.0f, 0.5f, 1.0f },
		{ 0.0f, 0.0f, 1.0f, 1.0f },
		{ 0.0f, 0.0f, 1.0f, 1.0f }
	);
	light1->setIndex(2);
	add(light1);
	


	m_buddha = new OBJMesh();
	m_buddha->load("Buddha.obj");
	m_buddha->getTransform()->setPosition({ 5.0f, 0.0f, 0.0f });
	m_buddha->getTransform()->setScale(glm::vec3(0.2f));
	add(m_buddha);

	/*m_cube = new Cube();
	m_cube->setColor(glm::vec4(0.6f, 0.2f, 0.4f, 1.0f));
	add(m_cube);*/

	m_texture = new Texture("earth_diffuse.jpg");
	add(m_texture);
}


void BuddhaWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light);
	destroy(m_buddha);
	destroy(m_cube);
	destroy(m_texture);
}
