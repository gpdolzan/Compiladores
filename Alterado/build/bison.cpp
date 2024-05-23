// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 2 "src/bison.y"

#include <iostream>
#include <string>
#include <cmath>
#include "flex.hpp"
#include "../includes/compilador.hpp"

#define flags(STR) std::cerr << "\033[1;31m" << STR << "\033[0m\n"
#define flag std::cerr << "\033[1;31mFLAG\033[0m\n"

int lexic_level = 0;
int num_total_vars = 0;
int num_total_params = 0;
int num_same_type_vars = 0;
int num_type_declared = 0;
int top_desloc = 0;

std::list<Param> *params;
std::stack<std::list<Param>> expression_list_types = {};
std::stack<std::stack<Param>> calling_proc_params = {};

#line 63 "bison.cpp"


#include "bison.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 30 "src/bison.y"
namespace bison {
#line 142 "bison.cpp"

  /// Build a parser object.
  Parser::Parser (yyscan_t scanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_expressao: // expressao
      case symbol_kind::S_expressao_simples: // expressao_simples
      case symbol_kind::S_termo: // termo
      case symbol_kind::S_fator: // fator
      case symbol_kind::S_variavel_func: // variavel_func
        value.copy< Param > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_52_2: // @2
      case symbol_kind::S_bloco: // bloco
      case symbol_kind::S_54_3: // @3
      case symbol_kind::S_56_5: // @5
      case symbol_kind::S_declaracao_procedimento: // declaracao_procedimento
      case symbol_kind::S_73_9: // @9
      case symbol_kind::S_declaracao_funcao: // declaracao_funcao
      case symbol_kind::S_75_10: // @10
      case symbol_kind::S_chamada_sem_pametro: // chamada_sem_pametro
      case symbol_kind::S_chamada_procedimento_parametros: // chamada_procedimento_parametros
      case symbol_kind::S_chamada_funcao_sem_parametros: // chamada_funcao_sem_parametros
      case symbol_kind::S_variavel: // variavel
        value.copy< Simbolo* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo: // tipo
        value.copy< Tipo* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parte_declara_tipo: // parte_declara_tipo
      case symbol_kind::S_parte_declara_vars: // parte_declara_vars
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ident: // ident
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo_parametro: // tipo_parametro
        value.copy< tipo_parametro > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_expressao: // expressao
      case symbol_kind::S_expressao_simples: // expressao_simples
      case symbol_kind::S_termo: // termo
      case symbol_kind::S_fator: // fator
      case symbol_kind::S_variavel_func: // variavel_func
        value.move< Param > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_52_2: // @2
      case symbol_kind::S_bloco: // bloco
      case symbol_kind::S_54_3: // @3
      case symbol_kind::S_56_5: // @5
      case symbol_kind::S_declaracao_procedimento: // declaracao_procedimento
      case symbol_kind::S_73_9: // @9
      case symbol_kind::S_declaracao_funcao: // declaracao_funcao
      case symbol_kind::S_75_10: // @10
      case symbol_kind::S_chamada_sem_pametro: // chamada_sem_pametro
      case symbol_kind::S_chamada_procedimento_parametros: // chamada_procedimento_parametros
      case symbol_kind::S_chamada_funcao_sem_parametros: // chamada_funcao_sem_parametros
      case symbol_kind::S_variavel: // variavel
        value.move< Simbolo* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tipo: // tipo
        value.move< Tipo* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_parte_declara_tipo: // parte_declara_tipo
      case symbol_kind::S_parte_declara_vars: // parte_declara_vars
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ident: // ident
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tipo_parametro: // tipo_parametro
        value.move< tipo_parametro > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expressao: // expressao
      case symbol_kind::S_expressao_simples: // expressao_simples
      case symbol_kind::S_termo: // termo
      case symbol_kind::S_fator: // fator
      case symbol_kind::S_variavel_func: // variavel_func
        value.YY_MOVE_OR_COPY< Param > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_52_2: // @2
      case symbol_kind::S_bloco: // bloco
      case symbol_kind::S_54_3: // @3
      case symbol_kind::S_56_5: // @5
      case symbol_kind::S_declaracao_procedimento: // declaracao_procedimento
      case symbol_kind::S_73_9: // @9
      case symbol_kind::S_declaracao_funcao: // declaracao_funcao
      case symbol_kind::S_75_10: // @10
      case symbol_kind::S_chamada_sem_pametro: // chamada_sem_pametro
      case symbol_kind::S_chamada_procedimento_parametros: // chamada_procedimento_parametros
      case symbol_kind::S_chamada_funcao_sem_parametros: // chamada_funcao_sem_parametros
      case symbol_kind::S_variavel: // variavel
        value.YY_MOVE_OR_COPY< Simbolo* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo: // tipo
        value.YY_MOVE_OR_COPY< Tipo* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parte_declara_tipo: // parte_declara_tipo
      case symbol_kind::S_parte_declara_vars: // parte_declara_vars
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ident: // ident
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo_parametro: // tipo_parametro
        value.YY_MOVE_OR_COPY< tipo_parametro > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expressao: // expressao
      case symbol_kind::S_expressao_simples: // expressao_simples
      case symbol_kind::S_termo: // termo
      case symbol_kind::S_fator: // fator
      case symbol_kind::S_variavel_func: // variavel_func
        value.move< Param > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_52_2: // @2
      case symbol_kind::S_bloco: // bloco
      case symbol_kind::S_54_3: // @3
      case symbol_kind::S_56_5: // @5
      case symbol_kind::S_declaracao_procedimento: // declaracao_procedimento
      case symbol_kind::S_73_9: // @9
      case symbol_kind::S_declaracao_funcao: // declaracao_funcao
      case symbol_kind::S_75_10: // @10
      case symbol_kind::S_chamada_sem_pametro: // chamada_sem_pametro
      case symbol_kind::S_chamada_procedimento_parametros: // chamada_procedimento_parametros
      case symbol_kind::S_chamada_funcao_sem_parametros: // chamada_funcao_sem_parametros
      case symbol_kind::S_variavel: // variavel
        value.move< Simbolo* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo: // tipo
        value.move< Tipo* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parte_declara_tipo: // parte_declara_tipo
      case symbol_kind::S_parte_declara_vars: // parte_declara_vars
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ident: // ident
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo_parametro: // tipo_parametro
        value.move< tipo_parametro > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expressao: // expressao
      case symbol_kind::S_expressao_simples: // expressao_simples
      case symbol_kind::S_termo: // termo
      case symbol_kind::S_fator: // fator
      case symbol_kind::S_variavel_func: // variavel_func
        value.copy< Param > (that.value);
        break;

      case symbol_kind::S_52_2: // @2
      case symbol_kind::S_bloco: // bloco
      case symbol_kind::S_54_3: // @3
      case symbol_kind::S_56_5: // @5
      case symbol_kind::S_declaracao_procedimento: // declaracao_procedimento
      case symbol_kind::S_73_9: // @9
      case symbol_kind::S_declaracao_funcao: // declaracao_funcao
      case symbol_kind::S_75_10: // @10
      case symbol_kind::S_chamada_sem_pametro: // chamada_sem_pametro
      case symbol_kind::S_chamada_procedimento_parametros: // chamada_procedimento_parametros
      case symbol_kind::S_chamada_funcao_sem_parametros: // chamada_funcao_sem_parametros
      case symbol_kind::S_variavel: // variavel
        value.copy< Simbolo* > (that.value);
        break;

      case symbol_kind::S_tipo: // tipo
        value.copy< Tipo* > (that.value);
        break;

      case symbol_kind::S_parte_declara_tipo: // parte_declara_tipo
      case symbol_kind::S_parte_declara_vars: // parte_declara_vars
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_ident: // ident
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_tipo_parametro: // tipo_parametro
        value.copy< tipo_parametro > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expressao: // expressao
      case symbol_kind::S_expressao_simples: // expressao_simples
      case symbol_kind::S_termo: // termo
      case symbol_kind::S_fator: // fator
      case symbol_kind::S_variavel_func: // variavel_func
        value.move< Param > (that.value);
        break;

      case symbol_kind::S_52_2: // @2
      case symbol_kind::S_bloco: // bloco
      case symbol_kind::S_54_3: // @3
      case symbol_kind::S_56_5: // @5
      case symbol_kind::S_declaracao_procedimento: // declaracao_procedimento
      case symbol_kind::S_73_9: // @9
      case symbol_kind::S_declaracao_funcao: // declaracao_funcao
      case symbol_kind::S_75_10: // @10
      case symbol_kind::S_chamada_sem_pametro: // chamada_sem_pametro
      case symbol_kind::S_chamada_procedimento_parametros: // chamada_procedimento_parametros
      case symbol_kind::S_chamada_funcao_sem_parametros: // chamada_funcao_sem_parametros
      case symbol_kind::S_variavel: // variavel
        value.move< Simbolo* > (that.value);
        break;

      case symbol_kind::S_tipo: // tipo
        value.move< Tipo* > (that.value);
        break;

      case symbol_kind::S_parte_declara_tipo: // parte_declara_tipo
      case symbol_kind::S_parte_declara_vars: // parte_declara_vars
        value.move< int > (that.value);
        break;

      case symbol_kind::S_ident: // ident
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_tipo_parametro: // tipo_parametro
        value.move< tipo_parametro > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, scanner));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_expressao: // expressao
      case symbol_kind::S_expressao_simples: // expressao_simples
      case symbol_kind::S_termo: // termo
      case symbol_kind::S_fator: // fator
      case symbol_kind::S_variavel_func: // variavel_func
        yylhs.value.emplace< Param > ();
        break;

      case symbol_kind::S_52_2: // @2
      case symbol_kind::S_bloco: // bloco
      case symbol_kind::S_54_3: // @3
      case symbol_kind::S_56_5: // @5
      case symbol_kind::S_declaracao_procedimento: // declaracao_procedimento
      case symbol_kind::S_73_9: // @9
      case symbol_kind::S_declaracao_funcao: // declaracao_funcao
      case symbol_kind::S_75_10: // @10
      case symbol_kind::S_chamada_sem_pametro: // chamada_sem_pametro
      case symbol_kind::S_chamada_procedimento_parametros: // chamada_procedimento_parametros
      case symbol_kind::S_chamada_funcao_sem_parametros: // chamada_funcao_sem_parametros
      case symbol_kind::S_variavel: // variavel
        yylhs.value.emplace< Simbolo* > ();
        break;

      case symbol_kind::S_tipo: // tipo
        yylhs.value.emplace< Tipo* > ();
        break;

      case symbol_kind::S_parte_declara_tipo: // parte_declara_tipo
      case symbol_kind::S_parte_declara_vars: // parte_declara_vars
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_ident: // ident
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_tipo_parametro: // tipo_parametro
        yylhs.value.emplace< tipo_parametro > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // $@1: %empty
#line 85 "src/bison.y"
   {
      iniciaCompilador();
      geraCodigo("INPP");
   }
#line 900 "bison.cpp"
    break;

  case 3: // @2: %empty
#line 91 "src/bison.y"
             {
      simbolo_main = new Simbolo("main", lexic_level, new std::list<Param>(), main_process);

      yylhs.value.as < Simbolo* > () = simbolo_main;
   }
#line 910 "bison.cpp"
    break;

  case 4: // programa: $@1 PROGRAM IDENT ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA @2 bloco PONTO
#line 97 "src/bison.y"
   {
      geraCodigo("PARA");
      desligaCompilador();
   }
#line 919 "bison.cpp"
    break;

  case 5: // @3: %empty
#line 104 "src/bison.y"
             {
      Simbolo* proce = yystack_[0].value.as< Simbolo* > ();
      
      if (proce->is_proc_or_func()) {
         entraProce(proce);
      }else if (!proce->is_main()) {
         error("Suposto ser um simbolo de procedimento ou funcao, final do bloco de "
               "declaracoes de subrotinas");
      }

      top_desloc = 0;
      yylhs.value.as< Simbolo* > () = proce;
   }
#line 937 "bison.cpp"
    break;

  case 6: // $@4: %empty
#line 118 "src/bison.y"
   {
      yystack_[1].value.as < Simbolo* > ()->number_types = yystack_[0].value.as < int > ();
   }
#line 945 "bison.cpp"
    break;

  case 7: // @5: %empty
#line 122 "src/bison.y"
             {
      yystack_[3].value.as < Simbolo* > ()->number_vars = yystack_[0].value.as < int > ();

      yylhs.value.as < Simbolo* > () = yystack_[3].value.as < Simbolo* > ();
   }
#line 955 "bison.cpp"
    break;

  case 8: // $@6: %empty
#line 128 "src/bison.y"
   {
      if (yystack_[5].value.as < Simbolo* > ()->is_func())
         yystack_[5].value.as < Simbolo* > ()->allow_return = true;
   }
#line 964 "bison.cpp"
    break;

  case 9: // bloco: @3 parte_declara_tipo $@4 parte_declara_vars @5 parte_declara_subrotinas_wrap $@6 comando_composto
#line 133 "src/bison.y"
   {
      Simbolo* proce = yystack_[7].value.as < Simbolo* > ();

      if(!proce->is_main())
         removeSimbolos(proce->parametros->size() + proce->number_vars);

      removeTipos(yystack_[7].value.as < Simbolo* > ()->number_types);
      geraCodigo("DMEM", proce->number_vars);
      visualizaTabelas();

      if (proce->is_proc_or_func())
         geraCodigo("RTPR", proce->nivel_lexico, proce->parametros->size());

      if (proce->is_func())
         yystack_[7].value.as < Simbolo* > ()->allow_return = false;
   }
#line 985 "bison.cpp"
    break;

  case 10: // parte_declara_tipo: TYPE define_tipos
#line 153 "src/bison.y"
   {
      yylhs.value.as < int > () = num_type_declared;
      visualizaTabelaTipos();
   }
#line 994 "bison.cpp"
    break;

  case 11: // parte_declara_tipo: %empty
#line 158 "src/bison.y"
   {
      yylhs.value.as < int > () = 0;
   }
#line 1002 "bison.cpp"
    break;

  case 14: // define_tipo: ident IGUAL tipo PONTO_E_VIRGULA
#line 170 "src/bison.y"
   {
      insereTipo(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Tipo* > ());
      num_type_declared++;
   }
#line 1011 "bison.cpp"
    break;

  case 15: // parte_declara_vars: VAR declara_vars
#line 179 "src/bison.y"
   {
      geraCodigo("AMEM", num_total_vars);
      yylhs.value.as < int > () = num_total_vars;
      visualizaTabelaSimbolos();
   }
#line 1021 "bison.cpp"
    break;

  case 16: // parte_declara_vars: %empty
#line 185 "src/bison.y"
   {
      yylhs.value.as < int > () = 0;
   }
#line 1029 "bison.cpp"
    break;

  case 19: // $@7: %empty
#line 197 "src/bison.y"
   {
      num_same_type_vars = 0;
   }
#line 1037 "bison.cpp"
    break;

  case 20: // declara_var: $@7 lista_var DOIS_PONTOS tipo PONTO_E_VIRGULA
#line 201 "src/bison.y"
   {
      colocaTipoEmSimbolos(yystack_[1].value.as < Tipo* > (), num_same_type_vars);
      num_same_type_vars = 0;
   }
#line 1046 "bison.cpp"
    break;

  case 21: // lista_var: lista_var VIRGULA ident
#line 209 "src/bison.y"
   {
      insereSimbolo(new Simbolo(yystack_[0].value.as < std::string > (), lexic_level, top_desloc, variavel_simples));
      top_desloc++;
      num_total_vars++;
      num_same_type_vars++;
   }
#line 1057 "bison.cpp"
    break;

  case 22: // lista_var: ident
#line 216 "src/bison.y"
   {
      insereSimbolo(new Simbolo(yystack_[0].value.as < std::string > (), lexic_level, top_desloc, variavel_simples));
      top_desloc++;
      num_total_vars++;
      num_same_type_vars++;
   }
#line 1068 "bison.cpp"
    break;

  case 23: // ident: IDENT
#line 226 "src/bison.y"
   {
      yylhs.value.as < std::string > () = simbolo_flex;
   }
#line 1076 "bison.cpp"
    break;

  case 26: // $@8: %empty
#line 251 "src/bison.y"
   {
      Simbolo *proc = yystack_[0].value.as< Simbolo* > ();

      geraCodigo("DSVS", "", proc->rotulo_begin()->identificador);
   }
#line 1086 "bison.cpp"
    break;

  case 27: // parte_declara_subrotinas_wrap: $@8 parte_declara_subrotinas
#line 257 "src/bison.y"
   {
      Simbolo *proc = yystack_[2].value.as< Simbolo* > ();

      geraCodigo("NADA", proc->rotulo_begin()->identificador);
   }
#line 1096 "bison.cpp"
    break;

  case 31: // parte_declara_subrotinas_two: declaracao_procedimento bloco PONTO_E_VIRGULA
#line 272 "src/bison.y"
   {
      lexic_level--;
   }
#line 1104 "bison.cpp"
    break;

  case 32: // parte_declara_subrotinas_two: declaracao_funcao bloco PONTO_E_VIRGULA
#line 277 "src/bison.y"
   {
      lexic_level--;
   }
#line 1112 "bison.cpp"
    break;

  case 33: // @9: %empty
#line 285 "src/bison.y"
             {
      lexic_level++;
      num_total_vars = 0;
      num_total_params = 0;
      num_type_declared = 0;
      
      params = new std::list<Param>();
      Simbolo *proce = new Simbolo(yystack_[0].value.as < std::string > (), lexic_level, params, process);
      insereSimbolo(proce);

      yylhs.value.as < Simbolo* > () = proce;
   }
#line 1129 "bison.cpp"
    break;

  case 34: // declaracao_procedimento: PROCEDURE ident @9 declaracao_params PONTO_E_VIRGULA
#line 298 "src/bison.y"
   {
      yylhs.value.as < Simbolo* > () = yystack_[2].value.as < Simbolo* > ();
   }
#line 1137 "bison.cpp"
    break;

  case 35: // @10: %empty
#line 306 "src/bison.y"
             {
      lexic_level++;
      num_total_vars = 0;
      num_total_params = 0;
      
      params = new std::list<Param>();
      Simbolo *proce = new Simbolo(yystack_[0].value.as < std::string > (), lexic_level, params, function);
      insereSimbolo(proce);
      
      yylhs.value.as < Simbolo* > () = proce;
   }
#line 1153 "bison.cpp"
    break;

  case 36: // declaracao_funcao: FUNCTION ident @10 declaracao_params DOIS_PONTOS tipo PONTO_E_VIRGULA
#line 318 "src/bison.y"
   {
      yylhs.value.as < Simbolo* > () = yystack_[4].value.as < Simbolo* > ();
      yystack_[4].value.as < Simbolo* > ()->tipo_param = t_copy;
      yystack_[4].value.as < Simbolo* > ()->deslocamento = -(4 + num_total_params);
      yystack_[4].value.as < Simbolo* > ()->tipo_v = yystack_[1].value.as < Tipo* > ();
   }
#line 1164 "bison.cpp"
    break;

  case 37: // $@11: %empty
#line 328 "src/bison.y"
   {
      colocaDeslocEmParams(num_total_params);
      
      params = nullptr;
   }
#line 1174 "bison.cpp"
    break;

  case 39: // declaracao_params: %empty
#line 335 "src/bison.y"
   {
      params = nullptr;
   }
#line 1182 "bison.cpp"
    break;

  case 42: // $@12: %empty
#line 348 "src/bison.y"
   {
      num_same_type_vars = 0;
   }
#line 1190 "bison.cpp"
    break;

  case 43: // secao_parametros_formais: $@12 tipo_parametro lista_params DOIS_PONTOS tipo
#line 352 "src/bison.y"
   {
      Tipo *tipo_v = yystack_[0].value.as < Tipo* > ();
      tipo_parametro tipo_param = yystack_[3].value.as < tipo_parametro > ();

      for(int i = 0;i < num_same_type_vars;i++) {
         params->push_back(Param(tipo_v, tipo_param));
      }

      colocaTipoEmSimbolos(tipo_v, num_same_type_vars);
      colocaTipoEmSimbolos(tipo_param, num_same_type_vars);
   }
#line 1206 "bison.cpp"
    break;

  case 44: // lista_params: lista_params VIRGULA ident
#line 367 "src/bison.y"
   {
      insereSimbolo(new Simbolo(yystack_[0].value.as < std::string > (), lexic_level, 0, parametros_formais));
      num_total_params++;
      num_same_type_vars++;
   }
#line 1216 "bison.cpp"
    break;

  case 45: // lista_params: ident
#line 373 "src/bison.y"
   {
      insereSimbolo(new Simbolo(yystack_[0].value.as < std::string > (), lexic_level, 0, parametros_formais));
      num_total_params++;
      num_same_type_vars++;
   }
#line 1226 "bison.cpp"
    break;

  case 46: // tipo_parametro: VAR
#line 382 "src/bison.y"
   {
      yylhs.value.as < tipo_parametro > () = t_pointer;
   }
#line 1234 "bison.cpp"
    break;

  case 47: // tipo_parametro: %empty
#line 386 "src/bison.y"
   {
      yylhs.value.as < tipo_parametro > () = t_copy;
   }
#line 1242 "bison.cpp"
    break;

  case 61: // lista_write: lista_write VIRGULA expressao
#line 421 "src/bison.y"
   {
      geraCodigo("IMPR");
   }
#line 1250 "bison.cpp"
    break;

  case 62: // lista_write: expressao
#line 425 "src/bison.y"
   {
      geraCodigo("IMPR");
   }
#line 1258 "bison.cpp"
    break;

  case 63: // lista_read: lista_read VIRGULA variavel
#line 432 "src/bison.y"
   {
      geraCodigo("LEIT");
      aplicarArmazena(yystack_[0].value.as < Simbolo* > ());
   }
#line 1267 "bison.cpp"
    break;

  case 64: // lista_read: variavel
#line 437 "src/bison.y"
   {
      geraCodigo("LEIT");
      aplicarArmazena(yystack_[0].value.as < Simbolo* > ());
   }
#line 1276 "bison.cpp"
    break;

  case 65: // atribuicao: variavel ATRIBUICAO expressao
#line 449 "src/bison.y"
   {
      if(yystack_[2].value.as < Simbolo* > ()->allow_return)
         error("Função não pode ser usada como variável");

      if(*(yystack_[2].value.as < Simbolo* > ()->tipo_v) != *(yystack_[0].value.as < Param > ().tipo_v))
         error("Tipos incompatíveis na atribuição");
      
      aplicarArmazena(yystack_[2].value.as < Simbolo* > ());
   }
#line 1290 "bison.cpp"
    break;

  case 66: // chamada_procedimento: chamada_sem_pametro
#line 463 "src/bison.y"
   {
      if(!yystack_[0].value.as < Simbolo* > ()->is_proc_or_func())
         error("Chamada de procedimento inválida");
      if(yystack_[0].value.as < Simbolo* > ()->parametros->size() != 0)
         error("Número de parâmetros inválido");
      if(yystack_[0].value.as < Simbolo* > ()->is_func())
         geraCodigo("AMEM", 1);
      geraCodigo("CHPR", "", yystack_[0].value.as < Simbolo* > ()->rotulo_enpr()->identificador, std::to_string(lexic_level));
      if(yystack_[0].value.as < Simbolo* > ()->is_func())
         geraCodigo("DMEM", 1);
   }
#line 1306 "bison.cpp"
    break;

  case 67: // chamada_procedimento: chamada_procedimento_parametros
#line 475 "src/bison.y"
   {
      if(yystack_[0].value.as < Simbolo* > ()->is_func())
         geraCodigo("DMEM", 1);
   }
#line 1315 "bison.cpp"
    break;

  case 68: // chamada_sem_pametro: variavel
#line 483 "src/bison.y"
   {
      yylhs.value.as < Simbolo* > () = yystack_[0].value.as < Simbolo* > ();
   }
#line 1323 "bison.cpp"
    break;

  case 69: // chamada_sem_pametro: variavel ABRE_PARENTESES FECHA_PARENTESES
#line 487 "src/bison.y"
   {
      yylhs.value.as < Simbolo* > () = yystack_[2].value.as < Simbolo* > ();
   }
#line 1331 "bison.cpp"
    break;

  case 70: // $@13: %empty
#line 494 "src/bison.y"
   {
      Simbolo *proc = yystack_[1].value.as < Simbolo* > ();

      if(!proc->is_proc_or_func())
         error("Chamada de procedimento inválida");
      
      expression_list_types.push({});
      calling_proc_params.push({});

      if(proc->is_func())
         geraCodigo("AMEM", 1);

      for(auto it = proc->parametros->rbegin();it != proc->parametros->rend();++it) {
         calling_proc_params.top().push(*it);
      }
   }
#line 1352 "bison.cpp"
    break;

  case 71: // chamada_procedimento_parametros: variavel ABRE_PARENTESES $@13 lista_de_expressoes FECHA_PARENTESES
#line 511 "src/bison.y"
   {
      Simbolo *proc = yystack_[4].value.as < Simbolo* > ();
      if(proc->parametros->size() != expression_list_types.top().size())
         error("Número de parâmetros inválido");

      for (auto it = proc->parametros->begin(), it_list = expression_list_types.top().begin();it != proc->parametros->end();++it, ++it_list) {
         if ((*it).tipo_v != (*it_list).tipo_v)
            error("Tipos de parâmetros incompatíveis");
      }

      geraCodigo("CHPR", "", yystack_[4].value.as < Simbolo* > ()->rotulo_enpr()->identificador, std::to_string(lexic_level));
      
      expression_list_types.pop();
      calling_proc_params.pop();

      yylhs.value.as < Simbolo* > () = yystack_[4].value.as < Simbolo* > ();
   }
#line 1374 "bison.cpp"
    break;

  case 72: // chamada_funcao_sem_parametros: variavel ABRE_PARENTESES FECHA_PARENTESES
#line 532 "src/bison.y"
   {
      Simbolo *proc = yystack_[2].value.as < Simbolo* > ();

      if(!proc->is_func())
         error("Chamada de função inválida");
      
      geraCodigo("AMEM", 1);
      geraCodigo("CHPR", "", yystack_[2].value.as < Simbolo* > ()->rotulo_enpr()->identificador, std::to_string(lexic_level));
      
      yylhs.value.as < Simbolo* > () = yystack_[2].value.as < Simbolo* > ();
   }
#line 1390 "bison.cpp"
    break;

  case 73: // variavel: IDENT
#line 547 "src/bison.y"
   {
      Simbolo* simbolo = buscaSimbolo(simbolo_flex);
      yylhs.value.as < Simbolo* > () = simbolo;
   }
#line 1399 "bison.cpp"
    break;

  case 75: // $@14: %empty
#line 560 "src/bison.y"
   {
      start_if();
   }
#line 1407 "bison.cpp"
    break;

  case 77: // $@15: %empty
#line 568 "src/bison.y"
   {
      start_else();
   }
#line 1415 "bison.cpp"
    break;

  case 78: // cond_else: ELSE $@15 comando_sem_rotulo
#line 572 "src/bison.y"
   {
      end_else();
   }
#line 1423 "bison.cpp"
    break;

  case 79: // cond_else: %empty
#line 576 "src/bison.y"
   {
      end_if();
   }
#line 1431 "bison.cpp"
    break;

  case 80: // $@16: %empty
#line 584 "src/bison.y"
   {
      start_while();
   }
#line 1439 "bison.cpp"
    break;

  case 81: // $@17: %empty
#line 588 "src/bison.y"
   {
      do_while();
   }
#line 1447 "bison.cpp"
    break;

  case 82: // comando_repetitivo: WHILE $@16 expressao_booleana DO $@17 comando_sem_rotulo
#line 592 "src/bison.y"
   {
      end_while();
   }
#line 1455 "bison.cpp"
    break;

  case 83: // expressao_booleana: expressao
#line 599 "src/bison.y"
   {
      if(yystack_[0].value.as < Param > ().tipo_v->primitive_type != t_bool)
         error("Expressão booleana inválida");
   }
#line 1464 "bison.cpp"
    break;

  case 84: // lista_de_expressoes: lista_de_expressoes VIRGULA expressao
#line 608 "src/bison.y"
   {
      expression_list_types.top().push_back(yystack_[0].value.as < Param > ());
      if(calling_proc_params.top().empty())
         error("Número de parâmetros inválido");
      calling_proc_params.top().pop();
   }
#line 1475 "bison.cpp"
    break;

  case 85: // lista_de_expressoes: expressao
#line 615 "src/bison.y"
   {
      expression_list_types.top().push_back(yystack_[0].value.as < Param > ());
      if(calling_proc_params.top().empty())
         error("Número de parâmetros inválido");
      calling_proc_params.top().pop();
   }
#line 1486 "bison.cpp"
    break;

  case 86: // expressao: expressao_simples MENOR_QUE expressao_simples
#line 626 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("CMME", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1494 "bison.cpp"
    break;

  case 87: // expressao: expressao_simples MAIOR_QUE expressao_simples
#line 630 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("CMMA", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1502 "bison.cpp"
    break;

  case 88: // expressao: expressao_simples IGUAL expressao_simples
#line 634 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("CMIG", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1510 "bison.cpp"
    break;

  case 89: // expressao: expressao_simples DIFERENTE expressao_simples
#line 638 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("CMDG", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1518 "bison.cpp"
    break;

  case 90: // expressao: expressao_simples MAIOR_OU_IGUAL expressao_simples
#line 642 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("CMAG", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1526 "bison.cpp"
    break;

  case 91: // expressao: expressao_simples MENOR_OU_IGUAL expressao_simples
#line 646 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("CMEG", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1534 "bison.cpp"
    break;

  case 92: // expressao: expressao_simples
#line 649 "src/bison.y"
     { yylhs.value.as < Param > () = yystack_[0].value.as < Param > (); }
#line 1540 "bison.cpp"
    break;

  case 93: // expressao_simples: expressao_simples MAIS termo
#line 655 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("SOMA", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1548 "bison.cpp"
    break;

  case 94: // expressao_simples: expressao_simples MENOS termo
#line 659 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("SUBT", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1556 "bison.cpp"
    break;

  case 95: // expressao_simples: expressao_simples OR termo
#line 663 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("DISJ", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1564 "bison.cpp"
    break;

  case 96: // expressao_simples: termo
#line 666 "src/bison.y"
     { yylhs.value.as < Param > () = yystack_[0].value.as < Param > (); }
#line 1570 "bison.cpp"
    break;

  case 97: // termo: termo MULTI fator
#line 672 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("MULT", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1578 "bison.cpp"
    break;

  case 98: // termo: termo DIV fator
#line 676 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("DIVI", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1586 "bison.cpp"
    break;

  case 99: // termo: termo AND fator
#line 680 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("CONJ", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1594 "bison.cpp"
    break;

  case 100: // termo: fator
#line 683 "src/bison.y"
     { yylhs.value.as < Param > () = yystack_[0].value.as < Param > (); }
#line 1600 "bison.cpp"
    break;

  case 101: // fator: NUMERO
#line 689 "src/bison.y"
   {
      geraCodigo("CRCT", "", simbolo_flex);
      yylhs.value.as < Param > () = Param(buscaTipoPrimitivo(t_int), t_copy);
   }
#line 1609 "bison.cpp"
    break;

  case 102: // fator: TRUE
#line 694 "src/bison.y"
   {
      geraCodigo("CRCT", 1);
      yylhs.value.as < Param > () = Param(buscaTipoPrimitivo(t_bool), t_copy);
   }
#line 1618 "bison.cpp"
    break;

  case 103: // fator: FALSE
#line 699 "src/bison.y"
   {
      geraCodigo("CRCT", 0);
      yylhs.value.as < Param > () = Param(buscaTipoPrimitivo(t_bool), t_copy);
   }
#line 1627 "bison.cpp"
    break;

  case 104: // fator: ABRE_PARENTESES expressao FECHA_PARENTESES
#line 704 "src/bison.y"
   {
      yylhs.value.as < Param > () = yystack_[1].value.as < Param > ();
   }
#line 1635 "bison.cpp"
    break;

  case 105: // fator: variavel_func
#line 707 "src/bison.y"
     { yylhs.value.as < Param > () = yystack_[0].value.as < Param > (); }
#line 1641 "bison.cpp"
    break;

  case 106: // variavel_func: variavel
#line 713 "src/bison.y"
   {
      Simbolo* simbolo = yystack_[0].value.as < Simbolo* > ();
      
      if(simbolo->is_proc_or_func())
         error("Variável não pode ser um procedimento");
      
      if(!calling_proc_params.empty()) {
         if(calling_proc_params.top().empty())
            error("Número de parâmetros inválido");
         
         Param param = calling_proc_params.top().top();

         aplicarCarrega(simbolo, param);
      } else {
         aplicarCarrega(simbolo);
      }
      
      yylhs.value.as < Param > () = Param(simbolo->tipo_v, simbolo->tipo_param);
   }
#line 1665 "bison.cpp"
    break;

  case 107: // variavel_func: chamada_procedimento_parametros
#line 733 "src/bison.y"
   {
      Simbolo* proc = yystack_[0].value.as < Simbolo* > ();
      if(!proc->is_func())
         error("Chamada de função inválida");

      yylhs.value.as < Param > () = Param(proc->tipo_v, proc->tipo_param);
   }
#line 1677 "bison.cpp"
    break;

  case 108: // variavel_func: chamada_funcao_sem_parametros
#line 741 "src/bison.y"
   {
      Simbolo* proc = yystack_[0].value.as < Simbolo* > ();
      if(!proc->is_func())
         error("Chamada de função inválida");

      yylhs.value.as < Param > () = Param(proc->tipo_v, proc->tipo_param);
   }
#line 1689 "bison.cpp"
    break;

  case 109: // tipo: ident
#line 752 "src/bison.y"
   {
      yylhs.value.as < Tipo* > () = buscaTipo(yystack_[0].value.as < std::string > ());
   }
#line 1697 "bison.cpp"
    break;


#line 1701 "bison.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char Parser::yypact_ninf_ = -98;

  const signed char Parser::yytable_ninf_ = -29;

  const signed char
  Parser::yypact_[] =
  {
     -98,    39,     6,   -98,   -36,    21,    35,   -98,   -98,   -24,
      35,    30,   -98,   -98,   -98,    73,    63,   -98,    35,   -98,
     -98,    35,    67,   102,   -98,    35,   -98,   -98,   -98,    80,
      61,   -98,    35,   104,   -98,   -98,    66,   -98,   -98,    19,
      35,    35,   105,    35,    35,    19,   -98,   -98,   -98,    84,
     -98,     9,   -98,   -98,   -98,   -98,    85,    86,   -98,    50,
     -98,    83,    89,    87,   -98,   -98,     1,   -98,   -98,   -98,
     -98,   -98,   -98,    10,   -98,   103,   -98,    90,    90,   -98,
     -98,   -98,   -98,    50,   -98,   -98,   -98,    91,   -98,   -98,
      22,    -2,   -98,   -98,    50,    69,    50,    11,   -98,     9,
      50,    92,   -98,   -98,   -98,    96,    97,    94,    95,   113,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,   112,    15,   -98,    40,   -98,   -98,   -98,   -98,
     -98,    50,    11,   106,   -98,   126,   -98,    35,   -98,   -98,
      11,    -2,    24,    24,    24,    24,    24,    24,    -2,    -2,
     -98,   -98,   -98,   -98,    69,   -98,    50,   -98,    41,   -98,
     -98,   -98,    99,   -98,    35,   107,   -98,    11,   -98,   -98,
      50,   -98,   -98,   -98,   -98,    71,   -98,   -98,   -98,    35,
      35,   -98,   -98
  };

  const signed char
  Parser::yydefact_[] =
  {
       2,     0,     0,     1,     0,     0,     0,    23,    25,     0,
       0,     0,    24,     3,     5,     0,    11,     4,     0,     6,
      10,    13,     0,    16,    12,     0,    19,     7,   109,     0,
      15,    18,     0,    26,    14,    17,     0,    22,     8,     0,
       0,     0,     0,     0,     0,    27,    30,     5,     5,     0,
      21,    53,     9,    33,    35,    29,     0,     0,    20,     0,
      80,     0,     0,     0,    73,    56,     0,    50,    52,    54,
      55,    66,    67,    68,    58,    79,    57,    39,    39,    31,
      32,   102,   103,     0,   101,   107,   108,   106,    75,    83,
      92,    96,   100,   105,     0,     0,     0,     0,    48,    53,
       0,    70,    77,    74,    42,     0,     0,     0,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,     0,    62,    51,    49,    65,
      69,     0,     0,    37,    41,    47,    34,     0,   104,    72,
       0,    95,    88,    89,    86,    91,    90,    87,    93,    94,
      98,    99,    97,    81,     0,    60,     0,    59,     0,    85,
      78,    42,     0,    46,     0,     0,    76,     0,    63,    61,
       0,    71,    40,    38,    45,     0,    36,    82,    84,     0,
       0,    43,    44
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -98,   -98,   -98,   -98,    54,   -98,   -98,   -98,   -98,   -98,
     -98,   111,   -98,   -98,   108,   -98,   -98,    -6,   -98,   -98,
     -98,   -98,    98,   -98,   -98,   -98,   -98,    57,   -98,   -98,
     -25,   -98,   -98,   -98,   100,   -98,    38,   -87,   -98,   -98,
     -98,   -98,   -98,   -48,   -98,   -98,   -49,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,    45,   -98,   -77,   -26,   -97,
     -43,   -98,   -39
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     1,     2,    14,    15,    16,    23,    33,    42,    19,
      20,    21,    27,    30,    31,    32,    36,    28,     9,    38,
      39,    45,    46,    47,    77,    48,    78,   105,   162,   133,
     134,   135,   175,   164,    65,    66,    67,    68,   125,   123,
      69,    70,    71,    85,   131,    86,    87,    74,    75,   109,
     103,   132,    76,    94,   167,    88,   158,    89,    90,    91,
      92,    93,    29
  };

  const short
  Parser::yytable_[] =
  {
       8,    49,    73,    72,    12,    10,   107,    98,    11,     4,
     127,     5,    22,   141,    51,    22,    51,   119,   120,   126,
     148,   149,    59,   129,    59,    60,    37,    60,    99,    43,
      44,    61,    62,    61,    62,    50,   100,    53,    54,     3,
     110,   101,   110,   121,   154,   160,   124,   155,    73,    72,
      73,    72,     6,   166,   159,    63,    64,    13,    64,   111,
     112,   113,   114,   115,   116,   117,   118,   117,   118,   156,
     170,    18,   157,   171,    81,    82,   150,   151,   152,   169,
     177,    83,     7,    73,    72,   142,   143,   144,   145,   146,
     147,    73,    72,   178,    40,    41,    84,    64,   165,   179,
     180,    56,    57,    17,    25,   168,    26,    34,   -19,   -28,
      51,    58,    79,    80,    95,    97,    64,   102,    73,    72,
      96,   104,   108,   136,   130,   137,   138,   139,   140,   153,
     163,   173,    24,   161,   176,   106,   172,   128,    35,   122,
     181,     0,    52,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   174,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   182
  };

  const short
  Parser::yycheck_[] =
  {
       6,    40,    51,    51,    10,    29,    83,     6,    32,     3,
      97,    47,    18,   110,     5,    21,     5,    19,    20,    96,
     117,   118,    13,   100,    13,    16,    32,    16,    27,    10,
      11,    22,    23,    22,    23,    41,    26,    43,    44,     0,
      18,    31,    18,    45,    29,   132,    95,    32,    97,    97,
      99,    99,    31,   140,   131,    46,    47,    27,    47,    37,
      38,    39,    40,    41,    42,    43,    44,    43,    44,    29,
      29,     8,    32,    32,    24,    25,   119,   120,   121,   156,
     167,    31,    47,   132,   132,   111,   112,   113,   114,   115,
     116,   140,   140,   170,    28,    29,    46,    47,   137,    28,
      29,    47,    48,    30,    37,   154,     4,    27,    47,     5,
       5,    27,    27,    27,    31,    28,    47,    14,   167,   167,
      31,    31,    31,    27,    32,    28,    32,    32,    15,    17,
       4,    32,    21,    27,    27,    78,   161,    99,    30,    94,
     179,    -1,    42,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    50,    51,     0,     3,    47,    31,    47,    66,    67,
      29,    32,    66,    27,    52,    53,    54,    30,     8,    58,
      59,    60,    66,    55,    60,    37,     4,    61,    66,   111,
      62,    63,    64,    56,    27,    63,    65,    66,    68,    69,
      28,    29,    57,    10,    11,    70,    71,    72,    74,   111,
      66,     5,    83,    66,    66,    71,    53,    53,    27,    13,
      16,    22,    23,    46,    47,    83,    84,    85,    86,    89,
      90,    91,    92,    95,    96,    97,   101,    73,    75,    27,
      27,    24,    25,    31,    46,    92,    94,    95,   104,   106,
     107,   108,   109,   110,   102,    31,    31,    28,     6,    27,
      26,    31,    14,    99,    31,    76,    76,   106,    31,    98,
      18,    37,    38,    39,    40,    41,    42,    43,    44,    19,
      20,    45,   104,    88,    95,    87,   106,    86,    85,   106,
      32,    93,   100,    78,    79,    80,    27,    28,    32,    32,
      15,   108,   107,   107,   107,   107,   107,   107,   108,   108,
     109,   109,   109,    17,    29,    32,    29,    32,   105,   106,
      86,    27,    77,     4,    82,   111,    86,   103,    95,   106,
      29,    32,    79,    32,    66,    81,    27,    86,   106,    28,
      29,   111,    66
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    49,    51,    52,    50,    54,    55,    56,    57,    53,
      58,    58,    59,    59,    60,    61,    61,    62,    62,    64,
      63,    65,    65,    66,    67,    67,    69,    68,    68,    70,
      70,    71,    71,    73,    72,    75,    74,    77,    76,    76,
      78,    78,    80,    79,    81,    81,    82,    82,    83,    84,
      84,    85,    85,    85,    86,    86,    86,    86,    86,    86,
      86,    87,    87,    88,    88,    89,    90,    90,    91,    91,
      93,    92,    94,    95,    96,    98,    97,   100,    99,    99,
     102,   103,   101,   104,   105,   105,   106,   106,   106,   106,
     106,   106,   106,   107,   107,   107,   107,   108,   108,   108,
     108,   109,   109,   109,   109,   109,   110,   110,   110,   111
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     0,     0,    10,     0,     0,     0,     0,     8,
       2,     0,     2,     1,     4,     2,     0,     2,     1,     0,
       5,     3,     1,     1,     3,     1,     0,     2,     0,     2,
       1,     3,     3,     0,     5,     0,     7,     0,     4,     0,
       3,     1,     0,     5,     3,     1,     1,     0,     3,     3,
       1,     3,     1,     0,     1,     1,     1,     1,     1,     4,
       4,     3,     1,     3,     1,     3,     1,     1,     1,     3,
       0,     5,     3,     1,     2,     0,     5,     0,     3,     0,
       0,     0,     6,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "VAR",
  "T_BEGIN", "T_END", "LABEL", "TYPE", "ARRAY", "PROCEDURE", "FUNCTION",
  "GOTO", "IF", "ELSE", "THEN", "WHILE", "DO", "OR", "DIV", "AND", "NOT",
  "READ", "WRITE", "TRUE", "FALSE", "ATRIBUICAO", "PONTO_E_VIRGULA",
  "DOIS_PONTOS", "VIRGULA", "PONTO", "ABRE_PARENTESES", "FECHA_PARENTESES",
  "ABRE_CHAVE", "FECHA_CHAVE", "ABRE_COLCHETE", "FECHA_COLCHETE", "IGUAL",
  "DIFERENTE", "MENOR_QUE", "MENOR_OU_IGUAL", "MAIOR_OU_IGUAL",
  "MAIOR_QUE", "MAIS", "MENOS", "MULTI", "NUMERO", "IDENT",
  "LOWER_THAN_ELSE", "$accept", "programa", "$@1", "@2", "bloco", "@3",
  "$@4", "@5", "$@6", "parte_declara_tipo", "define_tipos", "define_tipo",
  "parte_declara_vars", "declara_vars", "declara_var", "$@7", "lista_var",
  "ident", "lista_idents", "parte_declara_subrotinas_wrap", "$@8",
  "parte_declara_subrotinas", "parte_declara_subrotinas_two",
  "declaracao_procedimento", "@9", "declaracao_funcao", "@10",
  "declaracao_params", "$@11", "parametros_formais",
  "secao_parametros_formais", "$@12", "lista_params", "tipo_parametro",
  "comando_composto", "lista_comandos", "comando", "comando_sem_rotulo",
  "lista_write", "lista_read", "atribuicao", "chamada_procedimento",
  "chamada_sem_pametro", "chamada_procedimento_parametros", "$@13",
  "chamada_funcao_sem_parametros", "variavel", "comando_condicional",
  "if_then", "$@14", "cond_else", "$@15", "comando_repetitivo", "$@16",
  "$@17", "expressao_booleana", "lista_de_expressoes", "expressao",
  "expressao_simples", "termo", "fator", "variavel_func", "tipo", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,    85,    85,    91,    85,   104,   118,   122,   128,   104,
     152,   157,   164,   165,   169,   178,   184,   192,   193,   197,
     197,   208,   215,   225,   233,   240,   251,   251,   262,   266,
     267,   271,   275,   285,   284,   306,   305,   328,   327,   334,
     342,   343,   348,   348,   366,   372,   381,   385,   393,   397,
     398,   403,   404,   405,   410,   411,   412,   413,   414,   415,
     416,   420,   424,   431,   436,   446,   462,   474,   482,   486,
     494,   493,   531,   546,   555,   560,   559,   568,   567,   575,
     584,   588,   583,   598,   607,   614,   625,   629,   633,   637,
     641,   645,   649,   654,   658,   662,   666,   671,   675,   679,
     683,   688,   693,   698,   703,   707,   712,   732,   740,   751
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
    };
    // Last valid token kind.
    const int code_max = 303;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 30 "src/bison.y"
} // bison
#line 2200 "bison.cpp"

#line 757 "src/bison.y"


void bison::Parser::error(const std::string& msg) {
    std::cerr << msg << " at line " << nl <<'\n';
    std::cerr << "with token " << simbolo_flex << '\n';
    exit(0);
}
