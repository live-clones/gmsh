
#define LABEL_SIZE                      80
#define NUM_FACET_SIZE          4
#define HEADER_SIZE                     84
#define STL_MIN_FILE_SIZE       134
#define ASCII_LINES_PER_FACET   7
#define SIZEOF_EDGE_SORT        24

typedef struct 
{
    float x, y, z;
}stl_vertex;

typedef char stl_extra[2];

typedef struct
{
    stl_vertex  normal;
    stl_vertex  vertex[3];
    stl_extra   extra;
}stl_facet;

#define SIZEOF_STL_FACET       50

typedef enum {BINARY, ASCII} stl_type;

typedef struct
{
    long              file_size;
    char          header[81];
    stl_type      type;
    int           number_of_facets;
    stl_vertex    max;
    stl_vertex    min;
    stl_vertex    center;
    stl_vertex    size;
    float         bounding_diameter;
    float         shortest_edge;
    float         tolerance;
    float         volume;
    float         area;
    int           malloced;
    int           freed;
    int           facets_malloced;
}stl_stats;  

typedef struct
{
    FILE                        *fp;
    stl_facet           *facet_start;
    stl_stats           stats;
}stl_data;

typedef struct
{
    stl_vertex normal;
    float D;
}stl_plane;

int stl_index;

int   StlGetLittleInt(FILE *fp);
float StlGetLittleFloat(FILE *fp);

void  StlPutLittleInt(FILE *fp, int value_in);
void  StlPutLittleFloat(FILE *fp, float value_in);

int   StlCheckIfFileExists(char *file);

int   StlOpenStl(stl_data *stl, char *file);
int   StlAddStl(stl_data *stl, char *file);
void  StlReadStl(stl_data *stl, int first_facet, int first);

void  StlClose(stl_data *stl);

int   StlReallocate(stl_data *stl);
int   StlAllocate(stl_data *stl);


