#include "Core/Init/InitGLUT.h"
#include "Managers/SceneManager.h"
#include "Managers/ShaderManager.h"
#include "Rendering/Models/Cube.h"

using namespace Core;
using namespace Init;
int main(int argc, char **argv){
	WindowInfo window(std::string("my window"), 400, 200, 800, 600, true);
	ContextInfo context(4, 5, true);
	FramebufferInfo frameBufferInfo(true, true, true, true);

	Init_GLUT::init(window, context, frameBufferInfo);

	Managers::SceneManager* scene = new Managers::SceneManager();
    Models::LineRenderer* line1 = new Models::LineRenderer(glm::vec3(-5.0, 0.0, 0.0), glm::vec3(5.0, 0.0, 0.0), 1.0);
    Models::LineRenderer* line2 = new Models::LineRenderer(glm::vec3(0.0, 0.0, -5.0), glm::vec3(0.0, 0.0, 5.0), 1.0);
    Models::Cube* car = new Models::Cube(glm::vec3(0.0,0.5,1.0), glm::vec3(0.5));
    car->SetProgram(Managers::ShaderManager::GetShader("colorShader"));
    car->Create();
	line1->SetProgram(Managers::ShaderManager::GetShader("colorShader"));
	line1->Create();
    line2->SetProgram(Managers::ShaderManager::GetShader("colorShader"));
	line2->Create();
	scene->GetModelsManager()->SetModel("line1", line1);
    scene->GetModelsManager()->SetModel("line2", line2);
    scene->GetModelsManager()->SetModel("car", car);
	Init_GLUT::setListener(scene);

	Init_GLUT::run();

	delete scene;
	return 0;
}
