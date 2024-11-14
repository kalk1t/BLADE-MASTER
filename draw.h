
void draw::Draw(HWND hwnd) {
	HDC hdc_1 = GetDC(hwnd);
	HDC memory_dc_1 = CreateCompatibleDC(hdc_1);


	HBITMAP cover = (HBITMAP)LoadImageA(0, "background//Cover.bmp", IMAGE_BITMAP, 928, 793, LR_LOADFROMFILE);



	SelectObject(memory_dc_1, cover);//background;
	StretchBlt(hdc_1, 0, 0, 928, 793, memory_dc_1, 0, 0, 928, 793, SRCCOPY);


	//BACKGROUND(hwnd);

	//ORC_WALK(hwnd,P,Y);
	//CHARACTER_RUN(hwnd, X, Y);
	//CHARACTER_RUN(hwnd, 240, 80);
	//CHARACTER_RUN(hwnd, 320, 80);
	//CHARACTER_ATACK(hwnd,320, 80);
	//CHARACTER_JUMP(hwnd, 400, 80);
	//CHARACTER_ATACK(hwnd, 550, 80);
	//BACKGROUND(hwnd);
	//CHARACTER_ATACK(hwnd, 160, 80);
	//CHARACTER_RUN(hwnd, 160, 80);
	//BACKGROUND(hwnd);

}
