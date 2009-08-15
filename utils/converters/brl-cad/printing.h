/*
    (C) 2009 Mark van Doesburg, Technolution B.V.

    Distributed under GPL version 2
*/

#include "tprintf.h"

class Indent {
    char *buffer;
public:
    Indent(int i) { buffer=new char[i+1]; memset(buffer,' ',i); buffer[i]=0; }
    ~Indent() { delete buffer; }
    operator const char*() { return buffer; }
};

std::ostream &operator <<(std::ostream &o,rt_comb_internal const &c)
{
    o << "    unsigned long magic       " << c.magic << '\n';
    o << "    union tree * tree         " << c.tree << '\n';
    o << "    char	 region_flag    " << (int)c.region_flag << '\n';
    o << "    char	 is_fastgen     " << (int)c.is_fastgen << '\n';

    /* Begin GIFT compatability */
    o << "    long	 region_id      " << c.region_id << '\n';
    o << "    long	 aircode        " << c.aircode << '\n';
    o << "    long	 GIFTmater      " << c.GIFTmater << '\n';
    o << "    long	 los            " << c.los << '\n';
    /* End GIFT compatability */

    o << "    char	 rgb_valid      " << (int)c.rgb_valid << '\n';
    o << "    unsigned char	rgb[3]  " << (int)c.rgb[0] << ',' 
	<< (int)c.rgb[1] << ',' << (int)c.rgb[2] << '\n';
    o << "    float	 temperature    " << c.temperature << '\n';
    //cout << "    struct bu_vls shader " << c.shader << '\n';
    //cout << "    struct bu_vls material " << c.material << '\n';
    o << "    char	 inherit        " << (int)c.inherit << '\n';
    return o;
}

std::ostream &operator <<(std::ostream &o,point_t const &p)
{
    for(int i=0;i<ELEMENTS_PER_POINT;i++) {
        o<< (i? ',':'(') << p[i];
    }
    o<<')';
}

template <typename T>
std::ostream & operator<<(std::ostream &out, std::set<T> const &a)
{ 
    std::copy(a.begin(),a.end(),std::ostream_iterator<T>(out," "));
    return out;
}

std::ostream &operator <<(std::ostream &o,union tree &p)
{
    if(p.tr_a.magic!=RT_TREE_MAGIC)
        return o << "INVALID";
    switch(p.tr_op) {
    case OP_SOLID:      return o << "OP_SOLID";
    case OP_UNION:      return o << "OP_UNION";
    case OP_INTERSECT:  return o << "OP_INTERSECT";
    case OP_SUBTRACT:   return o << "OP_SUBTRACT";
    case OP_XOR:        return o << "OP_XOR";
    case OP_REGION:     return o << "OP_REGION";
    case OP_NOP:        return o << "OP_NOP";
    case OP_NOT:        return o << "OP_NOT";
    case OP_GUARD:      return o << "OP_GUARD";
    case OP_XNOP:       return o << "OP_XNOP";
    case OP_NMG_TESS:   return o << "OP_NMG_TESS";
    case OP_DB_LEAF:    return o << "OP_DB_LEAF";
    case OP_FREE:       return o << "OP_FREE";
    default:            return o << "UNKNOWN";
    }
}

std::ostream &operator <<(std::ostream &o,union tree *p)
{
    switch(p->tr_op) {
    case OP_DB_LEAF:
    case OP_SOLID:    return o << p->tr_l.tl_name;
    case OP_UNION:    return o << p->tr_b.tb_left << " u " << p->tr_b.tb_right;
    case OP_INTERSECT:return o << p->tr_b.tb_left << " + " << p->tr_b.tb_right;
    case OP_SUBTRACT: return o << p->tr_b.tb_left << " - " << p->tr_b.tb_right;
    default:          return o << *p;
    }
}

