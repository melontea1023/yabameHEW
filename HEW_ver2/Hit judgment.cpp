
#include"Game.h"

bool Game::Box_Hit_judgment(Object obj1, Object obj2)
{
	float p_up,p_down,p_left,p_right;
	float f_up, f_down, f_left, f_right;

	DirectX::XMFLOAT3 p_pos=obj1.GetPos();
	DirectX::XMFLOAT3 p_size= obj1.GetSize();

	DirectX::XMFLOAT3 ef_pos=obj2.GetPos();
	DirectX::XMFLOAT3 ef_size = obj2.GetSize();

	p_up = p_pos.y - p_size.y / 2;
	p_down = p_pos.y + p_size.y / 2;
	p_left = p_pos.x - p_size.x / 2;
	p_right = p_pos.x + p_size.x / 2;

	f_up = ef_pos.y - ef_size.y / 2;
	f_down = ef_pos.y + ef_size.y / 2;
	f_left = ef_pos.x - ef_size.x / 2;
	f_right = ef_pos.x + ef_size.x / 2;

	if (p_up >= f_down)
	{
		return false;
	}
	if (p_down <=f_up)
	{
		return false;
	}
	if(p_left >= f_right)
	{
		return false;
	}
	if (p_right <= f_left)
	{
		return false;
	}
	
	
		return true;
		


	/*return false;

	return false;*/

	
}

bool Game::Circle_Hit_judgment(Object obj1, Object obj2)
{
	//float bottom, height, slope, radius;

	//DirectX::XMFLOAT3 o1_pos = obj1.GetPos();
	//DirectX::XMFLOAT3 o1_size = obj1.GetSize();

	//DirectX::XMFLOAT3 o2_pos = obj2.GetPos();
	//DirectX::XMFLOAT3 o2_size = obj2.GetSize();

	//bottom = pow((o1_pos.x - o2_pos.x), 2.0f);
	//height = pow((o1_pos.y - o2_pos.y), 2.0f);

	//slope = bottom + height;

	//radius = pow((obj1.r + obj2.r), 2.0f);

	//if (slope > radius)
	//{
	//	return false;
	//}


	return true;



}


bool Game::Box_Hit_Judgment(Object obj1, Object obj2)
{



}