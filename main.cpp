#include <windows.h>
#include <stdio.h>
#include <process.h>
#include <thread>
#include <iostream>



#include "define.h"
#include "ctrl_main_win.h"
#include "background.h"
#include "character.h"
#include "draw.h"
#include "knight.h"
#include "threads.h"

long CALLBACK win_ctrl_function(HWND, unsigned int, WPARAM, LPARAM);

void paint_movement(HWND, HBITMAP, HBITMAP, int, int, int, int, int, int, int, int, int);
void paint_animation(HWND,HBITMAP,HBITMAP, int , int, int, int , int , int, int , int,int);
void ORC_WALK(HWND, int, int);


using namespace std;
void main() {

	WNDCLASSA wc = { 0 };
	wc.hbrBackground = CreateSolidBrush(0xFFFFFF);
	wc.lpszClassName = "1";
	wc.lpfnWndProc = win_ctrl_function;


	if (!RegisterClassA(&wc)) {
		return;
	}


	DWORD style = WS_VISIBLE
		| WS_OVERLAPPED
		| WS_CAPTION
		| WS_SYSMENU
		| WS_THICKFRAME
		| WS_MAXIMIZEBOX
		| WS_MINIMIZEBOX
		;


	HWND main = CreateWindowA(wc.lpszClassName, "wnd", style, 150, 0, 944, 793, 0, 0, 0, 0);

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)) {
		DispatchMessageA(&msg);
		TranslateMessage(&msg);
	}

}

void paint_movement(HWND hwnd,HBITMAP hbtm,HBITMAP Bckground, int xDest, int yDest,int wDest,int hDest,int xSource,int ySource,int wSource,int hSource,int imgCropTimes) {
	
	HDC hdc_1 = GetDC(hwnd);
	HDC memory_dc_1 = CreateCompatibleDC(hdc_1);

	HDC memory_dc_2 = CreateCompatibleDC(hdc_1);

	DWORD style = SRCAND;
	DWORD box_style = SRCCOPY;
	
	int t = 25;

	if (n >= imgCropTimes) {
		n = 0;
	}
	
	for (int i = 0;i < 1;i++) {
		int k = 5;
		for (int j = 0;j <imgCropTimes;j++) {
			
			SelectObject(memory_dc_1, Bckground);//atack's background;
			StretchBlt(hdc_1, xDest+(k*j), yDest, wDest, hDest, memory_dc_1, xDest, yDest, wDest, hDest, box_style);
			SelectObject(memory_dc_1, hbtm);//stand_1
			StretchBlt(hdc_1, xDest+(k*j), yDest, wDest, hDest, memory_dc_1, xSource * j, 0, wSource, hSource, style);

			Sleep(t);
		}
		X += (imgCropTimes-1) * k;
	}

	
}

void paint_animation(HWND hwnd, HBITMAP hbtm, HBITMAP Bckground, int xDest, int yDest, int wDest, int hDest, int xSource, int ySource, int wSource, int hSource, int imgCropTimes) {

	HDC hdc_1 = GetDC(hwnd);
	HDC memory_dc_1 = CreateCompatibleDC(hdc_1);

	HDC memory_dc_2 = CreateCompatibleDC(hdc_1);

	DWORD style = SRCAND;
	DWORD box_style = SRCCOPY;

	int t = 5;
	int c = 0;
	int sum = 0;
	if (n >= imgCropTimes) {
		n = 0;
	} 
	if(n<0)
	{
		n = imgCropTimes-1;
	}
	for (int i = 0;i < 1;i++) {
		for (int j = 0;j <1;j++) {

			//SelectObject(memory_dc_2, Bckground);//dstand's background;
			//BitBlt(hdc_1, 0, 0, 928, 793, memory_dc_2, 0, 0, box_style);

			
			SelectObject(memory_dc_1, Bckground);//atack's background;
			StretchBlt(hdc_1, xDest, yDest, wDest, hDest, memory_dc_1, xDest, yDest, wDest, hDest, box_style);
			SelectObject(memory_dc_1, hbtm);//stand_1
			StretchBlt(hdc_1, xDest, yDest, wDest, hDest, memory_dc_1, xSource * n, 0, wSource, hSource, style);
			Sleep(t);
			
		}
	}
		
	}


void ORC_WALK(HWND hwnd, int xDest, int yDest) {

	an_animation orc;

	orc.hwnd = hwnd;
	orc.hbtm = (HBITMAP)LoadImageA(0, "orc/Orc_Walk.bmp", IMAGE_BITMAP, 800, 100, LR_LOADFROMFILE);
	orc.Bckground = (HBITMAP)LoadImageA(0, "background//Background.bmp", IMAGE_BITMAP, 928, 793, LR_LOADFROMFILE);
	orc.xDest = xDest;
	orc.yDest = yDest;
	orc.wDest = 100 ;
	orc.hDest = 100 ;
	orc.xSource = 100;
	orc.ySource = 0;
	orc.wSource = 100;
	orc.hSource = 100;
	orc.imgCropTimes = 8;



	paint_movement(orc.hwnd, orc.hbtm, orc.Bckground, orc.xDest, orc.yDest, orc.wDest, orc.hDest, orc.xSource, orc.ySource, orc.wSource, orc.hSource, orc.imgCropTimes);



}