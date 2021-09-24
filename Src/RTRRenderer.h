#pragma once
#include "RTRApp.h"
#include "RTRShader.h"
#include "RTRCamera.h"
#include "RTRLighting.h"
#include "RTRObject.h"
#include "Console.h"

class RTRRenderer {
public:
	RTRRenderer();
	virtual void SetUp();
	virtual void ObjectTransformation(RTRShader* shader, glm::mat4 modelMatrix, glm::vec3 translation,
		glm::vec3 scale, glm::vec3 rotation);
	virtual void RenderWithShaders(RTRShader* shader, glm::mat4 modelMatrix, glm::mat4 viewMatrix,
		glm::mat4 projectionMatrix, RTRObject* object, RTRCamera* camera, RTRLightingModel* lightingModel,
		int curTime, int timeDelta, glm::vec3 translation, glm::vec3 scale, glm::vec3 rotation);
	virtual void DebugInfo(Console* console, int FPS, RTRCamera* camera);

	float lastTime;
	float timer;

private:
};