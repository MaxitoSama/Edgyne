#include "Application.h"
#include "ModuleImGui.h"
#include "ModuleRenderer3D.h"
#include "ModuleWindow.h"
#include "ModuleTest.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_sdl.h"
#include "ImGui/imgui_impl_opengl2.h"
#include <stdio.h>





ModuleImGui::ModuleImGui(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}



bool ModuleImGui::Init()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls

	ImGui_ImplSDL2_InitForOpenGL(App->window->window, App->renderer3D->context);
	ImGui_ImplOpenGL2_Init();

	// Setup style
	ImGui::StyleColorsDark();




	return true;
}

update_status ModuleImGui::PreUpdate(float dt)
{
	update_status status = UPDATE_CONTINUE;

		ImGui_ImplOpenGL2_NewFrame();
		ImGui_ImplSDL2_NewFrame(App->window->window);
		ImGui::NewFrame();

	
	return status;
}

update_status ModuleImGui::Update(float dt)
{
	update_status status = UPDATE_CONTINUE;

	

	ImGui::Begin("Shapes", &perma_true);
		if(ImGui::TreeNode("Sphere"))
		{
			static float fx = 1.0f;
			static float fy = 1.0f;
			static float fz = 1.0f;
			static float fr = 1.0f;
			ImGui::InputFloat("X", &fx, 0.1f, 1.0f);
			ImGui::InputFloat("Y", &fy, 0.1f, 1.0f);
			ImGui::InputFloat("Z", &fz, 0.1f, 1.0f);
			ImGui::InputFloat("Radius", &fr, 0.1f, 1.0f);
			
			if (ImGui::Button("Spawn/Respawn Sphere"))
			{
				App->test->CreateSphere(fx, fy, fz, fr);
			}
			ImGui::TreePop();
		}

		if (ImGui::TreeNode("Capsule"))
		{
			static float fxt = 1.0f;
			static float fyt = 1.0f;
			static float fzt = 1.0f;
			static float fr = 1.0f;
			ImGui::InputFloat("top X", &fxt, 0.1f, 1.0f);
			ImGui::InputFloat("top Y", &fyt, 0.1f, 1.0f);
			ImGui::InputFloat("top Z", &fzt, 0.1f, 1.0f);
			

			static float fxb = 1.0f;
			static float fyb = 1.0f;
			static float fzb = 1.0f;
			ImGui::InputFloat("bottom X", &fxb, 0.1f, 1.0f);
			ImGui::InputFloat("bottom Y", &fyb, 0.1f, 1.0f);
			ImGui::InputFloat("bottom Z", &fzb, 0.1f, 1.0f);
			
			ImGui::InputFloat("Radius", &fr, 0.1f, 1.0f);

			if (ImGui::Button("Spawn/Respawn Capsule"))
			{
				App->test->CreateCapsule(fxt,fyt,fzt,fxb,fyb,fzb,fr);
			}
			ImGui::TreePop();
		}

		if (ImGui::TreeNode("AABB"))
		{
			static float fxmax = 1.0f;
			static float fymax= 1.0f;
			static float fzmax = 1.0f;
			
			ImGui::InputFloat("maxX", &fxmax, 0.1f, 1.0f);
			ImGui::InputFloat("maxY", &fymax, 0.1f, 1.0f);
			ImGui::InputFloat("maxZ", &fzmax, 0.1f, 1.0f);

			static float fxmin = 1.0f;
			static float fymin = 1.0f;
			static float fzmin = 1.0f;

			ImGui::InputFloat("maxX", &fxmin, 0.1f, 1.0f);
			ImGui::InputFloat("maxY", &fymin, 0.1f, 1.0f);
			ImGui::InputFloat("maxZ", &fzmin, 0.1f, 1.0f);
			

			if (ImGui::Button("Spawn/Respawn AABB"))
			{
				App->test->CreateAABB(fxmax,fymax,fzmax,fxmin,fymin,fzmin);
			}
			ImGui::TreePop();
			
		}
	
	ImGui::End();

	ImGui::Begin("Intersections", &perma_true);
	ImGui::Checkbox("sphere", &App->test->sphere_intersection);
	LOG("%d", App->test->sphere_intersection);
	ImGui::Checkbox("capsule", &App->test->capsule_intersection);
	ImGui::Checkbox("aabb", &App->test->aabb_intersection);
	ImGui::End();
	ImGui::BeginMainMenuBar();
	
		if (ImGui::BeginMenu("Windows"))
		{
			ImGui::MenuItem("ExampleWindow", NULL, &show_demo_window);
		
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Close"))
		{
			to_close = true;
			
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	
	if (show_demo_window)
	{
		ImGui::ShowDemoWindow(&show_demo_window);
	}
	
	return status;
}

update_status ModuleImGui::PostUpdate(float dt)
{

	
	ImGui::Render();
	
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
	update_status status = UPDATE_CONTINUE;
	if (to_close == true)
	{
		status = UPDATE_STOP;
	}
	return status;
}


ModuleImGui::~ModuleImGui()
{
	ImGui_ImplOpenGL2_Shutdown();
		ImGui_ImplSDL2_Shutdown();
		ImGui::DestroyContext();
	
		SDL_GL_DeleteContext(App->renderer3D->context);
		SDL_DestroyWindow(App->window->window);
		SDL_Quit();
	
}


