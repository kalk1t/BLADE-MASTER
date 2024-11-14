
void character::fly(int xDest, int yDest) {
	an_animation an;

	an.hwnd = character::hwnd;
	an.hbtm = (HBITMAP)LoadImageA(0, "character//Jump.bmp", IMAGE_BITMAP, 960, 64, LR_LOADFROMFILE);
	an.Bckground = (HBITMAP)LoadImageA(0, "interface//Elements-02.bmp", IMAGE_BITMAP, 933, 125, LR_LOADFROMFILE);
	HBITMAP health = (HBITMAP)LoadImageA(0, "interface//Elements-03.bmp", IMAGE_BITMAP, 891, 125, LR_LOADFROMFILE);
	an.xDest = xDest;
	an.yDest = yDest;
	an.wDest = 64*2;
	an.hDest = 64*2;
	an.xSource = 64;
	an.ySource = 0;
	an.wSource = 64;
	an.hSource = 64;
	an.imgCropTimes = 15;


	HDC hdc_1 = GetDC(hwnd);
	HDC memory_dc_1 = CreateCompatibleDC(hdc_1);

	DWORD style = TRNR_CHR;

	int t = 125;
	for (int i = 0;i < 1;i++) {
		for (int j = 0;j <4;j++) {
			SelectObject(memory_dc_1, an.Bckground);
			StretchBlt(hdc_1, an.xDest , an.yDest - 30, 100, 20, memory_dc_1, 0, 0, 933, 125, style);
			SelectObject(memory_dc_1, health);
			StretchBlt(hdc_1, an.xDest , an.yDest -25, 100, 10, memory_dc_1, 33 * health_, 0, 891, 125, TRNR_HL);
			SelectObject(memory_dc_1, an.hbtm);//stand_1
			StretchBlt(hdc_1, an.xDest, an.yDest, an.wDest, an.hDest, memory_dc_1, an.xSource * 5, 0, an.wSource, an.hSource, style);
			

		}
	}



}

void character::run(int xDest, int yDest) {
	an_animation an;

	an.hwnd = character::hwnd;
	an.hbtm = (HBITMAP)LoadImageA(0, "character//Run.bmp", IMAGE_BITMAP, 640, 80, LR_LOADFROMFILE);
	an.Bckground = (HBITMAP)LoadImageA(0, "interface//Elements-02.bmp", IMAGE_BITMAP, 933, 125, LR_LOADFROMFILE);
	HBITMAP health = (HBITMAP)LoadImageA(0, "interface//Elements-03.bmp", IMAGE_BITMAP, 891, 125, LR_LOADFROMFILE);
	an.xDest = xDest;
	an.yDest = yDest;
	an.wDest = 80*2;
	an.hDest = 80*2;
	an.xSource = 80;
	an.ySource = 0;
	an.wSource = 80;
	an.hSource = 80;
	an.imgCropTimes = 8;

	HDC hdc_1 = GetDC(hwnd);
	HDC memory_dc_1 = CreateCompatibleDC(hdc_1);


	DWORD style = TRNR_CHR;

	int t = 25;
	int c = 0;
	int sum = 0;
	if (n >= an.imgCropTimes) {
		n = 0;
	}
	if (n < 0)
	{
		n = an.imgCropTimes - 1;
	}
	for (int i = 0;i < 1;i++) {
		for (int j = 0;j < 1;j++) {


			SelectObject(memory_dc_1, an.Bckground);
			StretchBlt(hdc_1, an.xDest+50, an.yDest , 100, 20, memory_dc_1, 0, 0, 933, 125, style);
			SelectObject(memory_dc_1, health);
			StretchBlt(hdc_1, an.xDest+50, an.yDest+5, 100, 10, memory_dc_1, 33*health_, 0, 891,  125, TRNR_HL);
			SelectObject(memory_dc_1, an.hbtm);//stand_1
			StretchBlt(hdc_1, an.xDest, an.yDest, an.wDest, an.hDest, memory_dc_1, an.xSource * n, 0, an.wSource, an.hSource, style);
			Sleep(t);

		}
	}

}

void character::attack(int xDest, int yDest) {

	an_animation an;

	an.hwnd = character::hwnd;
	an.hbtm = (HBITMAP)LoadImageA(0, "character//Attack.bmp", IMAGE_BITMAP, 768, 80, LR_LOADFROMFILE);
	an.Bckground = (HBITMAP)LoadImageA(0, "interface//Elements-02.bmp", IMAGE_BITMAP, 933, 125, LR_LOADFROMFILE);
	HBITMAP health = (HBITMAP)LoadImageA(0, "interface//Elements-03.bmp", IMAGE_BITMAP, 891, 125, LR_LOADFROMFILE);

	an.xDest = xDest;
	an.yDest = yDest;
	an.wDest = 96*2;
	an.hDest = 80*2;
	an.xSource = 96;
	an.ySource = 0;
	an.wSource = 96;
	an.hSource = 80;
	an.imgCropTimes = 8;



	HDC hdc_1 = GetDC(an.hwnd);
	HDC memory_dc_1 = CreateCompatibleDC(hdc_1);

	DWORD style = TRNR_CHR;

	int t = 21;

	if (char_attack >= an.imgCropTimes) {
		char_attack = 1;
	}

	for (int i = 0;i < 1;i++) {
		int k = 5;
		for (int j = 0;j < 1;j++) {

			SelectObject(memory_dc_1, an.Bckground);
			StretchBlt(hdc_1, an.xDest+70, an.yDest, 100, 20, memory_dc_1, 0, 0, 933, 125, style);
			SelectObject(memory_dc_1, health);
			StretchBlt(hdc_1, an.xDest + 70, an.yDest + 5, 100, 10, memory_dc_1, 33 * health_, 0, 891, 125, TRNR_HL);
			SelectObject(memory_dc_1, an.hbtm);//stand_1
			StretchBlt(hdc_1, an.xDest + (k * char_attack), an.yDest, an.wDest, an.hDest, memory_dc_1, an.xSource * char_attack, 0, an.wSource, an.hSource, style);

			Sleep(t);
		}
		X += (an.imgCropTimes - 1) * k;
	}


}
