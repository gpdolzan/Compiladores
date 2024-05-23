#ifndef __TIPO_H__
#define __TIPO_H__

typedef enum { t_int, t_bool, t_undefined } tipo_simples_variavel;

class Tipo {
public:
  Tipo();

private:
  static int index;
};

#endif