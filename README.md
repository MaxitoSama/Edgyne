﻿# Edgyne
Edgyne is a basic 3D game engine created as a project for the university. The engine is done mimicking the Unity style, but now it has only basic features.

### Authors
The authors of this engine are two students at the [UPC of barcelona](https://www.citm.upc.edu), studying the degree in engineering of development and design of videogames

[Jaume Surís](https://github.com/Farmak09)

[Lorién Portella](https://github.com/Witiza)

### Execution

Unzip the file and double click Edyne.exe. You have test models in the Assets folder.

### Camera Controls

- While Right clicking: WASD fps-like movement
- Mouse wheel should zoom in and out
- Alt+Left click orbits the object
- Pressing F resets and centers the camera on the object
- Holding SHIFT duplicates movement speed
- Pressing H hides the UI

### Engine Funcionality

- Importing FBX: To import a 3D model, drag and drop the file to the engine window. If everything is correct, the engine will generate a .edgymodel file in the Assets\Models folder which can be accessed from the Assets window.
- Updating the quadtree: The quadtree of the engine will be updated every time a GameObject is created or its switched to Static.
- Saving the Scene: By clicking in SaveScene, you save the currently open scene without changing the name. If you write a name in save scene as and press enter, the engine will check if the name already exists, and if not, will save the scene as a new one.

### Repository
- If you want to download new releases or just check the source code, you can go to our repository:
https://github.com/AWDaM/Edgyne

### Innovation

- The camera culling works using both AABBs and Spheres for more precision.
- Meshes and textures can be added individually to game objects.