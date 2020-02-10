#include "../include/RectDescription.hpp"

RectDescription::RectDescription() : m_left(0), m_top(0), m_right(0), m_bottom(0) {}

RectDescription::RectDescription(FGLong left, FGLong top, FGLong right, FGLong bottom) : m_left(left), m_top(top), m_right(right), m_bottom(bottom) {}

RectDescription::~RectDescription() {}


RectDescription& RectDescription::operator=(RectDescription const& src)
{
	m_left = src.m_left;
	m_top = src.m_top;
	m_right = src.m_right;
	m_bottom = src.m_bottom;
	
	return *this;
}


bool operator==(RectDescription const& rd1, RectDescription const& rd2)
{
	RectDescription copy(rd1);
	
	return rd1.isEqual(rd2);
}

bool operator!=(RectDescription const& rd1, RectDescription const& rd2)
{
	RectDescription copy(rd1);
	
	return rd1.isDifferent(rd2);
}