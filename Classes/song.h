#include "media.h"

#ifndef SONG_H
#define SONG_H
//just the song class
class song: public media {
public:
  char artist[80];
  float length;
  song();
  void disp();
  ~song();
};
#endif
