
typedef struct
{
    float x, y, z;
    int keep;
}msh_node;

typedef struct
{
    int node[8];
    int inside;    
}msh_element;

typedef struct
{
    int           number_of_nodes;
    int           number_of_elements;
    int           nodes_malloced;
    int           elements_malloced;
}msh_stats;  

typedef struct
{
    FILE			*fp;
    msh_node		*node_start;
    msh_element		*element_start;	
    msh_stats		stats;
}msh_data;

