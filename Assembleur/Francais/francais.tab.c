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
#line 1 "francais.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

FILE *fichier_asm;
FILE *fichier_temp;
extern char current_id[100];
extern char current_string[1000];
char affectation_var[100];
int etiquette_counter = 0;
int etiquette_stack[10];
int stack_ptr = 0;
int string_counter = 0;

#line 90 "francais.tab.c"

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

#include "francais.h"
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
  YYSYMBOL_SELON = 12,                     /* SELON  */
  YYSYMBOL_CAS = 13,                       /* CAS  */
  YYSYMBOL_DEFAUT = 14,                    /* DEFAUT  */
  YYSYMBOL_FINSELON = 15,                  /* FINSELON  */
  YYSYMBOL_SORTIR = 16,                    /* SORTIR  */
  YYSYMBOL_TANT_QUE = 17,                  /* TANT_QUE  */
  YYSYMBOL_FAIRE = 18,                     /* FAIRE  */
  YYSYMBOL_FINTANT = 19,                   /* FINTANT  */
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
  YYSYMBOL_QUESTION = 44,                  /* QUESTION  */
  YYSYMBOL_NOMBRE_ENTIER = 45,             /* NOMBRE_ENTIER  */
  YYSYMBOL_IDENTIFICATEUR = 46,            /* IDENTIFICATEUR  */
  YYSYMBOL_CHAINE_CARACTERES = 47,         /* CHAINE_CARACTERES  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_programme = 49,                 /* programme  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_bloc = 51,                      /* bloc  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_declarations = 53,              /* declarations  */
  YYSYMBOL_declaration = 54,               /* declaration  */
  YYSYMBOL_instructions = 55,              /* instructions  */
  YYSYMBOL_instruction = 56,               /* instruction  */
  YYSYMBOL_affectation = 57,               /* affectation  */
  YYSYMBOL_58_3 = 58,                      /* $@3  */
  YYSYMBOL_expression = 59,                /* expression  */
  YYSYMBOL_expression_arith = 60,          /* expression_arith  */
  YYSYMBOL_expression_comp = 61,           /* expression_comp  */
  YYSYMBOL_expression_ternaire = 62,       /* expression_ternaire  */
  YYSYMBOL_terme = 63,                     /* terme  */
  YYSYMBOL_facteur = 64,                   /* facteur  */
  YYSYMBOL_conditionnelle = 65,            /* conditionnelle  */
  YYSYMBOL_66_4 = 66,                      /* $@4  */
  YYSYMBOL_partie_sinon_opt = 67,          /* partie_sinon_opt  */
  YYSYMBOL_68_5 = 68,                      /* $@5  */
  YYSYMBOL_structure_selon = 69,           /* structure_selon  */
  YYSYMBOL_70_6 = 70,                      /* $@6  */
  YYSYMBOL_liste_cas = 71,                 /* liste_cas  */
  YYSYMBOL_cas_simple = 72,                /* cas_simple  */
  YYSYMBOL_73_7 = 73,                      /* $@7  */
  YYSYMBOL_partie_defaut_opt = 74,         /* partie_defaut_opt  */
  YYSYMBOL_75_8 = 75,                      /* $@8  */
  YYSYMBOL_sortir_instruction = 76,        /* sortir_instruction  */
  YYSYMBOL_boucle_tant_que = 77,           /* boucle_tant_que  */
  YYSYMBOL_78_9 = 78,                      /* $@9  */
  YYSYMBOL_79_10 = 79,                     /* $@10  */
  YYSYMBOL_boucle_pour = 80,               /* boucle_pour  */
  YYSYMBOL_81_11 = 81,                     /* $@11  */
  YYSYMBOL_82_12 = 82,                     /* $@12  */
  YYSYMBOL_boucle_repeter = 83,            /* boucle_repeter  */
  YYSYMBOL_84_13 = 84,                     /* $@13  */
  YYSYMBOL_lecture = 85,                   /* lecture  */
  YYSYMBOL_ecriture = 86,                  /* ecriture  */
  YYSYMBOL_ecriture_chaine = 87            /* ecriture_chaine  */
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
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    41,    41,    41,    83,    83,    99,   101,   105,   111,
     113,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   130,   130,   140,   141,   142,   146,   147,   153,   162,
     170,   178,   186,   194,   202,   214,   245,   246,   252,   259,
     269,   273,   277,   281,   281,   296,   300,   300,   310,   310,
     323,   325,   329,   329,   353,   355,   355,   361,   376,   381,
     376,   395,   397,   395,   429,   429,   446,   459,   470
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
  "SELON", "CAS", "DEFAUT", "FINSELON", "SORTIR", "TANT_QUE", "FAIRE",
  "FINTANT", "POUR", "DE", "A", "PAS", "FINPOUR", "REPETER", "JUSQUA",
  "AFFECTATION", "EGAL", "DIFFERENT", "SUP_EGAL", "INF_EGAL", "SUPERIEUR",
  "INFERIEUR", "PLUS", "MOINS", "FOIS", "DIVISE", "MODULO",
  "POINT_VIRGULE", "VIRGULE", "PAREN_OUV", "PAREN_FERM", "DEUX_POINTS",
  "QUESTION", "NOMBRE_ENTIER", "IDENTIFICATEUR", "CHAINE_CARACTERES",
  "$accept", "programme", "$@1", "bloc", "$@2", "declarations",
  "declaration", "instructions", "instruction", "affectation", "$@3",
  "expression", "expression_arith", "expression_comp",
  "expression_ternaire", "terme", "facteur", "conditionnelle", "$@4",
  "partie_sinon_opt", "$@5", "structure_selon", "$@6", "liste_cas",
  "cas_simple", "$@7", "partie_defaut_opt", "$@8", "sortir_instruction",
  "boucle_tant_que", "$@9", "$@10", "boucle_pour", "$@11", "$@12",
  "boucle_repeter", "$@13", "lecture", "ecriture", "ecriture_chaine", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-51)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,   -51,    17,   -51,   -51,     9,    14,   -51,   -20,   -51,
     -51,    -7,    89,   -51,    -6,     2,     1,     4,    11,   -51,
      61,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,    39,   -25,   -51,   -51,    54,   -37,
      93,   -51,   -51,    47,   -51,   -25,   -25,   -51,    19,   -51,
     -51,    85,   -51,    13,   -51,   -51,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,    32,    58,
     -25,    96,    -2,   -25,   -51,    25,    81,    81,    81,    81,
      81,    81,    47,    47,   -51,   -51,   -51,   129,   -51,    66,
     -25,    98,    -9,   -25,   -51,   -51,   122,   -19,   -25,   -51,
      97,   -51,    90,   -51,   -25,    69,    21,   -25,    99,   -51,
     128,   -51,   -10,   105,   -51,   134,    75,   -51,   -51,    46,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,    89,   -51,
      89,    74,    89,   -51
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     2,     0,     6,     1,     0,     4,     3,     0,     9,
       7,     0,     5,     8,     0,     0,     0,     0,     0,    58,
       0,    64,    21,    10,    11,    15,    19,    20,    16,    17,
      18,    12,    13,    14,     0,     0,    40,    41,     0,     0,
      23,    24,    25,    26,    36,     0,     0,    57,     0,    61,
       9,     0,    66,     0,    68,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,     0,    31,    32,    34,    33,
      29,    30,    27,    28,    37,    38,    39,     0,    48,     0,
       0,     0,     0,     0,    43,    50,     0,     0,     0,    22,
      35,     9,    54,    59,     0,     0,    45,     0,     0,    51,
       0,     9,     0,     0,    46,     0,     0,    55,    49,     0,
      62,    65,     9,    44,    52,     9,    60,     9,    47,     9,
      56,     0,    53,    63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -50,   -51,   -51,
     -51,   -34,    72,   -51,   -51,    73,    22,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     9,     6,    10,    12,    23,    24,
      51,    39,    40,    41,    42,    43,    44,    25,   101,   115,
     122,    26,    95,   102,   109,   129,   110,   125,    27,    28,
      48,   111,    29,    71,   127,    30,    50,    31,    32,    33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      72,    53,    55,   104,    14,    15,    16,    56,   120,     1,
      17,    68,    69,     7,    18,    19,    35,     4,    20,     8,
      36,    37,    75,    21,    91,    56,    11,    14,    15,    16,
      99,   114,    13,    17,    56,    56,    89,    18,    19,    92,
      34,    20,    45,    35,    22,    46,    21,    36,    37,    38,
      47,   106,    14,    15,    16,    74,    97,    56,    17,   100,
      70,   119,    18,    19,   105,   126,    20,    22,    93,    56,
     112,    21,   128,   116,    87,   130,    56,   131,    52,   132,
      14,    15,    16,    65,    66,    67,    17,    84,    85,    86,
      18,    19,    22,    54,    20,    14,    15,    16,   133,    21,
      88,    17,    56,   107,   108,    18,    19,    49,    96,    20,
      56,   113,    73,    56,    21,    63,    64,    90,   124,    56,
      22,    57,    58,    59,    60,    61,    62,    63,    64,    76,
      77,    78,    79,    80,    81,    22,    82,    83,    94,    98,
     103,    56,   117,   118,   121,   123
};

static const yytype_uint8 yycheck[] =
{
      50,    35,    39,    22,     6,     7,     8,    44,    18,     3,
      12,    45,    46,     4,    16,    17,    41,     0,    20,     5,
      45,    46,    56,    25,    26,    44,    46,     6,     7,     8,
      39,    10,    39,    12,    44,    44,    70,    16,    17,    73,
      46,    20,    41,    41,    46,    41,    25,    45,    46,    47,
      39,   101,     6,     7,     8,    42,    90,    44,    12,    93,
      41,   111,    16,    17,    98,    19,    20,    46,    43,    44,
     104,    25,   122,   107,    42,   125,    44,   127,    39,   129,
       6,     7,     8,    36,    37,    38,    12,    65,    66,    67,
      16,    17,    46,    39,    20,     6,     7,     8,    24,    25,
      42,    12,    44,    13,    14,    16,    17,    46,    42,    20,
      44,    42,    27,    44,    25,    34,    35,    21,    43,    44,
      46,    28,    29,    30,    31,    32,    33,    34,    35,    57,
      58,    59,    60,    61,    62,    46,    63,    64,     9,    41,
      18,    44,    43,    15,    39,    11
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    49,    50,     0,    51,    53,     4,     5,    52,
      54,    46,    55,    39,     6,     7,     8,    12,    16,    17,
      20,    25,    46,    56,    57,    65,    69,    76,    77,    80,
      83,    85,    86,    87,    46,    41,    45,    46,    47,    59,
      60,    61,    62,    63,    64,    41,    41,    39,    78,    46,
      84,    58,    39,    59,    39,    39,    44,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    59,    59,
      41,    81,    55,    27,    42,    59,    60,    60,    60,    60,
      60,    60,    63,    63,    64,    64,    64,    42,    42,    59,
      21,    26,    59,    43,     9,    70,    42,    59,    41,    39,
      59,    66,    71,    18,    22,    59,    55,    13,    14,    72,
      74,    79,    59,    42,    10,    67,    59,    43,    15,    55,
      18,    39,    68,    11,    43,    75,    19,    82,    55,    73,
      55,    55,    55,    24
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    50,    49,    52,    51,    53,    53,    54,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    58,    57,    59,    59,    59,    60,    60,    60,    61,
      61,    61,    61,    61,    61,    62,    63,    63,    63,    63,
      64,    64,    64,    66,    65,    67,    68,    67,    70,    69,
      71,    71,    73,    72,    74,    75,    74,    76,    78,    79,
      77,    81,    82,    80,    84,    83,    85,    86,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     0,     3,     0,     2,     3,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     1,     3,     3,     3,
       1,     1,     3,     0,     9,     0,     0,     3,     0,     8,
       0,     2,     0,     5,     0,     0,     4,     2,     0,     0,
       9,     0,     0,    11,     0,     8,     3,     3,     3
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
#line 41 "francais.y"
          { 
        fichier_temp = fopen("temp_strings.asm", "w");
        
        fichier_asm = fopen("programme.asm", "w");
        fprintf(fichier_asm, "; Programme francais avec chaines\n");
        fprintf(fichier_asm, "section .data\n");
        fprintf(fichier_asm, "    format_int db '%%d', 10, 0\n");
        fprintf(fichier_asm, "    format_string db '%%s', 10, 0\n");
        fprintf(fichier_asm, "    input_format db '%%d', 0\n");
        fprintf(fichier_asm, "    input_msg db 'Entrez un nombre: ', 0\n");
        fprintf(fichier_asm, "    temp_limite_0 dd 0\n");
        fprintf(fichier_asm, "    temp_limite_1 dd 0\n");
        fprintf(fichier_asm, "    temp_limite_2 dd 0\n");
        fprintf(fichier_asm, "    temp_switch_0 dd 0\n");
        fprintf(fichier_asm, "    temp_switch_1 dd 0\n");
        fprintf(fichier_asm, "    temp_switch_2 dd 0\n");
        
        string_counter = 0;
        printf("Debut de compilation avec chaines...\n");
    }
#line 1279 "francais.tab.c"
    break;

  case 3: /* programme: DEBUT $@1 bloc FIN  */
#line 62 "francais.y"
        { 
        /* Insérer les chaînes du fichier temporaire */
        fclose(fichier_temp);
        
        FILE *temp_read = fopen("temp_strings.asm", "r");
        if (temp_read) {
            char buffer[1000];
            while (fgets(buffer, sizeof(buffer), temp_read)) {
                fprintf(fichier_asm, "%s", buffer);
            }
            fclose(temp_read);
        }
        
        remove("temp_strings.asm");
        
        fclose(fichier_asm);
        printf("Compilation terminee avec succes!\n"); 
    }
#line 1302 "francais.tab.c"
    break;

  case 4: /* $@2: %empty  */
#line 83 "francais.y"
                 { 
        fprintf(fichier_asm, "\nsection .text\n");
        fprintf(fichier_asm, "    global _start\n");
        fprintf(fichier_asm, "    extern printf, scanf\n");
        fprintf(fichier_asm, "_start:\n");
        fprintf(fichier_asm, "    call main\n");
        fprintf(fichier_asm, "    mov eax, 1\n");
        fprintf(fichier_asm, "    mov ebx, 0\n");
        fprintf(fichier_asm, "    int 0x80\n");
        fprintf(fichier_asm, "main:\n");
    }
#line 1318 "francais.tab.c"
    break;

  case 5: /* bloc: declarations $@2 instructions  */
#line 93 "francais.y"
                   {
        /* CORRECTION: Ajout du return à la fin de main */
        fprintf(fichier_asm, "    ret\n");
    }
#line 1327 "francais.tab.c"
    break;

  case 8: /* declaration: TYPE_ENTIER IDENTIFICATEUR POINT_VIRGULE  */
#line 105 "francais.y"
                                             {
        fprintf(fichier_asm, "    %s dd 0\n", current_id);
        printf("Variable declaree: %s\n", current_id);
    }
#line 1336 "francais.tab.c"
    break;

  case 21: /* $@3: %empty  */
#line 130 "francais.y"
                   {
        strcpy(affectation_var, current_id);
    }
#line 1344 "francais.tab.c"
    break;

  case 22: /* affectation: IDENTIFICATEUR $@3 AFFECTATION expression POINT_VIRGULE  */
#line 132 "francais.y"
                                           {
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    mov [%s], eax\n", affectation_var);
        printf("Affectation a: %s\n", affectation_var);
    }
#line 1354 "francais.tab.c"
    break;

  case 27: /* expression_arith: expression_arith PLUS terme  */
#line 147 "francais.y"
                                  {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    add eax, ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1365 "francais.tab.c"
    break;

  case 28: /* expression_arith: expression_arith MOINS terme  */
#line 153 "francais.y"
                                   {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    sub eax, ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1376 "francais.tab.c"
    break;

  case 29: /* expression_comp: expression_arith SUPERIEUR expression_arith  */
#line 162 "francais.y"
                                                {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setg al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1389 "francais.tab.c"
    break;

  case 30: /* expression_comp: expression_arith INFERIEUR expression_arith  */
#line 170 "francais.y"
                                                  {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setl al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1402 "francais.tab.c"
    break;

  case 31: /* expression_comp: expression_arith EGAL expression_arith  */
#line 178 "francais.y"
                                             {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    sete al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1415 "francais.tab.c"
    break;

  case 32: /* expression_comp: expression_arith DIFFERENT expression_arith  */
#line 186 "francais.y"
                                                  {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setne al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1428 "francais.tab.c"
    break;

  case 33: /* expression_comp: expression_arith INF_EGAL expression_arith  */
#line 194 "francais.y"
                                                 {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setle al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1441 "francais.tab.c"
    break;

  case 34: /* expression_comp: expression_arith SUP_EGAL expression_arith  */
#line 202 "francais.y"
                                                 {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    setge al\n");
        fprintf(fichier_asm, "    movzx eax, al\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1454 "francais.tab.c"
    break;

  case 35: /* expression_ternaire: expression QUESTION expression DEUX_POINTS expression  */
#line 214 "francais.y"
                                                          {
        int etiq = etiquette_counter++;
        
        /* La pile contient maintenant (du haut vers le bas) :
         * - expression_sinon (expression après :)
         * - expression_alors (expression après ?)
         * - condition (première expression)
         */
        
        fprintf(fichier_asm, "    pop ecx\n");     /* expression_sinon */
        fprintf(fichier_asm, "    pop ebx\n");     /* expression_alors */
        fprintf(fichier_asm, "    pop eax\n");     /* condition */
        
        fprintf(fichier_asm, "    test eax, eax\n");
        fprintf(fichier_asm, "    jz ternaire_sinon_%d\n", etiq);
        
        /* Si condition vraie : utiliser expression_alors */
        fprintf(fichier_asm, "    push ebx\n");
        fprintf(fichier_asm, "    jmp ternaire_fin_%d\n", etiq);
        
        /* Si condition fausse : utiliser expression_sinon */
        fprintf(fichier_asm, "ternaire_sinon_%d:\n", etiq);
        fprintf(fichier_asm, "    push ecx\n");
        
        fprintf(fichier_asm, "ternaire_fin_%d:\n", etiq);
        
        printf("Operation ternaire - Valeur %d\n", etiq);
    }
#line 1487 "francais.tab.c"
    break;

  case 37: /* terme: terme FOIS facteur  */
#line 246 "francais.y"
                         {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    imul eax, ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1498 "francais.tab.c"
    break;

  case 38: /* terme: terme DIVISE facteur  */
#line 252 "francais.y"
                           {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cdq\n");
        fprintf(fichier_asm, "    idiv ebx\n");
        fprintf(fichier_asm, "    push eax\n");
    }
#line 1510 "francais.tab.c"
    break;

  case 39: /* terme: terme MODULO facteur  */
#line 259 "francais.y"
                           {
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    cdq\n");
        fprintf(fichier_asm, "    idiv ebx\n");
        fprintf(fichier_asm, "    push edx\n");
    }
#line 1522 "francais.tab.c"
    break;

  case 40: /* facteur: NOMBRE_ENTIER  */
#line 269 "francais.y"
                  {
        fprintf(fichier_asm, "    push %d\n", yylval);
        printf("Constante: %d\n", yylval);
    }
#line 1531 "francais.tab.c"
    break;

  case 41: /* facteur: IDENTIFICATEUR  */
#line 273 "francais.y"
                     {
        fprintf(fichier_asm, "    push dword [%s]\n", current_id);
        printf("Variable utilisee: %s\n", current_id);
    }
#line 1540 "francais.tab.c"
    break;

  case 43: /* $@4: %empty  */
#line 281 "francais.y"
                                             {
        int etiq = etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiq;
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    test eax, eax\n");
        fprintf(fichier_asm, "    jz sinon_%d\n", etiq);
        printf("Debut condition SI\n");
    }
#line 1553 "francais.tab.c"
    break;

  case 44: /* conditionnelle: SI PAREN_OUV expression PAREN_FERM ALORS $@4 instructions partie_sinon_opt FINSI  */
#line 288 "francais.y"
                                          {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "fin_si_%d:\n", etiq);
        printf("Fin condition SI\n");
    }
#line 1563 "francais.tab.c"
    break;

  case 45: /* partie_sinon_opt: %empty  */
#line 296 "francais.y"
               {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "sinon_%d:\n", etiq);
    }
#line 1572 "francais.tab.c"
    break;

  case 46: /* $@5: %empty  */
#line 300 "francais.y"
            {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    jmp fin_si_%d\n", etiq);
        fprintf(fichier_asm, "sinon_%d:\n", etiq);
        printf("Partie SINON\n");
    }
#line 1583 "francais.tab.c"
    break;

  case 48: /* $@6: %empty  */
#line 310 "francais.y"
                                          {
        int etiq = etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiq;
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    mov [temp_switch_%d], eax\n", etiq % 3);
        printf("SELON (switch) - etiquette %d\n", etiq);
    }
#line 1595 "francais.tab.c"
    break;

  case 49: /* structure_selon: SELON PAREN_OUV expression PAREN_FERM $@6 liste_cas partie_defaut_opt FINSELON  */
#line 316 "francais.y"
                                           {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "fin_selon_%d:\n", etiq);
        printf("Fin SELON - etiquette %d\n", etiq);
    }
#line 1605 "francais.tab.c"
    break;

  case 52: /* $@7: %empty  */
#line 329 "francais.y"
                               {
        int etiq_selon = etiquette_stack[stack_ptr-1];  /* Étiquette du selon parent */
        int cas_etiq = etiquette_counter++;
        
        fprintf(fichier_asm, "    pop ebx\n");
        fprintf(fichier_asm, "    mov eax, [temp_switch_%d]\n", etiq_selon % 3);
        fprintf(fichier_asm, "    cmp eax, ebx\n");
        fprintf(fichier_asm, "    jne cas_suivant_%d\n", cas_etiq);
        
        printf("CAS - etiquette %d, selon parent %d\n", cas_etiq, etiq_selon);
        
        /* Empiler l'étiquette du cas */
        etiquette_stack[stack_ptr] = cas_etiq;
        stack_ptr++;
    }
#line 1625 "francais.tab.c"
    break;

  case 53: /* cas_simple: CAS expression DEUX_POINTS $@7 instructions  */
#line 343 "francais.y"
                   {
        int cas_etiq = etiquette_stack[--stack_ptr];
        int etiq_selon = etiquette_stack[stack_ptr-1];
        
        /* Saut automatique vers la fin du selon (pas de fall-through) */
        fprintf(fichier_asm, "    jmp fin_selon_%d\n", etiq_selon);
        fprintf(fichier_asm, "cas_suivant_%d:\n", cas_etiq);
    }
#line 1638 "francais.tab.c"
    break;

  case 55: /* $@8: %empty  */
#line 355 "francais.y"
                         {
        printf("CAS DEFAUT\n");
    }
#line 1646 "francais.tab.c"
    break;

  case 57: /* sortir_instruction: SORTIR POINT_VIRGULE  */
#line 361 "francais.y"
                         {
        if (stack_ptr > 0) {
            /* Trouver l'étiquette du selon le plus proche */
            int etiq = etiquette_stack[stack_ptr-1];
            /* Si c'est un cas, prendre l'étiquette du selon parent */
            if (stack_ptr > 1) {
                etiq = etiquette_stack[stack_ptr-2];
            }
            fprintf(fichier_asm, "    jmp fin_selon_%d\n", etiq);
            printf("SORTIR (break) vers fin_selon_%d\n", etiq);
        }
    }
#line 1663 "francais.tab.c"
    break;

  case 58: /* $@9: %empty  */
#line 376 "francais.y"
             {
        int etiq = etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiq;
        fprintf(fichier_asm, "debut_boucle_%d:\n", etiq);
        printf("Debut boucle TANT_QUE\n");
    }
#line 1674 "francais.tab.c"
    break;

  case 59: /* $@10: %empty  */
#line 381 "francais.y"
                                            {
        int etiq = etiquette_stack[stack_ptr-1];
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    test eax, eax\n");
        fprintf(fichier_asm, "    jz fin_boucle_%d\n", etiq);
    }
#line 1685 "francais.tab.c"
    break;

  case 60: /* boucle_tant_que: TANT_QUE $@9 PAREN_OUV expression PAREN_FERM FAIRE $@10 instructions FINTANT  */
#line 386 "francais.y"
                           {
        int etiq = etiquette_stack[--stack_ptr];
        fprintf(fichier_asm, "    jmp debut_boucle_%d\n", etiq);
        fprintf(fichier_asm, "fin_boucle_%d:\n", etiq);
        printf("Fin boucle TANT_QUE\n");
    }
#line 1696 "francais.tab.c"
    break;

  case 61: /* $@11: %empty  */
#line 395 "francais.y"
                        {
        strcpy(affectation_var, current_id);
    }
#line 1704 "francais.tab.c"
    break;

  case 62: /* $@12: %empty  */
#line 397 "francais.y"
                                       {
        int etiq = etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiq;
        
        /* CORRECTION: Inverser l'ordre - limite en premier, puis valeur initiale */
        fprintf(fichier_asm, "    pop eax\n");                    /* limite (expression A) */
        fprintf(fichier_asm, "    mov [temp_limite_%d], eax\n", etiq % 3);
        fprintf(fichier_asm, "    pop eax\n");                    /* valeur initiale (expression DE) */
        fprintf(fichier_asm, "    mov [%s], eax\n", affectation_var);
        
        fprintf(fichier_asm, "debut_pour_%d:\n", etiq);
        fprintf(fichier_asm, "    mov eax, [%s]\n", affectation_var);
        fprintf(fichier_asm, "    cmp eax, [temp_limite_%d]\n", etiq % 3);
        fprintf(fichier_asm, "    jg fin_pour_%d\n", etiq);       /* Si variable > limite, sortir */
        
        printf("POUR %s de [valeur] a [limite]\n", affectation_var);
    }
#line 1726 "francais.tab.c"
    break;

  case 63: /* boucle_pour: POUR IDENTIFICATEUR $@11 DE expression A expression FAIRE $@12 instructions FINPOUR  */
#line 413 "francais.y"
                           {
        int etiq = etiquette_stack[--stack_ptr];
        
        /* CORRECTION: Vérifier la limite avant d'incrémenter pour éviter les boucles infinies */
        fprintf(fichier_asm, "    mov eax, [%s]\n", affectation_var);
        fprintf(fichier_asm, "    cmp eax, [temp_limite_%d]\n", etiq % 3);
        fprintf(fichier_asm, "    jge fin_pour_%d\n", etiq);      /* Si variable >= limite, sortir */
        fprintf(fichier_asm, "    inc dword [%s]\n", affectation_var);
        fprintf(fichier_asm, "    jmp debut_pour_%d\n", etiq);
        fprintf(fichier_asm, "fin_pour_%d:\n", etiq);
        
        printf("Fin POUR\n");
    }
#line 1744 "francais.tab.c"
    break;

  case 64: /* $@13: %empty  */
#line 429 "francais.y"
            {
        int etiq = etiquette_counter++;
        etiquette_stack[stack_ptr++] = etiq;
        fprintf(fichier_asm, "debut_repeter_%d:\n", etiq);
        printf("REPETER (do-while)\n");
    }
#line 1755 "francais.tab.c"
    break;

  case 65: /* boucle_repeter: REPETER $@13 instructions JUSQUA PAREN_OUV expression PAREN_FERM POINT_VIRGULE  */
#line 434 "francais.y"
                                                                        {
        int etiq = etiquette_stack[--stack_ptr];
        
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    test eax, eax\n");
        fprintf(fichier_asm, "    jz debut_repeter_%d\n", etiq);
        
        printf("JUSQUA (condition)\n");
    }
#line 1769 "francais.tab.c"
    break;

  case 66: /* lecture: LIRE IDENTIFICATEUR POINT_VIRGULE  */
#line 446 "francais.y"
                                      {
        fprintf(fichier_asm, "    push input_msg\n");
        fprintf(fichier_asm, "    call printf\n");
        fprintf(fichier_asm, "    add esp, 4\n");
        fprintf(fichier_asm, "    push %s\n", current_id);
        fprintf(fichier_asm, "    push input_format\n");
        fprintf(fichier_asm, "    call scanf\n");
        fprintf(fichier_asm, "    add esp, 8\n");
        printf("Lecture de: %s\n", current_id);
    }
#line 1784 "francais.tab.c"
    break;

  case 67: /* ecriture: ECRIRE expression POINT_VIRGULE  */
#line 459 "francais.y"
                                    {
        fprintf(fichier_asm, "    pop eax\n");
        fprintf(fichier_asm, "    push eax\n");
        fprintf(fichier_asm, "    push format_int\n");
        fprintf(fichier_asm, "    call printf\n");
        fprintf(fichier_asm, "    add esp, 8\n");
        printf("Ecriture d'une expression numerique\n");
    }
#line 1797 "francais.tab.c"
    break;

  case 68: /* ecriture_chaine: ECRIRE CHAINE_CARACTERES POINT_VIRGULE  */
#line 470 "francais.y"
                                           {
        fprintf(fichier_temp, "    string_%d db %s, 0\n", string_counter, current_string);
        
        fprintf(fichier_asm, "    push string_%d\n", string_counter);
        fprintf(fichier_asm, "    push format_string\n");
        fprintf(fichier_asm, "    call printf\n");
        fprintf(fichier_asm, "    add esp, 8\n");
        
        printf("Ecriture d'une chaine: %s\n", current_string);
        string_counter++;
    }
#line 1813 "francais.tab.c"
    break;


#line 1817 "francais.tab.c"

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

#line 483 "francais.y"


void yyerror(const char *s) {
    fprintf(stderr, "Erreur de syntaxe: %s\n", s);
}

int main() {
    printf("=== Compilateur Francais avec Chaines ===\n");
    printf("Entrez votre programme:\n");
    return yyparse();
}
