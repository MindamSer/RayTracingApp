#ifndef LIGHTBASE_H
#define LIGHTBASE_H

#include <memory>
#include "./qbLinAlg/qbVector.h"
#include "Ray.h"
#include "ObjectBase.h"

namespace RT
{
	class LightBase
	{
	public:
		LightBase();
		virtual ~LightBase();
		
		virtual bool ComputeIllumination(	const qbVector<double> &intPoint, 
							const qbVector<double> &localNormal, 
							const std::vector<std::shared_ptr<RT::ObjectBase>> &objectList, 
							const std::shared_ptr<RT::ObjectBase> &currentObject, 
							qbVector<double> &color,
							double &intensity);
							
		qbVector<double> m_color	{3};
		qbVector<double> m_location	{3};
		double m_intensity;
	private:
	
	};
}

#endif
