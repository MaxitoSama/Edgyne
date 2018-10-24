#include "Application.h"
#include "ModuleLevel.h"
#include "GameObject.h"

#include "SDL\include\SDL_opengl.h"

#include "ModuleLoader.h"

#include "QuadTreeChechu.h"

ModuleLevel::ModuleLevel(Application* app, bool start_enabled) : Module(start_enabled)
{
	name = "Level";
}


ModuleLevel::~ModuleLevel()
{
}

bool ModuleLevel::Init(rapidjson::Value& node)
{
	root = NewGameObject();
	AABB test({ -1,-1,-1 }, { 10, 2, 10 });

	QuadTreeChechu quadTree(1);
	quadTree.Create(test);

	AABB* firstCube = new AABB({ 1,0,1 }, { 2,1,2 });
	AABB* secondCube = new AABB({7,0,7}, {8,1,8});

	quadTree.Insert(firstCube);
	quadTree.Insert(secondCube);
	return true;
}

bool ModuleLevel::Start()
{
	App->loader->ReceivedFile("Assets\\BakerHouse\\BakerHouse.FBX");
	return true;
}

GameObject * ModuleLevel::NewGameObject(bool with_transform)
{
	GameObject* ret = new GameObject();
	if (with_transform)
	{
		ret->AddComponent(TRANSFORM);
	}

	return ret;
}

void ModuleLevel::Draw()
{


}
