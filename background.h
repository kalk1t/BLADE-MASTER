void background::bckgr(HWND hwnd) {
	HDC hdc_1 = GetDC(hwnd);
	HDC memory_dc_1 = CreateCompatibleDC(hdc_1);


	HBITMAP Bckgr = (HBITMAP)LoadImageA(0, "background//Background.bmp", IMAGE_BITMAP, 928, 793, LR_LOADFROMFILE);
	//HBITMAP Buildings = (HBITMAP)LoadImageA(0, "background//Buildings.bmp", IMAGE_BITMAP, 400, 400, LR_LOADFROMFILE);
	//HBITMAP orc = (HBITMAP)LoadImageA(0, "orc/Orc_Walk.bmp", IMAGE_BITMAP, 800, 100, LR_LOADFROMFILE);
	HBITMAP Score = (HBITMAP)LoadImageA(0, "interface//Elements-04.bmp", IMAGE_BITMAP, 1010, 420, LR_LOADFROMFILE);
	HBITMAP knight= (HBITMAP)LoadImageA(0, "knight//run.bmp", IMAGE_BITMAP, 256, 256, LR_LOADFROMFILE);
	HBITMAP knight_attack_01 = (HBITMAP)LoadImageA(0, "knight//knight_attack_01.bmp", IMAGE_BITMAP, 1024, 64, LR_LOADFROMFILE);
	HBITMAP knight_death = (HBITMAP)LoadImageA(0, "knight/knight_death.bmp", IMAGE_BITMAP, 256, 64, LR_LOADFROMFILE);
	int k = 232;
	int t = 0;
	int xx = 1;
	while (xx>0) {
		if (health_ > 27) {
			health_ = 27;
		}
		if (health_ < 0) {
			health_ = 0;
		}
		if (char_attack_count > 8) {
			X1 = 750;
			char_attack_count = 0;
		}


		background_rotation--;
		if (background_rotation == 4) {
			background_rotation = 0;
		}
		if (background_rotation < 0) {
			background_rotation = 3;
		}
		int count = 0;
		

			for (int i = 0;i < 1;i++) {
				/*int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
				if (background_rotation == 0) {
					b4 = 3;
					b3 = 2;
					b2 = 1;
					b1 = 0;
				}
				if (background_rotation == 1) {
					b4 = 2;
					b3 = 1;
					b2 = 0;
					b1 = 3;
				}
				if (background_rotation == 2) {
					b4 = 1;
					b3 = 0;
					b2 = 3;
					b1 = 2;
				}
				if (background_rotation == 3) {
					b4 = 0;
					b3 = 3;
					b2 = 2;
					b1 = 1;
				}*/
				X1 -= 20;
				if (X1< X + 100) {
					X1 = X+100;
			}
				SelectObject(memory_dc_1, Bckgr);//background;
				StretchBlt(hdc_1, k * 0, 0, 928, 793, memory_dc_1, k * 0, 0, 928, 793, TRNR_BCK);
				
				StretchBlt(hdc_1, k * 1, 0, 928, 793, memory_dc_1, k * 1, 0, 928, 793, TRNR_BCK);
				
				StretchBlt(hdc_1, k * 2, 0, 928, 793, memory_dc_1, k *2,0, 928, 793, TRNR_BCK);
				
				StretchBlt(hdc_1, k * 3, 0, 928, 793, memory_dc_1, k * 3, 0, 928, 793, TRNR_BCK);
				SelectObject(memory_dc_1, Score);
				StretchBlt(hdc_1, 0, 0, 700, 100, memory_dc_1, 0, 0, 1010, 420, TRNR_CHR);

				if (X1 < X + 150 && char_attack_count<8) {
					knight_move--;
					if (knight_move < 0) {
						knight_move = 7;
					}
					SelectObject(memory_dc_1, knight_attack_01);
					StretchBlt(hdc_1, X1, 600, 128 * 2, 64 * 2, memory_dc_1, 128 * knight_move, 0, 128, 64, TRNR_KN);
					if (X1 < X + 150 && Y == 600) {
						health_++;
					}
				}
				if (X1 > X + 130 && char_attack_count < 8) {
					SelectObject(memory_dc_1, knight);
					StretchBlt(hdc_1, X1, 600, 128 * 2, 64 * 2, memory_dc_1, 0, 64 * background_rotation, 128, 64, TRNR_KN);
				}
				int xX = X + 150 ;
				if (char_attack_count == 8) {
					


					SelectObject(memory_dc_1, knight_death);
					StretchBlt(hdc_1,xX , 600, 128*2 , 64*2, memory_dc_1, 128*1, 0, 128, 64, TRNR_KN);
					
					SelectObject(memory_dc_1, Bckgr);//background;
					StretchBlt(hdc_1, k * 0, 0, 928, 793, memory_dc_1, k * 0, 0, 928, 793, TRNR_BCK);

					StretchBlt(hdc_1, k * 1, 0, 928, 793, memory_dc_1, k * 1, 0, 928, 793, TRNR_BCK);

					StretchBlt(hdc_1, k * 2, 0, 928, 793, memory_dc_1, k * 2, 0, 928, 793, TRNR_BCK);

					StretchBlt(hdc_1, k * 3, 0, 928, 793, memory_dc_1, k * 3, 0, 928, 793, TRNR_BCK);
					SelectObject(memory_dc_1, Score);
					StretchBlt(hdc_1, 0, 0, 700, 100, memory_dc_1, 0, 0, 1010, 420, TRNR_CHR);


					SelectObject(memory_dc_1, knight_death);
					StretchBlt(hdc_1, xX, 600, 128 * 2, 64 * 2, memory_dc_1, 128 * 0, 0, 128, 64, TRNR_KN);
					Sleep(150);
					knight_kill_count++;
				}
				if (knight_kill_count > 0) {
					for (int i = 0;i < knight_kill_count;i++) {
						SelectObject(memory_dc_1, knight_death);
						StretchBlt(hdc_1, 10+(30*i), 0, 128, 64, memory_dc_1, 128 * 1, 0, 128, 64, TRNR_KN);
					}
				}
			}
			HBITMAP mission_completed = (HBITMAP)LoadImageA(0, "interface//mission_completed.bmp", IMAGE_BITMAP, 928, 793, LR_LOADFROMFILE);
			HBITMAP mission_failed = (HBITMAP)LoadImageA(0, "interface/mission_failed.bmp", IMAGE_BITMAP, 928, 793, LR_LOADFROMFILE);
			if (knight_kill_count == 21) {
				//CONGRATULATIONS
				SelectObject(memory_dc_1, mission_completed);
				StretchBlt(hdc_1,0, 0, 928, 793, memory_dc_1, 0, 0, 928, 793, SRCCOPY);
				int val;
				val = MessageBoxA(hwnd, "CONGRATULATION,YOU WON", "NEXT LVL WILL BE ADDED SOON", MB_OK);
				if (val == IDOK) {
					exit(1121);
				}
			}
			if (health_ == 27) {
				//Game OVER
				SelectObject(memory_dc_1, mission_failed);
				StretchBlt(hdc_1, 0, 0, 928, 793, memory_dc_1, 0, 0, 928, 793, SRCCOPY);
				int val;
				val=MessageBoxA(hwnd, "MISSION_FAILED,WANNA TRY AGAIN?", "BLADE-MASTER-I", MB_YESNO);
				if (val == IDYES) {
					health_ = 0;
					knight_kill_count = 0;
				}
				else {
					exit(1121);
				}
			}
		
			Sleep(t);
			xx--;
		//
	}
}
