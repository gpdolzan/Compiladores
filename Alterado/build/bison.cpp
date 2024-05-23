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
int top_desloc = 0;

std::list<Param> *params;
std::stack<std::list<Param>> expression_list_types = {};
std::stack<std::stack<Param>> calling_proc_params = {};

#line 62 "bison.cpp"


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

#line 29 "src/bison.y"
namespace bison {
#line 141 "bison.cpp"

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
      case symbol_kind::S_55_4: // @4
      case symbol_kind::S_declaracao_procedimento: // declaracao_procedimento
      case symbol_kind::S_69_8: // @8
      case symbol_kind::S_declaracao_funcao: // declaracao_funcao
      case symbol_kind::S_71_9: // @9
      case symbol_kind::S_chamada_sem_pametro: // chamada_sem_pametro
      case symbol_kind::S_chamada_procedimento_parametros: // chamada_procedimento_parametros
      case symbol_kind::S_chamada_funcao_sem_parametros: // chamada_funcao_sem_parametros
      case symbol_kind::S_variavel: // variavel
        value.copy< Simbolo* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parte_declara_vars: // parte_declara_vars
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ident: // ident
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo_parametro: // tipo_parametro
        value.copy< tipo_parametro > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo: // tipo
        value.copy< tipo_variavel > (YY_MOVE (that.value));
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
      case symbol_kind::S_55_4: // @4
      case symbol_kind::S_declaracao_procedimento: // declaracao_procedimento
      case symbol_kind::S_69_8: // @8
      case symbol_kind::S_declaracao_funcao: // declaracao_funcao
      case symbol_kind::S_71_9: // @9
      case symbol_kind::S_chamada_sem_pametro: // chamada_sem_pametro
      case symbol_kind::S_chamada_procedimento_parametros: // chamada_procedimento_parametros
      case symbol_kind::S_chamada_funcao_sem_parametros: // chamada_funcao_sem_parametros
      case symbol_kind::S_variavel: // variavel
        value.move< Simbolo* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_parte_declara_vars: // parte_declara_vars
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ident: // ident
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tipo_parametro: // tipo_parametro
        value.move< tipo_parametro > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tipo: // tipo
        value.move< tipo_variavel > (YY_MOVE (s.value));
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
      case symbol_kind::S_55_4: // @4
      case symbol_kind::S_declaracao_procedimento: // declaracao_procedimento
      case symbol_kind::S_69_8: // @8
      case symbol_kind::S_declaracao_funcao: // declaracao_funcao
      case symbol_kind::S_71_9: // @9
      case symbol_kind::S_chamada_sem_pametro: // chamada_sem_pametro
      case symbol_kind::S_chamada_procedimento_parametros: // chamada_procedimento_parametros
      case symbol_kind::S_chamada_funcao_sem_parametros: // chamada_funcao_sem_parametros
      case symbol_kind::S_variavel: // variavel
        value.YY_MOVE_OR_COPY< Simbolo* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parte_declara_vars: // parte_declara_vars
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ident: // ident
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo_parametro: // tipo_parametro
        value.YY_MOVE_OR_COPY< tipo_parametro > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo: // tipo
        value.YY_MOVE_OR_COPY< tipo_variavel > (YY_MOVE (that.value));
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
      case symbol_kind::S_55_4: // @4
      case symbol_kind::S_declaracao_procedimento: // declaracao_procedimento
      case symbol_kind::S_69_8: // @8
      case symbol_kind::S_declaracao_funcao: // declaracao_funcao
      case symbol_kind::S_71_9: // @9
      case symbol_kind::S_chamada_sem_pametro: // chamada_sem_pametro
      case symbol_kind::S_chamada_procedimento_parametros: // chamada_procedimento_parametros
      case symbol_kind::S_chamada_funcao_sem_parametros: // chamada_funcao_sem_parametros
      case symbol_kind::S_variavel: // variavel
        value.move< Simbolo* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parte_declara_vars: // parte_declara_vars
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ident: // ident
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo_parametro: // tipo_parametro
        value.move< tipo_parametro > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo: // tipo
        value.move< tipo_variavel > (YY_MOVE (that.value));
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
      case symbol_kind::S_55_4: // @4
      case symbol_kind::S_declaracao_procedimento: // declaracao_procedimento
      case symbol_kind::S_69_8: // @8
      case symbol_kind::S_declaracao_funcao: // declaracao_funcao
      case symbol_kind::S_71_9: // @9
      case symbol_kind::S_chamada_sem_pametro: // chamada_sem_pametro
      case symbol_kind::S_chamada_procedimento_parametros: // chamada_procedimento_parametros
      case symbol_kind::S_chamada_funcao_sem_parametros: // chamada_funcao_sem_parametros
      case symbol_kind::S_variavel: // variavel
        value.copy< Simbolo* > (that.value);
        break;

      case symbol_kind::S_parte_declara_vars: // parte_declara_vars
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_ident: // ident
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_tipo_parametro: // tipo_parametro
        value.copy< tipo_parametro > (that.value);
        break;

      case symbol_kind::S_tipo: // tipo
        value.copy< tipo_variavel > (that.value);
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
      case symbol_kind::S_55_4: // @4
      case symbol_kind::S_declaracao_procedimento: // declaracao_procedimento
      case symbol_kind::S_69_8: // @8
      case symbol_kind::S_declaracao_funcao: // declaracao_funcao
      case symbol_kind::S_71_9: // @9
      case symbol_kind::S_chamada_sem_pametro: // chamada_sem_pametro
      case symbol_kind::S_chamada_procedimento_parametros: // chamada_procedimento_parametros
      case symbol_kind::S_chamada_funcao_sem_parametros: // chamada_funcao_sem_parametros
      case symbol_kind::S_variavel: // variavel
        value.move< Simbolo* > (that.value);
        break;

      case symbol_kind::S_parte_declara_vars: // parte_declara_vars
        value.move< int > (that.value);
        break;

      case symbol_kind::S_ident: // ident
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_tipo_parametro: // tipo_parametro
        value.move< tipo_parametro > (that.value);
        break;

      case symbol_kind::S_tipo: // tipo
        value.move< tipo_variavel > (that.value);
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
      case symbol_kind::S_55_4: // @4
      case symbol_kind::S_declaracao_procedimento: // declaracao_procedimento
      case symbol_kind::S_69_8: // @8
      case symbol_kind::S_declaracao_funcao: // declaracao_funcao
      case symbol_kind::S_71_9: // @9
      case symbol_kind::S_chamada_sem_pametro: // chamada_sem_pametro
      case symbol_kind::S_chamada_procedimento_parametros: // chamada_procedimento_parametros
      case symbol_kind::S_chamada_funcao_sem_parametros: // chamada_funcao_sem_parametros
      case symbol_kind::S_variavel: // variavel
        yylhs.value.emplace< Simbolo* > ();
        break;

      case symbol_kind::S_parte_declara_vars: // parte_declara_vars
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_ident: // ident
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_tipo_parametro: // tipo_parametro
        yylhs.value.emplace< tipo_parametro > ();
        break;

      case symbol_kind::S_tipo: // tipo
        yylhs.value.emplace< tipo_variavel > ();
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
#line 83 "src/bison.y"
   {
      iniciaCompilador();
      geraCodigo("INPP");
   }
#line 892 "bison.cpp"
    break;

  case 3: // @2: %empty
#line 89 "src/bison.y"
             {
      simbolo_main = new Simbolo("main", lexic_level, new std::list<Param>(), main_process);

      yylhs.value.as < Simbolo* > () = simbolo_main;
   }
#line 902 "bison.cpp"
    break;

  case 4: // programa: $@1 PROGRAM IDENT ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA @2 bloco PONTO
#line 95 "src/bison.y"
   {
      geraCodigo("PARA");
      desligaCompilador();
   }
#line 911 "bison.cpp"
    break;

  case 5: // @3: %empty
#line 102 "src/bison.y"
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
#line 929 "bison.cpp"
    break;

  case 6: // @4: %empty
#line 116 "src/bison.y"
             {
      yystack_[1].value.as < Simbolo* > ()->number_vars = yystack_[0].value.as < int > ();

      yylhs.value.as < Simbolo* > () = yystack_[1].value.as < Simbolo* > ();
   }
#line 939 "bison.cpp"
    break;

  case 7: // $@5: %empty
#line 122 "src/bison.y"
   {
      if (yystack_[3].value.as < Simbolo* > ()->is_func())
         yystack_[3].value.as < Simbolo* > ()->allow_return = true;
   }
#line 948 "bison.cpp"
    break;

  case 8: // bloco: @3 parte_declara_vars @4 parte_declara_subrotinas_wrap $@5 comando_composto
#line 127 "src/bison.y"
   {
      Simbolo* proce = yystack_[5].value.as < Simbolo* > ();

      if(!proce->is_main())
         removeSimbolos(proce->parametros->size() + proce->number_vars);

      geraCodigo("DMEM", proce->number_vars);

      visualizaTabela();

      if (proce->is_proc_or_func())
         geraCodigo("RTPR", proce->nivel_lexico, proce->parametros->size());

      if (proce->is_func())
         yystack_[5].value.as < Simbolo* > ()->allow_return = false;
   }
#line 969 "bison.cpp"
    break;

  case 9: // parte_declara_vars: VAR declara_vars
#line 148 "src/bison.y"
   {
      geraCodigo("AMEM", num_total_vars);
      yylhs.value.as < int > () = num_total_vars;
      visualizaTabela();
   }
#line 979 "bison.cpp"
    break;

  case 10: // parte_declara_vars: %empty
#line 154 "src/bison.y"
   {
      yylhs.value.as < int > () = 0;
   }
#line 987 "bison.cpp"
    break;

  case 13: // $@6: %empty
#line 166 "src/bison.y"
   {
      num_same_type_vars = 0;
   }
#line 995 "bison.cpp"
    break;

  case 14: // declara_var: $@6 lista_var DOIS_PONTOS tipo PONTO_E_VIRGULA
#line 170 "src/bison.y"
   {
      colocaTipoEmSimbolos(yystack_[1].value.as< tipo_variavel > (), num_same_type_vars);
      num_same_type_vars = 0;
   }
#line 1004 "bison.cpp"
    break;

  case 15: // lista_var: lista_var VIRGULA ident
#line 178 "src/bison.y"
   {
      insereSimbolo(new Simbolo(yystack_[0].value.as < std::string > (), lexic_level, top_desloc, variavel_simples));
      top_desloc++;
      num_total_vars++;
      num_same_type_vars++;
   }
#line 1015 "bison.cpp"
    break;

  case 16: // lista_var: ident
#line 185 "src/bison.y"
   {
      insereSimbolo(new Simbolo(yystack_[0].value.as < std::string > (), lexic_level, top_desloc, variavel_simples));
      top_desloc++;
      num_total_vars++;
      num_same_type_vars++;
   }
#line 1026 "bison.cpp"
    break;

  case 17: // ident: IDENT
#line 195 "src/bison.y"
   {
      yylhs.value.as < std::string > () = simbolo_flex;
   }
#line 1034 "bison.cpp"
    break;

  case 20: // $@7: %empty
#line 220 "src/bison.y"
   {
      Simbolo *proc = yystack_[0].value.as< Simbolo* > ();

      geraCodigo("DSVS", "", proc->rotulo_begin()->identificador);
   }
#line 1044 "bison.cpp"
    break;

  case 21: // parte_declara_subrotinas_wrap: $@7 parte_declara_subrotinas
#line 226 "src/bison.y"
   {
      Simbolo *proc = yystack_[2].value.as< Simbolo* > ();

      geraCodigo("NADA", proc->rotulo_begin()->identificador);
   }
#line 1054 "bison.cpp"
    break;

  case 25: // parte_declara_subrotinas_two: declaracao_procedimento bloco PONTO_E_VIRGULA
#line 241 "src/bison.y"
   {
      lexic_level--;
   }
#line 1062 "bison.cpp"
    break;

  case 26: // parte_declara_subrotinas_two: declaracao_funcao bloco PONTO_E_VIRGULA
#line 246 "src/bison.y"
   {
      lexic_level--;
   }
#line 1070 "bison.cpp"
    break;

  case 27: // @8: %empty
#line 254 "src/bison.y"
             {
      lexic_level++;
      num_total_vars = 0;
      num_total_params = 0;
      
      params = new std::list<Param>();
      Simbolo *proce = new Simbolo(yystack_[0].value.as < std::string > (), lexic_level, params, process);
      insereSimbolo(proce);

      yylhs.value.as < Simbolo* > () = proce;
   }
#line 1086 "bison.cpp"
    break;

  case 28: // declaracao_procedimento: PROCEDURE ident @8 declaracao_params PONTO_E_VIRGULA
#line 266 "src/bison.y"
   {
      yylhs.value.as < Simbolo* > () = yystack_[2].value.as < Simbolo* > ();
   }
#line 1094 "bison.cpp"
    break;

  case 29: // @9: %empty
#line 274 "src/bison.y"
             {
      lexic_level++;
      num_total_vars = 0;
      num_total_params = 0;
      
      params = new std::list<Param>();
      Simbolo *proce = new Simbolo(yystack_[0].value.as < std::string > (), lexic_level, params, function);
      insereSimbolo(proce);
      
      yylhs.value.as < Simbolo* > () = proce;
   }
#line 1110 "bison.cpp"
    break;

  case 30: // declaracao_funcao: FUNCTION ident @9 declaracao_params DOIS_PONTOS tipo PONTO_E_VIRGULA
#line 286 "src/bison.y"
   {
      yylhs.value.as < Simbolo* > () = yystack_[4].value.as < Simbolo* > ();
      yystack_[4].value.as < Simbolo* > ()->tipo_param = t_copy;
      yystack_[4].value.as < Simbolo* > ()->deslocamento = -(4 + num_total_params);
      yystack_[4].value.as < Simbolo* > ()->tipo_v = yystack_[1].value.as < tipo_variavel > ();
   }
#line 1121 "bison.cpp"
    break;

  case 31: // $@10: %empty
#line 296 "src/bison.y"
   {
      colocaDeslocEmParams(num_total_params);
      
      params = nullptr;
   }
#line 1131 "bison.cpp"
    break;

  case 33: // declaracao_params: %empty
#line 303 "src/bison.y"
   {
      params = nullptr;
   }
#line 1139 "bison.cpp"
    break;

  case 36: // $@11: %empty
#line 316 "src/bison.y"
   {
      num_same_type_vars = 0;
   }
#line 1147 "bison.cpp"
    break;

  case 37: // secao_parametros_formais: $@11 tipo_parametro lista_params DOIS_PONTOS tipo
#line 320 "src/bison.y"
   {
      tipo_variavel tipo_v = yystack_[0].value.as< tipo_variavel > ();
      tipo_parametro tipo_param = yystack_[3].value.as< tipo_parametro > ();

      for(int i = 0;i < num_same_type_vars;i++) {
         params->push_back(Param(tipo_v, tipo_param));
      }

      colocaTipoEmSimbolos(tipo_v, num_same_type_vars);
      colocaTipoEmSimbolos(tipo_param, num_same_type_vars);
   }
#line 1163 "bison.cpp"
    break;

  case 38: // lista_params: lista_params VIRGULA ident
#line 335 "src/bison.y"
   {
      insereSimbolo(new Simbolo(yystack_[0].value.as < std::string > (), lexic_level, 0, parametros_formais));
      num_total_params++;
      num_same_type_vars++;
   }
#line 1173 "bison.cpp"
    break;

  case 39: // lista_params: ident
#line 341 "src/bison.y"
   {
      insereSimbolo(new Simbolo(yystack_[0].value.as < std::string > (), lexic_level, 0, parametros_formais));
      num_total_params++;
      num_same_type_vars++;
   }
#line 1183 "bison.cpp"
    break;

  case 40: // tipo_parametro: VAR
#line 350 "src/bison.y"
   {
      yylhs.value.as < tipo_parametro > () = t_pointer;
   }
#line 1191 "bison.cpp"
    break;

  case 41: // tipo_parametro: %empty
#line 354 "src/bison.y"
   {
      yylhs.value.as < tipo_parametro > () = t_copy;
   }
#line 1199 "bison.cpp"
    break;

  case 55: // lista_write: lista_write VIRGULA expressao
#line 389 "src/bison.y"
   {
      geraCodigo("IMPR");
   }
#line 1207 "bison.cpp"
    break;

  case 56: // lista_write: expressao
#line 393 "src/bison.y"
   {
      geraCodigo("IMPR");
   }
#line 1215 "bison.cpp"
    break;

  case 57: // lista_read: lista_read VIRGULA variavel
#line 400 "src/bison.y"
   {
      geraCodigo("LEIT");
      aplicarArmazena(yystack_[0].value.as < Simbolo* > ());
   }
#line 1224 "bison.cpp"
    break;

  case 58: // lista_read: variavel
#line 405 "src/bison.y"
   {
      geraCodigo("LEIT");
      aplicarArmazena(yystack_[0].value.as < Simbolo* > ());
   }
#line 1233 "bison.cpp"
    break;

  case 59: // atribuicao: variavel ATRIBUICAO expressao
#line 417 "src/bison.y"
   {
      if(yystack_[2].value.as < Simbolo* > ()->is_func())
         if(!yystack_[2].value.as < Simbolo* > ()->allow_return)
            error("Função não pode ser usada como variável");
      
      if(yystack_[2].value.as < Simbolo* > ()->tipo_v == yystack_[0].value.as < Param > ().tipo_v)
         aplicarArmazena(yystack_[2].value.as < Simbolo* > ());
      else
         error("Tipos incompatíveis na atribuição");
   }
#line 1248 "bison.cpp"
    break;

  case 60: // chamada_procedimento: chamada_sem_pametro
#line 432 "src/bison.y"
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
#line 1264 "bison.cpp"
    break;

  case 61: // chamada_procedimento: chamada_procedimento_parametros
#line 444 "src/bison.y"
   {
      if(yystack_[0].value.as < Simbolo* > ()->is_func())
         geraCodigo("DMEM", 1);
   }
#line 1273 "bison.cpp"
    break;

  case 62: // chamada_sem_pametro: variavel
#line 452 "src/bison.y"
   {
      yylhs.value.as < Simbolo* > () = yystack_[0].value.as < Simbolo* > ();
   }
#line 1281 "bison.cpp"
    break;

  case 63: // chamada_sem_pametro: variavel ABRE_PARENTESES FECHA_PARENTESES
#line 456 "src/bison.y"
   {
      yylhs.value.as < Simbolo* > () = yystack_[2].value.as < Simbolo* > ();
   }
#line 1289 "bison.cpp"
    break;

  case 64: // $@12: %empty
#line 463 "src/bison.y"
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
#line 1310 "bison.cpp"
    break;

  case 65: // chamada_procedimento_parametros: variavel ABRE_PARENTESES $@12 lista_de_expressoes FECHA_PARENTESES
#line 480 "src/bison.y"
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
#line 1332 "bison.cpp"
    break;

  case 66: // chamada_funcao_sem_parametros: variavel ABRE_PARENTESES FECHA_PARENTESES
#line 501 "src/bison.y"
   {
      Simbolo *proc = yystack_[2].value.as < Simbolo* > ();

      if(!proc->is_func())
         error("Chamada de função inválida");
      
      geraCodigo("AMEM", 1);
      geraCodigo("CHPR", "", yystack_[2].value.as < Simbolo* > ()->rotulo_enpr()->identificador, std::to_string(lexic_level));
      
      yylhs.value.as < Simbolo* > () = yystack_[2].value.as < Simbolo* > ();
   }
#line 1348 "bison.cpp"
    break;

  case 67: // variavel: IDENT
#line 516 "src/bison.y"
   {
      Simbolo* simbolo = buscaSimbolo(simbolo_flex);
      yylhs.value.as < Simbolo* > () = simbolo;
   }
#line 1357 "bison.cpp"
    break;

  case 69: // $@13: %empty
#line 529 "src/bison.y"
   {
      start_if();
   }
#line 1365 "bison.cpp"
    break;

  case 71: // $@14: %empty
#line 537 "src/bison.y"
   {
      start_else();
   }
#line 1373 "bison.cpp"
    break;

  case 72: // cond_else: ELSE $@14 comando_sem_rotulo
#line 541 "src/bison.y"
   {
      end_else();
   }
#line 1381 "bison.cpp"
    break;

  case 73: // cond_else: %empty
#line 545 "src/bison.y"
   {
      end_if();
   }
#line 1389 "bison.cpp"
    break;

  case 74: // $@15: %empty
#line 553 "src/bison.y"
   {
      start_while();
   }
#line 1397 "bison.cpp"
    break;

  case 75: // $@16: %empty
#line 557 "src/bison.y"
   {
      do_while();
   }
#line 1405 "bison.cpp"
    break;

  case 76: // comando_repetitivo: WHILE $@15 expressao_booleana DO $@16 comando_sem_rotulo
#line 561 "src/bison.y"
   {
      end_while();
   }
#line 1413 "bison.cpp"
    break;

  case 77: // expressao_booleana: expressao
#line 568 "src/bison.y"
   {
      if(yystack_[0].value.as < Param > ().tipo_v != t_bool)
         error("Expressão booleana inválida");
   }
#line 1422 "bison.cpp"
    break;

  case 78: // lista_de_expressoes: lista_de_expressoes VIRGULA expressao
#line 577 "src/bison.y"
   {
      expression_list_types.top().push_back(yystack_[0].value.as < Param > ());
      if(calling_proc_params.top().empty())
         error("Número de parâmetros inválido");
      calling_proc_params.top().pop();
   }
#line 1433 "bison.cpp"
    break;

  case 79: // lista_de_expressoes: expressao
#line 584 "src/bison.y"
   {
      expression_list_types.top().push_back(yystack_[0].value.as < Param > ());
      if(calling_proc_params.top().empty())
         error("Número de parâmetros inválido");
      calling_proc_params.top().pop();
   }
#line 1444 "bison.cpp"
    break;

  case 80: // expressao: expressao_simples MENOR_QUE expressao_simples
#line 595 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("CMME", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1452 "bison.cpp"
    break;

  case 81: // expressao: expressao_simples MAIOR_QUE expressao_simples
#line 599 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("CMMA", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1460 "bison.cpp"
    break;

  case 82: // expressao: expressao_simples IGUAL expressao_simples
#line 603 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("CMIG", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1468 "bison.cpp"
    break;

  case 83: // expressao: expressao_simples DIFERENTE expressao_simples
#line 607 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("CMDG", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1476 "bison.cpp"
    break;

  case 84: // expressao: expressao_simples MAIOR_OU_IGUAL expressao_simples
#line 611 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("CMAG", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1484 "bison.cpp"
    break;

  case 85: // expressao: expressao_simples MENOR_OU_IGUAL expressao_simples
#line 615 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("CMEG", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1492 "bison.cpp"
    break;

  case 86: // expressao: expressao_simples
#line 618 "src/bison.y"
     { yylhs.value.as < Param > () = yystack_[0].value.as < Param > (); }
#line 1498 "bison.cpp"
    break;

  case 87: // expressao_simples: expressao_simples MAIS termo
#line 624 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("SOMA", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1506 "bison.cpp"
    break;

  case 88: // expressao_simples: expressao_simples MENOS termo
#line 628 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("SUBT", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1514 "bison.cpp"
    break;

  case 89: // expressao_simples: expressao_simples OR termo
#line 632 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("DISJ", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1522 "bison.cpp"
    break;

  case 90: // expressao_simples: termo
#line 635 "src/bison.y"
     { yylhs.value.as < Param > () = yystack_[0].value.as < Param > (); }
#line 1528 "bison.cpp"
    break;

  case 91: // termo: termo MULTI fator
#line 641 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("MULT", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1536 "bison.cpp"
    break;

  case 92: // termo: termo DIV fator
#line 645 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("DIVI", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1544 "bison.cpp"
    break;

  case 93: // termo: termo AND fator
#line 649 "src/bison.y"
   {
      yylhs.value.as < Param > () = aplicarOperacao("CONJ", yystack_[2].value.as < Param > (), yystack_[0].value.as < Param > ());
   }
#line 1552 "bison.cpp"
    break;

  case 94: // termo: fator
#line 652 "src/bison.y"
     { yylhs.value.as < Param > () = yystack_[0].value.as < Param > (); }
#line 1558 "bison.cpp"
    break;

  case 95: // fator: NUMERO
#line 658 "src/bison.y"
   {
      geraCodigo("CRCT", "", simbolo_flex);
      yylhs.value.as < Param > () = Param(t_int, t_copy);
   }
#line 1567 "bison.cpp"
    break;

  case 96: // fator: TRUE
#line 663 "src/bison.y"
   {
      geraCodigo("CRCT", 1);
      yylhs.value.as < Param > () = Param(t_bool, t_copy);
   }
#line 1576 "bison.cpp"
    break;

  case 97: // fator: FALSE
#line 668 "src/bison.y"
   {
      geraCodigo("CRCT", 0);
      yylhs.value.as < Param > () = Param(t_bool, t_copy);
   }
#line 1585 "bison.cpp"
    break;

  case 98: // fator: ABRE_PARENTESES expressao FECHA_PARENTESES
#line 673 "src/bison.y"
   {
      yylhs.value.as < Param > () = yystack_[1].value.as < Param > ();
   }
#line 1593 "bison.cpp"
    break;

  case 99: // fator: variavel_func
#line 676 "src/bison.y"
     { yylhs.value.as < Param > () = yystack_[0].value.as < Param > (); }
#line 1599 "bison.cpp"
    break;

  case 100: // variavel_func: variavel
#line 682 "src/bison.y"
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
#line 1623 "bison.cpp"
    break;

  case 101: // variavel_func: chamada_procedimento_parametros
#line 702 "src/bison.y"
   {
      Simbolo* proc = yystack_[0].value.as < Simbolo* > ();
      if(!proc->is_func())
         error("Chamada de função inválida");

      yylhs.value.as < Param > () = Param(proc->tipo_v, proc->tipo_param);
   }
#line 1635 "bison.cpp"
    break;

  case 102: // variavel_func: chamada_funcao_sem_parametros
#line 710 "src/bison.y"
   {
      Simbolo* proc = yystack_[0].value.as < Simbolo* > ();
      if(!proc->is_func())
         error("Chamada de função inválida");

      yylhs.value.as < Param > () = Param(proc->tipo_v, proc->tipo_param);
   }
#line 1647 "bison.cpp"
    break;

  case 103: // tipo: IDENT
#line 721 "src/bison.y"
   {
      if (simbolo_flex == "boolean")
         yylhs.value.as < tipo_variavel > () = t_bool;
      else if (simbolo_flex == "integer")
         yylhs.value.as < tipo_variavel > () = t_int;
      else {
         yylhs.value.as < tipo_variavel > () = t_undefined;
         error("Tipo inválido");
      }
   }
#line 1662 "bison.cpp"
    break;


#line 1666 "bison.cpp"

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









  const signed char Parser::yypact_ninf_ = -119;

  const signed char Parser::yytable_ninf_ = -23;

  const signed char
  Parser::yypact_[] =
  {
    -119,    17,    10,  -119,   -28,    41,    -8,  -119,  -119,   -18,
      -8,    16,  -119,  -119,  -119,    62,    76,  -119,  -119,  -119,
      47,  -119,    -8,    92,  -119,    26,  -119,  -119,    60,    56,
      -8,   100,    -8,    -8,    60,  -119,  -119,  -119,  -119,    79,
    -119,    11,  -119,  -119,  -119,  -119,    80,    81,  -119,    28,
    -119,    78,    82,    83,  -119,  -119,     1,  -119,  -119,  -119,
    -119,  -119,  -119,   -16,  -119,    96,  -119,    84,    84,  -119,
    -119,  -119,  -119,    28,  -119,  -119,  -119,    85,  -119,  -119,
      24,   -15,  -119,  -119,    28,    67,    28,    13,  -119,    11,
      28,    87,  -119,  -119,  -119,    93,    94,    89,    91,    97,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,   107,     8,  -119,    12,  -119,  -119,  -119,  -119,
    -119,    28,    13,    98,  -119,   122,  -119,    56,  -119,  -119,
      13,   -15,   -12,   -12,   -12,   -12,   -12,   -12,   -15,   -15,
    -119,  -119,  -119,  -119,    67,  -119,    28,  -119,    64,  -119,
    -119,  -119,    95,  -119,    -8,   101,  -119,    13,  -119,  -119,
      28,  -119,  -119,  -119,  -119,    50,  -119,  -119,  -119,    56,
      -8,  -119,  -119
  };

  const signed char
  Parser::yydefact_[] =
  {
       2,     0,     0,     1,     0,     0,     0,    17,    19,     0,
       0,     0,    18,     3,     5,     0,    10,     4,    13,     6,
       9,    12,     0,    20,    11,     0,    16,     7,     0,     0,
       0,     0,     0,     0,    21,    24,     5,     5,   103,     0,
      15,    47,     8,    27,    29,    23,     0,     0,    14,     0,
      74,     0,     0,     0,    67,    50,     0,    44,    46,    48,
      49,    60,    61,    62,    52,    73,    51,    33,    33,    25,
      26,    96,    97,     0,    95,   101,   102,   100,    69,    77,
      86,    90,    94,    99,     0,     0,     0,     0,    42,    47,
       0,    64,    71,    68,    36,     0,     0,     0,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,    56,    45,    43,    59,
      63,     0,     0,    31,    35,    41,    28,     0,    98,    66,
       0,    89,    82,    83,    80,    85,    84,    81,    87,    88,
      92,    93,    91,    75,     0,    54,     0,    53,     0,    79,
      72,    36,     0,    40,     0,     0,    70,     0,    57,    55,
       0,    65,    34,    32,    39,     0,    30,    76,    78,     0,
       0,    37,    38
  };

  const signed char
  Parser::yypgoto_[] =
  {
    -119,  -119,  -119,  -119,    65,  -119,  -119,  -119,  -119,  -119,
     109,  -119,  -119,   -10,  -119,  -119,  -119,  -119,    99,  -119,
    -119,  -119,  -119,    63,  -119,  -119,   -21,  -119,  -119,  -119,
     103,  -119,    43,   -84,  -119,  -119,  -119,  -119,  -119,   -39,
    -119,  -119,   -40,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,    51,  -119,   -65,   -17,   -31,   -11,  -119,  -118
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     1,     2,    14,    15,    16,    23,    31,    19,    20,
      21,    22,    25,     8,     9,    27,    28,    34,    35,    36,
      67,    37,    68,    95,   152,   123,   124,   125,   165,   154,
      55,    56,    57,    58,   115,   113,    59,    60,    61,    75,
     121,    76,    77,    64,    65,    99,    93,   122,    66,    84,
     157,    78,   148,    79,    80,    81,    82,    83,    39
  };

  const short
  Parser::yytable_[] =
  {
      12,    63,    62,   117,   109,   110,   100,    88,    97,   155,
      90,    10,    26,     4,    11,    91,    41,     3,    41,     5,
      40,   116,    43,    44,    49,   119,    49,    50,    89,    50,
     111,   107,   108,    51,    52,    51,    52,   144,   150,     7,
     145,   146,   100,    13,   147,   114,   156,    63,    62,    63,
      62,   171,    71,    72,    29,    30,   149,    53,    54,    73,
      54,   101,   102,   103,   104,   105,   106,   107,   108,   131,
      32,    33,     6,   167,    74,    54,   138,   139,   169,   170,
      18,   159,    63,    62,   132,   133,   134,   135,   136,   137,
      63,    62,    17,   160,   -13,   168,   161,   -22,   140,   141,
     142,    46,    47,    38,   158,    41,    48,    69,    70,    85,
      92,    87,   130,    86,    54,    94,    98,    63,    62,   120,
     126,   128,   127,   129,   143,   151,   153,   163,   166,    24,
     162,    96,   118,    45,    42,   112,     0,     0,     0,     0,
       0,     0,     0,     0,   164,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     172
  };

  const short
  Parser::yycheck_[] =
  {
      10,    41,    41,    87,    19,    20,    18,     6,    73,   127,
      26,    29,    22,     3,    32,    31,     5,     0,     5,    47,
      30,    86,    32,    33,    13,    90,    13,    16,    27,    16,
      45,    43,    44,    22,    23,    22,    23,    29,   122,    47,
      32,    29,    18,    27,    32,    85,   130,    87,    87,    89,
      89,   169,    24,    25,    28,    29,   121,    46,    47,    31,
      47,    37,    38,    39,    40,    41,    42,    43,    44,   100,
      10,    11,    31,   157,    46,    47,   107,   108,    28,    29,
       4,   146,   122,   122,   101,   102,   103,   104,   105,   106,
     130,   130,    30,    29,    47,   160,    32,     5,   109,   110,
     111,    36,    37,    47,   144,     5,    27,    27,    27,    31,
      14,    28,    15,    31,    47,    31,    31,   157,   157,    32,
      27,    32,    28,    32,    17,    27,     4,    32,    27,    20,
     151,    68,    89,    34,    31,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     170
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    50,    51,     0,     3,    47,    31,    47,    62,    63,
      29,    32,    62,    27,    52,    53,    54,    30,     4,    57,
      58,    59,    60,    55,    59,    61,    62,    64,    65,    28,
      29,    56,    10,    11,    66,    67,    68,    70,    47,   107,
      62,     5,    79,    62,    62,    67,    53,    53,    27,    13,
      16,    22,    23,    46,    47,    79,    80,    81,    82,    85,
      86,    87,    88,    91,    92,    93,    97,    69,    71,    27,
      27,    24,    25,    31,    46,    88,    90,    91,   100,   102,
     103,   104,   105,   106,    98,    31,    31,    28,     6,    27,
      26,    31,    14,    95,    31,    72,    72,   102,    31,    94,
      18,    37,    38,    39,    40,    41,    42,    43,    44,    19,
      20,    45,   100,    84,    91,    83,   102,    82,    81,   102,
      32,    89,    96,    74,    75,    76,    27,    28,    32,    32,
      15,   104,   103,   103,   103,   103,   103,   103,   104,   104,
     105,   105,   105,    17,    29,    32,    29,    32,   101,   102,
      82,    27,    73,     4,    78,   107,    82,    99,    91,   102,
      29,    32,    75,    32,    62,    77,    27,    82,   102,    28,
      29,   107,    62
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    49,    51,    52,    50,    54,    55,    56,    53,    57,
      57,    58,    58,    60,    59,    61,    61,    62,    63,    63,
      65,    64,    64,    66,    66,    67,    67,    69,    68,    71,
      70,    73,    72,    72,    74,    74,    76,    75,    77,    77,
      78,    78,    79,    80,    80,    81,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    84,    84,    85,
      86,    86,    87,    87,    89,    88,    90,    91,    92,    94,
      93,    96,    95,    95,    98,    99,    97,   100,   101,   101,
     102,   102,   102,   102,   102,   102,   102,   103,   103,   103,
     103,   104,   104,   104,   104,   105,   105,   105,   105,   105,
     106,   106,   106,   107
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     0,     0,    10,     0,     0,     0,     6,     2,
       0,     2,     1,     0,     5,     3,     1,     1,     3,     1,
       0,     2,     0,     2,     1,     3,     3,     0,     5,     0,
       7,     0,     4,     0,     3,     1,     0,     5,     3,     1,
       1,     0,     3,     3,     1,     3,     1,     0,     1,     1,
       1,     1,     1,     4,     4,     3,     1,     3,     1,     3,
       1,     1,     1,     3,     0,     5,     3,     1,     2,     0,
       5,     0,     3,     0,     0,     0,     6,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1
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
  "@4", "$@5", "parte_declara_vars", "declara_vars", "declara_var", "$@6",
  "lista_var", "ident", "lista_idents", "parte_declara_subrotinas_wrap",
  "$@7", "parte_declara_subrotinas", "parte_declara_subrotinas_two",
  "declaracao_procedimento", "@8", "declaracao_funcao", "@9",
  "declaracao_params", "$@10", "parametros_formais",
  "secao_parametros_formais", "$@11", "lista_params", "tipo_parametro",
  "comando_composto", "lista_comandos", "comando", "comando_sem_rotulo",
  "lista_write", "lista_read", "atribuicao", "chamada_procedimento",
  "chamada_sem_pametro", "chamada_procedimento_parametros", "$@12",
  "chamada_funcao_sem_parametros", "variavel", "comando_condicional",
  "if_then", "$@13", "cond_else", "$@14", "comando_repetitivo", "$@15",
  "$@16", "expressao_booleana", "lista_de_expressoes", "expressao",
  "expressao_simples", "termo", "fator", "variavel_func", "tipo", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,    83,    83,    89,    83,   102,   116,   122,   102,   147,
     153,   161,   162,   166,   166,   177,   184,   194,   202,   209,
     220,   220,   231,   235,   236,   240,   244,   254,   253,   274,
     273,   296,   295,   302,   310,   311,   316,   316,   334,   340,
     349,   353,   361,   365,   366,   371,   372,   373,   378,   379,
     380,   381,   382,   383,   384,   388,   392,   399,   404,   414,
     431,   443,   451,   455,   463,   462,   500,   515,   524,   529,
     528,   537,   536,   544,   553,   557,   552,   567,   576,   583,
     594,   598,   602,   606,   610,   614,   618,   623,   627,   631,
     635,   640,   644,   648,   652,   657,   662,   667,   672,   676,
     681,   701,   709,   720
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

#line 29 "src/bison.y"
} // bison
#line 2157 "bison.cpp"

#line 733 "src/bison.y"


void bison::Parser::error(const std::string& msg) {
    std::cerr << msg << " at line " << nl <<'\n';
    std::cerr << "with token " << simbolo_flex << '\n';
    exit(0);
}
