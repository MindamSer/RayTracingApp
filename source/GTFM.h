#ifndef GTFM_HT
#define GTFM_HT

#include "./qbLinAlg/qbVector.h"
#include "./qbLinAlg/qbMatrix.h"
#include "Ray.h"

namespace RT
{
	constexpr bool FWDTFORM = true;
	constexpr bool BCKTFORM = false;
	
	class GTform
	{
	public:
		GTform();
		~GTform();
		
		GTform(const qbMatrix2<double> &fwd, const qbMatrix2<double> &bck);
		
		void SetTransform(	const qbVector<double> &translation,
					const qbVector<double> &rotation,
					const qbVector<double> &scale);
					
		qbMatrix2<double> GetForward();
		qbMatrix2<double> GetBackward();
		
		RT::Ray Apply(const RT::Ray &inputRay, bool dirFlag);
		qbVector<double> Apply(const qbVector<double> &inputVector, bool dirFlag);
		
		friend GTform operator* (const RT::GTform &lhs, const RT::GTform &rhs);
		
		GTform operator= (const RT::GTform &rhs);
		
		void PrintMatrix(bool dirFlag);
		
		static void PrintVector(const qbVector<double> &inputVector);
		
	private:
		void Print(const qbMatrix2<double> &matrix);
	
		qbMatrix2<double> m_fwdtfm {4, 4};
		qbMatrix2<double> m_bcktfm {4, 4};
	
	};
}

#endif
