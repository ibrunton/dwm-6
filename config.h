/* See LICENSE file for copyright and license details. */

/* appearance */
/*static const char font[]            = "-misc-fixed-medium-r-semicondensed--13-120-75-75-c-*-iso8859-2";*/
static const char font[]            = "-*-ohsnap.icons-medium-r-normal-*-11-79-100-100-C-60-ISO8859-1";
static const char colors[MAXCOLORS][ColLast][8] = {
	/* border     fg         bg       */
	{ "#666666", "#aaaaaa", "#222222" }, /* 0 = normal */
	{ "#426797", "#4abcd4", "#222222" }, /* 1 = selected */
	{ "#FF1881", "#FFFFFF", "#FF1881" }, /* 2 = urgent */
	{ "#333333", "#8f8f8f", "#222222" }, /* 3 = x04 = normal status bar */
	{ "#333333", "#e0e0e0", "#222222" }, /* 4 = x05 = data */
	{ "#333333", "#4abcd4", "#222222" }, /* 5 = x06 = highlight */
	{ "#333333", "#cd5666", "#222222" }, /* 6 = x07 = critical CPU/batter */
	{ "#333333", "#899CA1", "#1A1919" }, /* 7 = x08 = */
};
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 20;        /* snap pixel */
static const unsigned int gappx		= 2;		/* gap pixel width */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */
static const Bool clicktofocus      = True;     /* Change focus only on click */

static const Rule rules[] = {
	/* class		instance    title       tags mask     isFloating   isCentred	monitor */
	{ "Gimp",		NULL,       NULL,       1 << 5,		True,		False,	-1 },
	{ "Geeqie",		NULL,       NULL,       NULL,		True,		False,	-1 },
	{ "Dolphin",	NULL,       NULL,       NULL,		True,		False,	-1 },
	{ "Vlc",		NULL,       NULL,       NULL,		True,		True,	-1 },
	{ "Firefox",	NULL,       NULL,       1 << 1,		False,		False,	-1 },
	{ "Okular",		NULL,       NULL,       1 << 4,		False,		False,	-1 },
	{ "URxvt",		NULL,		"MAILTO",	1 << 1,		True,		True,	-1 },
};

/* layout(s) */
static const float mfact      = 0.5;   /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;     /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },        /* first entry is default */
	{ "[F]",      NULL },        /* no layout function means floating behavior */
	{ "[B]",      bstack },
	{ "[M]",      monocle },
};

/* tagging */
static const Tag tags[] = {
  /* name	layout			mfact	monitor */
  { "term",	&layouts[0],	-1,		-1 },
  { "www",	&layouts[0],	0.75,	-1 },
  { "xdr",	&layouts[1],	-1,		-1 },
  { "dev",	&layouts[0],	0.55,	-1 },
  { "doc",	&layouts[1],	-1,		-1 },
  { "etc",	&layouts[1],	-1,		-1 },
};

/* key definitions */
#define ALTKEY Mod1Mask
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* commands */
static const char terminal[]		= "urxvt";
static const char *dmenucmd[]		= { "dmenu_run", "-i", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG],"-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
static const char *mymenucmd[]		= { "/home/ian/bin/dmenu_custom.bash", NULL };
static const char *mygtkmenucmd[]	= { "/home/ian/bin/mygtkmenu.py", NULL };
static const char *termcmd[]		= { terminal, NULL };
static const char *emacscmd[]		= { "/home/ian/bin/emet", NULL };
static const char *filemancmd[]		= { "dolphin", NULL };
static const char *browsercmd[]		= { "firefox", NULL };
static const char *volmcmd[]		= { "volosd.sh", "mute", NULL };
static const char *voldcmd[]		= { "volosd.sh", "down", "-i", "1", NULL };
static const char *volucmd[]		= { "volosd.sh", "up", "-i", "1", NULL };
static const char *slrhcmd[]		= { "/home/ian/bin/slrh.sh", NULL };

static Key keys[] = {
	/* modifier                     key         function        argument */
	{ MODKEY,                       XK_p,		spawn,          {.v = dmenucmd } },
	{ MODKEY,			            XK_Return,  spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_p,		spawn,			{.v = mymenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,	spawn,			{.v = emacscmd } },
	{ MODKEY,                       XK_t,       spawn,          {.v = filemancmd } },
	{ MODKEY,                       XK_w,       spawn,          {.v = browsercmd } },
	{ MODKEY,						XK_b,		togglebar,		{0} },
	{ MODKEY,                       XK_j,       focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,       focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_a,       incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_z,       incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,       focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_l,       focusstack,     {.i = +1 } },
	{ MODKEY|ControlMask,           XK_h,       setmfact,       {.f = -0.05} },
	{ MODKEY|ControlMask,           XK_l,       setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,       pushdown,       {0} },
	{ MODKEY|ShiftMask,             XK_k,       pushup,         {0} },
	{ MODKEY,                       XK_Tab,		view,			{0} },
	{ MODKEY|ShiftMask,				XK_c,		killclient,		{0} },
	{ MODKEY|ShiftMask,				XK_t,		setlayout,		{.v = &layouts[0]} },
	{ MODKEY|ShiftMask,				XK_f,		setlayout,		{.v = &layouts[1]} },
	{ MODKEY|ShiftMask,				XK_b,		setlayout,		{.v = &layouts[2]} },
	{ MODKEY|ShiftMask,				XK_m,		setlayout,		{.v = &layouts[3]} },
	{ MODKEY,                       XK_space,	setlayout,		{0} },
	{ MODKEY|ShiftMask,             XK_space,	togglefloating,	{0} },
	{ MODKEY,                       XK_0,       view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,       tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,   focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,  focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,   tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,  tagmon,         {.i = +1 } },
	{ MODKEY,						XK_F10,		spawn,			{.v = voldcmd } },
	{ MODKEY,						XK_F11,		spawn,			{.v = volmcmd } },
	{ MODKEY,						XK_F12,		spawn,			{.v = volucmd } },
	{ MODKEY|ShiftMask,				XK_Escape,	spawn,			{.v = slrhcmd } },
	TAGKEYS(                        XK_1,                       0)
	TAGKEYS(                        XK_2,                       1)
	TAGKEYS(                        XK_3,                       2)
	TAGKEYS(                        XK_4,                       3)
	TAGKEYS(                        XK_5,                       4)
	TAGKEYS(                        XK_6,                       5)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkRootWin,			0,				Button2,		spawn,			{.v = mygtkmenucmd } },
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

