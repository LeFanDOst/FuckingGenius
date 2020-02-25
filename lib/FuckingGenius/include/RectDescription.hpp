#ifndef DEF_RECTDESCRIPTION
#define DEF_RECTDESCRIPTION

#include "Types/BasicTypes.hpp"
#include "Window.hpp"

class RectDescription
{
	public:
		RectDescription();
		RectDescription(FGLong left, FGLong top, FGLong right, FGLong bottom);
		~RectDescription();
		
		RectDescription& operator=(RectDescription const& src);
		
		inline FGLong getLeft() const { return m_left; }
		inline FGLong getTop() const { return m_top; }
		inline FGLong getRight() const { return m_right; }
		inline FGLong getBottom() const { return m_bottom; }
		
		inline void setLeft(FGLong left) { m_left = left; }
		inline void setTop(FGLong top) { m_top = top; }
		inline void setRight(FGLong right) { m_right = right; }
		inline void setBottom(FGLong bottom) { m_bottom = bottom; }
		
		inline bool isEqual(RectDescription const& src) const { return ((m_left == src.m_left) && (m_top == src.m_top) && (m_right == src.m_right) && (m_bottom == src.m_bottom)); }
		inline bool isDifferent(RectDescription const& src) const { return (!this->isEqual(src)); }
		
		static RectDescription haveWindowRect(FGWindow win);
	
	private:
		FGLong m_left;
		FGLong m_top;
		FGLong m_right;
		FGLong m_bottom;
};
bool operator==(RectDescription const& rd1, RectDescription const& rd2);
bool operator!=(RectDescription const& rd1, RectDescription const& rd2);

#endif // DEF_RECTDESCRIPTION