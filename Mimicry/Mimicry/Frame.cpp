#include "Frame.h"

Frame::Frame()
{

}

Frame::Frame(UV uv0, UV uv1, UV uv2, UV uv3)
{
	uv[0] = uv0;
	uv[1] = uv1;
	uv[2] = uv2;
	uv[3] = uv3;
}

Frame::~Frame()
{
}

UV Frame::GetUV(int index)
{
	return uv[index];
}
