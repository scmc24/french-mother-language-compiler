/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "duala.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

FILE *fichier_c;
extern char current_id[100];
char affectation_var[100];
char expression_buffer[1000];
int label_counter = 0;

#line 86 "duala.tab.c"

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

#include "duala.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DEBUT = 3,                      /* DEBUT  */
  YYSYMBOL_FIN = 4,                        /* FIN  */
  YYSYMBOL_TYPE_ENTIER = 5,                /* TYPE_ENTIER  */
  YYSYMBOL_LIRE = 6,                       /* LIRE  */
  YYSYMBOL_ECRIRE = 7,                     /* ECRIRE  */
  YYSYMBOL_SI = 8,                         /* SI  */
  YYSYMBOL_ALORS = 9,                      /* ALORS  */
  YYSYMBOL_SINON = 10,                     /* SINON  */
  YYSYMBOL_FINSI = 11,                     /* FINSI  */
  YYSYMBOL_TANT_QUE = 12,                  /* TANT_QUE  */
  YYSYMBOL_FAIRE = 13,                     /* FAIRE  */
  YYSYMBOL_FINTANT = 14,                   /* FINTANT  */
  YYSYMBOL_SELON = 15,                     /* SELON  */
  YYSYMBOL_CAS = 16,                       /* CAS  */
  YYSYMBOL_DEFAUT = 17,                    /* DEFAUT  */
  YYSYMBOL_FINSELON = 18,                  /* FINSELON  */
  YYSYMBOL_SORTIR = 19,                    /* SORTIR  */
  YYSYMBOL_POUR = 20,                      /* POUR  */
  YYSYMBOL_DE = 21,                        /* DE  */
  YYSYMBOL_A = 22,                         /* A  */
  YYSYMBOL_PAS = 23,                       /* PAS  */
  YYSYMBOL_FINPOUR = 24,                   /* FINPOUR  */
  YYSYMBOL_REPETER = 25,                   /* REPETER  */
  YYSYMBOL_JUSQUA = 26,                    /* JUSQUA  */
  YYSYMBOL_AFFECTATION = 27,               /* AFFECTATION  */
  YYSYMBOL_EGAL = 28,                      /* EGAL  */
  YYSYMBOL_DIFFERENT = 29,                 /* DIFFERENT  */
  YYSYMBOL_SUP_EGAL = 30,                  /* SUP_EGAL  */
  YYSYMBOL_INF_EGAL = 31,                  /* INF_EGAL  */
  YYSYMBOL_SUPERIEUR = 32,                 /* SUPERIEUR  */
  YYSYMBOL_INFERIEUR = 33,                 /* INFERIEUR  */
  YYSYMBOL_PLUS = 34,                      /* PLUS  */
  YYSYMBOL_MOINS = 35,                     /* MOINS  */
  YYSYMBOL_FOIS = 36,                      /* FOIS  */
  YYSYMBOL_DIVISE = 37,                    /* DIVISE  */
  YYSYMBOL_MODULO = 38,                    /* MODULO  */
  YYSYMBOL_POINT_VIRGULE = 39,             /* POINT_VIRGULE  */
  YYSYMBOL_VIRGULE = 40,                   /* VIRGULE  */
  YYSYMBOL_PAREN_OUV = 41,                 /* PAREN_OUV  */
  YYSYMBOL_PAREN_FERM = 42,                /* PAREN_FERM  */
  YYSYMBOL_DEUX_POINTS = 43,               /* DEUX_POINTS  */
  YYSYMBOL_NOMBRE_ENTIER = 44,             /* NOMBRE_ENTIER  */
  YYSYMBOL_IDENTIFICATEUR = 45,            /* IDENTIFICATEUR  */
  YYSYMBOL_CHAINE_CARACTERE = 46,          /* CHAINE_CARACTERE  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_programme = 48,                 /* programme  */
  YYSYMBOL_49_1 = 49,                      /* $@1  */
  YYSYMBOL_bloc = 50,                      /* bloc  */
  YYSYMBOL_declarations = 51,              /* declarations  */
  YYSYMBOL_declaration = 52,               /* declaration  */
  YYSYMBOL_instructions = 53,              /* instructions  */
  YYSYMBOL_instruction = 54,               /* instruction  */
  YYSYMBOL_affectation = 55,               /* affectation  */
  YYSYMBOL_56_2 = 56,                      /* $@2  */
  YYSYMBOL_expression = 57,                /* expression  */
  YYSYMBOL_terme = 58,                     /* terme  */
  YYSYMBOL_facteur = 59,                   /* facteur  */
  YYSYMBOL_conditionnelle = 60,            /* conditionnelle  */
  YYSYMBOL_61_3 = 61,                      /* $@3  */
  YYSYMBOL_partie_sinon_opt = 62,          /* partie_sinon_opt  */
  YYSYMBOL_63_4 = 63,                      /* $@4  */
  YYSYMBOL_boucle_tant_que = 64,           /* boucle_tant_que  */
  YYSYMBOL_65_5 = 65,                      /* $@5  */
  YYSYMBOL_lecture = 66,                   /* lecture  */
  YYSYMBOL_ecriture = 67,                  /* ecriture  */
  YYSYMBOL_structure_selon = 68,           /* structure_selon  */
  YYSYMBOL_69_6 = 69,                      /* $@6  */
  YYSYMBOL_liste_cas = 70,                 /* liste_cas  */
  YYSYMBOL_cas_simple = 71,                /* cas_simple  */
  YYSYMBOL_72_7 = 72,                      /* $@7  */
  YYSYMBOL_partie_defaut_opt = 73,         /* partie_defaut_opt  */
  YYSYMBOL_74_8 = 74,                      /* $@8  */
  YYSYMBOL_sortir_instruction = 75,        /* sortir_instruction  */
  YYSYMBOL_boucle_pour = 76,               /* boucle_pour  */
  YYSYMBOL_77_9 = 77,                      /* $@9  */
  YYSYMBOL_78_10 = 78,                     /* $@10  */
  YYSYMBOL_boucle_repeter = 79,            /* boucle_repeter  */
  YYSYMBOL_80_11 = 80                      /* $@11  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   336

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    41,    41,    41,    59,    62,    64,    68,    74,    76,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      97,    97,   107,   110,   116,   122,   128,   134,   140,   146,
     152,   161,   165,   171,   178,   187,   193,   198,   206,   206,
     216,   218,   218,   225,   225,   237,   245,   250,   258,   258,
     269,   271,   275,   275,   283,   285,   285,   293,   300,   300,
     313,   313,   328,   328
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DEBUT", "FIN",
  "TYPE_ENTIER", "LIRE", "ECRIRE", "SI", "ALORS", "SINON", "FINSI",
  "TANT_QUE", "FAIRE", "FINTANT", "SELON", "CAS", "DEFAUT", "FINSELON",
  "SORTIR", "POUR", "DE", "A", "PAS", "FINPOUR", "REPETER", "JUSQUA",
  "AFFECTATION", "EGAL", "DIFFERENT", "SUP_EGAL", "INF_EGAL", "SUPERIEUR",
  "INFERIEUR", "PLUS", "MOINS", "FOIS", "DIVISE", "MODULO",
  "POINT_VIRGULE", "VIRGULE", "PAREN_OUV", "PAREN_FERM", "DEUX_POINTS",
  "NOMBRE_ENTIER", "IDENTIFICATEUR", "CHAINE_CARACTERE", "$accept",
  "programme", "$@1", "bloc", "declarations", "declaration",
  "instructions", "instruction", "affectation", "$@2", "expression",
  "terme", "facteur", "conditionnelle", "$@3", "partie_sinon_opt", "$@4",
  "boucle_tant_que", "$@5", "lecture", "ecriture", "structure_selon",
  "$@6", "liste_cas", "cas_simple", "$@7", "partie_defaut_opt", "$@8",
  "sortir_instruction", "boucle_pour", "$@9", "$@10", "boucle_repeter",
  "$@11", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-44)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-21)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,   -44,     1,   -44,   -44,    10,    24,   -44,   -30,   -44,
     142,     2,    13,   -19,    18,   -33,    21,    25,    20,   -44,
     -33,   -44,    36,   -44,   -44,   257,   -17,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,    28,   -44,    29,
     269,   -33,     3,   -33,   -44,    48,   -44,   176,    43,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -44,   -33,   -33,
     -33,   -44,   -44,   -44,   191,   -44,   206,   -33,    -2,   -44,
     -33,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -44,
     -44,   -44,    63,   -44,   -44,   236,    32,   281,   -44,    41,
     -44,   -33,   -33,   -33,   -44,   -44,   -44,    34,   145,   249,
     221,    85,   -33,    33,   -44,    57,   -44,   -33,    44,   -44,
      76,   160,   -44,   -44,   -44,   293,   -44,   -44,   -44,   -44,
     -44,   100,    75,   142,   -44,   142,   -44,   -44,   142,   127,
     -44
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     2,     0,     5,     1,     0,     8,     3,     0,     6,
       4,     0,     0,     0,     0,     0,     0,     0,     0,    62,
       0,    35,    36,     9,    10,     0,    22,    31,    13,    16,
      11,    12,    14,    15,    17,    18,     7,     0,    36,     0,
       0,     0,     0,     0,    57,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       0,    45,    47,    46,     0,    43,     0,     0,     0,    37,
       0,    27,    28,    29,    30,    25,    26,    23,    24,    32,
      33,    34,     0,     8,    48,     0,     0,     0,    38,     0,
      50,     0,     0,     0,    21,     8,    44,    54,     0,     0,
       0,    40,     0,     0,    51,     0,    58,     0,     0,    41,
       0,     0,    55,    49,     8,    60,    63,     8,    39,    52,
       8,     0,     0,    42,     8,    56,    59,     8,    53,     0,
      61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -44,   -44,   -44,   -44,   -44,   -44,   -43,   -44,   -44,   -44,
     -13,   280,   -14,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     5,     6,     9,    10,    23,    24,    48,
      25,    26,    27,    28,    95,   110,   117,    29,    83,    30,
      31,    32,    90,    97,   104,   124,   105,   120,    33,    34,
     114,   122,    35,    46
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,     4,    42,    68,    12,    13,    14,    47,    20,     1,
      15,    21,    38,    16,     7,    11,    65,    17,    18,    58,
      59,    60,    20,    19,    86,    21,    38,    39,    64,     8,
      66,    49,    50,    51,    52,    53,    54,    55,    56,    20,
      89,    36,    21,    22,    79,    80,    81,    12,    13,    14,
     102,   103,   101,    15,    85,    96,    16,    87,    37,    41,
      17,    18,    43,   -20,    44,    45,    19,    61,    62,    67,
      70,   121,    88,    93,   123,   113,   112,   125,    98,    99,
     100,   128,    20,   116,   129,    21,    22,   118,   127,   111,
       0,    12,    13,    14,   115,   109,     0,    15,     0,     0,
      16,     0,     0,     0,    17,    18,    12,    13,    14,     0,
      19,     0,    15,     0,     0,    16,     0,     0,     0,    17,
      18,     0,     0,     0,   126,    19,    20,     0,     0,    21,
      22,     0,     0,    12,    13,    14,     0,     0,     0,    15,
       0,    20,    16,     0,    21,    22,    17,    18,    12,    13,
      14,   130,    19,     0,    15,     0,     0,    16,   106,     0,
       0,    17,    18,     0,     0,     0,     0,    19,    20,     0,
       0,    21,    22,    49,    50,    51,    52,    53,    54,    55,
      56,     0,     0,    20,     0,     0,    21,    22,    49,    50,
      51,    52,    53,    54,    55,    56,     0,     0,     0,     0,
       0,     0,     0,   119,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     0,     0,     0,     0,     0,    69,    49,
      50,    51,    52,    53,    54,    55,    56,     0,     0,     0,
       0,     0,     0,    82,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     0,     0,     0,     0,     0,    84,    49,
      50,    51,    52,    53,    54,    55,    56,     0,    91,     0,
       0,     0,    92,   108,    49,    50,    51,    52,    53,    54,
      55,    56,   107,     0,     0,     0,     0,    49,    50,    51,
      52,    53,    54,    55,    56,    49,    50,    51,    52,    53,
      54,    55,    56,     0,     0,     0,    57,    49,    50,    51,
      52,    53,    54,    55,    56,     0,     0,     0,    63,    49,
      50,    51,    52,    53,    54,    55,    56,     0,     0,     0,
      94,    49,    50,    51,    52,    53,    54,    55,    56,    71,
      72,    73,    74,    75,    76,    77,    78
};

static const yytype_int8 yycheck[] =
{
      13,     0,    15,    46,     6,     7,     8,    20,    41,     3,
      12,    44,    45,    15,     4,    45,    13,    19,    20,    36,
      37,    38,    41,    25,    26,    44,    45,    46,    41,     5,
      43,    28,    29,    30,    31,    32,    33,    34,    35,    41,
      83,    39,    44,    45,    58,    59,    60,     6,     7,     8,
      16,    17,    95,    12,    67,    14,    15,    70,    45,    41,
      19,    20,    41,    27,    39,    45,    25,    39,    39,    21,
      27,   114,     9,    41,   117,    18,    43,   120,    91,    92,
      93,   124,    41,    39,   127,    44,    45,    11,    13,   102,
      -1,     6,     7,     8,   107,    10,    -1,    12,    -1,    -1,
      15,    -1,    -1,    -1,    19,    20,     6,     7,     8,    -1,
      25,    -1,    12,    -1,    -1,    15,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    24,    25,    41,    -1,    -1,    44,
      45,    -1,    -1,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    41,    15,    -1,    44,    45,    19,    20,     6,     7,
       8,    24,    25,    -1,    12,    -1,    -1,    15,    13,    -1,
      -1,    19,    20,    -1,    -1,    -1,    -1,    25,    41,    -1,
      -1,    44,    45,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    -1,    41,    -1,    -1,    44,    45,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    22,    -1,
      -1,    -1,    26,    42,    28,    29,    30,    31,    32,    33,
      34,    35,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    39,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    39,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    28,    29,    30,    31,    32,    33,    34,    35,    49,
      50,    51,    52,    53,    54,    55,    56
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    48,    49,     0,    50,    51,     4,     5,    52,
      53,    45,     6,     7,     8,    12,    15,    19,    20,    25,
      41,    44,    45,    54,    55,    57,    58,    59,    60,    64,
      66,    67,    68,    75,    76,    79,    39,    45,    45,    46,
      57,    41,    57,    41,    39,    45,    80,    57,    56,    28,
      29,    30,    31,    32,    33,    34,    35,    39,    36,    37,
      38,    39,    39,    39,    57,    13,    57,    21,    53,    42,
      27,    58,    58,    58,    58,    58,    58,    58,    58,    59,
      59,    59,    42,    65,    42,    57,    26,    57,     9,    53,
      69,    22,    26,    41,    39,    61,    14,    70,    57,    57,
      57,    53,    16,    17,    71,    73,    13,    23,    42,    10,
      62,    57,    43,    18,    77,    57,    39,    63,    11,    43,
      74,    53,    78,    53,    72,    53,    24,    13,    53,    53,
      24
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    49,    48,    50,    51,    51,    52,    53,    53,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      56,    55,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    58,    58,    58,    58,    59,    59,    59,    61,    60,
      62,    63,    62,    65,    64,    66,    67,    67,    69,    68,
      70,    70,    72,    71,    73,    74,    73,    75,    77,    76,
      78,    76,    80,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     2,     0,     2,     3,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     5,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     1,     3,     0,     9,
       0,     0,     3,     0,     6,     3,     3,     3,     0,     8,
       0,     2,     0,     5,     0,     0,     4,     2,     0,    10,
       0,    12,     0,     8
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 41 "duala.y"
          { 
        fichier_c = fopen("programme.c", "w");
        fprintf(fichier_c, "#include <stdio.h>\n");
        fprintf(fichier_c, "#include <stdlib.h>\n\n");
        fprintf(fichier_c, "int main() {\n");
        printf("🔧 Mbɔmbɔ génération du code C...\n");
    }
#line 1292 "duala.tab.c"
    break;

  case 3: /* programme: DEBUT $@1 bloc FIN  */
#line 49 "duala.y"
        { 
        fprintf(fichier_c, "    printf(\"\\n--- Suka programme ---\\n\");\n");
        fprintf(fichier_c, "    return 0;\n");
        fprintf(fichier_c, "}\n");
        fclose(fichier_c);
        printf("✅ Code C généré na programme.c\n"); 
    }
#line 1304 "duala.tab.c"
    break;

  case 7: /* declaration: TYPE_ENTIER IDENTIFICATEUR POINT_VIRGULE  */
#line 68 "duala.y"
                                             {
        fprintf(fichier_c, "    int %s = 0;  // Variable déclarée\n", current_id);
        printf("📝 Variable déclarée: %s\n", current_id);
    }
#line 1313 "duala.tab.c"
    break;

  case 19: /* instruction: expression POINT_VIRGULE  */
#line 89 "duala.y"
                               {
        fprintf(fichier_c, "    %s;\n", (yyvsp[-1].sval));
        printf("📝 Expression évaluée: %s\n", (yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 1323 "duala.tab.c"
    break;

  case 20: /* $@2: %empty  */
#line 97 "duala.y"
                   {
        strcpy(affectation_var, current_id);
    }
#line 1331 "duala.tab.c"
    break;

  case 21: /* affectation: IDENTIFICATEUR $@2 AFFECTATION expression POINT_VIRGULE  */
#line 99 "duala.y"
                                           {
        fprintf(fichier_c, "    %s = %s;\n", affectation_var, (yyvsp[-1].sval));
        printf("⬅️  Affectation: %s = %s\n", affectation_var, (yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 1341 "duala.tab.c"
    break;

  case 22: /* expression: terme  */
#line 107 "duala.y"
          { 
        (yyval.sval) = (yyvsp[0].sval); 
    }
#line 1349 "duala.tab.c"
    break;

  case 23: /* expression: expression PLUS terme  */
#line 110 "duala.y"
                            {
        (yyval.sval) = malloc(100);
        sprintf((yyval.sval), "(%s + %s)", (yyvsp[-2].sval), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 1360 "duala.tab.c"
    break;

  case 24: /* expression: expression MOINS terme  */
#line 116 "duala.y"
                             {
        (yyval.sval) = malloc(100);
        sprintf((yyval.sval), "(%s - %s)", (yyvsp[-2].sval), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 1371 "duala.tab.c"
    break;

  case 25: /* expression: expression SUPERIEUR terme  */
#line 122 "duala.y"
                                 {
        (yyval.sval) = malloc(100);
        sprintf((yyval.sval), "(%s > %s)", (yyvsp[-2].sval), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 1382 "duala.tab.c"
    break;

  case 26: /* expression: expression INFERIEUR terme  */
#line 128 "duala.y"
                                 {
        (yyval.sval) = malloc(100);
        sprintf((yyval.sval), "(%s < %s)", (yyvsp[-2].sval), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 1393 "duala.tab.c"
    break;

  case 27: /* expression: expression EGAL terme  */
#line 134 "duala.y"
                            {
        (yyval.sval) = malloc(100);
        sprintf((yyval.sval), "(%s == %s)", (yyvsp[-2].sval), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 1404 "duala.tab.c"
    break;

  case 28: /* expression: expression DIFFERENT terme  */
#line 140 "duala.y"
                                 {
        (yyval.sval) = malloc(100);
        sprintf((yyval.sval), "(%s != %s)", (yyvsp[-2].sval), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 1415 "duala.tab.c"
    break;

  case 29: /* expression: expression SUP_EGAL terme  */
#line 146 "duala.y"
                                {
        (yyval.sval) = malloc(100);
        sprintf((yyval.sval), "(%s >= %s)", (yyvsp[-2].sval), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 1426 "duala.tab.c"
    break;

  case 30: /* expression: expression INF_EGAL terme  */
#line 152 "duala.y"
                                {
        (yyval.sval) = malloc(100);
        sprintf((yyval.sval), "(%s <= %s)", (yyvsp[-2].sval), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 1437 "duala.tab.c"
    break;

  case 31: /* terme: facteur  */
#line 161 "duala.y"
            { 
        printf("DEBUG: terme -> facteur: %s\n", (yyvsp[0].sval));
        (yyval.sval) = (yyvsp[0].sval); 
    }
#line 1446 "duala.tab.c"
    break;

  case 32: /* terme: terme FOIS facteur  */
#line 165 "duala.y"
                         {
        (yyval.sval) = malloc(100);
        sprintf((yyval.sval), "(%s * %s)", (yyvsp[-2].sval), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 1457 "duala.tab.c"
    break;

  case 33: /* terme: terme DIVISE facteur  */
#line 171 "duala.y"
                           {
        printf("DEBUG: Division de %s par %s\n", (yyvsp[-2].sval), (yyvsp[0].sval));
        (yyval.sval) = malloc(100);
        sprintf((yyval.sval), "(%s / %s)", (yyvsp[-2].sval), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 1469 "duala.tab.c"
    break;

  case 34: /* terme: terme MODULO facteur  */
#line 178 "duala.y"
                           {
        (yyval.sval) = malloc(100);
        sprintf((yyval.sval), "(%s %% %s)", (yyvsp[-2].sval), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 1480 "duala.tab.c"
    break;

  case 35: /* facteur: NOMBRE_ENTIER  */
#line 187 "duala.y"
                  {
        printf("DEBUG: facteur -> NOMBRE_ENTIER: %d\n", (yyvsp[0].ival));
        (yyval.sval) = malloc(20);
        sprintf((yyval.sval), "%d", (yyvsp[0].ival));
        printf("🔢 Constante: %d\n", (yyvsp[0].ival));
    }
#line 1491 "duala.tab.c"
    break;

  case 36: /* facteur: IDENTIFICATEUR  */
#line 193 "duala.y"
                     {
        (yyval.sval) = malloc(strlen(current_id) + 1);
        strcpy((yyval.sval), current_id);
        printf("📊 Variable utilisée: %s\n", current_id);
    }
#line 1501 "duala.tab.c"
    break;

  case 37: /* facteur: PAREN_OUV expression PAREN_FERM  */
#line 198 "duala.y"
                                      {
        (yyval.sval) = malloc(strlen((yyvsp[-1].sval)) + 3);
        sprintf((yyval.sval), "(%s)", (yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 1511 "duala.tab.c"
    break;

  case 38: /* $@3: %empty  */
#line 206 "duala.y"
                                             {
        fprintf(fichier_c, "    if (%s) {\n", (yyvsp[-2].sval));
        printf("🔀 Mbɔmbɔ condition SƆ\n");
        free((yyvsp[-2].sval));
    }
#line 1521 "duala.tab.c"
    break;

  case 39: /* conditionnelle: SI PAREN_OUV expression PAREN_FERM ALORS $@3 instructions partie_sinon_opt FINSI  */
#line 210 "duala.y"
                                          {
        fprintf(fichier_c, "    }  // Suka SƆ\n");
        printf("🔚 Suka condition SƆ\n");
    }
#line 1530 "duala.tab.c"
    break;

  case 41: /* $@4: %empty  */
#line 218 "duala.y"
            {
        fprintf(fichier_c, "    } else {\n");
        printf("🔄 Partie KƐMA\n");
    }
#line 1539 "duala.tab.c"
    break;

  case 43: /* $@5: %empty  */
#line 225 "duala.y"
                              {
        fprintf(fichier_c, "    while (%s) {\n", (yyvsp[-1].sval));
        printf("🔄 Mbɔmbɔ boucle MBƐLƐ\n");
        free((yyvsp[-1].sval));
    }
#line 1549 "duala.tab.c"
    break;

  case 44: /* boucle_tant_que: TANT_QUE expression FAIRE $@5 instructions FINTANT  */
#line 229 "duala.y"
                           {
        fprintf(fichier_c, "    }  // Suka MBƐLƐ\n");
        printf("🔚 Suka boucle MBƐLƐ\n");
    }
#line 1558 "duala.tab.c"
    break;

  case 45: /* lecture: LIRE IDENTIFICATEUR POINT_VIRGULE  */
#line 237 "duala.y"
                                      {
        fprintf(fichier_c, "    printf(\"Tɔlɛ valeur na %s: \");\n", current_id);
        fprintf(fichier_c, "    scanf(\"%%d\", &%s);\n", current_id);
        printf("📥 Yɛnɛ: %s\n", current_id);
    }
#line 1568 "duala.tab.c"
    break;

  case 46: /* ecriture: ECRIRE expression POINT_VIRGULE  */
#line 245 "duala.y"
                                    {
        fprintf(fichier_c, "    printf(\"%%d\\n\", %s);\n", (yyvsp[-1].sval));
        printf("📤 Kɔma expression\n");
        free((yyvsp[-1].sval));
    }
#line 1578 "duala.tab.c"
    break;

  case 47: /* ecriture: ECRIRE CHAINE_CARACTERE POINT_VIRGULE  */
#line 250 "duala.y"
                                            {
        fprintf(fichier_c, "    printf(\"%s\\n\");\n", (yyvsp[-1].sval));
        printf("📤 Kɔma chaine: %s\n", (yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 1588 "duala.tab.c"
    break;

  case 48: /* $@6: %empty  */
#line 258 "duala.y"
                                          {
        fprintf(fichier_c, "    switch (%s) {\n", (yyvsp[-1].sval));
        printf("🔀 NDƆŊ (switch)\n");
        free((yyvsp[-1].sval));
    }
#line 1598 "duala.tab.c"
    break;

  case 49: /* structure_selon: SELON PAREN_OUV expression PAREN_FERM $@6 liste_cas partie_defaut_opt FINSELON  */
#line 262 "duala.y"
                                           {
        fprintf(fichier_c, "    } // Suka NDƆŊ\n");
        printf("🔚 Suka NDƆŊ\n");
    }
#line 1607 "duala.tab.c"
    break;

  case 52: /* $@7: %empty  */
#line 275 "duala.y"
                               {
        fprintf(fichier_c, "        case %s:\n", (yyvsp[-1].sval));
        printf("📋 KƐS %s\n", (yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 1617 "duala.tab.c"
    break;

  case 55: /* $@8: %empty  */
#line 285 "duala.y"
                         {
        fprintf(fichier_c, "        default:\n");
        printf("📋 KƐS BƆSƆ\n");
    }
#line 1626 "duala.tab.c"
    break;

  case 57: /* sortir_instruction: SORTIR POINT_VIRGULE  */
#line 293 "duala.y"
                         {
        fprintf(fichier_c, "        break;\n");
        printf("🚪 BIMA (break)\n");
    }
#line 1635 "duala.tab.c"
    break;

  case 58: /* $@9: %empty  */
#line 300 "duala.y"
                                                         {
        char *var = strdup((yyvsp[-5].sval));  // Copie de l'identifiant
        fprintf(fichier_c, "    for (%s = %s; %s <= %s; %s++) {\n", 
                var, (yyvsp[-3].sval), var, (yyvsp[-1].sval), var);
        printf("🔄 PƆ %s na %s tɛ %s\n", var, (yyvsp[-3].sval), (yyvsp[-1].sval));
        free((yyvsp[-5].sval)); free((yyvsp[-3].sval)); free((yyvsp[-1].sval));
        strcpy(affectation_var, var); // utile si réutilisation
        free(var);
    }
#line 1649 "duala.tab.c"
    break;

  case 59: /* boucle_pour: POUR IDENTIFICATEUR DE expression A expression FAIRE $@9 instructions FINPOUR  */
#line 308 "duala.y"
                           {
        fprintf(fichier_c, "    }  // Suka PƆ\n");
        printf("🔚 Suka PƆ\n");
    }
#line 1658 "duala.tab.c"
    break;

  case 60: /* $@10: %empty  */
#line 313 "duala.y"
                                                                       {
        char *var = strdup((yyvsp[-6].sval));  // Copie de l'identifiant
        fprintf(fichier_c, "    for (%s = %s; %s <= %s; %s += %s) {\n", 
                var, (yyvsp[-4].sval), var, (yyvsp[-2].sval), var, (yyvsp[0].sval));
        printf("🔄 PƆ %s na %s tɛmbɛlɛ %s mbɛn %s\n", var, (yyvsp[-4].sval), (yyvsp[-2].sval), (yyvsp[0].sval));
        free((yyvsp[-6].sval)); free((yyvsp[-4].sval)); free((yyvsp[-2].sval)); free((yyvsp[0].sval));
        free(var);
    }
#line 1671 "duala.tab.c"
    break;

  case 61: /* boucle_pour: POUR IDENTIFICATEUR DE expression JUSQUA expression PAS expression $@10 FAIRE instructions FINPOUR  */
#line 320 "duala.y"
                                 {
        fprintf(fichier_c, "    }  // Suka PƆ na mbɛn\n");
        printf("🔚 Suka PƆ na mbɛn\n");
    }
#line 1680 "duala.tab.c"
    break;

  case 62: /* $@11: %empty  */
#line 328 "duala.y"
            {
        fprintf(fichier_c, "    do {\n");
        printf("🔄 SƆŊƆLƆ (do-while)\n");
    }
#line 1689 "duala.tab.c"
    break;

  case 63: /* boucle_repeter: REPETER $@11 instructions JUSQUA PAREN_OUV expression PAREN_FERM POINT_VIRGULE  */
#line 331 "duala.y"
                                                                        {
        fprintf(fichier_c, "    } while (%s);\n", (yyvsp[-2].sval));
        printf("🔚 TƐMBƐLƐ (condition)\n");
        free((yyvsp[-2].sval));
    }
#line 1699 "duala.tab.c"
    break;


#line 1703 "duala.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 339 "duala.y"


void yyerror(const char *s) {
    fprintf(stderr, "❌ Erreur de syntaxe: %s\n", s);
}

int main() {
    printf("🇨🇲 === COMPILATEUR DUALA VERS C ===\n");
    printf("📝 Tɔlɛ programme na wo:\n\n");
    return yyparse();
}
