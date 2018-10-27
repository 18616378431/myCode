//6.
#include<iostream>
#include"Move.h"

Move::Move(double a /* = 0 */,double b /* = 0 */)
{
	x = a;
	y = b;
}
void Move::showMove()const
{
	std::cout << "x:" << x << ",y:" << y << std::endl;
}
Move Move::add(const Move & m)const
{
	Move move(m.x,m.y);
	return move;
}
void Move::reset(double a /* = 0 */,double b /* = 0 */)
{
	x = a;
	y = b;
}