/* $Id: gl2gif.h,v 1.2 2000-11-23 14:11:33 geuzaine Exp $ */
#ifndef _GL2GIF_H_
#define _GL2GIF_H_

#define	GIF_ERROR	0
#define GIF_OK		1

#ifndef TRUE
#define TRUE		1
#define FALSE		0
#endif

#define VoidPtr void *

typedef	unsigned char	GifPixelType;
typedef unsigned char	GifByteType;

typedef struct GifColorType {
  GifByteType Red, Green, Blue;
} GifColorType;

typedef struct ColorMapObject{
  int	ColorCount;
  int BitsPerPixel;
  GifColorType *Colors;	 /* on malloc(3) heap */
} ColorMapObject;

typedef struct GifImageDesc {
  int Left, Top, Width, Height ; /* Current image dimensions. */
  int Interlace;		 /* Sequential/Interlaced lines. */
  ColorMapObject *ColorMap;	 /* The local color map */
} GifImageDesc;

typedef struct GifFileType {
  int SWidth, SHeight;		  /* Screen dimensions. */
  int SColorResolution; 	  /* How many colors can we generate? */
  int SBackGroundColor;		  /* I hope you understand this one... */
  ColorMapObject *SColorMap;	  /* NULL if not exists. */
  int ImageCount;		  /* Number of current image */
  GifImageDesc Image;		  /* Block describing current image */
  VoidPtr Private;	  	  /* Don't mess with this! */
} GifFileType;

typedef enum {
  UNDEFINED_RECORD_TYPE,
  SCREEN_DESC_RECORD_TYPE,
  IMAGE_DESC_RECORD_TYPE,	/* Begin with ',' */
  TERMINATE_RECORD_TYPE		/* Begin with ';' */
} GifRecordType;

#define HT_SIZE			8192	   /* 12bits = 4096 or twice as big! */
#define HT_KEY_MASK		0x1FFF			      /* 13bits keys */
#define HT_KEY_NUM_BITS		13			      /* 13bits keys */
#define HT_MAX_KEY		8191	/* 13bits - 1, maximal code possible */
#define HT_MAX_CODE		4095	/* Biggest code possible in 12 bits. */

/* The 32 bits of the long are divided into two parts for the key & code:   */
/* 1. The code is 12 bits as our compression algorithm is limited to 12bits */
/* 2. The key is 12 bits Prefix code + 8 bit new char or 20 bits.	    */
#define HT_GET_KEY(l)	(l >> 12)
#define HT_GET_CODE(l)	(l & 0x0FFF)
#define HT_PUT_KEY(l)	(l << 12)
#define HT_PUT_CODE(l)	(l & 0x0FFF)

typedef struct GifHashTableType {
  unsigned long HTable[HT_SIZE];
} GifHashTableType;

#define LZ_MAX_CODE	4095		/* Biggest code possible in 12 bits. */
#define LZ_BITS		12

#define FLUSH_OUTPUT		4096    /* Impossible code, to signal flush. */
#define FIRST_CODE		4097    /* Impossible code, to signal first. */
#define NO_SUCH_CODE		4098    /* Impossible code, to signal empty. */

#define FILE_STATE_WRITE    0x01
#define FILE_STATE_SCREEN   0x02
#define FILE_STATE_IMAGE    0x04
#define FILE_STATE_READ     0x08

#define IS_READABLE(Private)    (Private->FileState & FILE_STATE_READ)
#define IS_WRITEABLE(Private)   (Private->FileState & FILE_STATE_WRITE)

typedef struct GifFilePrivateType {
  int FileState;
  int   FileHandle;			     /* Where all this data goes to! */
  int   BitsPerPixel;	    /* Bits per pixel (Codes uses at least this + 1). */
  int   ClearCode;				       /* The CLEAR LZ code. */
  int   EOFCode;				         /* The EOF LZ code. */
  int   RunningCode;		    /* The next code algorithm can generate. */
  int   RunningBits;/* The number of bits required to represent RunningCode. */
  int   MaxCode1;  /* 1 bigger than max. possible code, in RunningBits bits. */
  int   LastCode;		        /* The code before the current code. */
  int   CrntCode;				  /* Current algorithm code. */
  int   StackPtr;		         /* For character stack (see below). */
  int   CrntShiftState;		        /* Number of bits in CrntShiftDWord. */
  unsigned long CrntShiftDWord;     /* For bytes decomposition into codes. */
  unsigned long PixelCount;		       /* Number of pixels in image. */
  FILE *File;						  /* File as stream. */
  GifByteType Buf[256];	       /* Compressed input is buffered here. */
  GifByteType Stack[LZ_MAX_CODE];	 /* Decoded pixels are stacked here. */
  GifByteType Suffix[LZ_MAX_CODE+1];	       /* So we can trace the codes. */
  int Prefix[LZ_MAX_CODE+1];
  GifHashTableType *HashTable;
} GifFilePrivateType;


#define	E_GIF_ERR_OPEN_FAILED	1		/* And EGif possible errors. */
#define	E_GIF_ERR_WRITE_FAILED	2
#define E_GIF_ERR_HAS_SCRN_DSCR	3
#define E_GIF_ERR_HAS_IMAG_DSCR	4
#define E_GIF_ERR_NO_COLOR_MAP	5
#define E_GIF_ERR_DATA_TOO_BIG	6
#define E_GIF_ERR_NOT_ENOUGH_MEM 7
#define E_GIF_ERR_DISK_IS_FULL	8
#define E_GIF_ERR_CLOSE_FAILED	9
#define E_GIF_ERR_NOT_WRITEABLE	10

/* Provate functions */

GifHashTableType *_InitHashTable(void);
void _ClearHashTable(GifHashTableType *HashTable);
void _InsertHashTable(GifHashTableType *HashTable, unsigned long Key, int Code);
int _ExistsHashTable(GifHashTableType *HashTable, unsigned long Key);

GifFileType *EGifOpenFileHandle(int GifFileHandle);
void EGifSetGifVersion(char *Version);
int EGifPutScreenDesc(GifFileType *GifFile,
		      int GifWidth, int GifHeight, int GifColorRes, int GifBackGround,
		      ColorMapObject *GifColorMap);
int EGifPutImageDesc(GifFileType *GifFile,
		     int GifLeft, int GifTop, int Width, int GifHeight, int GifInterlace,
		     ColorMapObject *GifColorMap);
int EGifPutLine(GifFileType *GifFile, GifPixelType *GifLine, int GifLineLen);
int EGifCloseFile(GifFileType *GifFile);

int QuantizeBuffer(int Width, int Height, int *ColorMapSize,
		   GifByteType *RedInput, GifByteType *GreenInput, GifByteType *BlueInput,
		   GifByteType *OutputBuffer, GifColorType *OutputColorMap);

extern void PrintGifError(void);
extern int GifLastError(void);
extern ColorMapObject *MakeMapObject(int ColorCount, GifColorType *ColorMap);
extern void FreeMapObject(ColorMapObject *Object);
extern int BitSize(int n);

/* Public functions */

void create_gif(FILE *fp, int width, int height);

#endif
