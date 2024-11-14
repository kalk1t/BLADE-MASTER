

#define TRNR_CHR 0x00BF0010
#define TRNR_BCK 0x00CF0224

#define TRNR_KN  0x0397588A

#define TRNR_HL   0x00891B08
typedef long(__stdcall* WNDPROC)(HWND, unsigned int, unsigned int, long);


static int X = 0;
static int Y = 600;
static int n = 0;
static int P = 500;


static int X1 = 750;
static int Y1 = 460;


static int char_jump = -1;
static int char_attack = 1;
static int char_attack_count = 0;

static int knight_run = -1;

static int background_rotation = -1;
static int knight_move = 7;
static int knight_kill_count = 0;

static int health_ = 0;
HWND Hwn;


unsigned __stdcall Thread_Entry(void*);
unsigned __stdcall Thread_background(void*);
unsigned __stdcall Thread_char_attack(void* Function);
unsigned __stdcall Thread_char_run(void* Function);
unsigned __stdcall Thread_char_fly(void* Function);


class an_animation
{
public:
	HWND hwnd;
	HBITMAP hbtm;
	HBITMAP Bckground;
	int xDest;
	int yDest;
	int wDest;
	int hDest;
	int xSource;
	int ySource;
	int wSource;
	int hSource;
	int imgCropTimes;

};

class character {
public:
	HWND hwnd;
	void attack(int xDest, int yDest);
	void fly(int xDest, int yDest);
	void run(int xDest, int yDest);
};

class background {
public:
	HWND hwnd;
	void bckgr(HWND hwnd);

};

class draw {
public:
	void Draw(HWND hwnd);
};

class knight {
public:
	HWND hwnd;
	void run(int xDest,int yDest);
	
};