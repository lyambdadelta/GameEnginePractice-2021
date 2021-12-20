#pragma once

#include <imgui.h>
#include <imgui_impl_win32.h>
#include <imgui_impl_dx11.h>
#include <d3d11.h>
#include <tchar.h>
#include <vector>
#include "../RenderNode.h"

void CleanupRenderTarget();
void CreateRenderTarget();
void CleanupDeviceD3D();
bool CreateDeviceD3D(HWND hWnd);

bool InitImGUI();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void UpdateImGUI(std::vector<RenderNode*>& m_pRenderNodes);

void CreateTree(std::vector<RenderNode*>& m_pRenderNodes);

bool NeedWrite();
bool EditorMode();
//void CreateNode(Ogre::SceneNode* sceneNode);