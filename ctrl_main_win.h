long CALLBACK win_ctrl_function(HWND hwnd, unsigned int message, WPARAM wp, LPARAM lp) {

	character cr;
	cr.hwnd = hwnd;
	draw d;
	background b;
	b.hwnd = hwnd;

	knight kn;
	kn.hwnd = hwnd;

	switch (message) {
	case WM_CREATE:
	{

	}
	break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		BeginPaint(hwnd, &ps);
		//---
		//d.Draw(hwnd);


		//HANDLE Thread = (HANDLE)_beginthreadex(NULL, 0, Thread_Entry, &kn, 0, NULL);
		//HANDLE CHAR_RUN = (HANDLE)_beginthreadex(NULL, 0, Thread_char_run, &cr, 0, NULL);
		//HANDLE CHAR_FLY = (HANDLE)_beginthreadex(NULL, 0, Thread_char_fly, &cr, 0, NULL);
		//HANDLE CHAR_ATTACK = (HANDLE)_beginthreadex(NULL, 0, Thread_char_attack, &cr, 0, NULL);

		HANDLE BCKGR = (HANDLE)_beginthreadex(NULL, 0, Thread_background, &b, 0, NULL);
		WaitForSingleObject(BCKGR, 1);
		if (BCKGR == NULL) {
			return 90;
		}
		//WaitForSingleObject(Thread, 1);
		/*if (Thread == NULL) {
			std::cout << "Error creating a thread" << std::endl;
			return 9;
		}*/
		// 
		//---
		//EndPaint(hwnd, &ps);

	}
	break;

	case WM_COMMAND:
	{
		switch ((short)wp) {


		}
	}
	break;

	case WM_KEYDOWN:
	{
		switch (wp) {


		case 0x44: //D
		{
			if (X > 650) {
				X = 650;
			}
			if (Y > 150 && Y < 350) {
				health_--;
			}
			
			//background_rotation++;
			b.bckgr(hwnd);
			if (Y == 600) {
				X += 50;
				n++;
				
				cr.run(X, Y);
				
			}
			else {
				X += 50;
				cr.fly(X, Y);
			}


		}
		break;

		case 0x57: //W
		{
			if (Y < 150) {
				Y = 150;
			}
			if (Y > 150 && Y < 350) {
				health_--;
			}
			b.bckgr(hwnd);
			//background_rotation++;
			char_jump++;
			Y -= 30;
			cr.fly(X, Y);

		}
		break;
		case 0x53: //S
		{

			if (Y > 600) {
				Y = 600;
			}
			if (Y > 150 && Y < 350) {
				health_--;
			}
			if (Y != 600) {
			b.bckgr(hwnd);
				//background_rotation++;
				Y += 30;
				cr.fly(X, Y);
			}
		}
		break;
		case 0x41: //A
		{
			if (X < 0) {
			X = 0;
		}
			if (Y > 150 && Y < 350) {
				health_--;
			}
			//background_rotation++;
			b.bckgr(hwnd);
			if (Y == 600) {
				X -= 50;
				n--;
				cr.run(X, Y);
			}
			else {
				X -= 50;
				cr.fly(X, Y);
			}
		}
		break;
		case 0x20: //SPACEBAR
		{

			if (Y > 600) {
				Y = 600;
			}

			while (Y < 600 ) {
				//background_rotation++;
			b.bckgr(hwnd);
				Y += 50;
				cr.fly(X, Y);
			}

		}
		break;
		case 0x47:  //G
		{

		}
		break;
		}
		break;

		break;
	}
	break;

	case WM_LBUTTONDOWN:
	{
		if (X > 580) {
			X = 580;
		}
		if (Y > 150 && Y < 350) {
			health_--;
		}
		if (char_attack > 2 && char_attack<5) {
			char_attack = 5;
		}
		//background_rotation++;
		b.bckgr(hwnd);
		X += 3;
		
		cr.attack(X,Y);
		char_attack++;
		if (X + 120 > X1) {
			char_attack_count++;
		}
	}
	break;

	case WM_RBUTTONDOWN:
	{
		if (X > 530) {
			X = 530;
		}
		if (Y > 150 && Y < 350) {
			health_--;
		}
		if (char_attack > 2 && char_attack < 5) {
			char_attack = 5;
		}
		//background_rotation++;
		b.bckgr(hwnd);
		X += 3;
		char_attack++;
		cr.attack( X, Y);
		if (X + 120 > X1) {
			char_attack_count++;
		}
	}
	break;
	case WM_DESTROY:
	{
		PostQuitMessage(21);
		exit(21);
	}
	break;


	}


	return DefWindowProc(hwnd, message, wp, lp);
}