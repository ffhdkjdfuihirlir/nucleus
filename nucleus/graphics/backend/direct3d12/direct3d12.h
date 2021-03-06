/**
 * (c) 2014-2016 Alexandro Sanchez Bach. All rights reserved.
 * Released under GPL v2 license. Read LICENSE for more details.
 */

#pragma once

#include "nucleus/common.h"

#include <Windows.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <d3dcompiler.h>

// Debugging
#if defined(NUCLEUS_BUILD_DEBUG)
#include <initguid.h>
#include <dxgidebug.h>
#endif

// Helper
#include "externals/direct3d12/d3dx12.h"

// Function types: dxgi.dll
typedef HRESULT(WINAPI *PFN_CreateDXGIFactory)(REFIID, void **);
typedef HRESULT(WINAPI *PFN_CreateDXGIFactory1)(REFIID, void **);
typedef HRESULT(WINAPI *PFN_CreateDXGIFactory2)(UINT, REFIID, void **);
typedef HRESULT(WINAPI *PFN_DXGIGetDebugInterface)(REFIID riid, void **ppDebug);

namespace gfx {
namespace direct3d12 {

// Declare Function
#if defined(NUCLEUS_TARGET_UWP)
#define _D3D12CreateDevice            D3D12CreateDevice
#define _D3D12GetDebugInterface       D3D12GetDebugInterface
#define _D3D12SerializeRootSignature  D3D12SerializeRootSignature
#define _CreateDXGIFactory            CreateDXGIFactory
#define _CreateDXGIFactory1           CreateDXGIFactory1
#define _CreateDXGIFactory2           CreateDXGIFactory2
#define _D3DCompile                   D3DCompile
#define _D3DDisassemble               D3DDisassemble
#define _D3DPreprocess                D3DPreprocess
#define _DXGIGetDebugInterface        DXGIGetDebugInterface
#define _DXGIGetDebugInterface1       DXGIGetDebugInterface1

#elif defined(NUCLEUS_TARGET_WINDOWS)
#define DECLARE_FUNCTION(type, module, function) extern type _##function;
#define FUNCTION DECLARE_FUNCTION
#include "direct3d12.inl"
#undef FUNCTION
#undef DECLARE_FUNCTION
#endif

// Load extensions
bool initializeDirect3D12();

}  // namespace direct3d12
}  // namespace gfx
