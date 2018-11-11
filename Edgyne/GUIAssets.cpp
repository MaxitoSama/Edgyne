#include "GUIAssets.h"
#include <experimental/filesystem>


GUIAssets::GUIAssets(bool active = false) : GUIElements("assets", active)
{
}


GUIAssets::~GUIAssets()
{
}

void GUIAssets::Draw()
{
	ImGui::Begin("Assets", &active);

	if (currentPath.c_str() != "Assets\\")
	{
		if (ImGui::Button("Root"))
		{
			currentPath = "Assets\\";
		}
	}
	const std::experimental::filesystem::directory_iterator end{};

	for (std::experimental::filesystem::directory_iterator iter{ currentPath.c_str() }; iter != end; ++iter)
	{
		if (std::experimental::filesystem::is_directory(*iter))
		{
			if (ImGui::Button(iter->path().string().c_str()))
			{
				currentPath = iter->path().string();
			}
		}
		else if (std::experimental::filesystem::is_regular_file(*iter))
		{
			ImGui::Button(iter->path().string().c_str());
		}
	}

	ImGui::End();

}

bool GUIAssets::Load(rapidjson::Value & Node)
{
	return false;
}

bool GUIAssets::Save(rapidjson::Value & Node, rapidjson::Document::AllocatorType & allocator)
{
	return false;
}