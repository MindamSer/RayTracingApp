#ifndef OBJSPHERE_H
#define OBJSPHERE_H

#include "ObjectBase.h"
#include "GTFM.h"

namespace RT
{
	class ObjSphere : public ObjectBase
	{
	public:
		ObjSphere();
		virtual ~ObjSphere() override;
		
		virtual bool TestIntersection(const Ray &castRay, qbVector<double> &intPoint, qbVector<double> &localNormal, qbVector<double> &localColor) override;
		
	private:
	
	};
}

#endif
