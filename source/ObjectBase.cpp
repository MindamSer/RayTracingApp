#include "ObjectBase.h"
#include <math.h>

#define EPSILON 1e-21f;

RT::ObjectBase::ObjectBase()
{

}

RT::ObjectBase::~ObjectBase()
{

}

bool RT::ObjectBase::TestIntersection(const Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal, qbVector<double> &localColor)
{
	return false;
}

void RT::ObjectBase::SetTransformMatrix(const RT::GTform &transformMatrix)
{
		
	m_transformMatrix = transformMatrix;
}

bool RT::ObjectBase::CloseEnough(const double f1, const double f2)
{
	return fabs(f1 - f2) < EPSILON;
}
