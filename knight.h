
void knight::run (int xDest,int yDest) {

	
	an_animation kn;
	

	kn.hwnd = knight::hwnd;
	kn.hbtm = (HBITMAP)LoadImageA(0, "knight//run.bmp", IMAGE_BITMAP, 256, 256, LR_LOADFROMFILE);
	kn.xDest = xDest;
	kn.yDest = yDest;
	kn.wDest = 64 * 4;
	kn.hDest = 64 * 4;
	kn.xSource = 0;
	kn.ySource = 64;
	kn.wSource = 128;
	kn.hSource = 64;
	kn.imgCropTimes = 4;


	HDC hdc_1 = GetDC(hwnd);
	HDC memory_dc_1 = CreateCompatibleDC(hdc_1);

	DWORD style = TRNR_KN;
	
		
		for (knight_run = 0;knight_run < 4;knight_run++) {

			if (X1 < 10) {
				X1 = 500;
			}
			for (int j = 0;j < 1;j++) {
				//bckgr(kn.hwnd);
				SelectObject(memory_dc_1, kn.hbtm);//stand_1
				StretchBlt(hdc_1, kn.xDest, kn.yDest, kn.wDest, kn.hDest, memory_dc_1, kn.xSource, kn.ySource * knight_run, kn.wSource, kn.hSource, style);

				//kn.xDest -= 2;

				
			}
			Sleep(150);
		}
	
}