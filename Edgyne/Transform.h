#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__


#include "Component.h"
#include "MathGeoLib/Math/float3.h"
#include "MathGeoLib/Math/Quat.h"

class Transform :
	public Component
{
public:
	Transform();
	Transform(GameObject* game_object);
	~Transform();

	void TransformChanged();
	void OnEditor();

private:
public:
	vec position;
	Quat rotation;
	vec rotation_euler;
	vec scale;
private:

};

#endif // !__TRANSFORM_H__