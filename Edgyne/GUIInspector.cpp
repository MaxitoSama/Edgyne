#include "GUIInspector.h"
#include "Application.h"
#include "ModuleRenderer3D.h"


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
		std::list<mesh*>::iterator item = App->renderer3D->mesh_list.begin();

		while (item != App->renderer3D->mesh_list.end())
		{
			if (ImGui::TreeNode((*item)->name))
			{
				if (ImGui::TreeNode("Transform"))
				{
					ImGui::Text("Position X: %f", (*item)->position.x);
					ImGui::Text("Position Y: %f", (*item)->position.y);
					ImGui::Text("Position Z: %f", (*item)->position.z);
					ImGui::Dummy({ 10,10 });
					ImGui::Text("Rotation X: %f", (*item)->rotation.x);
					ImGui::Text("Rotation Y: %f", (*item)->rotation.y);
					ImGui::Text("Rotation Z: %f", (*item)->rotation.z);
					ImGui::Dummy({ 10,10 });
					ImGui::Text("Scale X: %f", (*item)->scale.x);
					ImGui::Text("Scale Y: %f", (*item)->scale.y);
					ImGui::Text("Scale Z: %f", (*item)->scale.z);

					ImGui::TreePop();
				}
				if (ImGui::TreeNode("Mesh"))
				{
					ImGui::Text("Num Faces: %i", (*item)->num_faces);
					ImGui::Text("Num Vertices: %i", (*item)->num_vertex);
					ImGui::Text("Num Indexes: %i", (*item)->num_index);
					ImGui::TreePop();
				}
				if (ImGui::TreeNode("Texture"))
				{
					if ((*item)->id_texture > 0)
					{
						ImGui::Text("Image size %ix%i", (int)(*item)->image_size.x, (int)(*item)->image_size.y);
						ImGui::Image((void *)(intptr_t)(*item)->id_texture, ImVec2(256, 256));
					}
					else
						ImGui::Text("The model does not have a texture");
					ImGui::TreePop();
				}
				ImGui::TreePop();
			}


			item++;
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