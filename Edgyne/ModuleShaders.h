#pragma once

#include "Module.h"
#include "Globals.h"
#include <vector>
class ModuleShaders :
	public Module
{
public:
	ModuleShaders(Application* app, bool start_enabled = true);
	~ModuleShaders();

	bool Init(rapidjson::Value& node);

	uint CompileShader(char* shader, bool is_vertex_shader);
	uint CreateShaderProgram(std::vector<uint> shaders);

public:
	char* vertex_shader;
	char*pixel_shader;
	uint default_vertex_shader = 0;
	uint default_pixel_shader = 0;
	uint default_shader_program = 0;

};
