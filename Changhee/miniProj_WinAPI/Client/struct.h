#pragma once

struct Vec2
{
public:
	float		x;
	float		y;


	Vec2()
		: x(0.f)
		, y(0.f)
	{}

	Vec2(float _x, float _y)
		: x(_x)
		, y(_y)
	{}

	Vec2(int _x, int _y)
		: x((float)_x)
		, y((float)_y)
	{}
};


struct FKeyData
{
	KEY			eKey;
	KEY_STATE	eState;
	bool		bPressed;
};