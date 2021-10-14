#include "BuddahWorld.h"

void BuddhaWorld::onStart()
{
	//Camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

	//Light
	m_light = new Light(
		{ 1.0f, 1.0f, 1.0f },
		{ 0.5f, 0.5f, 0.5f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
		);
	m_light->setDirection({ -40.0f, -100.0f, 0.0f });
	add(m_light);

	m_buddha = new OBJMesh();
	m_buddha->load("Buddha.obj");
	m_buddha->getTransform()->setPosition({ 5.0f, 0.0f, 0.0f });
	m_buddha->getTransform()->setScale(glm::vec3(0.2f));
	add(m_buddha);

	m_cube = new Cube();
	m_cube->setColor(glm::vec4(0.6f, 0.2f, 0.4f, 1.0f));
	add(m_cube);
}


void BuddhaWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light);
	destroy(m_buddha);
	destroy(m_cube);
}
