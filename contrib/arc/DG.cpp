class groupOfElements{
  // tous les elements ont le meme nombre de points de gauss et le
  // meme nombre de noeuds

  vector<MElement*> elements;
  // 1) general case
  // store Jacobian + det at all gauss points

  // or 2) quadrature free
  // nothinto store
};

class MFaceWithAdditionalInfo : MFace{
  MElement *left, *right; // normales pointent vers extérieur du left
  // ordre 
};

class groupOfFaces{
  // toutes les faces ont le meme nombre de points points de gauss et
  // le meme nombre de noeuds

  vector<MFaceWithAdditionalInfo*> faces;
  // 
  // stockage normales à tous les points d'intégration
};

class DG{
  DG(vector<groupOfElements*> &groups)
  {
    // if need to, loop over all elements and store gradients at nodes
  }
  void volumeResidual(vector<groupOfElements*> &groups, dofManager &dofs,
                      conservationLaw &law, vecteur &residual)
  {
    // pour chaque groupe:
    //   1) calculer aux points de gauss toutes les variables (et leurs
    //      derivees si besoin est, using node gradients)
    //   2) boucler sur les elements, calculer les flux et les stocker
    //      dans un gros vecteur fx, fy, fz (lineaire en #pts de gauss)
    //   3) integrer (sommer) via blas 3 (quadratique)
    //   4) premultiplier par inverse de matrice de masse
  }
  void boundaryResidual(vector<groupOfFaces*> &groups, dofManager &dofs,
                        conservationLaw &law, vecteur &residual)
  {
    // pour chaque groupe:
    //   1) boucler sur les faces et evaluer les variables left et right
    //      aux points de colloc et stocker dans un gros vecteur 
    //   2) push sur les points de gauss
    //   3) calculer les flux aux points de gauss
    //   4) appeler riemanFlux avec left/right
    //   5) integrer tout d'un coup via blas
  }
  // pour l'implicite:
  void assemble()
  {
    
  }
};

class conservationLaw {
  void diffusionTerm(MElement*, integrationPoints, dataVec in[4], dataVec out[3]);
  void convectionTerm(MElement*, integrationPoints, dataVec in, dataVec out[3]);
  void massTerm(MElement*, integrationPoints, dataVec in, dataVec out);
  void rhs(MElement*, integrationPoints, dataVec in, dataVec out);
  void riemanFlux(MElement *ele[2], dataVec in[2], dataVec out);
  void maxEigenValue(MElement *);
  // pour le non-linéaire si linearisation sans differences finies
  void linearizeDiffusionFlux();
  void linearizeConvectionFlux();
};

