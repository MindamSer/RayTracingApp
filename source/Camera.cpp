#include "Camera.h"
#include "Ray.h"
#include <math.h>

RT::Camera::Camera()
{
	m_cameraPosition = qbVector<double> 	{std::vector<double> {0.0, -10.0, 0.0}};
	m_cameraLookAt = qbVector<double> 	{std::vector<double> {0.0, 0.0, 0.0}};
	m_cameraUp = qbVector<double> 		{std::vector<double> {0.0, 0.0, 1.0}};
	m_cameraLength = 1.0;
	m_cameraHorzSize = 1.0;
	m_cameraAspectRatio = 1.0;
}

void RT::Camera::SetPosition(const qbVector<double> &newPosition)
{
	m_cameraPosition = newPosition;
}

void RT::Camera::SetLookAt(const qbVector<double> &newLookAt)
{
	m_cameraLookAt = newLookAt;
}

void RT::Camera::SetUp(const qbVector<double> &newUp)
{
	m_cameraUp = newUp;
}

void RT::Camera::SetLength(double newLength)
{
	m_cameraLength = newLength;
}

void RT::Camera::SetHorzSize(double newSize)
{
	m_cameraHorzSize = newSize;
}

void RT::Camera::SetAspect(double newAspect)
{
	m_cameraAspectRatio = newAspect;
}

qbVector<double> RT::Camera::GetPosition()
{
	return m_cameraPosition;
}

qbVector<double> RT::Camera::GetLookAt()
{
	return m_cameraLookAt;
}

qbVector<double> RT::Camera::GetUp()
{
	return m_cameraUp;
}

qbVector<double> RT::Camera::GetU()
{
	return m_projectionScreenU;
}

qbVector<double> RT::Camera::GetV()
{
	return m_projectionScreenV;
}

qbVector<double> RT::Camera::GetScreenCenter()
{
	return m_projectionScreenCentre;
}

double RT::Camera::GetLength()
{
	return m_cameraLength;
}

double RT::Camera::GetHorzSize()
{
	return m_cameraHorzSize;
}

double RT::Camera::GetAspect()
{
	return m_cameraAspectRatio;
}

void RT::Camera::UpdateCameraGeometry()
{
	m_alignmentVector = m_cameraLookAt - m_cameraPosition;
	m_alignmentVector.Normalize();
	
	m_projectionScreenU = qbVector<double>::cross(m_alignmentVector, m_cameraUp);
	m_projectionScreenU.Normalize();
	
	m_projectionScreenV = qbVector<double>::cross(m_projectionScreenU, m_alignmentVector);
	m_projectionScreenV.Normalize();
	
	m_projectionScreenCentre = m_cameraPosition + (m_cameraLength * m_alignmentVector);
	
	m_projectionScreenU = m_projectionScreenU * m_cameraHorzSize;
	m_projectionScreenV = m_projectionScreenV * (m_cameraHorzSize / m_cameraAspectRatio);
}

bool RT::Camera::GenerateRay(float proScreenX, float proScreenY,  RT::Ray &cameraRay)
{
	qbVector<double> screenWorldPart1 = m_projectionScreenCentre + (m_projectionScreenU * proScreenX);
	qbVector<double> screenWorldCoordinate = screenWorldPart1 + (m_projectionScreenV * proScreenY);
	cameraRay.m_point1 = m_cameraPosition;
	cameraRay.m_point2 = screenWorldCoordinate;
	cameraRay.m_lab = screenWorldCoordinate - m_cameraPosition;
	
	return true;
}

