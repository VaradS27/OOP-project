#ifndef EFFECT_H
#define EFFECT_H
class Effect {
 public:
  virtual void apply(Cell& cell) = 0;
};
#endif