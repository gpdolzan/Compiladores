// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file bison.hpp
 ** Define the bison::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_BISON_HPP_INCLUDED
# define YY_YY_BISON_HPP_INCLUDED
// "%code requires" blocks.
#line 34 "src/bison.y"

  #include "../includes/utils/simbolos.hpp"

#line 53 "bison.hpp"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif



#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

#line 30 "src/bison.y"
namespace bison {
#line 189 "bison.hpp"




  /// A Bison parser.
  class Parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // expressao
      // expressao_simples
      // termo
      // fator
      // variavel_func
      char dummy1[sizeof (Param)];

      // @2
      // bloco
      // @3
      // @5
      // declaracao_procedimento
      // @9
      // declaracao_funcao
      // @10
      // chamada_sem_pametro
      // chamada_procedimento_parametros
      // chamada_funcao_sem_parametros
      // variavel
      char dummy2[sizeof (Simbolo*)];

      // tipo
      char dummy3[sizeof (Tipo*)];

      // parte_declara_tipo
      // parte_declara_vars
      char dummy4[sizeof (int)];

      // ident
      char dummy5[sizeof (std::string)];

      // tipo_parametro
      char dummy6[sizeof (tipo_parametro)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;


    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    PROGRAM = 258,                 // PROGRAM
    VAR = 259,                     // VAR
    T_BEGIN = 260,                 // T_BEGIN
    T_END = 261,                   // T_END
    LABEL = 262,                   // LABEL
    TYPE = 263,                    // TYPE
    ARRAY = 264,                   // ARRAY
    PROCEDURE = 265,               // PROCEDURE
    FUNCTION = 266,                // FUNCTION
    GOTO = 267,                    // GOTO
    IF = 268,                      // IF
    ELSE = 269,                    // ELSE
    THEN = 270,                    // THEN
    WHILE = 271,                   // WHILE
    DO = 272,                      // DO
    OR = 273,                      // OR
    DIV = 274,                     // DIV
    AND = 275,                     // AND
    NOT = 276,                     // NOT
    READ = 277,                    // READ
    WRITE = 278,                   // WRITE
    TRUE = 279,                    // TRUE
    FALSE = 280,                   // FALSE
    ATRIBUICAO = 281,              // ATRIBUICAO
    PONTO_E_VIRGULA = 282,         // PONTO_E_VIRGULA
    DOIS_PONTOS = 283,             // DOIS_PONTOS
    VIRGULA = 284,                 // VIRGULA
    PONTO = 285,                   // PONTO
    ABRE_PARENTESES = 286,         // ABRE_PARENTESES
    FECHA_PARENTESES = 287,        // FECHA_PARENTESES
    ABRE_CHAVE = 288,              // ABRE_CHAVE
    FECHA_CHAVE = 289,             // FECHA_CHAVE
    ABRE_COLCHETE = 290,           // ABRE_COLCHETE
    FECHA_COLCHETE = 291,          // FECHA_COLCHETE
    IGUAL = 292,                   // IGUAL
    DIFERENTE = 293,               // DIFERENTE
    MENOR_QUE = 294,               // MENOR_QUE
    MENOR_OU_IGUAL = 295,          // MENOR_OU_IGUAL
    MAIOR_OU_IGUAL = 296,          // MAIOR_OU_IGUAL
    MAIOR_QUE = 297,               // MAIOR_QUE
    MAIS = 298,                    // MAIS
    MENOS = 299,                   // MENOS
    MULTI = 300,                   // MULTI
    NUMERO = 301,                  // NUMERO
    IDENT = 302,                   // IDENT
    LOWER_THAN_ELSE = 303          // LOWER_THAN_ELSE
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 49, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_PROGRAM = 3,                           // PROGRAM
        S_VAR = 4,                               // VAR
        S_T_BEGIN = 5,                           // T_BEGIN
        S_T_END = 6,                             // T_END
        S_LABEL = 7,                             // LABEL
        S_TYPE = 8,                              // TYPE
        S_ARRAY = 9,                             // ARRAY
        S_PROCEDURE = 10,                        // PROCEDURE
        S_FUNCTION = 11,                         // FUNCTION
        S_GOTO = 12,                             // GOTO
        S_IF = 13,                               // IF
        S_ELSE = 14,                             // ELSE
        S_THEN = 15,                             // THEN
        S_WHILE = 16,                            // WHILE
        S_DO = 17,                               // DO
        S_OR = 18,                               // OR
        S_DIV = 19,                              // DIV
        S_AND = 20,                              // AND
        S_NOT = 21,                              // NOT
        S_READ = 22,                             // READ
        S_WRITE = 23,                            // WRITE
        S_TRUE = 24,                             // TRUE
        S_FALSE = 25,                            // FALSE
        S_ATRIBUICAO = 26,                       // ATRIBUICAO
        S_PONTO_E_VIRGULA = 27,                  // PONTO_E_VIRGULA
        S_DOIS_PONTOS = 28,                      // DOIS_PONTOS
        S_VIRGULA = 29,                          // VIRGULA
        S_PONTO = 30,                            // PONTO
        S_ABRE_PARENTESES = 31,                  // ABRE_PARENTESES
        S_FECHA_PARENTESES = 32,                 // FECHA_PARENTESES
        S_ABRE_CHAVE = 33,                       // ABRE_CHAVE
        S_FECHA_CHAVE = 34,                      // FECHA_CHAVE
        S_ABRE_COLCHETE = 35,                    // ABRE_COLCHETE
        S_FECHA_COLCHETE = 36,                   // FECHA_COLCHETE
        S_IGUAL = 37,                            // IGUAL
        S_DIFERENTE = 38,                        // DIFERENTE
        S_MENOR_QUE = 39,                        // MENOR_QUE
        S_MENOR_OU_IGUAL = 40,                   // MENOR_OU_IGUAL
        S_MAIOR_OU_IGUAL = 41,                   // MAIOR_OU_IGUAL
        S_MAIOR_QUE = 42,                        // MAIOR_QUE
        S_MAIS = 43,                             // MAIS
        S_MENOS = 44,                            // MENOS
        S_MULTI = 45,                            // MULTI
        S_NUMERO = 46,                           // NUMERO
        S_IDENT = 47,                            // IDENT
        S_LOWER_THAN_ELSE = 48,                  // LOWER_THAN_ELSE
        S_YYACCEPT = 49,                         // $accept
        S_programa = 50,                         // programa
        S_51_1 = 51,                             // $@1
        S_52_2 = 52,                             // @2
        S_bloco = 53,                            // bloco
        S_54_3 = 54,                             // @3
        S_55_4 = 55,                             // $@4
        S_56_5 = 56,                             // @5
        S_57_6 = 57,                             // $@6
        S_parte_declara_tipo = 58,               // parte_declara_tipo
        S_define_tipos = 59,                     // define_tipos
        S_define_tipo = 60,                      // define_tipo
        S_parte_declara_vars = 61,               // parte_declara_vars
        S_declara_vars = 62,                     // declara_vars
        S_declara_var = 63,                      // declara_var
        S_64_7 = 64,                             // $@7
        S_lista_var = 65,                        // lista_var
        S_ident = 66,                            // ident
        S_lista_idents = 67,                     // lista_idents
        S_parte_declara_subrotinas_wrap = 68,    // parte_declara_subrotinas_wrap
        S_69_8 = 69,                             // $@8
        S_parte_declara_subrotinas = 70,         // parte_declara_subrotinas
        S_parte_declara_subrotinas_two = 71,     // parte_declara_subrotinas_two
        S_declaracao_procedimento = 72,          // declaracao_procedimento
        S_73_9 = 73,                             // @9
        S_declaracao_funcao = 74,                // declaracao_funcao
        S_75_10 = 75,                            // @10
        S_declaracao_params = 76,                // declaracao_params
        S_77_11 = 77,                            // $@11
        S_parametros_formais = 78,               // parametros_formais
        S_secao_parametros_formais = 79,         // secao_parametros_formais
        S_80_12 = 80,                            // $@12
        S_lista_params = 81,                     // lista_params
        S_tipo_parametro = 82,                   // tipo_parametro
        S_comando_composto = 83,                 // comando_composto
        S_lista_comandos = 84,                   // lista_comandos
        S_comando = 85,                          // comando
        S_comando_sem_rotulo = 86,               // comando_sem_rotulo
        S_lista_write = 87,                      // lista_write
        S_lista_read = 88,                       // lista_read
        S_atribuicao = 89,                       // atribuicao
        S_chamada_procedimento = 90,             // chamada_procedimento
        S_chamada_sem_pametro = 91,              // chamada_sem_pametro
        S_chamada_procedimento_parametros = 92,  // chamada_procedimento_parametros
        S_93_13 = 93,                            // $@13
        S_chamada_funcao_sem_parametros = 94,    // chamada_funcao_sem_parametros
        S_variavel = 95,                         // variavel
        S_comando_condicional = 96,              // comando_condicional
        S_if_then = 97,                          // if_then
        S_98_14 = 98,                            // $@14
        S_cond_else = 99,                        // cond_else
        S_100_15 = 100,                          // $@15
        S_comando_repetitivo = 101,              // comando_repetitivo
        S_102_16 = 102,                          // $@16
        S_103_17 = 103,                          // $@17
        S_expressao_booleana = 104,              // expressao_booleana
        S_lista_de_expressoes = 105,             // lista_de_expressoes
        S_expressao = 106,                       // expressao
        S_expressao_simples = 107,               // expressao_simples
        S_termo = 108,                           // termo
        S_fator = 109,                           // fator
        S_variavel_func = 110,                   // variavel_func
        S_tipo = 111                             // tipo
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
      {
        switch (this->kind ())
    {
      case symbol_kind::S_expressao: // expressao
      case symbol_kind::S_expressao_simples: // expressao_simples
      case symbol_kind::S_termo: // termo
      case symbol_kind::S_fator: // fator
      case symbol_kind::S_variavel_func: // variavel_func
        value.move< Param > (std::move (that.value));
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
        value.move< Simbolo* > (std::move (that.value));
        break;

      case symbol_kind::S_tipo: // tipo
        value.move< Tipo* > (std::move (that.value));
        break;

      case symbol_kind::S_parte_declara_tipo: // parte_declara_tipo
      case symbol_kind::S_parte_declara_vars: // parte_declara_vars
        value.move< int > (std::move (that.value));
        break;

      case symbol_kind::S_ident: // ident
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_tipo_parametro: // tipo_parametro
        value.move< tipo_parametro > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Param&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Param& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Simbolo*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Simbolo*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Tipo*&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Tipo*& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, tipo_parametro&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const tipo_parametro& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_expressao: // expressao
      case symbol_kind::S_expressao_simples: // expressao_simples
      case symbol_kind::S_termo: // termo
      case symbol_kind::S_fator: // fator
      case symbol_kind::S_variavel_func: // variavel_func
        value.template destroy< Param > ();
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
        value.template destroy< Simbolo* > ();
        break;

      case symbol_kind::S_tipo: // tipo
        value.template destroy< Tipo* > ();
        break;

      case symbol_kind::S_parte_declara_tipo: // parte_declara_tipo
      case symbol_kind::S_parte_declara_vars: // parte_declara_vars
        value.template destroy< int > ();
        break;

      case symbol_kind::S_ident: // ident
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_tipo_parametro: // tipo_parametro
        value.template destroy< tipo_parametro > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return Parser::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#else
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#endif
      {}
    };

    /// Build a parser object.
    Parser (yyscan_t scanner_yyarg);
    virtual ~Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    Parser (const Parser&) = delete;
    /// Non copyable.
    Parser& operator= (const Parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0


    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#else
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#else
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#else
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PROGRAM ()
      {
        return symbol_type (token::PROGRAM);
      }
#else
      static
      symbol_type
      make_PROGRAM ()
      {
        return symbol_type (token::PROGRAM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR ()
      {
        return symbol_type (token::VAR);
      }
#else
      static
      symbol_type
      make_VAR ()
      {
        return symbol_type (token::VAR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_BEGIN ()
      {
        return symbol_type (token::T_BEGIN);
      }
#else
      static
      symbol_type
      make_T_BEGIN ()
      {
        return symbol_type (token::T_BEGIN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_T_END ()
      {
        return symbol_type (token::T_END);
      }
#else
      static
      symbol_type
      make_T_END ()
      {
        return symbol_type (token::T_END);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LABEL ()
      {
        return symbol_type (token::LABEL);
      }
#else
      static
      symbol_type
      make_LABEL ()
      {
        return symbol_type (token::LABEL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE ()
      {
        return symbol_type (token::TYPE);
      }
#else
      static
      symbol_type
      make_TYPE ()
      {
        return symbol_type (token::TYPE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY ()
      {
        return symbol_type (token::ARRAY);
      }
#else
      static
      symbol_type
      make_ARRAY ()
      {
        return symbol_type (token::ARRAY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PROCEDURE ()
      {
        return symbol_type (token::PROCEDURE);
      }
#else
      static
      symbol_type
      make_PROCEDURE ()
      {
        return symbol_type (token::PROCEDURE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FUNCTION ()
      {
        return symbol_type (token::FUNCTION);
      }
#else
      static
      symbol_type
      make_FUNCTION ()
      {
        return symbol_type (token::FUNCTION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GOTO ()
      {
        return symbol_type (token::GOTO);
      }
#else
      static
      symbol_type
      make_GOTO ()
      {
        return symbol_type (token::GOTO);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF ()
      {
        return symbol_type (token::IF);
      }
#else
      static
      symbol_type
      make_IF ()
      {
        return symbol_type (token::IF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE ()
      {
        return symbol_type (token::ELSE);
      }
#else
      static
      symbol_type
      make_ELSE ()
      {
        return symbol_type (token::ELSE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THEN ()
      {
        return symbol_type (token::THEN);
      }
#else
      static
      symbol_type
      make_THEN ()
      {
        return symbol_type (token::THEN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE ()
      {
        return symbol_type (token::WHILE);
      }
#else
      static
      symbol_type
      make_WHILE ()
      {
        return symbol_type (token::WHILE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DO ()
      {
        return symbol_type (token::DO);
      }
#else
      static
      symbol_type
      make_DO ()
      {
        return symbol_type (token::DO);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR ()
      {
        return symbol_type (token::OR);
      }
#else
      static
      symbol_type
      make_OR ()
      {
        return symbol_type (token::OR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV ()
      {
        return symbol_type (token::DIV);
      }
#else
      static
      symbol_type
      make_DIV ()
      {
        return symbol_type (token::DIV);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND ()
      {
        return symbol_type (token::AND);
      }
#else
      static
      symbol_type
      make_AND ()
      {
        return symbol_type (token::AND);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT ()
      {
        return symbol_type (token::NOT);
      }
#else
      static
      symbol_type
      make_NOT ()
      {
        return symbol_type (token::NOT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_READ ()
      {
        return symbol_type (token::READ);
      }
#else
      static
      symbol_type
      make_READ ()
      {
        return symbol_type (token::READ);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WRITE ()
      {
        return symbol_type (token::WRITE);
      }
#else
      static
      symbol_type
      make_WRITE ()
      {
        return symbol_type (token::WRITE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRUE ()
      {
        return symbol_type (token::TRUE);
      }
#else
      static
      symbol_type
      make_TRUE ()
      {
        return symbol_type (token::TRUE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FALSE ()
      {
        return symbol_type (token::FALSE);
      }
#else
      static
      symbol_type
      make_FALSE ()
      {
        return symbol_type (token::FALSE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ATRIBUICAO ()
      {
        return symbol_type (token::ATRIBUICAO);
      }
#else
      static
      symbol_type
      make_ATRIBUICAO ()
      {
        return symbol_type (token::ATRIBUICAO);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PONTO_E_VIRGULA ()
      {
        return symbol_type (token::PONTO_E_VIRGULA);
      }
#else
      static
      symbol_type
      make_PONTO_E_VIRGULA ()
      {
        return symbol_type (token::PONTO_E_VIRGULA);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOIS_PONTOS ()
      {
        return symbol_type (token::DOIS_PONTOS);
      }
#else
      static
      symbol_type
      make_DOIS_PONTOS ()
      {
        return symbol_type (token::DOIS_PONTOS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VIRGULA ()
      {
        return symbol_type (token::VIRGULA);
      }
#else
      static
      symbol_type
      make_VIRGULA ()
      {
        return symbol_type (token::VIRGULA);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PONTO ()
      {
        return symbol_type (token::PONTO);
      }
#else
      static
      symbol_type
      make_PONTO ()
      {
        return symbol_type (token::PONTO);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ABRE_PARENTESES ()
      {
        return symbol_type (token::ABRE_PARENTESES);
      }
#else
      static
      symbol_type
      make_ABRE_PARENTESES ()
      {
        return symbol_type (token::ABRE_PARENTESES);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FECHA_PARENTESES ()
      {
        return symbol_type (token::FECHA_PARENTESES);
      }
#else
      static
      symbol_type
      make_FECHA_PARENTESES ()
      {
        return symbol_type (token::FECHA_PARENTESES);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ABRE_CHAVE ()
      {
        return symbol_type (token::ABRE_CHAVE);
      }
#else
      static
      symbol_type
      make_ABRE_CHAVE ()
      {
        return symbol_type (token::ABRE_CHAVE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FECHA_CHAVE ()
      {
        return symbol_type (token::FECHA_CHAVE);
      }
#else
      static
      symbol_type
      make_FECHA_CHAVE ()
      {
        return symbol_type (token::FECHA_CHAVE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ABRE_COLCHETE ()
      {
        return symbol_type (token::ABRE_COLCHETE);
      }
#else
      static
      symbol_type
      make_ABRE_COLCHETE ()
      {
        return symbol_type (token::ABRE_COLCHETE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FECHA_COLCHETE ()
      {
        return symbol_type (token::FECHA_COLCHETE);
      }
#else
      static
      symbol_type
      make_FECHA_COLCHETE ()
      {
        return symbol_type (token::FECHA_COLCHETE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IGUAL ()
      {
        return symbol_type (token::IGUAL);
      }
#else
      static
      symbol_type
      make_IGUAL ()
      {
        return symbol_type (token::IGUAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIFERENTE ()
      {
        return symbol_type (token::DIFERENTE);
      }
#else
      static
      symbol_type
      make_DIFERENTE ()
      {
        return symbol_type (token::DIFERENTE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MENOR_QUE ()
      {
        return symbol_type (token::MENOR_QUE);
      }
#else
      static
      symbol_type
      make_MENOR_QUE ()
      {
        return symbol_type (token::MENOR_QUE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MENOR_OU_IGUAL ()
      {
        return symbol_type (token::MENOR_OU_IGUAL);
      }
#else
      static
      symbol_type
      make_MENOR_OU_IGUAL ()
      {
        return symbol_type (token::MENOR_OU_IGUAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAIOR_OU_IGUAL ()
      {
        return symbol_type (token::MAIOR_OU_IGUAL);
      }
#else
      static
      symbol_type
      make_MAIOR_OU_IGUAL ()
      {
        return symbol_type (token::MAIOR_OU_IGUAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAIOR_QUE ()
      {
        return symbol_type (token::MAIOR_QUE);
      }
#else
      static
      symbol_type
      make_MAIOR_QUE ()
      {
        return symbol_type (token::MAIOR_QUE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAIS ()
      {
        return symbol_type (token::MAIS);
      }
#else
      static
      symbol_type
      make_MAIS ()
      {
        return symbol_type (token::MAIS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MENOS ()
      {
        return symbol_type (token::MENOS);
      }
#else
      static
      symbol_type
      make_MENOS ()
      {
        return symbol_type (token::MENOS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULTI ()
      {
        return symbol_type (token::MULTI);
      }
#else
      static
      symbol_type
      make_MULTI ()
      {
        return symbol_type (token::MULTI);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMERO ()
      {
        return symbol_type (token::NUMERO);
      }
#else
      static
      symbol_type
      make_NUMERO ()
      {
        return symbol_type (token::NUMERO);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENT ()
      {
        return symbol_type (token::IDENT);
      }
#else
      static
      symbol_type
      make_IDENT ()
      {
        return symbol_type (token::IDENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOWER_THAN_ELSE ()
      {
        return symbol_type (token::LOWER_THAN_ELSE);
      }
#else
      static
      symbol_type
      make_LOWER_THAN_ELSE ()
      {
        return symbol_type (token::LOWER_THAN_ELSE);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    Parser (const Parser&);
    /// Non copyable.
    Parser& operator= (const Parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const signed char yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const unsigned char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 174,     ///< Last index in yytable_.
      yynnts_ = 63,  ///< Number of nonterminal symbols.
      yyfinal_ = 3 ///< Termination state number.
    };


    // User arguments.
    yyscan_t scanner;

  };


#line 30 "src/bison.y"
} // bison
#line 2067 "bison.hpp"


// "%code provides" blocks.
#line 39 "src/bison.y"

    #define YY_DECL \
        int yylex(bison::Parser::semantic_type *yylval, yyscan_t yyscanner)
    YY_DECL;

#line 2077 "bison.hpp"


#endif // !YY_YY_BISON_HPP_INCLUDED
