#ifndef __TABELA_TIPOS_H__
#define __TABELA_TIPOS_H__

#include "tipo.hpp"
#include <deque>
#include <string>

class TabelaTipos {
public:
  TabelaTipos() : tipos{std::deque<Tipo *>()} {};

  void push(Tipo *rotulo);
  void pop();
  Tipo *busca_tipo(const std::string &simb);
  Tipo *busca_tipo(int offset);

  void print_tabela();

private:
  std::deque<Tipo *> tipos;
};

#endif