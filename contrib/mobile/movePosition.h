#ifndef _MOVE_POSITION_H_
#define _MOVE_POSITION_H_

class movePosition {
 public:
  float win[3]; // window coordinates
  float wnr[3]; // world coordinates BEFORE rotation
  float s[3]; // scaling state when the event was recorded
  float t[3]; // translation state when the event was recorded
  movePosition()
  {
    for(int i = 0; i < 3; i++)
      win[i] = wnr[i] = s[i] = t[i] = 0.;
  }
  movePosition(const movePosition &instance)
  {
    for(int i = 0; i < 3; i++){
      win[i] = instance.win[i];
      wnr[i] = instance.wnr[i];
      s[i] = instance.s[i];
      t[i] = instance.t[i];
    }
  }
  void set(float scale[3], float translate[3], float vxmax, float vxmin,
           float vymin, float vymax, int width, int height, int x, int y)
  {
    for(int i = 0; i < 3; i++){
      s[i] = scale[i];
      t[i] = translate[i];
    }
    win[0] = (float)x;
    win[1] = (float)y;
    win[2] = 0.;

    wnr[0] =
      (vxmin + win[0] / (float)width * (vxmax - vxmin)) / scale[0] - translate[0];
    wnr[1] =
      (vymax - win[1] / (float)height * (vymax - vymin)) / scale[1] - translate[1];
    wnr[2] = 0.;
  }
  void recenter(float scale[3], float translate[3]) const
  {
    // compute the equivalent translation to apply *after* the scaling so that
    // the scaling is done around the point which was clicked:
    translate[0] = t[0] * (s[0] / scale[0]) - wnr[0] * (1. - (s[0] / scale[0]));
    translate[1] = t[1] * (s[1] / scale[1]) - wnr[1] * (1. - (s[1] / scale[1]));
  }
};

#endif
