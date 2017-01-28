#pragma once

#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#include <D3D11.h>

#include <DirectXMath.h>
#include <d3dcompiler.h>
#include <string>
#include <math.h>

#include "VolumetricData.h"
#include "Utilities.h"

#define PI 3.14159265
using namespace DirectX;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//class VolumetricData;

class DirectXApp
{
public:
    DirectXApp();
    ~DirectXApp();
    bool Init(HINSTANCE, HINSTANCE, LPWSTR, int);
    bool Run();
	void SetVisualizationData(const char);
private:
    HRESULT createWindow(HINSTANCE, int);
    HRESULT initDX();
    void render();
	HRESULT compileAndEnableShaders();
	HRESULT compileShaderFromFile(WCHAR* FileName, LPCSTR EntryPoint, LPCSTR ShaderModel, ID3DBlob** OutBlob);
	HRESULT setupConstantBuffer();
	HRESULT createDepthStencil();
	HRESULT setupVertexAndIndexAndSOBuffer();
	HRESULT setupVisualizationData(const char);

	VolumetricData* m_volumetricData;

	XMFLOAT4 m_dataStep;

	//Window and viewport size
	UINT m_width = 1920;
	UINT m_height = 1080;
	//XMFLOAT4 m_lightPosition;
	Utilities m_utils;
};

/*
Constant buffer description
*/
struct ConstantBuffer
{
	XMMATRIX m_World;
	XMMATRIX m_View;
	XMMATRIX m_Projection;
	XMFLOAT4 m_LightPosition;
};
