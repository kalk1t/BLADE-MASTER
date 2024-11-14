#pragma once
unsigned __stdcall Thread_Entry(void* Function) {
	
	knight* kn = static_cast<knight*>(Function);
	kn->run(X1, Y1);

	return 0;
}

unsigned __stdcall Thread_background(void* Function) {
	background* b = static_cast<background*>(Function);
	
	b->bckgr(b->hwnd);

	return 0;
}
unsigned __stdcall Thread_char_attack(void* Function) {
	character* cr = static_cast<character*>(Function);
	cr->attack(X, Y);

	return 0;
}
unsigned __stdcall Thread_char_run(void* Function) {
	character* cr = static_cast<character*>(Function);
	cr->run(X, Y);

	return 0;
}
unsigned __stdcall Thread_char_fly(void* Function) {
	character* cr = static_cast<character*>(Function);
	cr->fly(X, Y);

	return 0;
}