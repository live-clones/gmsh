#ifndef IO_INCLUDED
#define IO_INCLUDED

namespace SEQ {
    void writeModels(std::vector<GModel*> &models);
    void writeProFile(GModel* m, const int npart);
    std::vector<int> getNumFromString(std::string name);
    bool communPhysicals(const std::vector<int> vec1, const std::vector<int> vec2, std::vector<int>* vecCommun);
}

#endif /* IO_INCLUDED */
