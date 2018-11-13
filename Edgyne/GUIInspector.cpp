#include "GUIInspector.h"
#include "Application.h"
#include "ModuleRenderer3D.h"
#include "ModuleLevel.h"
#include "GameObject.h"
#include "Component.h"
#include "QuadTree.h"


#include <list>

GUIInspector::GUIInspector(bool active = false) : GUIElements("inspector",active)
{
	position = { 420, 200 };
	size = { 600, 300 };
}


GUIInspector::~GUIInspector()
{
	
}

void GUIInspector::Draw()
{
	ImGui::Begin("Inspector", &active);
		Move();
	
		if (App->level->selected_game_object)
		{
			static char name[25];
			strcpy_s(name, 25, App->level->selected_game_object->name.c_str());
			if (ImGui::InputText("Name", name, 25, ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_AutoSelectAll))
			{
				App->level->selected_game_object->name = name;
			}
			if (ImGui::Checkbox("Active", &App->level->selected_game_object->active))
			{
				App->level->selected_game_object->RecursiveSetChildsActive(App->level->selected_game_object->active);
			}
			ImGui::SameLine();
			if (ImGui::Checkbox("Static", &App->level->selected_game_object->Static))
			{
				App->level->selected_game_object->RecursiveSetChildsStatic(App->level->selected_game_object->Static);
				//App->level->quad_tree->Clear
			}
			ImGui::Checkbox("Delete", &App->level->selected_game_object->to_remove);

			std::vector<Component*>::iterator item = App->level->selected_game_object->components.begin();

			while (item != App->level->selected_game_object->components.end())
			{
				(*item)->OnEditor();
				item++;
			}
		}
		
		ImGui::End();
}

bool GUIInspector::Save(rapidjson::Value & Node, rapidjson::Document::AllocatorType& allocator)
{
	Node.AddMember("active", active, allocator);

	return true;
}
bool GUIInspector::Load(rapidjson::Value& Node)
{
	active = Node["active"].GetBool();
	return true;
}