#pragma once

#include "DXUtil.h"

using namespace DirectX;

class Camera : public AlignedAllocation<16>
{
public:
	Camera();
	Camera(float fovY, float aspectRatio, float nearZ, float farZ);
	~Camera();

	// Getter.
	float GetAspectRatio() const { return aspectRatio; }
	
	XMMATRIX GetViewMatrix() const { return viewMatrix; }
	XMMATRIX GetProjectionMatrix() const { return projectionMatrix; }

	XMVECTOR GetPositionVector() const { return cameraPosition; }
	XMFLOAT3 GetPosition() const;
	XMVECTOR GetCameraLook() const { return cameraLook; }
	XMVECTOR GetCameraUp() const { return cameraUp; }
	float GetNearZ() const { return nearZ; }
	float GetFarZ() const { return farZ; }

	// Setter.
	void SetAspectRatio(UINT width, UINT height);

	// New.
	void SetPosition(float x, float y, float z);

	// 카메라 이동 관련.
	void MoveForward(float direction);
	void MoveRight(float direction);
	void MoveUp(float direction);

	// 요(Yaw) Y 축 회전.
	void Yaw(float angle);
	// 피치(Pitch) X 축 회전.
	void Pitch(float angle);

	void UpdateCamera();
	float GetSpeed()const { return moveSpeed; }
	float GetMouseSpeed()const { return mouseSpeed; }

private:

	void UpdateViewMatrix();
	void UpdateProjectMatrix();

private:

	float fovY;						// 세로 시야각.
	float aspectRatio;				// 종횡비.
	float nearZ;					// 프러스텀 near 거리.
	float farZ;						// 프러스텀 far 거리.

	float yaw = 0.0f;				// 요 회전 값.
	float pitch = 0.0f;				// 피치 회전 값.

	float moveSpeed = 240.f;        //카메라 스피드
	float mouseSpeed = 20.0f;       //마우스 스피드

	XMMATRIX viewMatrix;
	XMMATRIX projectionMatrix;

	XMVECTOR cameraPosition 
		= XMVectorSet(0.0f, 0.0f, -200.0f, 1.0f);
	XMVECTOR cameraLook 
		= XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR cameraUp 
		= XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

	// New.
	XMVECTOR cameraRight
		= XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR cameraForward
		= XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);

	XMVECTOR defaultUp
		= XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR defaultRight
		= XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR defaultForward
		= XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
};