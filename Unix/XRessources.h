/* $Id: XRessources.h,v 1.3 2000-11-25 15:26:12 geuzaine Exp $ */

/* 
   Les resources ci-dessous sont prises en compte par defaut. Toutre 
   resource definie dans ~/.gmshrc ou dans APP_DEFAULTS/.gmshrc est 
   prioritaire

   Palette I-DEAS   R   G   B 
   background      42  71  94 
   foreground     255 232 148 
   highlight       42  71  95 
   topshadow       84 127 158 
   bottomshadow     8  12  28 

   Palette netscape   
   background              gray70
   foreground              black
   highlightColor          gray71
   XmTextField*background  MistyRose3
   XmList*background       MistyRose3
   ArrowBack*foreground    MistyRose3
*/

String FallbackResources[] = {

  /* couleurs */
  "gmshGW*background: Grey75",
  "gmshGW*borderColor: Grey75",
  "gmshGW*foreground: Black",
  "gmshGW*highlightColor: Grey76",
  
  "gmshMW*background: Grey75",
  "gmshMW*borderColor: Grey75",
  "gmshMW*foreground: Black",
  "gmshMW*XmText*background: White",
  "gmshMW*XmText*foreground: Black",
  "gmshMW*XmTextField*background: White",
  "gmshMW*XmList*background: White",
  "gmshMW*selectColor: Yellow",
  "gmshMW*highlightColor: DarkOrchid",
  
  "gmshCW*background: Grey75",
  "gmshCW*foreground: Black",
  "gmshCW*borderColor: Gray75",
  "gmshCW*XmTextField*background: Gray75",
  "gmshCW*XmList*background: Gray75",
  "gmshCW*highlightColor: Grey76",

  /* fontes */
  "*fontList: -*-helvetica-medium-r-*-*-10-*-*-*-*-*-*-*",
  "*XmTextField*fontList:  -*-helvetica-medium-r-*-*-10-*-*-*-*-*-*-*",
  "*XmList*fontList:  -*-helvetica-medium-r-*-*-10-*-*-*-*-*-*-*",
  "gmshMW*HDkeysText*fontList: fixed",
  "gmshMW*HDkeysText*XmPushButton*fontList: -*-helvetica-medium-r-*-*-10-*-*-*-*-*-*-*",
  "gmshMW*HDaboutDialog*fontList: fixed",

  /* geometrie */
  "gmshGW*geometry: 700x525+20+30",
  "gmshMW*geometry: x420+800+80",
  "gmshCW*geometry: 440x130+30+570",

  /* sizes -> compact layout */

  "*XmCascadeButton*marginWidth: 2",

  NULL };

/*
  *toolbar*XmPushButton.baseTranslations: #override\n\
  : CustomShadows(on) Arm()\n\
  :  CustomShadows(on) Enter()\n\
  :  CustomShadows(off) Leave()\n\
  : MapCheck()

  *toolbar*XmToggleButton.baseTranslations: #override\n\
  : CustomShadows(on) Arm()\n\
  : Select() Disarm() CustomShadows(check)\n\
  :  CustomShadows(on) Enter()\n\
  :  CustomShadows(off) Leave()\n\
  : MapCheck()
  */
