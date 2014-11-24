//
//  Common.h
//  SChart
//
//  Copyright 2011 Scott Logic Ltd. All rights reserved.
//

#ifndef SChartGL_Common
#define SChartGL_Common

#if __cplusplus
#  include <iostream>
#endif


// A shared struct. The JNI wrapper can fake this as an array of floats. :-0
typedef struct
{
    float zoomX, zoomY;
    float minX,  minY;
    float originX, originY;
} SChartGLTranslation;

#if __cplusplus
inline std::ostream &operator<<(
		std::ostream &stream,
		SChartGLTranslation const &translation)
{
	stream << translation.zoomX << ", "
		<< translation.zoomY << ", "
		<< translation.minX << ", "
		<< translation.minY << ", "
		<< translation.originY << ", "
		<< translation.originY;

	return stream;
}
#endif

typedef struct GLColour4f
{
    float red;
    float green;
    float blue;
    float alpha;
#if __cplusplus
    bool isClear() const
    {
        return alpha <= 0;
    }

    static GLColour4f clearColor()
    {
        return {}; // all zero, including alpha
    }

    static GLColour4f blackColor()
    {
        return { .alpha = 1 }; // all zero, except alpha
    }
#endif
} GLColour4f;

#if __cplusplus
static inline std::ostream &operator<<(
		std::ostream &stream,
		GLColour4f const &colour)
{
	stream << colour.red << ", "
		<< colour.green << ", "
		<< colour.blue << ", "
		<< colour.alpha;

	return stream;
}
#endif

#endif
