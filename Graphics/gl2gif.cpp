/*
  This file is a big hack from

  The GIFLIB distribution is Copyright (c) 1997  Eric S. Raymond

 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>

#include <GL/gl.h>
#include "gl2gif.h"

static int _GifError = 0;
static int ExpNumOfColors = 8, ColorMapSize = 256;


/******************************************************************************
* Initialize HashTable - allocate the memory needed and clear it.	      *
******************************************************************************/
GifHashTableType *_InitHashTable(void)
{
    GifHashTableType *HashTable;

    if ((HashTable = (GifHashTableType *) malloc(sizeof(GifHashTableType)))
	== NULL)
	return NULL;

    _ClearHashTable(HashTable);

    return HashTable;
}

/******************************************************************************
* Routine to clear the HashTable to an empty state.			      *
* This part is a little machine depended. Use the commented part otherwise.   *
******************************************************************************/
void _ClearHashTable(GifHashTableType *HashTable)
{
  int index = HT_SIZE;
  unsigned long* HTable = HashTable->HTable;
  while (--index>=0)
    HTable[index] = 0xfffffffful;
}

/******************************************************************************
* Routine to generate an HKey for the hashtable out of the given unique key.  *
* The given Key is assumed to be 20 bits as follows: lower 8 bits are the     *
* new postfix character, while the upper 12 bits are the prefix code.	      *
* Because the average hit ratio is only 2 (2 hash references per entry),      *
* evaluating more complex keys (such as twin prime keys) does not worth it!   *
******************************************************************************/
static int KeyItem(unsigned long Item)
{
    return ((Item >> 12) ^ Item) & HT_KEY_MASK;
}

/******************************************************************************
* Routine to insert a new Item into the HashTable. The data is assumed to be  *
* new one.								      *
******************************************************************************/
void _InsertHashTable(GifHashTableType *HashTable, unsigned long Key, int Code)
{
    int HKey = KeyItem(Key);
    unsigned long *HTable = HashTable -> HTable;

    while (HT_GET_KEY(HTable[HKey]) != 0xFFFFFL) {
	HKey = (HKey + 1) & HT_KEY_MASK;
    }
    HTable[HKey] = HT_PUT_KEY(Key) | HT_PUT_CODE(Code);
}

/******************************************************************************
* Routine to test if given Key exists in HashTable and if so returns its code *
* Returns the Code if key was found, -1 if not.				      *
******************************************************************************/
int _ExistsHashTable(GifHashTableType *HashTable, unsigned long Key)
{
    int HKey = KeyItem(Key);
    unsigned long *HTable = HashTable -> HTable, HTKey;

    while ((HTKey = HT_GET_KEY(HTable[HKey])) != 0xFFFFFL) {
	if (Key == HTKey) return HT_GET_CODE(HTable[HKey]);
	HKey = (HKey + 1) & HT_KEY_MASK;
    }

    return -1;
}

/******************************************************************************
* Miscellaneous utility functions					      *
******************************************************************************/

int BitSize(int n)
/* return smallest bitfield size n will fit in */
{
    register int i;

    for (i = 1; i <= 8; i++)
	if ((1 << i) >= n)
	    break;
    return(i);
}


/******************************************************************************
* Color map object functions						      *
******************************************************************************/

ColorMapObject *MakeMapObject(int ColorCount, GifColorType *ColorMap)
{
    ColorMapObject *Object;

    if (ColorCount != (1 << BitSize(ColorCount))){
      printf("Arrrrrgggg\n");
      return((ColorMapObject *)NULL);
    }

    Object = (ColorMapObject *)malloc(sizeof(ColorMapObject));
    if (Object == (ColorMapObject *)NULL)
	return((ColorMapObject *)NULL);

    Object->Colors = (GifColorType *)calloc(ColorCount, sizeof(GifColorType));
    if (Object->Colors == (GifColorType *)NULL)
	return((ColorMapObject *)NULL);

    Object->ColorCount = ColorCount;
    Object->BitsPerPixel = BitSize(ColorCount);

    if (ColorMap)
	memcpy((char *)Object->Colors,
	       (char *)ColorMap, ColorCount * sizeof(GifColorType));

    return(Object);
}

void FreeMapObject(ColorMapObject *Object)
{
    free(Object->Colors);
    free(Object);
}

/*****************************************************************************
* Print the last GIF error to stderr.					     *
*****************************************************************************/
void PrintGifError(void)
{
    char *Err;

    switch(_GifError) {
	case E_GIF_ERR_OPEN_FAILED:
	    Err = "Failed to open given file";
	    break;
	case E_GIF_ERR_WRITE_FAILED:
	    Err = "Failed to Write to given file";
	    break;
	case E_GIF_ERR_HAS_SCRN_DSCR:
	    Err = "Screen Descriptor already been set";
	    break;
	case E_GIF_ERR_HAS_IMAG_DSCR:
	    Err = "Image Descriptor is still active";
	    break;
	case E_GIF_ERR_NO_COLOR_MAP:
	    Err = "Neither Global Nor Local color map";
	    break;
	case E_GIF_ERR_DATA_TOO_BIG:
	    Err = "#Pixels bigger than Width * Height";
	    break;
	case E_GIF_ERR_NOT_ENOUGH_MEM:
	    Err = "Fail to allocate required memory";
	    break;
	case E_GIF_ERR_DISK_IS_FULL:
	    Err = "Write failed (disk full?)";
	    break;
	case E_GIF_ERR_CLOSE_FAILED:
	    Err = "Failed to close given file";
	    break;
	case E_GIF_ERR_NOT_WRITEABLE:
	    Err = "Given file was not opened for write";
	    break;
	default:
	    Err = NULL;
	    break;
    }
    if (Err != NULL)
	fprintf(stderr, "Error: %s\n", Err);
    else
	fprintf(stderr, "Error: GIF undefined error %d\n", _GifError);
}

#define ABS(x)	((x) > 0 ? (x) : (-(x)))

#define COLOR_ARRAY_SIZE 32768
#define BITS_PER_PRIM_COLOR 5
#define MAX_PRIM_COLOR      0x1f

static int SortRGBAxis;

typedef struct QuantizedColorType {
    GifByteType RGB[3];
    GifByteType NewColorIndex;
    long Count;
    struct QuantizedColorType *Pnext;
} QuantizedColorType;

typedef struct NewColorMapType {
    GifByteType RGBMin[3], RGBWidth[3];
    int NumEntries;    /* # of QuantizedColorType in linked list below. */
    long Count;        /* Total number of pixels in all the entries. */
    QuantizedColorType *QuantizedColors;
} NewColorMapType;

static int SubdivColorMap(NewColorMapType *NewColorSubdiv,
			  int ColorMapSize,
			  int *NewColorMapSize);
static int SortCmpRtn(const VoidPtr Entry1, const VoidPtr Entry2);

/******************************************************************************
* Quantize high resolution image into lower one. Input image consists of a    *
* 2D array for each of the RGB colors with size Width by Height. There is no  *
* Color map for the input. Output is a quantized image with 2D array of       *
* indexes into the output color map.					      *
*   Note input image can be 24 bits at the most (8 for red/green/blue) and    *
* the output has 256 colors at the most (256 entries in the color map.).      *
* ColorMapSize specifies size of color map up to 256 and will be updated to   *
* real size before returning.						      *
*   Also non of the parameter are allocated by this routine.		      *
*   This function returns GIF_OK if succesfull, GIF_ERROR otherwise.	      *
******************************************************************************/
int QuantizeBuffer(int Width, int Height, int *ColorMapSize,
	GifByteType *RedInput, GifByteType *GreenInput, GifByteType *BlueInput,
	GifByteType *OutputBuffer, GifColorType *OutputColorMap)
{
    int Index, NumOfEntries;
    int i, j, MaxRGBError[3];
    int NewColorMapSize;
    long Red, Green, Blue;
    NewColorMapType NewColorSubdiv[256];
    QuantizedColorType *ColorArrayEntries, *QuantizedColor;

    if ((ColorArrayEntries = (QuantizedColorType *)
	    malloc(sizeof(QuantizedColorType) * COLOR_ARRAY_SIZE)) == NULL) {
	_GifError = E_GIF_ERR_NOT_ENOUGH_MEM;
	return GIF_ERROR;
    }

    for (i = 0; i < COLOR_ARRAY_SIZE; i++) {
	ColorArrayEntries[i].RGB[0]= i >> (2 * BITS_PER_PRIM_COLOR);
	ColorArrayEntries[i].RGB[1] = (i >> BITS_PER_PRIM_COLOR) &
	    						MAX_PRIM_COLOR;
	ColorArrayEntries[i].RGB[2] = i & MAX_PRIM_COLOR;
	ColorArrayEntries[i].Count = 0;
    }

    /* Sample the colors and their distribution: */
    for (i = 0; i < (int)(Width * Height); i++) {
	Index = ((RedInput[i] >> (8 - BITS_PER_PRIM_COLOR))
		    << (2 * BITS_PER_PRIM_COLOR)) +
		((GreenInput[i] >> (8 - BITS_PER_PRIM_COLOR))
		    << BITS_PER_PRIM_COLOR) +
		(BlueInput[i] >> (8 - BITS_PER_PRIM_COLOR));
	ColorArrayEntries[Index].Count++;
    }

    /* Put all the colors in the first entry of the color map, and call the  */
    /* recursive subdivision process.					     */
    for (i = 0; i < 256; i++) {
	NewColorSubdiv[i].QuantizedColors = NULL;
	NewColorSubdiv[i].Count = NewColorSubdiv[i].NumEntries = 0;
	for (j = 0; j < 3; j++) {
	    NewColorSubdiv[i].RGBMin[j] = 0;
	    NewColorSubdiv[i].RGBWidth[j] = 255;
	}
    }

    /* Find the non empty entries in the color table and chain them: */
    for (i = 0; i < COLOR_ARRAY_SIZE; i++)
	if (ColorArrayEntries[i].Count > 0) break;
    QuantizedColor = NewColorSubdiv[0].QuantizedColors = &ColorArrayEntries[i];
    NumOfEntries = 1;
    while (++i < COLOR_ARRAY_SIZE)
	if (ColorArrayEntries[i].Count > 0) {
	    QuantizedColor -> Pnext = &ColorArrayEntries[i];
	    QuantizedColor = &ColorArrayEntries[i];
	    NumOfEntries++;
	}
    QuantizedColor -> Pnext = NULL;

    NewColorSubdiv[0].NumEntries = NumOfEntries;/* Different sampled colors. */
    NewColorSubdiv[0].Count = ((long) Width) * Height;            /* Pixels. */
    NewColorMapSize = 1;
    if (SubdivColorMap(NewColorSubdiv, *ColorMapSize, &NewColorMapSize) !=
								     GIF_OK) {
	free((char *) ColorArrayEntries);
	return GIF_ERROR;
    }
    if (NewColorMapSize < *ColorMapSize) {
	/* And clear rest of color map: */
	for (i = NewColorMapSize; i < *ColorMapSize; i++)
	    OutputColorMap[i].Red =
	    OutputColorMap[i].Green =
	    OutputColorMap[i].Blue = 0;
    }

    /* Average the colors in each entry to be the color to be used in the    */
    /* output color map, and plug it into the output color map itself.       */
    for (i = 0; i < NewColorMapSize; i++) {
	if ((j = NewColorSubdiv[i].NumEntries) > 0) {
	    QuantizedColor = NewColorSubdiv[i].QuantizedColors;
	    Red = Green = Blue = 0;
	    while (QuantizedColor) {
		QuantizedColor -> NewColorIndex = i;
		Red += QuantizedColor -> RGB[0];
		Green += QuantizedColor -> RGB[1];
		Blue += QuantizedColor -> RGB[2];
		QuantizedColor = QuantizedColor -> Pnext;
	    }
	    OutputColorMap[i].Red = (Red << (8 - BITS_PER_PRIM_COLOR)) / j;
	    OutputColorMap[i].Green = (Green << (8 - BITS_PER_PRIM_COLOR)) / j;
	    OutputColorMap[i].Blue= (Blue << (8 - BITS_PER_PRIM_COLOR)) / j;
	}
	else
	    fprintf(stderr, "Warning, Null entry in quantized color map - that's weird\n");
    }

    /* Finally scan the input buffer again and put the mapped index in the   */
    /* output buffer.							     */
    MaxRGBError[0] = MaxRGBError[1] = MaxRGBError[2] = 0;
    for (i = 0; i < (int)(Width * Height); i++) {
	Index = ((RedInput[i] >> (8 - BITS_PER_PRIM_COLOR))
		    << (2 * BITS_PER_PRIM_COLOR)) +
		((GreenInput[i] >> (8 - BITS_PER_PRIM_COLOR))
		    << BITS_PER_PRIM_COLOR) +
		(BlueInput[i] >> (8 - BITS_PER_PRIM_COLOR));
	Index = ColorArrayEntries[Index].NewColorIndex;
	OutputBuffer[i] = Index;
	if (MaxRGBError[0] < ABS(OutputColorMap[Index].Red - RedInput[i]))
	    MaxRGBError[0] = ABS(OutputColorMap[Index].Red - RedInput[i]);
	if (MaxRGBError[1] < ABS(OutputColorMap[Index].Green - GreenInput[i]))
	    MaxRGBError[1] = ABS(OutputColorMap[Index].Green - GreenInput[i]);
	if (MaxRGBError[2] < ABS(OutputColorMap[Index].Blue - BlueInput[i]))
	    MaxRGBError[2] = ABS(OutputColorMap[Index].Blue - BlueInput[i]);
    }

    free((char *) ColorArrayEntries);

    *ColorMapSize = NewColorMapSize;

    return GIF_OK;
}

/******************************************************************************
* Routine to subdivide the RGB space recursively using median cut in each     *
* axes alternatingly until ColorMapSize different cubes exists.		      *
* The biggest cube in one dimension is subdivide unless it has only one entry.*
* Returns GIF_ERROR if failed, otherwise GIF_OK.			      *
******************************************************************************/
static int SubdivColorMap(NewColorMapType *NewColorSubdiv,
			  int ColorMapSize,
			  int *NewColorMapSize)
{
    int MaxSize;
    int i, j, Index = 0, NumEntries, MinColor, MaxColor;
    long Sum, Count;
    QuantizedColorType *QuantizedColor, **SortArray;

    while (ColorMapSize > *NewColorMapSize) {
	/* Find candidate for subdivision: */
	MaxSize = -1;
	for (i = 0; i < *NewColorMapSize; i++) {
	    for (j = 0; j < 3; j++) {
		if (((int) NewColorSubdiv[i].RGBWidth[j]) > MaxSize &&
		    NewColorSubdiv[i].NumEntries > 1) {
		    MaxSize = NewColorSubdiv[i].RGBWidth[j];
		    Index = i;
		    SortRGBAxis = j;
		}
	    }
	}

	if (MaxSize == -1)
	    return GIF_OK;

	/* Split the entry Index into two along the axis SortRGBAxis: */

	/* Sort all elements in that entry along the given axis and split at */
	/* the median.							     */
	if ((SortArray = (QuantizedColorType **)
	    malloc(sizeof(QuantizedColorType *) *
		   NewColorSubdiv[Index].NumEntries)) == NULL)
    	    return GIF_ERROR;
	for (j = 0, QuantizedColor = NewColorSubdiv[Index].QuantizedColors;
	     j < NewColorSubdiv[Index].NumEntries && QuantizedColor != NULL;
	     j++, QuantizedColor = QuantizedColor -> Pnext)
	    SortArray[j] = QuantizedColor;
	qsort(SortArray, NewColorSubdiv[Index].NumEntries,
	      sizeof(QuantizedColorType *), SortCmpRtn);

	/* Relink the sorted list into one: */
	for (j = 0; j < NewColorSubdiv[Index].NumEntries - 1; j++)
	    SortArray[j] -> Pnext = SortArray[j + 1];
	SortArray[NewColorSubdiv[Index].NumEntries - 1] -> Pnext = NULL;
	NewColorSubdiv[Index].QuantizedColors = QuantizedColor = SortArray[0];
	free((char *) SortArray);

	/* Now simply add the Counts until we have half of the Count: */
	Sum = NewColorSubdiv[Index].Count / 2 - QuantizedColor -> Count;
	NumEntries = 1;
	Count = QuantizedColor -> Count;
	while ((Sum -= QuantizedColor -> Pnext -> Count) >= 0 &&
	       QuantizedColor -> Pnext != NULL &&
	       QuantizedColor -> Pnext -> Pnext != NULL) {
	    QuantizedColor = QuantizedColor -> Pnext;
	    NumEntries++;
	    Count += QuantizedColor -> Count;
	}
	/* Save the values of the last color of the first half, and first    */
	/* of the second half so we can update the Bounding Boxes later.     */
	/* Also as the colors are quantized and the BBoxes are full 0..255,  */
	/* they need to be rescaled.					     */
	MaxColor = QuantizedColor -> RGB[SortRGBAxis];/* Max. of first half. */
	MinColor = QuantizedColor -> Pnext -> RGB[SortRGBAxis];/* of second. */
	MaxColor <<= (8 - BITS_PER_PRIM_COLOR);
	MinColor <<= (8 - BITS_PER_PRIM_COLOR);

	/* Partition right here: */
	NewColorSubdiv[*NewColorMapSize].QuantizedColors =
	    QuantizedColor -> Pnext;
	QuantizedColor -> Pnext = NULL;
	NewColorSubdiv[*NewColorMapSize].Count = Count;
	NewColorSubdiv[Index].Count -= Count;
	NewColorSubdiv[*NewColorMapSize].NumEntries =
	    NewColorSubdiv[Index].NumEntries - NumEntries;
	NewColorSubdiv[Index].NumEntries = NumEntries;
	for (j = 0; j < 3; j++) {
	    NewColorSubdiv[*NewColorMapSize].RGBMin[j] =
		NewColorSubdiv[Index].RGBMin[j];
	    NewColorSubdiv[*NewColorMapSize].RGBWidth[j] =
		NewColorSubdiv[Index].RGBWidth[j];
	}
	NewColorSubdiv[*NewColorMapSize].RGBWidth[SortRGBAxis] =
	    NewColorSubdiv[*NewColorMapSize].RGBMin[SortRGBAxis] +
	    NewColorSubdiv[*NewColorMapSize].RGBWidth[SortRGBAxis] -
	    MinColor;
	NewColorSubdiv[*NewColorMapSize].RGBMin[SortRGBAxis] = MinColor;

	NewColorSubdiv[Index].RGBWidth[SortRGBAxis] =
	    MaxColor - NewColorSubdiv[Index].RGBMin[SortRGBAxis];

	(*NewColorMapSize)++;
    }

    return GIF_OK;
}

/******************************************************************************
* Routine called by qsort to compare to entries.			      *
******************************************************************************/
static int SortCmpRtn(const VoidPtr Entry1, const VoidPtr Entry2)
{
    return (* ((QuantizedColorType **) Entry1)) -> RGB[SortRGBAxis] -
	   (* ((QuantizedColorType **) Entry2)) -> RGB[SortRGBAxis];
}

#define GIF87_STAMP	"GIF87a"         /* First chars in file - GIF stamp. */
#define GIF89_STAMP	"GIF89a"         /* First chars in file - GIF stamp. */

/* Masks given codes to BitsPerPixel, to make sure all codes are in range: */
static GifPixelType CodeMask[] = {
    0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff
};

static char *GifVersionPrefix = GIF87_STAMP;

#define WRITE(_gif,_buf,_len)   \
   fwrite(_buf, 1, _len, ((GifFilePrivateType*)_gif->Private)->File)

static int EGifPutWord(int Word, GifFileType *GifFile);
static int EGifSetupCompress(GifFileType *GifFile);
static int EGifCompressLine(GifFileType *GifFile, GifPixelType *Line,
								int LineLen);
static int EGifCompressOutput(GifFileType *GifFile, int Code);
static int EGifBufferedOutput(GifFileType *GifFile, GifByteType *Buf, int c);

/******************************************************************************
*   Update a new gif file, given its file handle, which must be opened for    *
* write in binary mode.							      *
*   Returns GifFileType pointer dynamically allocated which serves as the gif *
* info record. _GifError is cleared if succesfull.			      *
******************************************************************************/
GifFileType *EGifOpenFileHandle(FILE *f, int FileHandle)
{
    GifFileType *GifFile;
    GifFilePrivateType *Private;

    if ((GifFile = (GifFileType *) malloc(sizeof(GifFileType))) == NULL) {
        _GifError = E_GIF_ERR_NOT_ENOUGH_MEM;
        return NULL;
    }

    memset(GifFile, '\0', sizeof(GifFileType));

    if ((Private = (GifFilePrivateType *)
                   malloc(sizeof(GifFilePrivateType))) == NULL) {
        free(GifFile);
        _GifError = E_GIF_ERR_NOT_ENOUGH_MEM;
        return NULL;
    }
    if ((Private->HashTable = _InitHashTable()) == NULL) {
        free(GifFile);
        free(Private);
        _GifError = E_GIF_ERR_NOT_ENOUGH_MEM;
        return NULL;
    }

    GifFile->Private = (VoidPtr) Private;
    Private->FileHandle = FileHandle;
    Private->File = f;
    Private->FileState = FILE_STATE_WRITE;
    
    _GifError = 0;

    return GifFile;
}

/******************************************************************************
*   Routine to set current GIF version. All files open for write will be      *
* using this version until next call to this routine. Version consists of     *
* 3 characters as "87a" or "89a". No test is made to validate the version.    *
******************************************************************************/
void EGifSetGifVersion(char *Version)
{
    strncpy(&GifVersionPrefix[3], Version, 3);
}

/******************************************************************************
*   This routine should be called before any other EGif calls, immediately    *
* follows the GIF file openning.					      *
******************************************************************************/
int EGifPutScreenDesc(GifFileType *GifFile,
	int Width, int Height, int ColorRes, int BackGround,
	ColorMapObject *ColorMap)
{
    int i;
    GifByteType Buf[3];
    GifFilePrivateType *Private = (GifFilePrivateType *) GifFile->Private;

    if (Private->FileState & FILE_STATE_SCREEN) {
	/* If already has screen descriptor - something is wrong! */
	_GifError = E_GIF_ERR_HAS_SCRN_DSCR;
	return GIF_ERROR;
    }
    if (!IS_WRITEABLE(Private)) {
	/* This file was NOT open for writing: */
	_GifError = E_GIF_ERR_NOT_WRITEABLE;
	return GIF_ERROR;
    }

    /* First write the version prefix into the file. */
    if (WRITE(GifFile, GifVersionPrefix, strlen(GifVersionPrefix)) != strlen(GifVersionPrefix)) {
	_GifError = E_GIF_ERR_WRITE_FAILED;
	return GIF_ERROR;
    }

    GifFile->SWidth = Width;
    GifFile->SHeight = Height;
    GifFile->SColorResolution = ColorRes;
    GifFile->SBackGroundColor = BackGround;
    if(ColorMap)
      GifFile->SColorMap=MakeMapObject(ColorMap->ColorCount,ColorMap->Colors);
    else
      GifFile->SColorMap=NULL;

    /* Put the screen descriptor into the file: */
    EGifPutWord(Width, GifFile);
    EGifPutWord(Height, GifFile);
    Buf[0] = (ColorMap ? 0x80 : 0x00) |
	     ((ColorRes - 1) << 4) |
	     (ColorMap->BitsPerPixel - 1);
    Buf[1] = BackGround;
    Buf[2] = 0;
    WRITE(GifFile, Buf, 3);

    /* If we have Global color map - dump it also: */
    if (ColorMap != NULL)
	for (i = 0; i < ColorMap->ColorCount; i++) {
	    /* Put the ColorMap out also: */
	    Buf[0] = ColorMap->Colors[i].Red;
	    Buf[1] = ColorMap->Colors[i].Green;
	    Buf[2] = ColorMap->Colors[i].Blue;
	    if (WRITE(GifFile, Buf, 3) != 3) {
	        _GifError = E_GIF_ERR_WRITE_FAILED;
		return GIF_ERROR;
	    }
	}

    /* Mark this file as has screen descriptor, and no pixel written yet: */
    Private->FileState |= FILE_STATE_SCREEN;

    return GIF_OK;
}

/******************************************************************************
*   This routine should be called before any attemp to dump an image - any    *
* call to any of the pixel dump routines.				      *
******************************************************************************/
int EGifPutImageDesc(GifFileType *GifFile,
	int Left, int Top, int Width, int Height, int Interlace,
	ColorMapObject *ColorMap)
{
    int i;
    GifByteType Buf[3];
    GifFilePrivateType *Private = (GifFilePrivateType *) GifFile->Private;

    if (Private->FileState & FILE_STATE_IMAGE &&
#if defined(__GNUC__)
	Private->PixelCount > 0xffff0000UL) {
#else
	Private->PixelCount > 0xffff0000) {
#endif
	/* If already has active image descriptor - something is wrong! */
	_GifError = E_GIF_ERR_HAS_IMAG_DSCR;
	return GIF_ERROR;
    }
    if (!IS_WRITEABLE(Private)) {
	/* This file was NOT open for writing: */
	_GifError = E_GIF_ERR_NOT_WRITEABLE;
	return GIF_ERROR;
    }
    GifFile->Image.Left = Left;
    GifFile->Image.Top = Top;
    GifFile->Image.Width = Width;
    GifFile->Image.Height = Height;
    GifFile->Image.Interlace = Interlace;
    if(ColorMap)
      GifFile->Image.ColorMap =MakeMapObject(ColorMap->ColorCount,ColorMap->Colors);
    else
      GifFile->Image.ColorMap = NULL;

    /* Put the image descriptor into the file: */
    Buf[0] = ',';			       /* Image seperator character. */
    WRITE(GifFile, Buf, 1);
    EGifPutWord(Left, GifFile);
    EGifPutWord(Top, GifFile);
    EGifPutWord(Width, GifFile);
    EGifPutWord(Height, GifFile);
    Buf[0] = (ColorMap ? 0x80 : 0x00) |
	  (Interlace ? 0x40 : 0x00) |
	  (ColorMap ? ColorMap->BitsPerPixel - 1 : 0);
    WRITE(GifFile, Buf, 1);

    /* If we have Global color map - dump it also: */
    if (ColorMap != NULL)
	for (i = 0; i < ColorMap->ColorCount; i++) {
	    /* Put the ColorMap out also: */
	    Buf[0] = ColorMap->Colors[i].Red;
	    Buf[1] = ColorMap->Colors[i].Green;
	    Buf[2] = ColorMap->Colors[i].Blue;
	    if (WRITE(GifFile, Buf, 3) != 3) {
	        _GifError = E_GIF_ERR_WRITE_FAILED;
		return GIF_ERROR;
	    }
	}
    if (GifFile->SColorMap == NULL && GifFile->Image.ColorMap == NULL)
    {
	_GifError = E_GIF_ERR_NO_COLOR_MAP;
	return GIF_ERROR;
    }

    /* Mark this file as has screen descriptor: */
    Private->FileState |= FILE_STATE_IMAGE;
    Private->PixelCount = (long) Width * (long) Height;

    EGifSetupCompress(GifFile);      /* Reset compress algorithm parameters. */

    return GIF_OK;
}

/******************************************************************************
*  Put one full scanned line (Line) of length LineLen into GIF file.	      *
******************************************************************************/
int EGifPutLine(GifFileType *GifFile, GifPixelType *Line, int LineLen)
{
    int i;
    GifPixelType Mask;
    GifFilePrivateType *Private = (GifFilePrivateType *) GifFile->Private;

    if (!IS_WRITEABLE(Private)) {
	/* This file was NOT open for writing: */
	_GifError = E_GIF_ERR_NOT_WRITEABLE;
	return GIF_ERROR;
    }

    if (!LineLen)
      LineLen = GifFile->Image.Width;
    if (Private->PixelCount < (unsigned)LineLen) {
	_GifError = E_GIF_ERR_DATA_TOO_BIG;
	return GIF_ERROR;
    }
    Private->PixelCount -= LineLen;

    /* Make sure the codes are not out of bit range, as we might generate    */
    /* wrong code (because of overflow when we combine them) in this case:   */
    Mask = CodeMask[Private->BitsPerPixel];
    for (i = 0; i < LineLen; i++) Line[i] &= Mask;

    return EGifCompressLine(GifFile, Line, LineLen);
}

/******************************************************************************
*   This routine should be called last, to close GIF file.		      *
******************************************************************************/
int EGifCloseFile(GifFileType *GifFile)
{
    GifByteType Buf;
    GifFilePrivateType *Private;

    if (GifFile == NULL) return GIF_ERROR;

    Private = (GifFilePrivateType *) GifFile->Private;
    if (!IS_WRITEABLE(Private)) {
	/* This file was NOT open for writing: */
	_GifError = E_GIF_ERR_NOT_WRITEABLE;
	return GIF_ERROR;
    }

    Buf = ';';
    WRITE(GifFile, &Buf, 1);

    if (GifFile->Image.ColorMap)
	FreeMapObject(GifFile->Image.ColorMap);
    if (GifFile->SColorMap)
	FreeMapObject(GifFile->SColorMap);
    if (Private) {
        if (Private->HashTable) free((char *) Private->HashTable);
	    free((char *) Private);
    }
    free(GifFile);
    return GIF_OK;
}

/******************************************************************************
*   Put 2 bytes (word) into the given file:				      *
******************************************************************************/
static int EGifPutWord(int Word, GifFileType *GifFile)
{
    char c[2];

    c[0] = Word & 0xff;
    c[1] = (Word >> 8) & 0xff;
    if (WRITE(GifFile, c, 2) == 2)
	return GIF_OK;
    else
	return GIF_ERROR;
}

/******************************************************************************
*   Setup the LZ compression for this image:				      *
******************************************************************************/
static int EGifSetupCompress(GifFileType *GifFile)
{
    int BitsPerPixel;
    GifByteType Buf;
    GifFilePrivateType *Private = (GifFilePrivateType *) GifFile->Private;

    /* Test and see what color map to use, and from it # bits per pixel: */
    if (GifFile->Image.ColorMap)
	BitsPerPixel = GifFile->Image.ColorMap->BitsPerPixel;
    else if (GifFile->SColorMap)
	BitsPerPixel = GifFile->SColorMap->BitsPerPixel;
    else {
	_GifError = E_GIF_ERR_NO_COLOR_MAP;
	return GIF_ERROR;
    }

    Buf = BitsPerPixel = (BitsPerPixel < 2 ? 2 : BitsPerPixel);
    WRITE(GifFile, &Buf, 1);     /* Write the Code size to file. */

    Private->Buf[0] = 0;			  /* Nothing was output yet. */
    Private->BitsPerPixel = BitsPerPixel;
    Private->ClearCode = (1 << BitsPerPixel);
    Private->EOFCode = Private->ClearCode + 1;
    Private->RunningCode = Private->EOFCode + 1;
    Private->RunningBits = BitsPerPixel + 1;	 /* Number of bits per code. */
    Private->MaxCode1 = 1 << Private->RunningBits;	   /* Max. code + 1. */
    Private->CrntCode = FIRST_CODE;	   /* Signal that this is first one! */
    Private->CrntShiftState = 0;      /* No information in CrntShiftDWord. */
    Private->CrntShiftDWord = 0;

   /* Clear hash table and send Clear to make sure the decoder do the same. */
    _ClearHashTable(Private->HashTable);

    if (EGifCompressOutput(GifFile, Private->ClearCode) == GIF_ERROR) {
	_GifError = E_GIF_ERR_DISK_IS_FULL;
	return GIF_ERROR;
    }
    return GIF_OK;
}

/******************************************************************************
*   The LZ compression routine:						      *
*   This version compress the given buffer Line of length LineLen.	      *
*   This routine can be called few times (one per scan line, for example), in *
* order the complete the whole image.					      *
******************************************************************************/
static int EGifCompressLine(GifFileType *GifFile, GifPixelType *Line,
								int LineLen)
{
    int i = 0, CrntCode, NewCode;
    unsigned long NewKey;
    GifPixelType Pixel;
    GifHashTableType *HashTable;
    GifFilePrivateType *Private = (GifFilePrivateType *) GifFile->Private;

    HashTable = Private->HashTable;

    if (Private->CrntCode == FIRST_CODE)		  /* Its first time! */
	CrntCode = Line[i++];
    else
        CrntCode = Private->CrntCode;     /* Get last code in compression. */

    while (i < LineLen) {			    /* Decode LineLen items. */
	Pixel = Line[i++];		      /* Get next pixel from stream. */
       /* Form a new unique key to search hash table for the code combines  */
       /* CrntCode as Prefix string with Pixel as postfix char.             */
       NewKey = (((unsigned long) CrntCode) << 8) + Pixel;
       if ((NewCode = _ExistsHashTable(HashTable, NewKey)) >= 0) {
           /* This Key is already there, or the string is old one, so       */
           /* simple take new code as our CrntCode:                         */
           CrntCode = NewCode;
       }
       else {
           /* Put it in hash table, output the prefix code, and make our    */
           /* CrntCode equal to Pixel.                                      */
           if (EGifCompressOutput(GifFile, CrntCode)
               == GIF_ERROR) {
               _GifError = E_GIF_ERR_DISK_IS_FULL;
               return GIF_ERROR;
           }
           CrntCode = Pixel;

           /* If however the HashTable if full, we send a clear first and   */
           /* Clear the hash table.                                         */
           if (Private->RunningCode >= LZ_MAX_CODE) {
               /* Time to do some clearance: */
               if (EGifCompressOutput(GifFile, Private->ClearCode)
                   == GIF_ERROR) {
                   _GifError = E_GIF_ERR_DISK_IS_FULL;
                   return GIF_ERROR;
               }
               Private->RunningCode = Private->EOFCode + 1;
               Private->RunningBits = Private->BitsPerPixel + 1;
               Private->MaxCode1 = 1 << Private->RunningBits;
               _ClearHashTable(HashTable);
           }
           else {
               /* Put this unique key with its relative Code in hash table: */
               _InsertHashTable(HashTable, NewKey, Private->RunningCode++);
           }
       }

    }

    /* Preserve the current state of the compression algorithm: */
    Private->CrntCode = CrntCode;

    if (Private->PixelCount == 0)
    {
	/* We are done - output last Code and flush output buffers: */
	if (EGifCompressOutput(GifFile, CrntCode)
	    == GIF_ERROR) {
	    _GifError = E_GIF_ERR_DISK_IS_FULL;
	    return GIF_ERROR;
	}
	if (EGifCompressOutput(GifFile, Private->EOFCode)
	    == GIF_ERROR) {
	    _GifError = E_GIF_ERR_DISK_IS_FULL;
	    return GIF_ERROR;
	}
	if (EGifCompressOutput(GifFile, FLUSH_OUTPUT) == GIF_ERROR) {
	    _GifError = E_GIF_ERR_DISK_IS_FULL;
	    return GIF_ERROR;
	}
    }

    return GIF_OK;
}

/******************************************************************************
*   The LZ compression output routine:                                        *
*   This routine is responsible for the compression of the bit stream into    *
*   8 bits (bytes) packets.                                                   *
*   Returns GIF_OK if written succesfully.                                    *
******************************************************************************/
static int EGifCompressOutput(GifFileType *GifFile, int Code)
{
    GifFilePrivateType *Private = (GifFilePrivateType *)GifFile->Private;
    int retval = GIF_OK;

    if (Code == FLUSH_OUTPUT) {
	while (Private->CrntShiftState > 0) {
	    /* Get Rid of what is left in DWord, and flush it. */
	    if (EGifBufferedOutput(GifFile, Private->Buf,
		Private->CrntShiftDWord & 0xff) == GIF_ERROR)
		    retval = GIF_ERROR;
	    Private->CrntShiftDWord >>= 8;
	    Private->CrntShiftState -= 8;
	}
	Private->CrntShiftState = 0;			   /* For next time. */
	if (EGifBufferedOutput(GifFile, Private->Buf,
	    FLUSH_OUTPUT) == GIF_ERROR)
    	        retval = GIF_ERROR;
    }
    else {
	Private->CrntShiftDWord |= ((long) Code) << Private->CrntShiftState;
	Private->CrntShiftState += Private->RunningBits;
	while (Private->CrntShiftState >= 8) {
	    /* Dump out full bytes: */
	    if (EGifBufferedOutput(GifFile, Private->Buf,
		Private->CrntShiftDWord & 0xff) == GIF_ERROR)
		    retval = GIF_ERROR;
	    Private->CrntShiftDWord >>= 8;
	    Private->CrntShiftState -= 8;
	}
    }

    /* If code cannt fit into RunningBits bits, must raise its size. Note */
    /* however that codes above 4095 are used for special signaling.      */
    if (Private->RunningCode >= Private->MaxCode1 && Code <= 4095) {
       Private->MaxCode1 = 1 << ++Private->RunningBits;
    }

    return retval;
}

/******************************************************************************
*   This routines buffers the given characters until 255 characters are ready *
* to be output. If Code is equal to -1 the buffer is flushed (EOF).	      *
*   The buffer is Dumped with first byte as its size, as GIF format requires. *
*   Returns GIF_OK if written succesfully.				      *
******************************************************************************/
static int EGifBufferedOutput(GifFileType *GifFile, GifByteType *Buf, int c)
{
    if (c == FLUSH_OUTPUT) {
	/* Flush everything out. */
	if (Buf[0] != 0 && WRITE(GifFile, Buf, Buf[0]+1) != (unsigned)(Buf[0] + 1))
	{
	    _GifError = E_GIF_ERR_WRITE_FAILED;
	    return GIF_ERROR;
	}
	/* Mark end of compressed data, by an empty block (see GIF doc): */
	Buf[0] = 0;
	if (WRITE(GifFile, Buf, 1) != 1)
	{
	    _GifError = E_GIF_ERR_WRITE_FAILED;
	    return GIF_ERROR;
	}
    }
    else {
	if (Buf[0] == 255) {
	    /* Dump out this buffer - it is full: */
	    if (WRITE(GifFile, Buf, Buf[0] + 1) != (unsigned)(Buf[0] + 1))
	    {
		_GifError = E_GIF_ERR_WRITE_FAILED;
		return GIF_ERROR;
	    }
	    Buf[0] = 0;
	}
	Buf[++Buf[0]] = c;
    }

    return GIF_OK;
}

static void QuitGifError(GifFileType *GifFile)
{
  PrintGifError();
  if (GifFile != NULL) EGifCloseFile(GifFile);
}

static void SaveGif(FILE *fp,
		    GifByteType *OutputBuffer,
		    ColorMapObject *OutputColorMap,
		    int ExpColorMapSize, int Width, int Height){
  int i;
  GifFileType *GifFile;
  GifByteType *Ptr;

  if ((GifFile = EGifOpenFileHandle(fp, 1)) == NULL){
    QuitGifError(GifFile);
    return;
  }

  if (EGifPutScreenDesc(GifFile, Width, Height, ExpColorMapSize, 0, OutputColorMap) == GIF_ERROR){
    QuitGifError(GifFile);
    return;
  }

  if (EGifPutImageDesc(GifFile, 0, 0, Width, Height, FALSE, NULL) == GIF_ERROR){
    QuitGifError(GifFile);
    return;
  }

  Ptr = &OutputBuffer[(Height-1)*Width] ;
  for (i = 0; i < Height; i++) {
    if (EGifPutLine(GifFile, Ptr, Width) == GIF_ERROR){
      QuitGifError(GifFile);
      return;
    }
    Ptr -= Width;
  }

  if (EGifCloseFile(GifFile) == GIF_ERROR)
    QuitGifError(GifFile);
}

void create_gif(FILE *fp, int width, int height){
  GifByteType *RedBuffer, *GreenBuffer, *BlueBuffer, *OutputBuffer = NULL;
  ColorMapObject *OutputColorMap = NULL;

  _GifError = 0;
  ExpNumOfColors = 8;
  ColorMapSize = 256;
  
  RedBuffer = (unsigned char *)malloc(height*width*sizeof(unsigned char));
  GreenBuffer = (unsigned char *)malloc(height*width*sizeof(unsigned char));
  BlueBuffer = (unsigned char *)malloc(height*width*sizeof(unsigned char));

  if(!RedBuffer || !GreenBuffer || !BlueBuffer){
    fprintf(stderr, "Error: Failed to allocate memory for RGB Buffers\n");
    return;
  }

  glReadPixels(0,0,width,height,GL_RED,GL_UNSIGNED_BYTE,RedBuffer);
  glReadPixels(0,0,width,height,GL_GREEN,GL_UNSIGNED_BYTE,GreenBuffer);
  glReadPixels(0,0,width,height,GL_BLUE,GL_UNSIGNED_BYTE,BlueBuffer);
  
  if (!(OutputColorMap = MakeMapObject(ColorMapSize, NULL))){
    fprintf(stderr, "Warning: Failed to allocate memory for ColorMap\n");
    return;
  }

  if(!(OutputBuffer = (GifByteType *) malloc(width * height * sizeof(GifByteType)))){
    fprintf(stderr, "Error: Failed to allocate memory for Output Buffer\n");
    return;
  }

  if (QuantizeBuffer(width, height, &ColorMapSize,
		     RedBuffer, GreenBuffer, BlueBuffer,
		     OutputBuffer, OutputColorMap->Colors) == GIF_ERROR)
    fprintf(stderr, "Warning: Quantize Buffer Failed\n");

  free(RedBuffer);
  free(GreenBuffer);
  free(BlueBuffer);
  
  SaveGif(fp, OutputBuffer, OutputColorMap, ExpNumOfColors, width, height);
}

